#!/usr/bin/env bash

# setting the context of the build to "~/" b/c that's where my .vimrc is
docker build -t openal_testing --build-arg user_id=$(id -u) -f ./Dockerfile ~/
