#!/usr/bin/env bash

if [ $# -ne 2 ]
then
  echo "Usage: $0 image-name path-to-OpenAL-code"
  exit 1
fi

code=$2

# used the following resource to help setup audio capabilities inside of docker
# https://github.com/jacknlliu/ros-docker-images/issues/7
docker run -it \
  --rm \
  -v $code:/home/developer/ws/ \
  --device /dev/snd \
  -e PULSE_SERVER=unix:${XDG_RUNTIME_DIR}/pulse/native \
  -v ${XDG_RUNTIME_DIR}/pulse/native:${XDG_RUNTIME_DIR}/pulse/native \
  --group-add $(getent group audio | cut -d: -f3) \
  $1
