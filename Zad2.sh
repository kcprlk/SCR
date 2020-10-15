#!/bin/bash

#uzyto mutt client


for mail in $(cat ~/pliki/adresy.txt)
do
    cat ~/pliki/tresc.txt | mutt -s "Temat maila" $mail -a ~/pliki/spec*.pdf
done

