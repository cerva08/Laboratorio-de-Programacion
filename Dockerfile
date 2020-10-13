# Definimos OS base
FROM ubuntu:20.04

ENV TZ=America/Costa_Rica
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime \
    && echo $TZ > /etc/timezone

# Algo de información
LABEL mantainer="josepablo.laurent@gmail.com"
LABEL version="1.0"
LABEL description="Custom docker image for a Gtest example"

# Choose user root
USER root
RUN apt-get update \
    && apt-get --yes --no-install-recommends install \
        build-essential cmake libgtest-dev \
    && cd /usr/src/gtest/ \
    && cmake CMakeLists.txt \
    && make

# Crear carpeta del proyecto
RUN mkdir -p /usr/bin/run_unittest

# copio archivos
COPY include /usr/bin/run_unittest/include
COPY src /usr/bin/run_unittest/src
COPY debug /usr/bin/run_unittest/debug
COPY test /usr/bin/run_unittest/test
COPY doc /usr/bin/run_unittest/doc
COPY CMakeLists.txt /usr/bin/run_unittest/CMakeLists.txt
COPY gitlab-ci.yml /usr/bin/run_unittest/gitlab-ci.yml
COPY README.md /usr/bin/run_unittest/README.md

# DEBUG: imprimir los contenidos
RUN ls /usr/bin/run_unittest/
