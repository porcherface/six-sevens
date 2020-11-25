#!/bin/bash
# ###############
#
# MISSING TEMPLATE
#
# ##

# #start
number=03
cd ..
rm -rf ex$number
mkdir ex$number
cd ex$number

# #go
kinit
sed -n 4p klist > klist.txt
cat klist.txt