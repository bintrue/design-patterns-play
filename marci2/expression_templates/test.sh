#!/usr/bin/env bash

g++ -O3 -DEXPRESSION -o expression expression.cpp
g++ -O3 -o naive expression.cpp

echo measuring expression
time expression >/dev/null
echo measuring naive
time naive >/dev/null

