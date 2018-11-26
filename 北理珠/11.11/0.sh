#!/bin/bash
while true; do
    ./data > data.in
    ./C <data.in >C.out
    ./CC <data.in >CC.out
    if diff C.out CC.out; then
        printf "AC\n"
    else
        printf "Wa\n"
        exit 0
    fi
done