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

#ifndef __LXC_EXECUTOR_HPP__
#define __LXC_EXECUTOR_HPP__

#include <map>
#include <stirng>

#include <mesos/executor.hpp>
#include <mesos/mesos.hpp>

#include <process/delay.hpp>
#include <process/id.hpp>
#include <process/owned.hpp>
#include <process/process.hpp>
#include <process/protobuf.hpp>
#include <process/reap.hpp>
#include <process/subprocess.hpp>

#include <stout/error.hpp>
#include <stout/flags.hpp>
#include <stout/json.hpp>
#include <stout/lambda.hpp>
#include <stout/os.hpp>
#include <stout/protobuf.hpp>
#include <stout/try.hpp>

#include <stout/os/killtree.hpp>

#include "checks/health_checker.hpp"

#include "common/protobuf_utils.hpp"
#include "common/status_utils.hpp"

#include "lxc/lxc.hpp"
#include "lxc/executor.hpp"

#include "logging/flags.hpp"
#include "logging/logging.hpp"

#include "messages/flags.hpp"
#include "messages/messages.hpp"

#include "slave/constants.hpp"

#include "lxc/lxc.hpp"
#include "lxc/executor.hpp"

namespace mesos{
namespace internal{
namespace lxc{



} // namespace lxc {
} // namespace internal {
} // namespace mesos {

#endif /* __LXC_EXECUTOR_HPP__ */
