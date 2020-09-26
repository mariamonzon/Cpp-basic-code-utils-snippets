# C++ Compilation process

## Build

The first thing that happens is we say that the code is built.
And that in itself is a multistep process.
First a tool called the preprocessor goes through your code and
manipulates it a little bit. 
The output of the preprocessor goes to something called the compiler.

## Compile
Real programs have lots of files in them,
like not just five or ten, but thousands.
And each one is compiled individually and the output of that is called an object file.

## Link
After everybody's been compiled, then they're linked together
into your actual executable, the thing that you run under the
debugger or without the debugger.

Now, when you're writing these individual files, the compiler
makes sure that you've used the syntax of the library correctly.
For example, the single line of useful code in there had quite
a lot of syntax. 
It had bits and pieces of punctuation that you
will understand by the time we're done. And the compiler makes
sure that all that punctuation is being used properly.
It doesn't necessarily check every single thing about your program.
You are allowed to basically make a promise to the compiler.

The linker makes sure that those promises are being kept.
And it puts all the somewhere elses together and connects everybody
to the places they were planning to use and, okay, this is good,
it all works.

Those three steps of building are actually critical to understanding
what happens when you get error messages. 

## Cmake Files
CMake reads the project configuration (path to header files and libraries) from a file named CMakeLists.txt.


    ############# Contents of a sample CMakeLists.txt file #############
    # Define the minimum CMake version which can execute this file
    cmake_minimum_required(VERSION 2.8.12)

    # Give a name to your project
    PROJECT(myProject)

    ## If the library is installed on your machine, we tell CMake to find it.
    # CMake looks for files OpenCVConfig.cmake and OpenCVConfig-version.cmake to 
    # configure settings for OpenCV.

    # There are two ways to help CMake find these OpenCV files.
    # 1. Define an Environment Variable named OpenCV_DIR and give path to the folder
    #    which contains files OpenCVConfig.cmake and OpenCVConfig-version.cmake
    # 2. Set this variable OpenCV_DIR within CMakeLists.txt file. (Explained in Step 1)
    # We will follow the second option. This way you can have multiple OpenCV
    # versions on your machine but still you can point to exact OpenCV version
    # you want to use for a particular project

    # Find header folder and library folder for OpenCV
    find_package( OpenCV REQUIRED )

    # Include headers’ folders for OpenCV
    include_directories( ${OpenCV_INCLUDE_DIRS})

    # Now suppose we have a cpp file named, myCode.cpp
    # We will write rule for compilation and linking.
    # In ADD_EXECUTABLE first myCode is the name of executable 
    # which will be generated when we compile our code myCode.cpp
    ADD_EXECUTABLE(myCode myCode.cpp)

    # This is all we need to build our C++ code. But what if we have
    # many C++ files to compile and build.
    # We can write a Macro so that we don’t have to type this again and again.

    # Define a Macro named add_example and add rules for compilation.
    MACRO(add_example name)
      ADD_EXECUTABLE(${name} ${name}.cpp)
      TARGET_LINK_LIBRARIES(${name} ${OpenCV_LIBS})
    ENDMACRO()

    # Now we can use this macro to compile many C++ files.
    add_example(myCode1)
    add_example(myCode2)

### Compile commands

    cd build
    cmake ..
    cmake -G "Visual Studio 16 2019" ..

    cmake --build . --config Release
