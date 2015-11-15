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
        source/client.c
        source/daemon.c
        source/fork.c
        source/pipeio.c
        source/server.c
        source/service.c
        source/socket.c
        source/socket.h
        source/utils.c
        source/version.h
)

add_definitions(-D$ENV{PS_OS} -D$ENV{PS_OSTYPE})

include_directories($ENV{TDBNODE}/org.yafra.clibs/include)

add_custom_command(OUTPUT source/version.h COMMAND sh -c "$ENV{YAFRABIN}/makeversion psipc 1.0 >$ENV{TDBNODE}/org.yafra.clibs/libs/psipc/source/version.h")

add_library (psipc ${SOURCE_FILES})
#add_library (psipc SHARED ${SOURCE_FILES})

target_include_directories (psipc PUBLIC $ENV{TDBNODE}/org.yafra.clibs/include)

install(TARGETS psipc
        RUNTIME DESTINATION $ENV{WORKNODE}/libs
        LIBRARY DESTINATION $ENV{WORKNODE}/libs
        ARCHIVE DESTINATION $ENV{WORKNODE}/libs
        )
