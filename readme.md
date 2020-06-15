# CMake UseSwig C# namespace

A minimal example project demonstrating, that CMake's [`UseSwig`](https://cmake.org/cmake/help/v3.17/module/UseSWIG.html) module doesn't copy C# support files into the `SWIG_SUPPORT_FILES_DIRECTORY` directory when using C++ namespaces.

Configure, build and install the project.

The C# wrapper files are then supposed to get copied from the `SWIG_SUPPORT_FILES_DIRECTORY` to the `CMAKE_INSTALL_PREFIX` directory. This partially works, but the C# wrapper code for the `mylib::my_class_in_namespace` is missing. When building the library this code lives in the `${PROJECT_BINARY_DIR}/CMakeFiles/mylib_csharp.dir/mylib.files/mylib/my_class_in_namespace.cs` file, but it seems like only the files inside `${PROJECT_BINARY_DIR}/CMakeFiles/mylib_csharp.dir/mylib.files` will get copied to `SWIG_SUPPORT_FILES_DIRECTORY` during the build step.

Tested on MacOS 10.15.4 with CMake 3.17.0, Swig 4.0.1 and using the Ninja generator.
