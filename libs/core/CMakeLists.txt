#Copyright 2019 Boris Vinogradov <no111u3@gmail.com>

#Licensed under the Apache License, Version 2.0 (the "License");
#you may not use this file except in compliance with the License.
#You may obtain a copy of the License at

#    http://www.apache.org/licenses/LICENSE-2.0

#Unless required by applicable law or agreed to in writing, software
#distributed under the License is distributed on an "AS IS" BASIS,
#WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#See the License for the specific language governing permissions and
#limitations under the License.

# setup C++17 required compiler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CORE_SOURCES
        src/reader/json.cc
        src/config.cc
        src/core.cc
        src/environment.cc
        src/singleton.cc
        )

add_library(core ${CORE_SOURCES})

find_package(fmt)
find_package(yaml-cpp)
find_package(jsoncpp)

target_link_libraries(core
        fmt::fmt
        yaml-cpp
        stdc++fs
        jsoncpp
        )

target_include_directories(core PUBLIC include)
