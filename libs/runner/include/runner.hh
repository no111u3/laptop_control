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

#include "inwriter.hh"
#include "outwriter.hh"

#include <boost/process/child.hpp>
#include <boost/process/pipe.hpp>

#include <string>
#include <system_error>
#include <utility>

namespace runner {
    namespace bp = boost::process;

    class Runner {
    public:
        ~Runner() {
            child_.wait();
        }

        explicit Runner(std::string program) : program_{std::move(program)} {}

        bool asyncRun();

        bool run();

        OutWriter pout() {
            return OutWriter{pout_};
        }

        OutWriter perr() {
            return OutWriter{perr_};
        }

        InWriter pin() {
            return InWriter{pin_};
        }
    private:
        std::string program_;
        bp::child child_;
        bp::ipstream pout_;
        bp::ipstream perr_;
        bp::opstream pin_;
        std::error_code ec_;

    };
} // namespace runner
