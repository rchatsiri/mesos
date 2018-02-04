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

#include <map>
#include <string>

#include <gmock/gmock.h>

#include <mesos/mesos.hpp>
#include <mesos/resources.hpp>

#include <mesos/slave/paravirtualizer.hpp>

#include <process/future.hpp>
#include <process/gmock.hpp>
#include <process/http.hpp>

#include "slave/paravirtualizer/paravirtualizer.hpp"

namespace mesos {
namespace internal {
namespace tests{

class MockParaVirtualizer : public slave::ParaVirtualizer
{
public:
  MOCK_METHOD(
	launch,
	process::Future<bool>(
	    const ContainerID&,
	    const mesos::slave::ParaVirtualConfig&,
	    const std::map<std::string, std::string>&,
	    const Option<std::string>&))
};

} // namespace tests
} // namespace internal
} // namespace messos {
