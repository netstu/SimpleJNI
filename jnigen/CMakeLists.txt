#
# Copyright 2023 SmJNI Contributors
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

add_custom_target(build-jnigen  
    COMMAND ./gradlew -Pcode.version=SNAPSHOT publishToMavenLocal
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
)

add_custom_target(test-jnigen
    COMMAND ./gradlew -Pcode.version=SNAPSHOT test
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
)