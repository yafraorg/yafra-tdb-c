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
        source/alloc.c
        source/cgi.c
        source/char.c
        source/cmd_clnt.c
        source/config.c
        source/date.c
        source/free.c
        source/help.c
        source/html.c
        source/inettools.c
        source/log.c
        source/password.c
        source/signal.c
        source/wintools.c
        source/version.h
)

add_definitions(-D$ENV{PS_OS} -D$ENV{PS_OSTYPE})

include_directories($ENV{TDBNODE}/org.yafra.clibs/include)

add_custom_command(OUTPUT source/version.h COMMAND sh -c "$ENV{YAFRABIN}/makeversion pssys 1.0 >$ENV{TDBNODE}/org.yafra.clibs/libs/pssys/source/version.h")

add_library (pssys ${SOURCE_FILES})
#add_library (pssys SHARED ${SOURCE_FILES})

target_include_directories (pssys PUBLIC $ENV{TDBNODE}/org.yafra.clibs/include)

install(TARGETS pssys
        RUNTIME DESTINATION $ENV{WORKNODE}/libs
        LIBRARY DESTINATION $ENV{WORKNODE}/libs
        ARCHIVE DESTINATION $ENV{WORKNODE}/libs
        )
