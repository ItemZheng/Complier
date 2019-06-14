#!/usr/bin/env bash

echo -e "\n\n--------- TEST BEGIN ---------"
for file in `ls ./test/*`;
do
	echo -n "Test $file ............."
	cat ${file} | (./compiler 2> error.log)
	if [[ $? -ne 0 ]]; then
		echo ${file} >> error.log
		echo "  " >> error.log
		echo "Failed"
	else
		echo "Succeed"
	fi
done