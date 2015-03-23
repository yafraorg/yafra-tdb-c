# yafra-tdb-c
Yafra travel db C Server (travel database example with C daemon and OSF Motif client, Python Gtk3 client)

## Development Environment
 * Based on Eclipse: https://github.com/yafraorg/yafra/wiki/Devc
 * Python Gtk3 client: Jetbrains PyCharm

## Automatic build and run environment
 * Shippable: [![Build Status](https://api.shippable.com/projects/54d36cf15ab6cc13528aecf2/badge?branchName=master)](https://app.shippable.com/projects/54d36cf15ab6cc13528aecf2/builds/latest)
 * Docker: https://github.com/yafraorg/docker-yafrac
 * To run it on Docker, the mpgui process needs to be started with mpgui -D -a -s DOCKER_IP. The /usr/local/etc/mpgui.pro 1 must be the MYSQL_IP and the 2 user must be added on the DOCKER (adduser tdbadmin with pwd yafra).

## Further information
read more about yafra on:
 * http://www.yafra.org
 * https://github.com/yafraorg/yafra/wiki
 * raise a ticket related to yafra.org framework: https://github.com/yafraorg/yafra/issues?state=open
 * raise a ticket related to this C/Python code: https://github.com/yafraorg/yafra-tdb-c/issues?state=open
