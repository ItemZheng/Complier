#!/usr/bin/env bash

echo -e "\n\n--------- TEST BEGIN EXPECT SUCCESSFULLY---------"
rm error.log
for file in `ls ./test/Success/*`;
do
	echo -n "Test $file ............."
	./compiler ${file} 1>>error.log 2>> error.log
	if [[ $? -ne 0 ]]; then
		echo "  " >> error.log
		echo "Failed"
	else
		echo "Pass"
	fi
done
echo -e "\n\n--------- TEST BEGIN EXPECT FAILED---------"
for file in `ls ./test/Fail/*`;
do
	echo -n "Test $file ............."
	./compiler ${file} 1>>error.log 2>> error.log
	if [[ $? -ne 0 ]]; then
		echo " " >> error.log
		echo "Pass"
	else
		echo "Failed"
	fi
done