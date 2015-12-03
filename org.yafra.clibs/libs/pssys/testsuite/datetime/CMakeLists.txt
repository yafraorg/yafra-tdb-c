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
# build pssys datetime test
cmake_minimum_required(VERSION 3.3.2)

add_definitions(-D$ENV{PS_OS} -D$ENV{PS_OSTYPE})

include_directories($ENV{TDBNODE}/org.yafra.clibs/include)

add_custom_command(OUTPUT version.h COMMAND sh -c "$ENV{YAFRABIN}/makeversion psdatetime 1.0 >$ENV{TDBNODE}/org.yafra.clibs/libs/pssys/testsuite/datetime/version.h")

add_executable (psdatetime psdatetime.c version.h)
target_link_libraries (psdatetime $ENV{WORKNODE}/libs/libpssys.a)

install(TARGETS psdatetime
        RUNTIME DESTINATION $ENV{WORKNODE}/bin
        )
