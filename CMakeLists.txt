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

cmake_minimum_required(VERSION 3.9.6 FATAL_ERROR)

project(laptop_control VERSION 0.0.0 LANGUAGES CXX)

# setup C++17 required compiler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS OFF)

# programms
add_subdirectory(laptop_control)
add_subdirectory(software_updater)

#libs
add_subdirectory(libs)
