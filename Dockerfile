FROM ubuntu

# Install build packages
RUN apt-get update
RUN apt-get -y install git

# Add git repository source code
RUN git clone https://github.com/tripplet/vbus-collector.git --recursive --branch master --depth 1 /src

RUN apt-get -y install build-essential libsqlite3-dev
RUN apt-get -y install cmake

RUN cd "/src/paho.mqtt.c" && mkdir build && cd build && cmake -DPAHO_BUILD_STATIC=TRUE .. && make -j
RUN cd /src && make -j

#### Stage 2
FROM ubuntu

LABEL maintainer="Tobias Tanegmann"

RUN apt-get update && \
    apt-get -y install sqlite && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

COPY --from=0 /src/vbus-collector /bin/vbus-collector