#!/usr/bin/env bash

num=1000000

for(( i=0; i<num; i++ )); do
	echo "$((1 + $RANDOM % num)) $((1 + $RANDOM % num))" >> PRIGAME.test
done
