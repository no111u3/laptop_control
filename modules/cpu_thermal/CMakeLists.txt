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

set(CPU_THERM_SOURCES
        src/cpu_thermal.cc
        )

add_library(cpu_thermal ${CPU_THERM_SOURCES})

target_link_libraries(cpu_thermal
        core
        runner
        )

target_include_directories(cpu_thermal PUBLIC include)