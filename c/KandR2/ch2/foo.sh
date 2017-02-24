#!/bin/bash

#
# This depends on:
# https://github.com/btoll/tools/blob/master/c/asbits.c
#
#   curl -O https://raw.githubusercontent.com/btoll/tools/273a0484c41f72a56a14a49f8717b72761a407dd/c/asbits.c
#   gcc -Wall -o asbits asbits.c
#

for n in {8..1}; do
    echo "$n & ($n - 1)";

    echo -n "        $n -> ";
    asbits $n;

    # Bash arithmetic $((expr1 [operator] expr2)).
    echo -n "        "$(($n - 1))" -> "
    asbits $(echo $(($n - 1)));

    echo -n "    $n & "$(($n - 1))" -> "
    asbits $(echo $(($n & ($n - 1))));

    echo;
    sleep 1;
done

