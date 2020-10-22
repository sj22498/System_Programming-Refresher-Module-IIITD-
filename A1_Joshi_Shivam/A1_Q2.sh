#! /bin/bash
# shivam 's script

if [ -d $1 ]   # to check if such directory exist or not
then 
if [ -r $1 ]   # to check the readibility of directory
then
ls $1 | wc -l  # list no.of files in directory
else
echo "Error-code 3 : Not Readable ";
fi
else
echo "Error-code 2 : Does Not Name A Directory";
fi


if [ "$2" != "" ]  # if second argument is passed or not
then
 cd $1
ls *.$2 | wc -l;  # Applying filter as provided in input
fi


if [ "$3" != "" ] # more than 2 parameter rsult in error
then
echo "Error-code 1 : wrong number of command line parameters";
fi








