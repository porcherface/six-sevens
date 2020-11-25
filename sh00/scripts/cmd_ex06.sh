#!/bin/bash
# ###############
#
# MISSING TEMPLATE
#
# ##

# #start
number=06
name=git_ignore.sh
cd ..
rm -rf ex$number
mkdir ex$number
cd ex$number

# #cp script
script="../scripts/src/$name"
cp $script .
chmod 777 $name

# #test 
cp $script ../testgit/
cd ../testgit 
chmod 777 $name
./$name

rm -rf $name