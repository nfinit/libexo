#!/bin/bash
clear
echo -n "Building orbital characterization tool..."
gcc -lm -Wall src/tools/orbit.c src/utils/units.c src/math/orbits.c -o orbit
echo "done"
