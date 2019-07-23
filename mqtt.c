#include "mqtt.h"

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "MQTTClient.h"

#define ADDRESS     "tcp://192.168.1.34:1883"
#define CLIENTID    "controlador-solar"
#define QOS         1
#define TIMEOUT     3000L

MQTTClient client;

int connect_mqtt(const char* last_will_topic)
{
    MQTTClient_willOptions last_will = MQTTClient_willOptions_initializer;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    int rc;

    MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    last_will.topicName = last_will_topic;
    last_will.retained = 1;
    last_will.message = "0";
    conn_opts.will = &last_will;
    conn_opts.keepAliveInterval = 600;
    conn_opts.cleansession = 1;
    conn_opts.connectTimeout = TIMEOUT;
    
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        //publish_str(last_will_topic, "0");
        return false;
    }

    publish_str(last_will_topic, "1");

    return true;
}

void disconnect_mqtt()
{

    MQTTClient_disconnect(client, TIMEOUT);
    MQTTClient_destroy(&client);
}

void publish_str(const char *topic, const char *payload)
{
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    pubmsg.payload = (char*)payload;
    pubmsg.payloadlen = strlen(payload);
    pubmsg.qos = QOS;
    pubmsg.retained = 1;

    MQTTClient_deliveryToken token;
    MQTTClient_publishMessage(client, topic, &pubmsg, &token);
    MQTTClient_waitForCompletion(client, token, TIMEOUT);
}

void publish_int(const char *topic, int payload)
{
    char buffer[32];
    snprintf(buffer, 32, "%d", payload);
    publish(topic, buffer);
}

void publish_double(const char *topic, double payload, const char *format)
{
    char buffer[32];
    snprintf(buffer, 32, format, payload);
    publish(topic, buffer);
}

