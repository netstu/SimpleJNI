/*
 Copyright 2014 Smartsheet.com, Inc.
 
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

#ifndef HEADER_JAVA_EXTERNALS_H_INCLUDED
#define HEADER_JAVA_EXTERNALS_H_INCLUDED

#include <exception>

namespace smjni
{
    [[noreturn]] void throw_java_problem(const char * file_line, const char * format, ...) __attribute__((format (printf, 2, 3)));
    void log_java_error(const std::exception & ex) noexcept;
    void log_java_error(const char * format, ...) noexcept __attribute__((format (printf, 1, 2)));
}

#define JAVA_STRINGIZE1(x) #x
#define JAVA_STRINGIZE(x) JAVA_STRINGIZE1(x)

#define JAVA_FILE_LINE __FILE__ ":" JAVA_STRINGIZE(__LINE__)

#define THROW_JAVA_PROBLEM(format, ...) throw_java_problem(JAVA_FILE_LINE, format, ##__VA_ARGS__)


#endif