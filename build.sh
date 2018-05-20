#!/bin/bash
rm -rf ./build
rm -rf ./bin
rm ./stats.txt
mkdir ./build
mkdir ./bin
cd ./build && cmake ../src
make
mv ./top_k_freq ../bin/
echo "Done!"


