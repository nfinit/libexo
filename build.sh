#!/bin/bash
clear
echo -n "Building orbital characterization tool..."
gcc -lm -Wall src/tools/orbit.c src/utils/units.c src/math/orbits.c -o orbit
echo "done"
echo -n "Earth orbital period test..."
orbit 1 AU 1 MSun 1 Me
echo -n "Moon orbital period test..."
orbit 384400 km 1 Me 0.0123 Me
echo -n "Jupter orbital period test..."
orbit 5.20336301 AU 1 MSun 1 Mj
echo -n "Earth SmA test..."
orbit 1 year 1 MSun 1 Me
echo -n "Moon SmA test..."
orbit 27.322 days 1 Me 0.0123 Me
echo -n "Jupiter SmA test..."
orbit 11.862615 years 1 MSun 1 Mj
