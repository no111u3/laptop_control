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

#include <plugin/holder.hh>
#include <plugin/plugin.hh>

#include <fmt/format.h>

namespace cpu_thermal {
    class Plugin : public core::plugin::IPlugin, public core::plugin::PluginMarker<Plugin> {
    public:
        ~Plugin() override = default;

        std::set<std::type_index> depends() override;

        void init() override;

        bool thermalIsAvailable();

    private:
        std::shared_ptr<core::plugin::IEntity> getEntity(const std::type_info &type) override;
    };

    using Holder = core::plugin::THolder<Plugin>;
} // namespace cpu_thermal