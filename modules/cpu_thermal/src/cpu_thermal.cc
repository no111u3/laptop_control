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
#include "cpu_thermal.hh"

namespace cpu_thermal {
    void Module::init() {

    }

    std::shared_ptr<core::module::IEntity> Module::getEntity(const std::string &name) {
        return std::shared_ptr<core::module::IEntity>();
    }
} // namespace cpu_thermal