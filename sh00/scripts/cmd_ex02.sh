#!/bin/bash
# ###############
#
# MISSING TEMPLATE
#
# ##

# #start
number=02
cd ..
rm -rf ex$number
mkdir ex$number
cd ex$number

#DATE MISSING!!!!

# #go
FILENAME=test
mkdir $FILENAME"0" 
touch $FILENAME"1"  
echo aaa > $FILENAME"1"  
mkdir $FILENAME"2" 
touch $FILENAME"3"  
echo  > $FILENAME"3"
touch $FILENAME"4"
echo a > $FILENAME"4"
ln $FILENAME"3" $FILENAME"5"
touch $FILENAME"5"
echo  > $FILENAME"5"


touch -m -t202006012047.30 $FILENAME"0" 
touch -m -t202006012146.30 $FILENAME"1" 
touch -m -t202006012245.30 $FILENAME"2" 
touch -m -t202006012344.30 $FILENAME"3" 
touch -m -t202006012343.30 $FILENAME"4" 
touch -m -t202006012344.30 $FILENAME"5" 
ln -s "test0" $FILENAME"6"
touch -mht 202006012220.30 $FILENAME"6"

chmod u=rx $FILENAME"6" #user
chmod g=rx $FILENAME"6" #group
chmod o=rx $FILENAME"6" #owner 

chmod u=rwx $FILENAME"0" #user
chmod g=x $FILENAME"0" #group
chmod o=rx $FILENAME"0" #owner 

chmod u=rwx $FILENAME"1" #user
chmod g=x $FILENAME"1" #group
chmod o=r $FILENAME"1" #owner 

chmod u=rx $FILENAME"2" #user
chmod g= $FILENAME"2" #group
chmod o=r $FILENAME"2" #owner 

chmod u=r $FILENAME"3" #user
chmod g= $FILENAME"3" #group
chmod o=r $FILENAME"3" #owner 

chmod u=rw $FILENAME"4" #user
chmod g=r $FILENAME"4" #group
chmod o=x $FILENAME"4" #owner 

chmod u=r $FILENAME"5" #user
chmod g= $FILENAME"5" #group
chmod o=r $FILENAME"5" #owner 

ls -l
tar -cf exo2.tar *
rm -rf test*
