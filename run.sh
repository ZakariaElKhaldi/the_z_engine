#!/usr/bin/env bash

set -e
cd $(pwd)/build

if [ $1 -eq 1 ]; then
	cmake . -DCMAX_BUILD_TYPE=Debug &&
	make &&
	echo "done" &&
	./learnGraphics
else
	cmake . &&
	make &&
	echo "done" &&
	./learnGraphics
fi

cd ..
