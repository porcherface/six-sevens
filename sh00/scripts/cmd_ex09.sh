#!/bin/bash
# ###############
#
# MISSING TEMPLATE
#
# ##

# #start
number=09
name=ft_magic
cd ..
rm -rf ex$number
mkdir ex$number
cd ex$number

# #cp script
script="../scripts/src/$name"
cp $script .
chmod 777 $name
cat $name