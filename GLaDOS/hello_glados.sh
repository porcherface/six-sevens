#!/bin/bash.sh

# this works only for SH00 test slot
# it is to be intende mostly a 
# feasability/effort test

######################
# target configuration

echo "
############################################################"

test_subject_url="git@vogsphere.42roma.it:vogsphere/intra-uuid-a009fe86-3b9a-4a04-af9e-57993daf4b28-3386740"
cd testenv
rm -rf *-*-*-* 
ls -lart
echo "
############################################################"

git init
git clone $test_subject_url
ls -lart
cd ..
######################
# target init

cd testenv
#test_subject=$(find . -mindepth 1 -maxdepth 1 -type d -printf '%f\n')
test_subject=cut -c34 $test_subject_url

logfile=testenv/log.log
cd ..


echo "
############################################################

GLaDOS: (pre-alpha version 0.0.1)    

  
              .,-:;//;:=,
          . :H@@@MM@M#H/.,+%;,
       ,/X+ +M@@M@MM%=,-%HMMM@X/,
     -+@MM; $M@@MH+-,;XMMMM@MMMM@+-
    ;@M@@M- XM@X;. -+XXXXXHHH@M@M#@/.
  ,%MM@@MH ,@%=             .---=-=:=,.
  =@#@@@MX.,                -%HX$$%%%:;
 =-./@M@M$                   .;@MMMM@MM:
 X@/ -$MM/                    . +MM@@@M$
,@M@H: :@:                    . =X#@@@@-
,@@@MMX, .                    /H- ;@M@M=
.H@@@@M@+,                    %MM+..%#$.
 /MMMM@MMH/.                  XM@MH; =;
  /%+%$XHH@$=              , .H@@@@MX,
   .=--------.           -%H.,@@@@@MX,
   .%MM@@@HHHXX$$$%+- .:$MMX =M@@MM%.
     =XMMM@MM@MM#H;,-+HMM@M+ /MMMX=
       =%@M@M#@$-.=$@MM@@@M; %M%=
         ,:+$+-,/H#MMMMMMM@= =,
               =++%%%%+/:-.
  
"               
echo "           Hello test subject "$test_subject
echo "           test subject link:"$test_subject_url
echo
echo " - test blueprint: pre-alpha version 0.0.1 - hardcoded "
echo " - test_slot:SH00                        "
oracle_dir="oracles/sh00"
subject_dir="testenv/$test_subject"
test_dir="testenv/test_chamber"
mkdir $test_dir
checklog=""
faillog="" 
read -n 1 -r -s -p $'Press enter to continue...\n'

##########################
# preliminary checks

echo " - preliminary checks: folders "
ls -ar $oracle_dir > $test_dir/afolder.log
ls -ar $subject_dir > $test_dir/bfolder.log
echo 
echo 
res=$(diff -N -rq $test_dir/afolder.log $test_dir/bfolder.log ) 1>/dev/null

if [[ $res == "0" ]]
then
  echo "[PASS]"
  echo "preliminary checks complete, parsing..."
  echo
else
  echo " [FAIL]"
  echo "preliminary checks failed, early termination"
  echo "dump: "
  diff $test_dir/afolder.log $test_dir/bfolder.log   
  rm -rf $test_dir
  exit 1
fi

read -n 1 -r -s -p $'Press enter to continue...\n'

