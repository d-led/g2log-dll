Summary
=======


This is a research on using the [wonderful asynchronous C++11 logger g2log](http://www.codeproject.com/Articles/288827/g2log-An-efficient-asynchronous-logger-using-Cplus) in a pre-C++11 project.

For that purpose, g2log is compiled as a dynamically loaded library (shared objec on linux).

The goal is to provide the same syntax for logging by means of a header mimicing the g2log api and a binary safe api that will be used to delegate the calls to the g2log in the dll.

Details
=======

Usage
-----

Check out the project into the g2log repository first.

Building is currently supported using Visual Studio 2012 Express using the provided solution, or on linux from the g2log-dll folder:
<pre>
./premake4 gmake
cd Build
make
</pre>

When built, the logger can be used by loading the dll using the import library, and on linux by linking with the shared object(?). See vs9test and vs11test/test.cpp

Status
------

Currently, the simplest form of logging is provided by the file g2log_dll.h. The tests have been performed using various compilers, and the results seem promising - the penalty of crossing the dll boundary seem insignificant _at least on my machine_.

Contributions are welcome!

Todos
-----
see [Issues](https://github.com/d-led/g2log-dll/issues)

Dependencies
------------

 * [g2log](http://www.codeproject.com/Articles/288827/g2log-An-efficient-asynchronous-logger-using-Cplus) the logger itself
 * [Premake](http://industriousone.com/premake) for generating makefiles
 * [Boost](http://www.boost.org/) for cross-compiler testing

Compilers
---------

the resulting dynamic library is known to work with

 * Visual Studio 2008 (Express), 2012 (Express)
 * gcc 4.7.2 (linux,using premake build)

License
=======

Author: Dmitry Ledentsov

MIT License (http://www.opensource.org/licenses/mit-license.php)

dependencies retain their respective licenses
