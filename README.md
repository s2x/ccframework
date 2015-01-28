ccFramework
===========

Extreme fast C++ framework for web projects. Designed for low-cost VPS as well as for high-performance, multi-processor servers.

Requirements
===========
* Git for source download,
* G++ compiler with support for C++11,
* autotools,
* libfcgi

Debian 7 installation instructions
===========
Here is list of packages to install before compile ccFramework
* install some debian packages
<code>apt-get install g++ autoconf intltool libtool libglib2.0-dev libfcgi-dev libboost-dev git</code>
* clone repo: <code>git clone https://github.com/s2x/ccframework.git</code>
* change dir: <code>cd ccframework</code>
* run autogen: <code>./autogen.sh</code>
* install: <code>make && make install</code>

Examples
===========
Code examples can be found in [docs directory](https://github.com/s2x/ccframework/tree/master/docs/examples). 

RoadMap
===========
Version 0.6
* Stabilize the API
* Add some Documentation

Version 0.5
* Forms support - a lot work to do here

Version 0.4
* Add loadable plugins

Version 0.3
* Rewrite routing as tree structure
* Add ACL to routing

Version 0.2
* [Simple translation module](https://github.com/s2x/ccframework/issues/3),
* [Rewrite session module - add session providers (memory, file, memcached)](https://github.com/s2x/ccframework/issues/4)
* [Add examples of use](https://github.com/s2x/ccframework/issues/5)
 
Version 0.1
* Support of array in request,
* Switch to ccArray with simple ini (un)serializer,
* Completly remove yaml-cpp from source - no more boosts needed,
* ~~Cleanup dependencies and fix automake files.~~

