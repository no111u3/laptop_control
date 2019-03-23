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

#include <plugin/entity.hh>

namespace cpu_thermal {
    class ICpuPackage : public core::plugin::IEntity, public core::plugin::EntityMarker<ICpuPackage, Plugin>  {
    public:
        ICpuPackage() : IEntity() {}
        virtual ~ICpuPackage() override = default;

        virtual double temp() = 0;

        virtual double tempMax() = 0;

        virtual double tempCritical() = 0;
    };
} // namespace cpu_thermal