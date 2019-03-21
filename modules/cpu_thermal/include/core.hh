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

#include <module/entity.hh>

#include <fmt/format.h>

namespace cpu_thermal {
    class Core : public core::module::IEntity {
    public:
        Core(int coreId) : IEntity("cpu_thermal", fmt::format("Core{}", coreId)) {}
        ~Core() override = default;

        double temp();

        double tempMax();

        double tempCritical();
    };
} // namespace cpu_thermal
