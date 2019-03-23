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

#include "plugin.hh"

#include <map>
#include <string>

namespace core {
    namespace plugin {
        template <typename Plugin>
        struct HolderMarker {
            using plugin = typename Plugin::plugin;
        };

        class IHolder {
        public:
            IHolder() = default;
            virtual ~IHolder() = default;

            virtual std::shared_ptr<IPlugin> plugin() = 0;
        };

        template <typename _Plugin>
        class THolder : public IHolder, public HolderMarker<_Plugin> {
        public:
            THolder() : IHolder() {}

            std::shared_ptr<IPlugin> plugin() override {
                return std::make_shared<_Plugin>();
            }
        };

        class Holder {
        public:
            Holder() = default;

            template <typename ...Holders>
            void construct() {
                (plugins_.emplace(create<Holders>()), ...);
            }


            template <typename Entity>
            std::shared_ptr<Entity> entity() {
                return plugin<Entity::plugin>()->template entity<Entity>();
            }

            template <typename Plugin>
            std::shared_ptr<Plugin> plugin() {
                return std::dynamic_pointer_cast<Plugin>(plugins_.at(typeid(typename Plugin::plugin)));
            }

            void process() {
                for (const auto &plugin : plugins_) {
                    plugin.second->init();
                }
            }

        private:
            template <typename Holder>
            std::pair<std::type_index, std::shared_ptr<IPlugin>> create() {
                auto holder = Holder{};

                return {typeid(typename Holder::plugin), holder.plugin()};
            }

            std::map<std::type_index, std::shared_ptr<IPlugin>> plugins_;
        };
    } // namespace plugin
} // namespace core