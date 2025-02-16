#!/bin/bash

g++ src/*.cpp -std=c++11 -o main -Ilib/ -lssl -lcrypto
