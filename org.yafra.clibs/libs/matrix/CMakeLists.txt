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
        source/Actions.c
        source/Caption.c
        source/Cell.c
        source/Clip.c
        source/Converters.c
        source/Matrix.c
        source/Methods.c
        source/Public.c
        source/ScrollMgr.c
        source/Utils.c
        source/version.h
        )

find_package(X11)
find_package(Motif)

add_definitions(-D$ENV{PS_OS} -D$ENV{PS_OSTYPE})

include_directories(${X11_INCLUDE_DIR} ${MOTIF_INCLUDE_DIR} $ENV{TDBNODE}/org.yafra.clibs/include)

add_custom_command(OUTPUT source/version.h COMMAND sh -c "$ENV{YAFRABIN}/makeversion psmatrix 1.0 >$ENV{TDBNODE}/org.yafra.clibs/libs/matrix/source/version.h")

add_library (psmatrix ${SOURCE_FILES})

target_include_directories (psmatrix PUBLIC $ENV{TDBNODE}/org.yafra.clibs/include)

install(TARGETS psmatrix
        RUNTIME DESTINATION $ENV{WORKNODE}/libs
        LIBRARY DESTINATION $ENV{WORKNODE}/libs
        ARCHIVE DESTINATION $ENV{WORKNODE}/libs
        )
