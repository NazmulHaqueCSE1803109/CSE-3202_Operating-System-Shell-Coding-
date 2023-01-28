#! /bin/bash
arr=(24 3 4)
echo "Array in orginal order : "
echo ${arr[*]}

#sorting
for ((i=0;i<3;i++))
do
   for((J=0;j<3-i-1;j++))
   do
      if [ ${arr[j]} -gt ${arr[$((j+1))]} ]
      then
           temp=${arr[j]}
           arr[$j]=${arr[$((j+1))]}
           arr[$((j+1))]=$temp
      fi
   done
done
echo "Array in sorted order : "
echo ${arr[*]}
sum=$((${arr[0]}+${arr[1]}+${arr[0]}))
echo $sum
awt=$(echo $sum / 3|bc -l)
echo $awt
