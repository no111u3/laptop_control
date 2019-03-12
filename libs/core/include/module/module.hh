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

#include "entity.hh"

#include <map>
#include <memory>
#include <string>
#include <utility>

namespace core {
    namespace module {
        class IModule {
        public:
            explicit IModule(std::string moduleName) : moduleName_{std::move(moduleName)} {}

            virtual ~IModule() = default;

            virtual void init() = 0;

            std::shared_ptr<IEntity> entity(const std::string &name) {
                return entities_.at(name);
            }

            std::shared_ptr<IEntity> addEntity(const std::string &name, const std::shared_ptr<IEntity> &entity) {
                return entities_[name] = entity;
            }

            const std::string name() const {
                return moduleName_;
            }


        private:
            const std::string moduleName_;
            std::map<std::string, std::shared_ptr<IEntity>> entities_;
        };
    } // namespace module
} // namespace core
