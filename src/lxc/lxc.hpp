// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef __LXC_HPP__
#define __LXC_HPP__

#include <process/future.hpp>
#include <process/owned.hpp>
#include <process/subprocess.hpp>

#include <stout/duration.hpp>
#include <stout/json.hpp>
#include <stout/none.hpp>
#include <stout/nothing.hpp>
#include <stout/option.hpp>
#include <stout/path.hpp>
#include <stout/version.hpp>

#include <stout/os/rm.hpp>

#include "mesos/resources.hpp"

#include "messages/flags.hpp"

class Lxc
{
public:
  // Create lxc service.
  Try<process::Owned<Lxc>> create(
     const Option<JSON::Object>& config = None());

  virtual ~Lxc() {}
private:
  static process::Future<Version> _version(
     const std::string& cmd,
     const process::Subprocess& s);
};

#endif /* __LXC_HPP__ */
