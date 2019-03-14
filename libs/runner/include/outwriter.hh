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

#include <boost/process/pipe.hpp>

#include <string>

namespace runner {
    namespace bp = boost::process;

    class OutWriter {
    public:
        OutWriter(const OutWriter &) = default;
        OutWriter(OutWriter &&) = default;
        ~OutWriter() = default;

        explicit OutWriter(bp::ipstream & input) : input_{input} {}

        template <typename ...Args>
        void getArgs(Args &...args) {
            (input_ >> ... >> args);
        }

        bool getLine(std::string &str) {

            auto &res = std::getline(input_, str);

            return input_ && res;
        }

    private:
        bp::ipstream &input_;
    };
} // namespace runner
