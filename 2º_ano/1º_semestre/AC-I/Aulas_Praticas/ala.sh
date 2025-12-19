#!/bin/bash

for i in Aula-*; do
    num=${i#Aula-}                 # remove "Aula-"
    novo=$(printf "%02d" "$num")   # formata com 2 dígitos
    mv "$i" "$novo"
done

