/**
Copyright 2019 Boris Vinogradov <no111u3@gmail.com>

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#pragma once

#include "core.hh"
#include "cpu_package.hh"

#include <module/entity.hh>

#include <map>

namespace cpu_thermal {
    class Cpu : public core::module::IEntity {
    public:
        Cpu() : IEntity("cpu_thermal", "Cpu") {}
        ~Cpu() override = default;

        CpuPackage package();

        int coreNumber();

        Core core(int coreId);

        std::map<int, Core> cores();
    };
} // namespace cpu_thermal
