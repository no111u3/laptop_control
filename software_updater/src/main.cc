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

namespace {
}

auto main(int argc, char **argv, char **env) -> int {
    core::Env::create(argc, argv, env);
    core::Env::get().setProgrammInto("simple program to update software for Gentoo based linux");
    if (auto isHelpMode = core::Env::get().process(); !isHelpMode) {
        core::Conf::create("software_updater");
        core::Conf::get().process();
    }
}
