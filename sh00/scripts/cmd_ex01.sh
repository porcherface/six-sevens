#!/bin/bash
# ###############
#
# MISSING TEMPLATE
#
# ##

# #start
number=01
cd ..
rm -rf ex$number
mkdir ex$number
cd ex$number

# #go
FILENAME=testShell00

touch $FILENAME
echo zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz > $FILENAME 
touch -m -t202006012342.30 $FILENAME 

chmod u=r $FILENAME #user
chmod g=rx $FILENAME #group
chmod o=rx $FILENAME #owner
 
ls -l
tar -cf $FILENAME".tar" $FILENAME
rm -f $FILENAME
