#!/usr/bin/env bash

g++ -DEXPRESSION -o expression expression.cpp
g++ -o naive expression.cpp

echo measuring expression
time expression >/dev/null
echo measuring naive
time naive >/dev/null

