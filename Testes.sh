#!/bin/bash

make clean
make

declare -a quickSortTypes=(
    "QC"
    "QM3"
    "QPE"
    "QI1"
    "QI5"
    "QI10"
    "QNR"
)

declare -a arrayTypes=(
    "Ale"
    "OrdC"
    "OrdD"
)

dir="output/"
underscore="_"

for arrSize in {50000..500000..50000}; do
    for quickSort in "${quickSortTypes[@]}"; do
        for arrType in "${arrayTypes[@]}"; do
            for iteration in {1..20}; do
                echo "Running $quickSort for array size $arrSize with type $arrType, iteration $iteration".
                ./tp2 $quickSort $arrType $arrSize >> "$dir$quickSort$underscore$arrType$underscore$arrSize.txt"
                echo "Done..."
            done
        done
    done
done