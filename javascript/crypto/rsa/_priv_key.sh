#!/bin/bash

#echo "(2^5)^17%21" | bc <-- 2
#echo "(2^17)^5%21" | bc <-- 2
#echo "2^(5*17)%21" | bc <-- 2

#echo "(11^5)^17%21" | bc <-- 11
#echo "(11^17)^5%21" | bc <-- 11
#echo "11^(5*17)%21" | bc <-- 11

for i in {1..200}; do
    if [[ $(echo "5*$i%21" | bc) -eq 1 ]]; then
        echo $i;
    fi
done

