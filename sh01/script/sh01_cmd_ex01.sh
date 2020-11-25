#!/bin/bash
##
#!/bin/bash
# ###############
#
# MISSING TEMPLATE
#
# ##

# #start
number=01
name=print_groups.sh
cd ..
rm -rf git/ex$number
mkdir git/ex$number
cd git/ex$number
script="../../script/src/$name"
cp $script .
chmod 777 $name

# #go
value=daemon
export FT_USER=$value
./$name