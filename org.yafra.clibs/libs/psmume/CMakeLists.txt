#  Copyright 2015 yafra.org
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
#
# build library
cmake_minimum_required(VERSION 3.3.2)

set(SOURCE_FILES
        source/version.h
        source/aud_hp.c
        source/audio.c
        source/libpbm3.c
        source/libpgm2.c
        source/libppm4.c
        source/pbmfont.h
        source/pgm.h
        source/video.c
        source/aud_hp.h
        source/image.c
        source/libpbm4.c
        source/libppm.h
        source/libppm5.c
        source/pbmload.c
        source/ppm.h
        source/aud_hputils.c
        source/libpbm.h
        source/libpbm5.c
        source/libppm1.c
        source/orread.c
        source/pbmplus.h
        source/ppmcmap.h
        source/aud_linux.c
        source/libpbm1.c
        source/libpgm.h
        source/libppm2.c
        source/orrsize.c
        source/pbmprint.c
        source/ppmdraw.h
        source/aud_windows.c
        source/libpbm2.c
        source/libpgm1.c
        source/libppm3.c
        source/pbm.h
        source/pbmvers.h
        source/ppmload.c
        )

find_package(X11)
find_package(Motif)

add_definitions(-D$ENV{PS_OS} -D$ENV{PS_OSTYPE} -DSYSV)

include_directories(${X11_INCLUDE_DIR} ${MOTIF_INCLUDE_DIR} $ENV{TDBNODE}/org.yafra.clibs/include)

add_custom_command(OUTPUT source/version.h COMMAND sh -c "$ENV{YAFRABIN}/makeversion psmume 1.0 >$ENV{TDBNODE}/org.yafra.clibs/libs/psmume/source/version.h")

add_library (psmume ${SOURCE_FILES})
#add_library (psmume SHARED ${SOURCE_FILES})

target_include_directories (psmume PUBLIC $ENV{TDBNODE}/org.yafra.clibs/include)

install(TARGETS psmume
        RUNTIME DESTINATION $ENV{WORKNODE}/libs
        LIBRARY DESTINATION $ENV{WORKNODE}/libs
        ARCHIVE DESTINATION $ENV{WORKNODE}/libs
        )
