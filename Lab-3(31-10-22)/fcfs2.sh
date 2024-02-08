#! /bin/bash
echo "Enter bt: "
read -a bt
n=${#bt[@]}
n=$((n-1))
wt=(0 0 0 0 0 0 0 0)
for ((i=1;i<=$n;i++));
do 
     wt[i]=$((bt[i-1]+wt[i-1]))
done
total=0
for t in ${wt[@]}
do
    total=$((total+t))
done
n=$((n+1))
echo "awt"
echo "scale=3;$total/$n"|bc
