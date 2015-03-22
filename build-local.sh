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

#
# setup general paths
#
export BASENODE=/work/repos
export WORKNODE=/work/yafra-runtime
export TDBNODE=/work/repos/yafra-tdb-c
export SYSADM=$BASENODE/yafra/org.yafra.sysadm
export YAFRATOOLS=$SYSADM/defaults
export YAFRABIN=$SYSADM/defaults/scripts
export YAFRADOC=$WORKNODE/doc
export YAFRAMAN=$WORKNODE/man
export YAFRAEXE=$WORKNODE/bin
    
export PATH=$PATH:$YAFRABIN:$YAFRAEXE


#
# setup system
#
export PS_TARGET=`$YAFRABIN/gettarget`
export PS_OSTYPE=`$YAFRABIN/getostype`
export PS_OS=`$YAFRABIN/getos`
export PS_OSVER=`$YAFRABIN/getosver`
export PS_COMPTYPE=$PS_OSTYPE
export PS_HW=`$YAFRABIN/gethardware`
export PS_HOSTNAME=`$YAFRABIN/getserver`
export HARDWARE=$PS_HW

#
# setup include/lib path
#
export YAFRAINC=$TDBNODE/org.yafra.clibs/include
export YAFRALIBS=$TDBNODE/org.yafra.clibs/libs
export YAFRALIBPATH=$WORKNODE/libs
export INCX11=`$YAFRABIN/getx11inc`
export INCMOTIF=`$YAFRABIN/getmotifinc`
export LIBX11=`$YAFRABIN/getx11lib`
export LIBMOTIF=`$YAFRABIN/getmotiflib`

#
# setup control flags
#
export OMANUAL=
export OSHARED=1
export ODEBUG=1

#
# setup foundation LIBS
#
export PSSYSLIB=$YAFRALIBS/pssys
export PSMUMELIB=$YAFRALIBS/psmume
export PSIPCLIB=$YAFRALIBS/psipc
export PSSERCOMLIB=$YAFRALIBS/pssercom
export PSGUILIB=$YAFRALIBS/psgui
export PSMATRIXLIB=$YAFRALIBS/matrix
export PSMODULLIB=$YAFRALIBS/psmodul

export YAFRALIBSO=$WORKNODE/obj/libs
export PSSYSLIBO=$YAFRALIBSO
export PSIPCLIBO=$YAFRALIBSO
export PSMUMELIBO=$YAFRALIBSO
export PSSERCOMLIBO=$YAFRALIBSO
export PSMODULLIBO=$YAFRALIBSO
export PSGUILIBO=$YAFRALIBSO
export PSMATRIXLIBO=$YAFRALIBSO

#
# section: travelDB
#
#travelDB
export TDB=$TDBNODE/org.yafra.tdb.classic
export TDBCS=$TDB/csharp
export TDBS=$TDB
export TDBI=$MAPOS/include
export TDBSETUP=$TDBNODE/org.yafra.tdb.setup
export TDBDB=$TDBSETUP/db
export TDBO=$WORKNODE/obj/tdb

#set which database to use
export TDBMYSQL=1
#export TDBMSSQL=1
#export TDBORACLE=1
#export TDBORACLECLASSIC=1
#export TDBODBC=1

#
# add on's
#
export YAFRAADDONS=$TDBNODE
export CMDSRV=$TDBNODE/org.yafra.tdb.addons.cmdsrv
export PSWHAT=$TDBNODE/org.yafra.tdb.addons.pswhat
export PSEDIT=$TDBNODE/org.yafra.tdb.addons.psedit
export CMDSRVO=$WORKNODE/obj/addons
export PSWHATO=$WORKNODE/obj/addons
export PSEDITO=$WORKNODE/obj/addons
export TESTSUITEO=$WORKNODE/obj/testsuite

#
# depreciated
#
export MPDBMYSQL=$TDBMYSQL


#
# make sure the generic profile is loaded and you have enough permissions!!
#
if [ ! -d $SYSADM/defaults ]
then
	echo "Environment not loaded - install first !"
	exit
fi

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
make all

if [ "$PS_COMPTYPE" = "ps_unix" ]; then
	if [ "$PS_OS" != "ps_cygwin" ]; then
		if [ "$PS_OS" != "ps_osx" ]; then
			cd $WORKNODE/libs
			symlinks -c .
		fi
	fi
fi

echo "done - save in /work"
