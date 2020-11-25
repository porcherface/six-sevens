#!/bin/bash
# ###############
#
# MISSING TEMPLATE
#
# ##

# #start
number=07
cd ..
rm -rf ex$number
mkdir ex$number
cd ex$number

# #cp res
#diff -u a(old) b(new) > myapp.patch
#patch < myapp.patch
cp ../scripts/res/a .
cp ../scripts/res/sw.diff .
patch a sw.diff
rm sw.diff
mv a b
cat b