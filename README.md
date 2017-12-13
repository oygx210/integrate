integrate
===

\cond [![MIT license](http://img.shields.io/badge/license-MIT-brightgreen.svg)](http://opensource.org/licenses/MIT)\endcond

`integrate` is a header-only C++ library of numerical integrators to solve Ordinary Differential Equations (ODE). A CMake module is available to make it easy to include `integrate` in other projects: [Findintegrate.cmake](https://github.com/openastro/cmake-modules/blob/master/Modules/Findintegrate.cmake).

Features
------

  - Header-only
  - Generic numerical integrators
  - Full suite of tests

Requirements
------

To install this project, please ensure that you have installed the following (install guides are provided on the respective websites):

  - [Git](http://git-scm.com)
  - A C++ compiler, e.g., [GCC](https://gcc.gnu.org/), [clang](http://clang.llvm.org/), [MinGW](http://www.mingw.org/)
  - [CMake](http://www.cmake.org)
  - [Doxygen](http://www.doxygen.org "Doxygen homepage") (optional)
  - [Gcov](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html) (optional)
  - [LCOV](http://ltp.sourceforge.net/coverage/lcov.php) (optional)

`integrate` does not depend on any libraries. The following libraries are optional (see `Build options`):

  - [CATCH](https://www.github.com/philsquared/Catch) (unit testing library necessary for `BUILD_TESTS` option)
  - [Eigen](http://eigen.tuxfamily.org/) (linear algebra library necessary for `BUILD_TESTS_WITH_EIGEN` option)

These dependencies will be downloaded and configured automagically if not already present locally (requires an internet connection).

Installation
------

Run the following commands to download, build, and install this project.

    git clone https://www.github.com/openastro/integrate
    cd integrate
    git submodule init && git submodule update
    mkdir build && cd build
    cmake .. && cmake --build .

To install the header files, run the following from within the `build` directory:

    make install

Note that dependencies are installed by fetching them online, in case they cannot be detected on your local system. If the build process fails, check the error log given. Typically, building fails due to timeout. Simply run the `cmake --build .` command once more.

Build options
-------------

You can pass the following, general command-line options when running CMake:

  - `-DCMAKE_INSTALL_PREFIX[=$install_dir]`: set path prefix for install script (`make install`); if not set, defaults to usual locations
  - `-DBUILD_DOXYGEN_DOCS[=ON|OFF (default)]`: build the [Doxygen](http://www.doxygen.org "Doxygen homepage") documentation ([LaTeX](http://www.latex-project.org/) must be installed with `amsmath` package)
  - `-DBUILD_TESTS[=ON|OFF (default)]`: build tests (execute tests from build-directory using `ctest -V`)
  - `-DBUILD_DEPENDENCIES[=ON|OFF (default)]`: force local build of dependencies, instead of first searching system-wide using `find_package()`

The following commands are conditional and can only be set if `BUILD_TESTS = ON`:

 - `-DBUILD_TESTS_WITH_EIGEN[=ON|OFF (default)]`: build tests using [Eigen](http://eigen.tuxfamily.org/) (execute tests from build-directory using `ctest -V`)
 - `-DBUILD_COVERAGE_ANALYSIS[=ON|OFF (default)]`: build code coverage using [Gcov](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html) and [LCOV](http://ltp.sourceforge.net/coverage/lcov.php) (both must be installed; requires [GCC](https://gcc.gnu.org/) compiler; execute coverage analysis from build-directory using `make coverage`)

Pass these options either directly to the `cmake ..` command, e.g., to build the tests:

    cmake -DBUILD_TESTS=on ..

N.B.: Toggling options to build tests using `ccmake` does not work correctly, as the necessarily libraries are not download automagically!

Project structure
-------------

This project has been set up with a specific file/folder structure in mind. The following describes some important features of this setup:

  - `cmake/Modules` : Contains `CMake` modules, including `Findintegrate.cmake` module
  - `docs`: Contains project-specific docs in [Markdown](https://help.github.com/articles/github-flavored-markdown/ "GitHub Flavored Markdown") that are also parsed by [Doxygen](http://www.doxygen.org "Doxygen homepage"). This sub-directory includes `global_todo.md`, which contains a global list of TODO items for project that appear on TODO list generated in [Doxygen](http://www.doxygen.org "Doxygen homepage") documentation
  - `doxydocs`: HTML output generated by building [Doxygen](http://www.doxygen.org "Doxygen homepage") documentation
  - `include/integrate`: Project header files (*.hpp)
  - `scripts`: Shell scripts used in [Travis CI](https://travis-ci.org/ "Travis CI homepage") build
  - `test`: Project test source files (*.cpp), including `testCppProject.cpp`, which contains include for [Catch](https://www.github.com/philsquared/Catch "Catch Github repository")
  - `.travis.yml`: Configuration file for [Travis CI](https://travis-ci.org/ "Travis CI homepage") build, including static analysis using [Coverity Scan](https://scan.coverity.com/ "Coverity Scan homepage") and code coverage using [Coveralls](https://coveralls.io "Coveralls.io homepage")
  - `CMakeLists.txt`: main `CMakelists.txt` file for project (should not need to be modified for basic build)
  - `Dependencies.cmake`: list of dependencies and automated build, triggered if dependency cannot be found locally
  - `Doxyfile.in`: [Doxygen](http://www.doxygen.org "Doxygen homepage") configuration file, adapted for generic use within project build (should not need to be modified)
  - `LICENSE.md`: license file for project
  - `ProjectFiles.cmake`: list of project source files to build
  - `README.md`: project readme file, parsed as main page for [Doxygen](http://www.doxygen.org "Doxygen homepage") documentation

Contributing
------------

Once you've made your great commits:

  1. [Fork](https://github.com/openastro/integrate/fork) integrate
  2. Create a topic branch - `git checkout -b my_branch`
  3. Push to your branch - `git push origin my_branch`
  4. Create a [Pull Request](http://help.github.com/pull-requests/) from your branch
  5. That's it!

Disclaimer
------

The copyright holders are not liable for any damage(s) incurred due to improper use of `integrate`.
