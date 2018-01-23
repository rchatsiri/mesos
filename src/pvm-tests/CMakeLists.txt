# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "-Wno-deprecated-declarations")

include("../../3rdparty/libprocess/cmake/macros/External.cmake")

include("../tests/cmake/MesosTestsConfigure.cmake")

# Include file from cmake directory : src/tests/cmake/MesosTestsConfigure.cmake
# include(MesosTestsConfigure)
# Include file from cmake directory : stout/cmake/StoutTestConfigure.cmake
include("../../3rdparty/stout/cmake/StoutTestsConfigure.cmake")

#SET(CPPFLAGS += -DSOURCE_DIR="${CURRENT_CMAKE_SOURCE_DIR}/../")

add_definitions(-DSOURCE_DIR="${CURRENT_CMAKE_SOURCE_DIR}/../")

# Sources for a test helper binary.
###################################
set(TEST_HELPER_SRC
  ${TEST_HELPER_SRC}
  active_user_test_helper.cpp
  flags.cpp
  http_server_test_helper.cpp
  resources_utils.cpp
  test_helper_main.cpp
  utils.cpp
  )

if (NOT WIN32)
  set(TEST_HELPER_SRC
    ${TEST_HELPER_SRC}
    kill_policy_test_helper.cpp
    containerizer/memory_test_helper.cpp
    )
endif ()

if (LINUX)
  set(TEST_HELPER_SRC
    ${TEST_HELPER_SRC}
    containerizer/capabilities_test_helper.cpp
    containerizer/setns_test_helper.cpp
    )
endif ()

# Test utilities.
#################
set(MESOS_TESTS_UTILS_SRC
  ${MESOS_TESTS_UTILS_SRC}
  active_user_test_helper.cpp
  cluster.cpp
  containerizer.cpp
  environment.cpp
  flags.cpp
  http_server_test_helper.cpp
  main.cpp
  mesos.cpp
  mock_docker.cpp
  mock_fetcher.cpp
  mock_registrar.cpp
  mock_slave.cpp
  module.cpp
  resources_utils.cpp
  utils.cpp
  containerizer/launcher.cpp
  )

if (NOT WIN32)
  set(MESOS_TESTS_UTILS_SRC
    ${MESOS_TESTS_UTILS_SRC}
    kill_policy_test_helper.cpp
    script.cpp
    containerizer/memory_test_helper.cpp
    )
endif ()

if (LINUX)
  set(MESOS_TESTS_UTILS_SRC
    ${MESOS_TESTS_UTILS_SRC}
    containerizer/capabilities_test_helper.cpp
    containerizer/setns_test_helper.cpp
    )
endif ()

set(MESOS_TESTS_SRC
  ${MESOS_TESTS_SRC}
  containerizer/containerizer_tests.cpp
  containerizer/docker_tests.cpp
  )

if (NOT WIN32)

  set(MESOS_TESTS_SRC
    ${MESOS_TESTS_SRC}
    containerizer/docker_containerizer_tests.cpp
    )
endif ()

if (LINUX)
  set(MESOS_TESTS_SRC
    ${MESOS_TESTS_SRC}
    ldcache_tests.cpp
    ldd_tests.cpp
    containerizer/docker_volume_isolator_tests.cpp
    )
endif ()

# INCLUDE DIRECTIVES (generates, e.g., -I/path/to/thing on Linux).
##################################################################
include_directories(SYSTEM ${MESOS_3RDPARTY_TESTS_INCLUDE_DIRS})
include_directories(${MESOS_TESTS_INCLUDE_DIRS})

# LINKING LIBRARIES (might generate, e.g., -L/path/to/thing on Linux).
######################################################################
link_directories(${MESOS_TESTS_LIB_DIRS})
link_directories(/home/rchatsiri/workspacecpp/mesos/build/src/.libs)

# THE TEST AND HELPER EXECUTABLEs (generates, e.g., stout-tests, etc., on Linux).
#################################$###############################################
add_executable(${MESOS_TESTS_TARGET} EXCLUDE_FROM_ALL ${MESOS_TESTS_SRC})
add_executable(${TEST_HELPER_TARGET} EXCLUDE_FROM_ALL ${TEST_HELPER_SRC})

# ADD LINKER FLAGS (generates, e.g., -lglog on Linux).
######################################################
target_link_libraries(${MESOS_TESTS_TARGET} ${MESOS_TESTS_LIBS})
target_link_libraries(${TEST_HELPER_TARGET} ${MESOS_TESTS_LIBS})
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../)



#external
include_directories(/home/rchatsiri/workspacecpp/mesos/include)
include_directories(/home/rchatsiri/workspacecpp/mesos/build/include)
include_directories(/home/rchatsiri/workspacecpp/mesos/build/3rdparty/protobuf-3.3.0/src)
include_directories(/home/rchatsiri/workspacecpp/mesos/3rdparty/stout/include)
include_directories(/home/rchatsiri/workspacecpp/mesos/build/3rdparty/boost-1.53.0)
include_directories(/home/rchatsiri/workspacecpp/mesos/src)
include_directories(/home/rchatsiri/workspacecpp/mesos/build/3rdparty/glog-0.3.3/src)
include_directories(/home/rchatsiri/workspacecpp/mesos/build/3rdparty/picojson-1.3.0/)
include_directories(/home/rchatsiri/workspacecpp/mesos/3rdparty/libprocess/include)
include_directories(/home/rchatsiri/workspacecpp/mesos/build/src)
include_directories(/home/rchatsiri/workspacecpp/mesos/build/3rdparty/googletest-release-1.8.0/googlemock/include)
include_directories(/home/rchatsiri/workspacecpp/mesos/build/include/mesos)
include_directories(/home/rchatsiri/workspacecpp/mesos/build/3rdparty/nvml-352.79)
include_directories(/home/rchatsiri/workspacecpp/mesos/build/3rdparty/zookeeper-3.4.8/src/c/include)
include_directories(/home/rchatsiri/workspacecpp/mesos/build/3rdparty/zookeeper-3.4.8/src/c/generated)

# ADD BINARY DEPENDENCIES (tells CMake what to compile/build first).
####################################################################
add_dependencies(
  ${MESOS_TESTS_TARGET}
  ${MESOS_TESTS_DEPENDENCIES}
  ${TEST_HELPER_TARGET}
  )

#if (NOT WIN32)
  # The tests require all the test modules.
  # NOTE: Modules are not supported on Windows.
  #  add_dependencies(
  #    ${MESOS_TESTS_TARGET}
  #     )

  # The tests require all the example frameworks and executors.
  # TODO(josephw): The scheduler driver is current not built on Windows.
  #  add_dependencies(
  #    ${MESOS_TESTS_TARGET}
  #     )
  #endif ()

  #add_dependencies(${TEST_HELPER_TARGET} ${MESOS_TESTS_DEPENDENCIES})

# ADD TEST TARGET (runs when you do, e.g., `make check`).
#########################################################

add_executable(docker_test ${MESOS_TESTS_SRC})

target_link_libraries(docker_test PRIVATE mesos pthread)


add_test(NAME docker_test COMMAND ${MESOS_TESTS_TARGET})
