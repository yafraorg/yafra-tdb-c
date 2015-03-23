#!/bin/sh
#
# used for CI services like Jenkins, Shippable, Travis-CI
#
# variables must be set by CI service
#export ANDROID_HOME=/work/adt/sdk
#export PATH=${PATH}:$ANDROID_HOME/tools:$ANDROID_HOME/platform-tools

echo "Make sure the environment is loaded!"

#
# set current version info
#
export YAFRAVER="1"
export YAFRAREL="0"
export YAFRAPATCH=$YAFRABUILD

#
# setup general paths
#
export BASENODE=/work/repos
export TDBNODE=/home/shippable/workspace/src/github.com/yafraorg/yafra-tdb-c
export WORKNODE=/work/yafra-runtime
export SYSADM=$BASENODE/yafra/org.yafra.sysadm
export YAFRADB=$BASENODE/yafra-database
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
export TDBDB=$YAFRADB/traveldb
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
# create dirs
#
mkdir -p $WORKNODE
mkdir -p $YAFRADOC
mkdir -p $YAFRAMAN
mkdir -p $YAFRAEXE
mkdir -p $YAFRALIBPATH
mkdir -p $YAFRALIBSO
test -d $TDBO || mkdir $TDBO
test -d $CMDSRVO || mkdir $CMDSRVO
test -d $PSWHATO || mkdir $PSWHATO
test -d $PSEDITO || mkdir $PSEDITO
test -d $TESTSUITEO || mkdir $TESTSUITEO
test -d $WORKNODE/apps || mkdir $WORKNODE/apps
test -d $WORKNODE/yafra-dist || mkdir $WORKNODE/yafra-dist

#
# setup some variables
#
TIMESTAMP="$(date +%y%m%d)"
VERREL="$YAFRAVER.$YAFRAREL-$YAFRABUILD"
echo "-> settings for release $VERREL with basenode $BASENODE on $TIMESTAMP"
echo "-> build number $YAFRABUILD"
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

cd $WORKNODE/libs
symlinks -c .

