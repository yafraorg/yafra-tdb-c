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
        alloc.c
        datstr.c
        debug.c
        free.c
        getbuf.c
        log.c
        signal.c
        version.h
)

add_definitions(-D$ENV{PS_OS} -D$ENV{PS_OSTYPE})

include_directories($ENV{TDBNODE}/org.yafra.clibs/include)

add_custom_command(OUTPUT version.h COMMAND sh -c "$ENV{YAFRABIN}/makeversion mplib 1.0 >$ENV{TDBNODE}/org.yafra.tdb.classic/lib/version.h")

add_library (mplib ${SOURCE_FILES})
#add_library (psipc SHARED ${SOURCE_FILES})

target_include_directories (mplib PUBLIC $ENV{TDBNODE}/org.yafra.tdb.classic/include $ENV{TDBNODE}/org.yafra.clibs/include)

install(TARGETS mplib
        RUNTIME DESTINATION $ENV{WORKNODE}/libs
        LIBRARY DESTINATION $ENV{WORKNODE}/libs
        ARCHIVE DESTINATION $ENV{WORKNODE}/libs
        )
