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
#include <set>
#include <string>
#include <typeindex>
#include <utility>

namespace core {
    namespace plugin {
        template <typename Plugin>
        class PluginMarker {
        public:
            using plugin = Plugin;
        };

        class IPlugin {
        public:
            virtual ~IPlugin() = default;

            virtual void init() = 0;

            virtual std::set<std::type_index> depends() = 0;

            template <typename Entity>
            std::shared_ptr<Entity> entity(const std::type_info &type) {
                return std::dynamic_pointer_cast<Entity>(getEntity(type));
            }

        protected:
            virtual std::shared_ptr<IEntity> getEntity(const std::type_info &type) = 0;
        };
    } // namespace plugin
} // namespace core
