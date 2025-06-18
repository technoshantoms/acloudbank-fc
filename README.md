FC
==

Build status: [![](https://github.com/bitshares/bitshares-fc/workflows/macOS/badge.svg?branch=master)](https://github.com/bitshares/bitshares-fc/actions?query=workflow%3A"macOS"+branch%3Amaster)
[![](https://github.com/bitshares/bitshares-fc/workflows/Ubuntu%20Debug/badge.svg?branch=master)](https://github.com/bitshares/bitshares-fc/actions?query=workflow%3A"Ubuntu+Debug"+branch%3Amaster)
[![](https://github.com/bitshares/bitshares-fc/workflows/Ubuntu%20Release/badge.svg?branch=master)](https://github.com/bitshares/bitshares-fc/actions?query=workflow%3A"Ubuntu+Release"+branch%3Amaster)

**NOTE:** This fork reverts upstream commit a421e280488385cab26a42153f7ce3c8d5b6281f to avoid changing the BitShares API.

FC stands for fast-compiling c++ library and provides a set of utility libraries useful
for the development of asynchronous libraries.  Some of the highlights include:

 - Cooperative Multi-Tasking Library with support for Futures, mutexes, signals.
 - Wrapper on Boost ASIO for handling async opperations cooperatively with easy to code synchronous style.
 - Reflection for C++ allowing automatic serialization in Json & Binary of C++ Structs 
 - Automatic generation of client / server stubs for reflected interfaces with support for JSON-RPC
 - Cryptographic Primitives for a variaty of hashes and encryption algorithms
 - Logging Infrastructure 
 - Wraps many Boost APIs, such as boost::filesystem, boost::thread, and boost::exception to acceleate compiles
 - Support for unofficial Boost.Process library.
