#!/usr/bin/env bash

g++ -o expression expression.cpp
g++ -o naive naive.cpp

time expression >/dev/null
time naive >/dev/null

