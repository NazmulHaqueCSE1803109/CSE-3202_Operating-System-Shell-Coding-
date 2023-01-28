#! /bin/bash
a=10.1
b=20..1
c=$($a+$b)
echo $c|bc
