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
#include "environment.hh"

#include <fmt/format.h>

namespace core {
    Environment::Environment(int argc, char **argv, char **env) :
        programArguments_{argc, argv, env},
        parser_("Program options") {
    }

    bool Environment::process() {
        auto &&[argc, argv, env] = programArguments_;
        parseArguments(argc, argv);
        parseEnvironment(env);

        if (parser_.get_option<popl::Switch>("help")->count()) {
            fmt::print("{} - {}\n\n{}", argv[0], programIntro_, parser_.help());

            return false;
        }
        else {
            configFile_ = getValue("config", std::string{});

            return true;
        }
    }

    void Environment::parseArguments(int argc, char **argv) {
        parser_.add<popl::Switch>("h", "help", "this programm help");
        parser_.add<popl::Value<std::string>>("c", "config", "program config file", "config.yaml");

        parser_.parse(argc, argv);
    }

    void Environment::parseEnvironment(char **env) {
        (void)env;
    }
} // namespace core
