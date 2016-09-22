#!/bin/bash

rm -rf tmp
mkdir tmp
cd tmp
git clone $1 .
for ((i=0; i< $2;i++))
do    
    git branch team$i
    git push origin team$i
done
	cd ../
    rm -rf tmp

echo "Done"

