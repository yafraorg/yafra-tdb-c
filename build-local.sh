#!/bin/sh
#
# used for CI services like Jenkins, Shippable, Travis-CI
#
# variables must be set by CI service
#export ANDROID_HOME=/work/adt/sdk
#export PATH=${PATH}:$ANDROID_HOME/tools:$ANDROID_HOME/platform-tools


#
# set current version info
#
export YAFRAVER="1"
export YAFRAREL="0"
export YAFRAPATCH=$BUILD_NUMBER

source ./run-environment.sh

#
#
# make sure the generic profile is loaded and you have enough permissions!!
#
if [ ! -d $SYSADM/defaults ]
then
	echo "Environment not loaded - install first !"
	exit
fi


test -d $YAFRALIBPATH || mkdir -p $YAFRALIBPATH
test -d $YAFRALIBSO || mkdir -p $YAFRALIBSO
test -d $TDBO || mkdir -p $TDBO
test -d $CMDSRVO || mkdir -p $CMDSRVO
test -d $PSWHATO || mkdir -p $PSWHATO
test -d $PSEDITO || mkdir -p $PSEDITO
test -d $TESTSUITEO || mkdir -p $TESTSUITEO
test -d $WORKNODE/apps || mkdir -p $WORKNODE/apps
test -d $WORKNODE/yafra-dist || mkdir -p $WORKNODE/yafra-dist


#
# setup some variables
#
TIMESTAMP="$(date +%y%m%d)"
VERREL="$YAFRAVER.$YAFRAREL-$BUILD_NUMBER"
echo "-> settings for release $VERREL with basenode $BASENODE on $TIMESTAMP"
#
echo "OSAHRED: $OSHARED and ODEBUG: $ODEBUG"

#
#CLASSIC/ANSIC
#
cd $YAFRALIBS
make all
cd psipc/testsuite/psserver
make all
cd ../psclient-cons
make all
cd ../fork
make all
cd $YAFRALIBS/pssys/testsuite/datetime
make all
cd ../logging
make all
cd ../chars
make all
if [ "$PS_OS" = "ps_cygwin" ]; then
	cd $PSMATRIXLIB
	make clean
	make all
fi

#CLASSIC/ADDONS
cd $PSWHAT
make all
cd $PSEDIT
make all
cd $CMDSRV
make all

#CLASSIC/TDB
cd $TDBS
make mpapi
make mpgui
#make all

if [ "$PS_COMPTYPE" = "ps_unix" ]; then
	if [ "$PS_OS" != "ps_cygwin" ]; then
		if [ "$PS_OS" != "ps_osx" ]; then
			cd $WORKNODE/libs
			symlinks -c .
		fi
	fi
fi

echo "done - save in /work"
