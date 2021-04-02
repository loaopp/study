#!/bin/bash

docker stop `docker ps -aq`
docker rm `docker ps -aq`
docker build -t test .
docker run -it --name tt -p 80:80 -p 443:443 test
