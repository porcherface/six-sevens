#!/bin/bash
# ###############
#
# MISSING TEMPLATE
#
# ##

# #start
number=05
name=git_commit.sh
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
bash $name
rm -rf  $name