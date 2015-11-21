#!/bin/bash
#MY_QMAKE="../RibiLibraries/mxe/usr/i686-w64-mingw32.static/qt5/bin/qmake"
MY_QMAKE="../RibiLibraries/mxe/usr/bin/i686-w64-mingw32.static-qmake-qt5"


if [ ! -e $MY_QMAKE ]
then
  echo "FAIL: qmake not found at path: "$MY_QMAKE
  exit
fi
 
for myprofile in `ls | egrep ".pro\>"`
do
  mytarget=`echo $myprofile | sed "s/\.pro//"`
   
  $MY_QMAKE $myprofile
   
  if [ ! -e Makefile ]
  then
    echo "FAIL: $MY_QMAKE $myprofile"
  fi
   
  make
   
  if [ -e ./release/$mytarget".exe" ]
  then
    echo $mytarget": SUCCESS"
    cp ./release/$mytarget".exe" ~/bin/
  else
    echo $mytarget": FAIL"
  fi
   
done #next .pro file
