#include <sqlite3.h>
#include <stdio.h>

#include "sqlite.h"

/**
  CREATE TABLE data (
    "id"          INTEGER PRIMARY KEY AUTOINCREMENT,
    "time"        DEFAULT CURRENT_TIMESTAMP NOT NULL,
    "system_time" TEXT NOT NULL,
    "temp1"       DOUBLE NOT NULL,
    "temp2"       DOUBLE NOT NULL,
    "temp3"       DOUBLE NOT NULL,
    "temp4"       DOUBLE NOT NULL,
    "pump1"       INTEGER NOT NULL,
    "pump2"       INTEGER NOT NULL,
    "hours1"      INTEGER NOT NULL,
    "hours2"      INTEGER NOT NULL
  );
*/

static sqlite3 *db = NULL;

bool sqlite_open(char *path) {
  if (sqlite3_open(path, &db) != 0) {
    printf("Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite_close();
    return false;
  }

  return true;
}

void sqlite_close() {
  if (db != NULL) {
    sqlite3_close(db);
  }
}

bool sqlite_exec(char* sql) {
  char *errMsg;

  if (sqlite3_exec(db, sql, NULL, 0, &errMsg) != SQLITE_OK) {
    printf("SQL error: %s\n", errMsg);
    sqlite3_free(errMsg);
    return false;
  }

  return true;
}

bool sqlite_insert_data(Data_Packet* packet) {
  char *errMsg;
  char sql_buffer[256];

  sprintf(sql_buffer, "INSERT INTO data "
    "(system_time, temp1, temp2, temp3, temp4, pump1, pump2, hours1, hours2) VALUES "
    "(\"%02d:%02d\", %.1f, %.1f, %.1f, %.1f, %d, %d, %d, %d);",
    packet->bsPlusPkt.SystemTime / 60,
    packet->bsPlusPkt.SystemTime % 60,
    packet->bsPlusPkt.TempSensor1 * 0.1,
    packet->bsPlusPkt.TempSensor2 * 0.1,
    packet->bsPlusPkt.TempSensor3 * 0.1,
    packet->bsPlusPkt.TempSensor4 * 0.1,
    packet->bsPlusPkt.PumpSpeed1,
    packet->bsPlusPkt.PumpSpeed2,
    packet->bsPlusPkt.OperatingHoursRelay1,
    packet->bsPlusPkt.OperatingHoursRelay2);

  if (sqlite3_exec(db, sql_buffer, NULL, 0, &errMsg) != 0) {
    printf("SQL error: %s\n", errMsg);
    sqlite3_free(errMsg);
    return false;
  }

  return true;
}