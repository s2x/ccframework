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


RoadMap
===========
Version 0.4
* Stabilize the API
* Add some Documentation

Version 0.3
* Forms support - a lot work to do here
* Add ACL to routing
* Add loadable plugins

Version 0.2
* Simple translation module,
* Support of array in request,
* Switch to ccArray with simple ini (un)serializer,
* Cleanup dependencies and fix automake files.
* Add examples of use
