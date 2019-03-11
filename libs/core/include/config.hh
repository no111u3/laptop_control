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

#include <yaml-cpp/yaml.h>

#include <filesystem>
#include <string>
#include <utility>

namespace core {
    namespace fs = std::filesystem;

    class Config {
    public:
        Config() = default;
        Config(const Config &) = default;
        Config(Config &&) = default;
        ~Config() {
            store();
        }

        explicit Config(std::string name) : name_{std::move(name)} {}

        void process();

        auto & conf() const {
            return conf_;
        }
    private:
        void store();

        fs::path configPath();

        const std::string name_;
        YAML::Node conf_;
    };
} // namespace core
