#!/bin/bash

for (( i=1; $i <= 15; i++ ))
do
trap 'echo "Trap"' $i
done

while true;
do 
date 
sleep 5
done