echo " - preliminary checks: files "
ls -ar $oracle_dir/* > $test_dir/afolder.log
ls -ar $subject_dir/* > $test_dir/bfolder.log
echo 
echo 
res=$(diff -N -rq $test_dir/afolder.log $test_dir/bfolder.log ) 1>/dev/null

if [[ $? == "0" ]]
then
  echo "[PASS]"
  echo "preliminary checks complete, parsing..."
  echo
else
  echo " [FAIL]"
  echo "preliminary checks failed, early termination"
  echo "dump: "
  diff $test_dir/afolder.log $test_dir/bfolder.log   
  rm -rf $test_dir
  exit 1
fi
read -n 1 -r -s -p $'Press enter to continue...\n'
#
# _________________
#< don't murder me >
# -----------------
##     \
#      \
#
# +@##########M/             :@#########@/
# ##############$;H#######@;+#############
# ###############M########################
# ##############X,-/++/+%+/,%#############
# ############M$:           -X############
# ##########H;.      ,--.     =X##########
# :X######M;     -$H@M##MH%:    :H#######@
#   =%#M+=,   ,+@#######M###H:    -=/M#%
#   %M##@+   .X##$, ./+- ./###;    +M##%
#   %####M.  /###=         @##M.   X###%
#   %####M.  ;M##H:.     =$###X.   $###%
#   %####@.   /####M$-./@#####:    %###%
#   %H#M/,     /H###########@:     ./M#%
#  ;$H##@@H:    .;$HM#MMMH$;,   ./H@M##M$=
# X#########%.      ..,,.     .;@#########
# ###########H+:.           ./@###########
# ##############/ ./%%%%+/.-M#############
# ##############H$@#######@@##############
# ##############X%########M$M#############
# +M##########H:            .$##########X=
##########################
# test 00
number=00

oracle=$oracle_dir"/"ex$number/z
subject=$subject_dir/ex$number/z

printf " test "$number" - "
res=$(diff -N -rq "$oracle" "$subject") 1>/dev/null
if [[ $? == "0" ]]
then
  echo "[ OK ]"
else
  echo " [FAIL]"
  faillog=$faillog$number","
fi

##########################
# test 01
number=01

oracle=$oracle_dir/ex$number/testShell00.tar
subject=$subject_dir/ex$number/testShell00.tar

n1=$(tar -C $test_dir/ex$number -zxvf $oracle)
n2=$(tar -C $subject_dir/ex$number -zxvf $subject) 

a=$(ls -gGt $oracle_dir/ex$number)
b=$(ls -gGt $subject_dir/ex$number)

printf " test "$number" - "
res=$(diff -Nq "$oracle" "$subject") 1>/dev/null
if [[ $? == "0" ]]
then
  echo "[ OK ]"
else
  echo "[FAIL]"
  faillog=$faillog$number","
fi

##########################
# test 02
number=02

oracle=$oracle_dir"/"ex$number/exo2
subject=$subject_dir/ex$number/exo2

n1=$(tar -C $oracle_dir/ex$number -zxvf $oracle)
n2=$(tar -C $subject_dir/ex$number -zxvf $subject) 

a=$(ls -gGt $oracle_dir/ex$number)
b=$(ls -gGt $subject_dir/ex$number)

printf " test "$number" - "
res=$(diff -Nq "$oracle" "$subject") 1>/dev/null
if [[ $? == "0" ]]
then
  echo "[ OK ]"
else
  echo "[FAIL]"
  faillog=$faillog$number","
fi


##########################
# test 03
number=03

oracle=$oracle_dir"/"ex$number/klist.txt
subject=$subject_dir/ex$number/klist.txt

printf " test "$number" - "
res=$(diff -N -rq "$oracle" "$subject") 1>/dev/null
if [[ $? == "0" ]]
then
  echo "[ OK ]"
else
  echo "[TEST]"
  checklog=$checklog$number","
fi

##########################
# test 04
number=04

oracle="$oracle_dir"/"ex$number/midLS"
subject=$subject_dir/ex$number/midLS

printf " test "$number" - "


cd $test_dir
cp $oracle a
cp $subject b

mkdir testdir
touch \#test
touch test
touch .test
touch testdir/test
./a > alog
./b > blog

res=$(diff -Nq "$alog" "$blog") 1>/dev/null
if [[ $? == "0" ]]
then
  echo "[ OK ]"
else
  echo "[FAIL]"
  faillog=$faillog$number","
fi

cd ../..
##########################
# test 05 TBD
number=05

oracle=$oracle_dir"/"ex$number/z
subject=$subject_dir/ex$number/z

printf " test "$number" - "
res=$(diff -N -rq "$oracle" "$subject") 1>/dev/null
if [[ $? == "0" ]]
then
  echo "[ OK ]"
else
  echo "[TEST]"
  checklog=$checklog$number","
fi


##########################
# test 06
number=06

oracle=$oracle_dir"/"ex$number/z
subject=$subject_dir/ex$number/z

printf " test "$number" - "
res=$(diff -N -rq "$oracle" "$subject") 1>/dev/null
if [[ $? == "0" ]]
then
  echo "[ OK ]"
else
  echo "[TEST]"
  checklog=$checklog$number","
fi


##########################
# test 07
number=07

oracle=$oracle_dir"/"ex$number/b
subject=$subject_dir/ex$number/b

printf " test "$number" - "
res=$(diff -N -rq "$oracle" "$subject") 1>/dev/null
if [[ $? == "0" ]]
then
  echo "[ OK ]"
else
  echo "[FAIL]"
  faillog=$faillog$number","
fi


##########################
# test 08
number=08

oracle=$oracle_dir"/"ex$number/z
subject=$subject_dir/ex$number/z

printf " test "$number" - "
res=$(diff -N -rq "$oracle" "$subject") 1>/dev/null
if [[ $? == "0" ]]
then
  echo "[ OK ]"
else
  echo "[TEST]"
  checklog=$checklog$number","

fi


##########################
# test 09
number=09

oracle=$oracle_dir"/"ex$number/z
subject=$subject_dir/ex$number/z

printf " test "$number" - "
res=$(diff -N -rq "$oracle" "$subject") 1>/dev/null
if [[ $? == "0" ]]
then
  echo "[ OK ]"
else
  echo "[TEST]"
  checklog=$checklog$number","
fi

##########################
#
# REPORT
#
echo 
if [[ $faillog == "" ]]
then
  echo 
  echo "test chamber complete"
else
  echo "test chamber failed"
  echo "evaluation associate, please discuss failures on"
  echo "   "$faillog
fi

echo
if [[ $checklog == "" ]]
then
  echo 
  echo "no stalemates detected"
else
  echo "stalemates detected"
  echo "stalemate associate, please resolve stalemates on"
  echo "   "$checklog

fi

echo
#echo "cleaning and trimming out the fat? (no, wanna see what happened)"



#rm -rf $test_dir
echo "Terminating"