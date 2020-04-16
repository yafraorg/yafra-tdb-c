#
#  Copyright 2015 yafra.org
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.

#
# yafra.org C docker image
#

# source is yafra ubuntu
FROM yafraorg/docker-yafrabase

MAINTAINER Martin Weber <info@yafra.org>

# Install C packages
RUN apt-get update && \
  apt-get install -yq libmotif4 libmotif-dev libxpm-dev libxml2-dev libmysqlclient-dev libgtk-3-dev  && \
  apt-get install -yq libpq5 mysql-client-5.5 libmysql-cil-dev symlinks clang glade supervisor libdbi-perl cpanminus && \
  rm -rf /var/lib/apt/lists/*

# Install PHP composer
RUN cd /work/repos && \
  git clone https://github.com/yafraorg/yafra-tdb-c.git && \
  git clone https://github.com/yafraorg/yafra.git

# Install run-docker script
COPY supervisord.conf /etc/supervisor/conf.d/supervisord.conf
COPY run-docker.sh /work/run-docker.sh
RUN cd /work && \
  chmod 755 run-docker.sh

# Expose daemon ports
EXPOSE 5000
EXPOSE 5001
EXPOSE 5002

# Run container
CMD ["/work/run-docker.sh"]
