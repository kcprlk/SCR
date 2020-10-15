#!/bin/bash


#parametry:
#$1 - zadawane rozszerzenie
#$2 - liczba dni
#$3 - nazwa archiwum

find -name "*.$1" -mtime -$2 -print

find -name "*.$1" -mtime -$2 | xargs tar -cf $3.tar
