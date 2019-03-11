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
#include "config.hh"

#include "core.hh"

#include <fstream>
#include <config.hh>


namespace core {

    const inline auto configDirectory{".config"};

    void Config::process() {
        auto &env = Env::get();

        auto configName = configPath();

        if (!fs::exists(configName)) {
            auto directory = configName.parent_path();
            fmt::print("create new config in: {}\n", directory.string());
            if (!fs::exists(directory) && !fs::create_directories(directory)) {
                fmt::print("failed to create path: {}\n", directory.string());
            }
            else {
                store();
            }
        }
        else {
            conf_ = YAML::LoadFile(configName.string());
        }
    }

    void Config::store() {
        std::ofstream fout(configPath().string());
        fout << conf_;
    }

    fs::path Config::configPath() {
        auto &env = Env::get();

        return fs::path(env.getEnvVariable("HOME")) /
               configDirectory /
               name_ /
               env.getValue("config", std::string{});
    }
} // namespace core
