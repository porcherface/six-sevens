#!/bin/bash
# ###############
#
# MISSING TEMPLATE
#
# ##

# #start
number=08
name=clean
cd ..
rm -rf ex$number
mkdir ex$number
cd ex$number

# #cp script
script="../scripts/src/$name"
cp $script .
chmod 777 $name

#test
touch test~ \#test \#test\#
mkdir testdir
touch testdir/test~
./clean
rm \#test
rm -rf testdir