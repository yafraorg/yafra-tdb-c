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
        source/cmd.h
        source/io.c
        source/server.c
        source/utils.c
        )

add_definitions(-D$ENV{PS_OS} -D$ENV{PS_OSTYPE})

include_directories($ENV{TDBNODE}/org.yafra.clibs/include)

add_custom_command(OUTPUT source/version.h COMMAND sh -c "$ENV{YAFRABIN}/makeversion pscmdsrv 1.0 >$ENV{TDBNODE}/org.yafra.tdb.addons.cmdsrv/source/version.h")

add_executable (pscmdsrv ${SOURCE_FILES})
target_link_libraries (pscmdsrv $ENV{WORKNODE}/libs/libpsipc.a $ENV{WORKNODE}/libs/libpssys.a)

install(TARGETS pscmdsrv
        RUNTIME DESTINATION $ENV{WORKNODE}/bin
        )
