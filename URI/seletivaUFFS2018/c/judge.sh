#!/bin/bash
rm -rf myout
mkdir myout
g++ c.cpp -Wall
for i in input/atreus-*; do
    j=$(echo $i | cut -d '-' -f2)
    k=$(echo $j | cut -d '.' -f1)
    #echo "$i"
    time ./a.out < $i > myout/C_$k
    echo "Julgando $j..."
    diff output/atreus-$k.sol myout/C_$k
done
