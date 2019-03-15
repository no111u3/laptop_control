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

#include "singlerunner.hh"

#include <boost/process.hpp>


namespace runner {
    bool SingleRunner::asyncRun() {

        child_ = std::move(bp::child(program_,
                bp::std_out > output_,
                bp::std_err > error_,
                bp::std_in < input_, ec_, ios_));

        return child_;
    }

    bool SingleRunner::run() {
        asyncRun();

        ios_.run();

        child_.wait();

        return ec_.value() == 0;
    }
} // namespace runner
