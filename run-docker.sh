#!/bin/sh
#
# docker run script
#
# variables must be set by CI service
# setup local environment first https://github.com/yafraorg/yafra/wiki/Development-Environment
export WORKNODE=/work/yafra-runtime
DESTDIR=/usr/local
BINDIR=$DESTDIR/bin
ETCDIR=$DESTDIR/etc
LIBSDIR=$DESTDIR/lib
GUIINSTALL=$ETCDIR/tdb
APPDIR=$DESTDIR/apps
X11APPDEF=/etc/X11/app-defaults

echo "download latest build and make it available as tomcat webapp"
# issues, tomcat users, ports and database type and config of cayenne
cd /
curl -O http://www.yafra.org/build/yafra-tdb-c-build.tar.gz
tar xvfz yafra-tdb-c-build.tar.gz

#create dirs
test -d $BINDIR || mkdir $BINDIR
test -d $ETCDIR || mkdir $ETCDIR
test -d $LIBSDIR || mkdir $LIBSDIR
test -d $APPDIR || mkdir $APPDIR
test -d $GUIINSTALL || mkdir $GUIINSTALL

#
# install all binaries and apps
#
echo "install binaries and apps"
cd $WORKNODE/yafra-dist
cp bin/* $BINDIR
cp -P lib/* $LIBSDIR
cp -r apps/* $APPDIR
cp etc/mpgui.pro $ETCDIR
cp etc/tdb/* $GUIINSTALL
cp etc/tdb/MPgui $X11APPDEF

echo "/usr/local/lib" > yafratdb.conf
ldconfig

echo "run tests"
$BINDIR/mptest -n $DB_PORT_3306_TCP_ADDR

echo "done - running now under tomcat"
