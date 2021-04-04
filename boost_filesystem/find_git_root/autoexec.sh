#!/bin/bash

while :
do
	if [ $? ]; then
		make
		if make; then
			./pcd2jpg
		fi
	fi
	res=$(fswatch -1 --event Updated ..)
done
