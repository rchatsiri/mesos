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

"""
This file defines the default settings of the mesos-cli. It also takes care
of updating the default configuration from reading environment variables or
parsing a configuration file.
"""

import os


# There is no version module included in this package. However,
# when creating an executable using pyinstaller, a version.py
# file will be autogenerated and inserted into the PYTHONPATH.
# When this happens we import it to set the VERSION.
try:
    # pylint: disable=F0401,W0611
    from version import VERSION
except Exception:
    VERSION = "Development"

# The top-level directory of this project.
PROJECT_DIR = os.path.join(os.path.dirname(__file__), os.pardir)

# The builtin plugins.
PLUGINS = [
    os.path.join(PROJECT_DIR, "lib", "mesos", "plugins", "agent"),
    os.path.join(PROJECT_DIR, "lib", "mesos", "plugins", "config"),
    os.path.join(PROJECT_DIR, "lib", "mesos", "plugins", "task")
]

DEFAULT_MESOS_CLI_CONFIG = os.path.join(
    os.path.expanduser("~"),
    ".mesos",
    "config.toml")
