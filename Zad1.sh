#!/bin/bash

LC_ALL=C

DzienTygodnia=$(date +%w)

if [ $DzienTygodnia -lt 6 ]; then

	echo "Aktualnie jest dzien roboczy"    
else

   	echo "Aktualnie jest dzien swiateczny"
fi
