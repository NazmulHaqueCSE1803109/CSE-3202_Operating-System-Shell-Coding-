#! /bin/bash
arr=(24 3 4)
s=$((${arr[0]}+${arr[0]}+${arr[1]}))
echo $s
avg=$(echo $s / 3 | bc -l )
echo $avg