if [ "$OSHARED" = "1" ]; then
	sudo cp -P $WORKNODE/libs/* /usr/local/lib
	sudo ldconfig
fi

#copy python app to worknode
test -d $WORKNODE/apps/tdbpyadmin || mkdir $WORKNODE/apps/tdbpyadmin
cp $TDBNODE/org.yafra.tdb.admin-ui/* $WORKNODE/apps/tdbpyadmin/
#copy perl db admin to worknode
test -d $WORKNODE/apps/tdbdbadmin || mkdir $WORKNODE/apps/tdbdbadmin
cp $YAFRADB/traveldb/tdb*pl $WORKNODE/apps/tdbdbadmin
cp $YAFRADB/traveldb/tdbdb.pm $WORKNODE/apps/tdbdbadmin

# run some tests
echo "\nRun some tests\n\n"

echo "============================================================"
echo " TEST CASE: yafra ansi c common libraries test"
echo "============================================================"
$YAFRAEXE/pschar
$YAFRAEXE/pslog
$YAFRAEXE/psdatetime -d 01.01.1013 -t 12.30
$YAFRAEXE/psdatetime -d 01.02.2013 -t 12.30
$YAFRAEXE/psdatetime -d 01.03.2113 -t 12.30
$YAFRAEXE/psdatetime -d 01.04.3013 -t 12.30
$YAFRAEXE/psclientcons $DBSERVER

#get releases of binaries
echo "============================================================"
echo " TEST CASE TDB 1: tdb - get information on binaries"
echo "============================================================"
ldd $YAFRAEXE/mpdbi
ldd $YAFRAEXE/mpgui
ldd $YAFRAEXE/mpnet
$YAFRAEXE/pswhat -i $YAFRAEXE/pswhat
$YAFRAEXE/pswhat $YAFRAEXE/mpdbi
$YAFRAEXE/pswhat $YAFRAEXE/mpgui

echo "============================================================"
echo " TEST CASE TDB 2: tdb classic test db access and structure - reading db"
echo "============================================================"
$YAFRAEXE/mpstruct
$YAFRAEXE/mptest -n localhost


# run some tests
echo "\nComplete package\n\n"
INSTDIR=$WORKNODE/yafra-dist
test -d $INSTDIR || mkdir -p $INSTDIR
if [ ! -d $INSTDIR ]
then
	echo "error: main staging / publish directory not available: $INSTDIR - perform a full build first !"
	exit
fi
BINDIR=$INSTDIR/bin
ETCDIR=$INSTDIR/etc
LIBSDIR=$INSTDIR/lib
GUIINSTALL=$ETCDIR/tdb
APPDIR=$INSTDIR/apps
DBDIR=$ETCDIR/yafradb
TRAVELDBDIR=$ETCDIR/traveldb
TDBCONFIG=$TDBSETUP/config
echo "-> start publish with worknode $WORKNODE and target install directory $INSTDIR"
echo "TIMESTAMP: $TIMESTAMP"

#
# create staging environment
#
test -d $BINDIR || mkdir $BINDIR
test -d $ETCDIR || mkdir $ETCDIR
test -d $LIBSDIR || mkdir $LIBSDIR
test -d $GUIINSTALL || mkdir $GUIINSTALL
test -d $DBDIR || mkdir $DBDIR
test -d $TRAVELDBDIR || mkdir $TRAVELDBDIR
test -d $APPDIR || mkdir $APPDIR
test -d $APPDIR/yafrarcp || mkdir $APPDIR/yafrarcp
test -d $APPDIR/yafrapython || mkdir $APPDIR/yafrapython
test -d $APPDIR/tdbdbadmin || mkdir $APPDIR/tdbdbadmin
test -d $APPDIR/tdbpyadmin || mkdir $APPDIR/tdbpyadmin

# system administration files
cp $SYSADM/shellscripts/build-install.sh $INSTDIR/install.sh
cp $SYSADM/README-DISTRIBUTION.txt $INSTDIR
cp $TDBNODE/LICENSE $INSTDIR
cp $TDBNODE/NOTICE $INSTDIR
cp $SYSADM/defaults/profile.sh $ETCDIR/yafra-profile.sh
cp $SYSADM/defaults/scripts/yafra-prgkill.sh $BINDIR


# database generation files
# this works fine on unix with perl
echo "installing mysql database"
cd $TDBDB/mysql
$TDBDB/mysql/convert.sh
cp $TDBDB/mysql/* $TRAVELDBDIR/

#python admin
cp -r $WORKNODE/apps/tdbpyadmin/* $APPDIR/tdbpyadmin/
cp -r $WORKNODE/apps/tdbdbadmin/* $APPDIR/tdbdbadmin/

# TDB parts
cp $TDBCONFIG/linux/mpgui.pro $ETCDIR
cp $YAFRAEXE/* $BINDIR
cp -P $WORKNODE/libs/* $LIBSDIR
#copy python db query app
cp $WORKNODE/apps/tdbpyadmin/* $APPDIR/tdbpyadmin/.
cp $TDBSETUP/config/linux/update-services.pl $BINDIR/tdb-setup-services.pl
cp $TDBCONFIG/linux/MPgui $GUIINSTALL
cp $TDBCONFIG/linux/errors $GUIINSTALL
cp $TDBCONFIG/linux/labels* $GUIINSTALL
cp $TDBCONFIG/common/* $GUIINSTALL
cp $TDBCONFIG/license.txt $GUIINSTALL

#
# set unix executable bit
#
chmod 755 $BINDIR/*
chmod 755 $APPDIR/tdbdbadmin/*.pl
chmod 755 $APPDIR/tdbpyadmin/main.py
chmod 755 $INSTDIR/install.sh


echo "done - save in /work"
