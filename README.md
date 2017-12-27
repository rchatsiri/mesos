# Apache Mesos

Apache Mesos is a cluster manager that provides efficient resource isolation
and sharing across distributed applications, or frameworks. It can run Hadoop,
Jenkins, Spark, Aurora, and other frameworks on a dynamically shared pool of
nodes.

Visit us at [mesos.apache.org](http://mesos.apache.org).

# Mailing Lists

 * [User Mailing List](mailto:user-subscribe@mesos.apache.org) ([Archive](https://mail-archives.apache.org/mod_mbox/mesos-user/))
 * [Development Mailing List](mailto:dev-subscribe@mesos.apache.org) ([Archive](https://mail-archives.apache.org/mod_mbox/mesos-dev/))

# Documentation

Documentation is available in the docs/ directory. Additionally, a rendered HTML
version can be found on the Mesos website's [Documentation](http://mesos.apache.org/documentation/) page.

# Installation

Instructions are included on the [Getting Started](http://mesos.apache.org/gettingstarted/) page.

# License

Apache Mesos is licensed under the [Apache License, Version 2.0](http://www.apache.org/licenses/LICENSE-2.0).

For additional information, see the LICENSE and NOTICE files.

# Command test run application.

  * Debug master with command line ``` $sudo ./gdb-mesos-master.sh && run --ip=127.0.0.1 --work_dir=/var/lib/mesos ```
  * Slave service communicate to master ``` $sudo ./mesos-slave.sh --master=127.0.0.1:5050 --work_dir=/var/lib/mesos --containerizers=mesos,docker ```
  * Slave with docker flag ``` sudo ./mesos-slave.sh --master=127.0.0.1:5050 \
   --work_dir=/var/lib/mesos --containerizers=mesos,docker \
   --docker_registry=/tmp/mesos/images/docker \
   --executor_registration_timeout=5mins \
   --isolation=filesystem/linux,docker/runtime ```
  * Export path Mesos supports marathon : ``` export MESOS_NATIVE_JAVA_LIBRARY=/home/ec2-user/workspacecpp/mesos/build/src/.libs/libmesos.so ```
  * Marathon services ``` sbt -mem 2048 'run --master localhost:5050 --zk zk://127.0.0.1:2181/marathon' ```
  * Curl call marathon to create docker use docker.json at marathon-tools directory : ``` curl -X POST -H "Content-Type: application/json" http://127.0.0.1:8080/v2/apps -d@docker.json ```
