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

#include "stdpch.h"
#include <smjni/java_field.h>

using namespace smjni;

jfieldID java_field_core::get_field_id(JNIEnv * jenv, jclass clazz, const char * name, const std::string & signature)
{
    jfieldID ret = jenv->GetFieldID(clazz, name, signature.c_str());
    if (!ret)
    {
        java_exception::check(jenv);
        THROW_JAVA_PROBLEM("Unable to get field %s with signature %s", name, signature.c_str());
    }
    return ret;
}

jfieldID java_field_core::get_static_field_id(JNIEnv * jenv, jclass clazz, const char * name, const std::string & signature)
{
    jfieldID ret = jenv->GetStaticFieldID(clazz, name, signature.c_str());
    if (!ret)
    {
        java_exception::check(jenv);
        THROW_JAVA_PROBLEM("Unable to get static field %s with signature %s", name, signature.c_str());
    }
    return ret;
}
