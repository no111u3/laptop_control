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

#include "main.hh"

#include <core.hh>
#include <cpu_thermal.hh>

namespace {
}

auto main(int argc, char **argv, char **env) -> int {
    core::Env::create(argc, argv, env);
    core::Env::get().setProgrammInto("simple program to control laptop power management and other");
    if (auto isHelpMode = core::Env::get().process(); !isHelpMode) {
        core::Conf::create("laptop_control");
        core::Conf::get().process();
        core::Plug::create();
        core::Plug::get().construct<cpu_thermal::Holder>();
        core::Plug::get().process();

        auto therm = core::Plug::get().plugin<cpu_thermal::Plugin>();

        fmt::print("thermal is available: {}\n", therm->thermalIsAvailable());
    }
}
