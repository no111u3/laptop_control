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

#include "module.hh"

#include <map>
#include <string>

namespace core {
    namespace module {
        class IHolder {
        public:
            IHolder() = default;
            virtual ~IHolder() = default;

            virtual std::shared_ptr<IModule> module() = 0;
        };

        template <typename _Module>
        class THolder : public IHolder {
        public:
            THolder() : IHolder() {}

            std::shared_ptr<IModule> module() override {
                return std::make_shared<_Module>();
            }
        };

        class Holder {
        public:
            Holder() = default;

            template <typename ...Holders>
            void construct() {
                (modules_.emplace(create<Holders>()), ...);
            }

            std::shared_ptr<IModule> module(const std::string &name) {
                return modules_.at(name);
            }

            void process() {
                for (const auto &module : modules_) {
                    module.second->init();
                }
            }

        private:
            template <typename Holder>
            std::pair<std::string, std::shared_ptr<IModule>> create() {
                auto holder = Holder{};

                return {holder.module()->name(), holder.module()};
            }

            std::map<std::string, std::shared_ptr<IModule>> modules_;
        };
    } // namespace plugin
} // namespace core