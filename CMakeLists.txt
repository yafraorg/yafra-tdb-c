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
project(travelDB)

add_subdirectory (org.yafra.clibs/libs/pssys)
add_subdirectory (org.yafra.clibs/libs/pssys/testsuite/chars)
add_subdirectory (org.yafra.clibs/libs/pssys/testsuite/datetime)
add_subdirectory (org.yafra.clibs/libs/psipc)
add_subdirectory (org.yafra.clibs/libs/pssercom)
add_subdirectory (org.yafra.clibs/libs/psmodul)
add_subdirectory (org.yafra.clibs/libs/psmume)
add_subdirectory (org.yafra.clibs/libs/psgui)
add_subdirectory (org.yafra.clibs/libs/matrix)
add_subdirectory (org.yafra.tdb.addons.pswhat)
#add_subdirectory (org.yafra.tdb.addons.psedit)
#add_subdirectory (org.yafra.tdb.addons.cmdsrv)
add_subdirectory (org.yafra.tdb.classic/lib)

