#! /bin/bash
echo "Enter bt(burst time) : "
read -a bt
bt=($(printf '%s\n' "${bt[@]}" | sort -n))
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
echo "Average Waiting time : "
echo "scale=3;$total/$n"|bc
