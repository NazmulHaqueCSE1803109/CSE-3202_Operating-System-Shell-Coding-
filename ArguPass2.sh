#! /bin/bash
echo "Argument : "
echo $0 $1 $2 $3
args=("$@")
echo $@
echo $#
args=("$@")
echo ${args[0]} ${args[1]} ${args[2]}

