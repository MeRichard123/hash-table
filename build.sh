#!/bin/sh

set -xe

g++ -Wall -g -o main main.cpp -std=c++11

echo "Running Program... \n"

./main