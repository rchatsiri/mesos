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

#ifndef __TESTS_LXC_HPP__
#define __TESTS_LXC_HPP__

#include <list>
#include <map>
#include <string>
#include <vector>

#include <gmock/gmock.h>

#include <mesos/resources.hpp>

#include <mesos/slave/container_logger.hpp>

#include <process/future.hpp>
#include <process/owned.hpp>
#include <process/shared.hpp>

#include <stout/json.hpp>
#include <stout/option.hpp>

#include "slave/containerizer/docker.hpp"

#include "slave/containerizer/lxc.hpp"

#include "slave/containerizer/mesos/isolators/gpu/components.hpp"

using ::testing::_;
using ::testing::Invoke;

using mesos::internal::slave::NvidiaComponents;

class MockLxc : public Lxc
{
public:
  void readJsonCreateImage();
};


#endif /* __TESTS_LXC_HPP__ */
