#!/bin/bash
if (($# == 0))
then
    echo "No arguments supplied"
    exit $?
fi
for i; do
    mkdir $i
done
exit 0
