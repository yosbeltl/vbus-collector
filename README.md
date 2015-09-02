# vbus-collector
[![Build Status](https://travis-ci.org/tripplet/vbus-collector.svg?branch=master)](https://travis-ci.org/tripplet/vbus-collector)

Data visualization is done by [vbus-server](https://github.com/tripplet/vbus-server)

## HowTo
The RaspberryPi or other linux machine should be running and connected to the internet, ssh sould be available.

* Get root via `sudo -s`, `su` or other ways :smile:

Get the necessary packages (raspbian)
```shell
$ apt-get update
$ apt-get install git build-essential cmake libsqlite3-dev
```

Get the necessary packages (archlinux-arm)
```shell
$ pacman -Syu
$ pacman -S git base-devel cmake libsqlite3-dev sqlite
```

Download the source code
```shell
$ mkdir -p /opt/vbus
$ cd /opt/vbus
$ git clone https://github.com/tripplet/vbus-collector.git collector
```

Compile the data collector service
```shell
$ cd /opt/vbus/collector
$ make
```


### Setting up config files

Now the udev rules and systemd service files need to be soft linked to the right locations
```shell
$ ln -s /opt/vbus/collector/00-resol-vbus-usb.rules /etc/udev/rules.d/
$ ln -s /opt/vbus/collector/monitor-vbus.service /etc/systemd/system/
```

Now reload the udev rules
```shell
$ udevadm control --reload-rules
```

If the VBUS-USB adapter is connected the file /dev/tty_resol should exist
```shell
$ stat /dev/tty_resol
  File: '/dev/tty_resol' -> 'ttyACM0'
  Size: 7    Blocks: 0    IO Block: 4096    symbolic link
```

Check if the collector is working (stop with Ctrl+C)
```shell
$ /opt/vbus/collector/vbus-collector --delay 1 /dev/tty_resol
  System time:13:19, Sensor1 temp:20.7C, Sensor2 temp:21.0C, Sensor3 temp:22.9C, Sensor4 temp:24.0C, Pump speed1:0%, Pump speed2:0%, Hours1:2302, Hours2:2425
  System time:13:19, Sensor1 temp:20.7C, Sensor2 temp:21.0C, Sensor3 temp:22.9C, Sensor4 temp:24.0C, Pump speed1:0%, Pump speed2:0%, Hours1:2302, Hours2:2425
  System time:13:19, Sensor1 temp:20.7C, Sensor2 temp:21.0C, Sensor3 temp:22.9C, Sensor4 temp:24.0C, Pump speed1:0%, Pump speed2:0%, Hours1:2302, Hours2:2425
```

Start the monitor-vbus service
```shell
$ systemctl start monitor-vbus
```

Check wether the service is running properly
```shell
$ systemctl status monitor-vbus
  ● monitor-vbus.service - Monitor resol vbus temperatures
     Loaded: loaded (/opt/vbus/collector/monitor-vbus.service; linked; vendor preset: disabled)
     Active: active (running) since Mi 2015-09-02 13:29:23 CEST; 10min ago
   Main PID: 12422 (vbus-collector)
     CGroup: /system.slice/monitor-vbus.service
             └─12422 /opt/vbus/collector/vbus-collector --no-print --delay 60 --db /opt/vbus/collector/data.db /dev/tty_resol
```
