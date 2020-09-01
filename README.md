# C++ Notes

## C++ Fundamentals

C++ is a case sensitive language. Case sensitivity means that your keywords and variable declarations must match the case. Aside from the case sensitivity, C++ also has a defined outline for program code and specific "elements" found in a typical C++ application. These elements consist of:

    Preprocessor directives which are used to have the compiler execute tasks prior to compiling the source code
    using directives which are utilized to indicate which namespaces to include in a source code file
    a function header which consists of a return type, function name, and parameters
    a function body containing the code that performs the actions required of that function
    statements that are contained in the C++ source code file
    comments for documenting the source code for programmers to understand what the code is intended to do
    a return statement that sends data back to the function caller
    curly braces to enclose bodies of statements. Commonly used to denote the body of a function or a flow controls statement such as a for loop

C++ source code also permits judicious use of white space (tabs, spaces, new lines) to create code that is easier to read. The compiler completely ignores the white space, with a small exception concerning if statements that will be covered later. It is highly recommended that you make use of white space to indent and separate lines of code to aid in readability of your source code files.

### Cpp Compilation Basics

The code is built as a multistep process.

First a tool called the preprocessor goes through your code and
manipulates it a little bit. The output of the preprocessor goes
to something called the compiler.
Real programs have lots of files in them,
like not just five or ten, but thousands. And each one is compiled
individually and the output of that is called an object file.

After everybody's been compiled, then they're linked together
into your actual executable, the thing that you run under the
debugger or without the debugger.
Now, when you're writing these individual files, the compiler
makes sure that you've used the syntax of the library correctly.
For example, the single line of useful code in there had quite
a lot of syntax. It had bits and pieces of punctuation that you
will understand by the time we're done. And the compiler makes
sure that all that punctuation is being used properly.
It doesn't necessarily check every single thing about your program.
You are allowed to basically make a promise to the compiler.
I'd like to call this piece of code that I swear to you will
be somewhere else.

The linker makes sure that those promises are being kept.
And it puts all the somewhere elses together and connects everybody
to the places they were planning to use and, okay, this is good,
it all works.

Those three steps of building are actually critical to understanding
what happens when you get error messages.
In C++ you're told whether the error is a compiler
error or a linker error. And that's vital to being able to solve
the problem.

###C++ Statements
A C++ program is comprised of various components such as functions, methods, classes, etc. The instructions that form part of a C++ program typically reside inside of functions or methods. These functions are comprised of C++ statements. You will find yourself using various types of statements in your C++ code as listed here:

-declarations - these are used to declare variables and constants that will be used in your application
-assignments - these are used to assign values to variables in your application code
-preprocessor directives - covered in the topic on Code Formatting
-comments - used to document your code
-function declarations - covered in the topic on Code Formatting
-executable statements - these are used to perform operations and execute instructions. Examples:
    be cout << "Hello World!"; which outputs Hello World! to the console.
