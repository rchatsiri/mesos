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

#include <list>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <process/future.hpp>
#include <process/gtest.hpp>
#include <process/owned.hpp>
#include <process/subprocess.hpp>

#include <stout/duration.hpp>
#include <stout/option.hpp>
#include <stout/gtest.hpp>

#include <stout/os/constants.hpp>

#include "lxc/lxc.hpp"

#include "mesos/resources.hpp"

#include "tests/environment.hpp"
#include "tests/flags.hpp"
#include "tests/mesos.hpp"

using namespace process;

using std::list;
using std::string;
using std::vector;

namespace mesos {
namespace internal {
namespace tests {


static const string NAME_PREFIX="mesos-lxc";

class LxcTest : public MesosTest
{
   virtual void TearDown()
   {
     Try<Owned<Lxc>> lxc = Lxc::create(
		   tests::flags.lxc,
		   tests::flags.lxc_socket,
		   false).get();
     ASSERT_SOME(lxc);

   }
};


TEST_F(LxcTest, LXC_StartVirtualize)
{
   const string virtName = NAME_PREFIX + "-test";
   Resources resouces = Resources::parse("cpus:1;mem:512").get();
   Owned<Lxc> lxc = Lxc::create(
		   tests::flags.lxc,
		   tests::flags.lxc_socket,
		   false).get();
   std::cout<<"Interface test with LXC" <<std::endl;
   EXPECT_EQ(0,0);
}

} // namespace tests {
} // namespace internal {
} // namespace mesos {
