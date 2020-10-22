#! /bin/bash
# shivam 's script
VAR=$(date "+%H")  # used to fetch the hour from the Date and Time Format
VAR1=12;
VAR2=16;

if [ $VAR -lt $VAR1 ]
then
echo "Good Morning";
elif [ $VAR -lt $VAR2 ]
then
echo "Good Afternoon"
else
echo "Good Evening";
fi


