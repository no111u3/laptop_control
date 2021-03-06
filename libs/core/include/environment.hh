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

#include <popl.hpp>

#include <string>
#include <map>
#include <utility>

namespace core {
    class Environment {
    public:
        Environment() = default;
        Environment(const Environment &) = default;
        Environment(Environment &&) = default;

        Environment(int argc, char **argv, char **env);

        template <typename T, typename ...Args>
        decltype(auto) addCustomValue(Args &&...args) {
            return parser_.add<popl::Value<T>>(std::forward<Args>(args)...);
        }

        template <typename T>
        auto getValue(const std::string &name, T) {
            if (auto variable = parser_.get_option<popl::Value<T>>(name); variable->is_set()) {
                return variable->value();
            }
            else {
                return variable->get_default();
            }
        }

        void setProgrammInto(const std::string &intro) {
            programIntro_ = intro;
        }

        const std::string configFile() const {
            return configFile_;
        }

        const std::string getEnvVariable(const std::string &name) const {
            auto it = env_.find(name);
            if (it == env_.end()) {
                return {};
            }
            return it->second;
        }

        const auto env() const {
            return env_;
        }

        bool process();
    private:
        struct ProgramArguments {
            int argc;
            char **argv;
            char **env;
        };

        void parseArguments(int argc, char **argv);
        void parseEnvironment(char **env);

        ProgramArguments programArguments_{};
        popl::OptionParser parser_{};
        std::map<std::string, std::string> env_;
        std::string programIntro_{};
        std::string configFile_{};
    };
} // namespace core