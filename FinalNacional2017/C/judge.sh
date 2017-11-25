#!/bin/bash
rm -rf myout
mkdir myout
g++ C.cpp -Wall
for i in input/C_*; do
    j=$(echo $i | cut -d '_' -f2)
    #echo "$j"
    ./a.out < $i > myout/C_$j
    echo "Julgando $j..."
    diff output/C_$j myout/C_$j
done
