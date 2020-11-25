#!/bin/bash
# ###############
#
# MISSING TEMPLATE
#
# ##

# #start
number=04
cd ..
rm -rf ex$number
mkdir ex$number
cd ex$number
name=midLS

# #cp script
script="../scripts/src/$name"

cp $script .

# #test
touch test
touch .test
mkdir testdir
touch :hardtest
chmod 777 $name
./$name

rm -rf *test*
rm -rf .test