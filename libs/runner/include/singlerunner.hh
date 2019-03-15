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

#include <boost/process/child.hpp>
#include <boost/process/pipe.hpp>
#include <boost/asio/io_service.hpp>

#include <future>
#include <string>
#include <system_error>
#include <tuple>
#include <utility>

namespace runner {
    namespace bp = boost::process;

    class SingleRunner {
    public:
        using ExType = std::future<std::string>;

        explicit SingleRunner(std::string program) : program_{std::move(program)} {}

        ~SingleRunner() {
            child_.wait();
        }

        bool asyncRun();

        bool run();

        std::string output() {
            return output_.get();
        }

        std::string error() {
            return error_.get();
        }

        void setInput(const std::string &input) {
            input_ = input;
        }
    private:
        std::string program_;
        bp::child child_;
        std::error_code ec_;
        std::string input_;
        ExType output_;
        ExType error_;
        boost::asio::io_service ios_;
    };
} // namespace runner
