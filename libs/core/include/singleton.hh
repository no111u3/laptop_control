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

#include <memory>
#include <utility>

namespace core {
    template <typename T>
    class Singleton {
    public:
        static T & get() {
            return *t_;
        }

        template <typename ...Args>
        static void create(Args ...args) {
            t_ = std::make_unique<T>(std::forward<Args>(args)...);
        }

    private:
        Singleton() = default;
        Singleton(const Singleton &) = default;
        Singleton(Singleton &&) noexcept = default;
        ~Singleton() = default;

        static inline std::unique_ptr<T> t_;
    };
} // namespace core