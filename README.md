# C++ Introduction Notes

## C++ Fundamentals

C++ is a case sensitive language. Case sensitivity means that your keywords and variable declarations must match the case. Aside from the case sensitivity, C++ also has a defined outline for program code and specific "elements" found in a typical C++ application. These elements consist of:

* Preprocessor directives which are used to have the compiler execute tasks prior to compiling the source code using directives which are utilized to indicate which namespaces to include in a source code file
* a function header which consists of a return type, function name, and parameters
* a function body containing the code that performs the actions required of that function statements that are contained in the C++ source code file
* comments for documenting the source code for programmers to understand what the code is intended to do
* a return statement that sends data back to the function caller
* curly braces to enclose bodies of statements. Commonly used to denote the body of a function or a flow controls statement such as a for loop

C++ source code also permits judicious use of white space (tabs, spaces, new lines) to create code that is easier to read. The compiler completely ignores the white space, with a small exception concerning if statements that will be covered later. It is highly recommended that you make use of white space to indent and separate lines of code to aid in readability of your source code files.

### Compilation Basics

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

### C++ Statements
A C++ program is comprised of various components such as functions, methods, classes, etc. The instructions that form part of a C++ program typically reside inside of functions or methods. These functions are comprised of C++ statements. You will find yourself using various types of statements in your C++ code as listed here:

* declarations - these are used to declare variables and constants that will be used in your application

* assignments - these are used to assign values to variables in your application code

* preprocessor directives - covered in the topic on Code Formatting

* comments - used to document your code

* function declarations - covered in the topic on Code Formatting

* executable statements - these are used to perform operations and execute instructions

## Data Types in C++ 
C++ contains intrinsic data types to store numeric values in your application code. It's important to remember that these values are binary-based and not as flexible as their base 10 counterparts. The range does not exceed 3 billion in either direction.

### Variables

Variables are identifiers that you create to hold values or references to objects in your code. A variable is essentially a named memory location. C++ is known as a strongly typed language. 

When you create a variable in C++, you must give it a data type. You can assign a value to the variable at the time you create it or later in your program code. This is known as initializing the variable. Even though you can initialize a variable separate from its creation, you must assign the data type when you define the variable. C++ will not allow you to use an uninitialized variable to help prevent unwanted data from being used in your application. The following code sample demonstrates declaring a variable and assigning a value to it.  C++ supports two methods of initializing a variable.

    int myVar = 0;
    int yourVar{0};

C++ has some restrictions around identifiers that you need to be aware of.

First off, identifiers are case-sensitive because C++ is a case-sensitive language. That means that identifiers such as myVar, _myVar, and myvar, are considered different identifiers.

Identifiers can only contain letters (in any case), digits, and the underscore character. You can only start an identifier with a letter or an underscore character. You cannot start the identifier with a digit. myVar and _myVar are legal but 2Vars is not.

C++ has a set of reserved keywords that the language uses. You cannot use these keywords as an identifier in your code. You may choose to take advantage of the case-sensitivity of C++ and use Long as an identifier to distinguish it from the reserved keyword long, but that is not a recommended approach.

### Constants

Similar to a variable, a constant expression is a named memory location for a value used in your application.  The difference is that, as you might expect, a constant expression cannot have its value change in the program during run time.  C++ uses the keyword const to indicate that an expression is a constant.

When you declare a constant in C++, you must assign a literal value to that constant at the same time.  You cannot assign it later in program nor can you change the value in code later.  Also, because the value cannot be changed, you cannot initialize a constant with a variable or any other value that will have its value modified during runtime.


### Casting


Casting refers to converting one data type to another. Some data conversions are not possible while some are possible but result in data loss. C++ can perform many conversions automatically, what is known as implicit casting or implicit conversion. For example, attempting to convert a smaller data type to larger data type as shown here:

    int myInt = 12;
    long myLong;
    myLong = myInt;

In the first line, we declare an integer data type and assign it a value of 12. The next line declares a long data type and in the third line, we assign the integer data type value to the long data type. C++ automatically converts the data type for you. This is known as a widening conversion. Some programmers also call this an expanding assignment. We are expanding or widening the data type to a larger one. In this case, there is no loss in data. The following table highlights some potential data conversion problems.


When you want to explicitly perform a conversion or cast, you can use the type cast features of C++. For example, the previous widening conversion in the int to long cast was implicit but you can also tell the compiler that you are know what you are doing by using the type cast statement as in:

    long myLong = (long)myInt;

    // or you can use this version as well

    long myLong = long(myInt);

C++ also provides a cast operator that is more restrictive in its usage. This in the form static_cast (type). This static cast operator can be used for converting numeric values or to numeric values. As an example:

    char ch;
    int i = 65;
    float f = 2.5;
    double dbl;
    ch = static_cast<char>(i);   // int to char
    dbl = static_cast<double>(f);   // float to double

C++ also provides support for complex data types. These are also referred to as compound data types. Mostly because they store more than one piece of data or potentially more than one data type.

### Arrays (Complex data Types)


An array is a set of objects that are grouped together and managed as a unit. You can think of an array as a sequence of elements, all of which are the same type. You can build simple arrays that have one dimension (a list), two dimensions (a table), three dimensions (a cube), and so on. Arrays in C++ have the following features:

* Every element in the array contains a value.
* Arrays are zero-indexed, that is, the first item in the array is element 0.
* The size of an array is the total number of elements that it can contain.
* Arrays can be single-dimensional, multidimensional, or jagged.
* The rank of an array is the number of dimensions in the array.

Arrays of a particular type can only hold elements of that type. This means that you cannot store integers, longs, and character data types in the same array.

__Creating and Using Arrays__

When you declare an array, you specify the type of data that it contains and a name for the array. To declare a single-dimensional array, you specify the type of elements in the array and use brackets, [] to indicate that a variable is an array. The following code example shows how to create a single-dimensional array of integers with elements zero through nine.

    int arrayName[10];

You can also choose to create an array and initialize it with values at the same time as in the following example that declares and integer array and assigns values to it. The compiler knows how large to make the array by the number of values in the curly braces. 
You can also declare an array and only initialize some of the elements:

    int arrayName[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arrayName[10] = {1, 2, 3};

In this case, we have declared an array of size 10 but have only assigned values to the first three elements. The compiler will initialize the remaining elements to the default value for the data type the array holds. In this case, int data type, the remaining values are initialized to 0.

__Accessing Data in an Array__

You can access data in an array in several ways, such as by specifying the index of a specific element that you require or by iterating through the entire array and returning each element in sequence.

The following code example uses an index to access the element at index two.

    //Accessing Data by Index
    int oldNumbers[] = { 1, 2, 3, 4, 5 };

    //number will contain the value 3
    int number = oldNumbers[2];

Note: Arrays are zero-indexed, so the first element in any dimension in an array is at index zero. The last element in a dimension is at index N-1, where N is the size of the dimension. If you are using some other languages, such as C#, and you attempt to access an element outside this range, the C# runtime will throw an exception (error). C++ doesn't offer such protection. If you attempt to access an element that is outside the bounds of your array, you will still return data, but you have no idea what that data is.

The reason for this is because an array is simply a pointer to a memory location. The first element of the array is the starting memory address for the entire array. If you have an array of integer data types, then the number of the elements multiplied by the size of the int data type on your system, determines how much memory is used by the array, and at the same time, permits the access of the elements in the array by performing math on the memory address to get at the required element. If you attempt to access oldNumbers[5], the program will simply return the data found at the memory address that is the next memory address location beyond the last array element. This can be a dangerous situation and is in fact, the result of some security issues found in software.

You can also iterate through an array by using a for loop. You will cover loops in module 3 so don't worry if you don't completely understand this example at this time. Essentially, the for loop starts at 0 and repeats the portion in the curly braces {} for each of the five steps in the loop.
The following code example shows how to use a for loop to iterate through an array.

    //Iterating Over an Array
    int oldNumbers[] = { 1, 2, 3, 4, 5 };
    for (int i = 0; i < 5; i++)
    {
         int number = oldNumbers[i];
         ...
    }
### Strings

Strings are a series of characters. C++ represents strings in one of two ways. The first maintains backward compatibility with the C language and represents the string as a character array. There is one aspect to a C-style string that is important to note. The last character of every string you store is the null character string, typically represented by the ASCII code for 0 which is \0. This is necessary so that the compiler knows when the string ends. An example demonstrates a C-style string stored in a character array:

    char isAString[6] = { 'H', 'e', 'l', 'l', 'o', '\0'};
    char isNotAString[5] = { 'H', 'e', 'l', 'l', 'o'};
    cout << isAString << endl;
    cout << isNotAString << endl;

The most common mistake made by users of the C-style string is to forget to make the char array large enough to accommodate the \0 character, but also forgetting include the \0. In the previous example, a programmer might think that an array of size 5 would be large enough to contain Hello because that's how many characters are in the word. However, the null character would not be included in the second array, which could result in errors in code that uses this array. The reason is that C++ does not consider the isNotAString array to be a string.

An alternative method of declaring a character array for use as a string is to simply initialize it with a string literal. A string literal is a sequence of characters enclosed in the double quotes ("). For example:

    char isAString[6] = "Hello";
    char isAnotherString[] = "Array size is inferred";

In the previous example, the first line creates an array of size 6 and assigns the string literal Hello to the array. The second example lets the compiler infer the size from the string literal itself. Note that neither of these two string literals specifies a \0 character. The compiler will implicitly add that for you. However, caution is advised in the first line to ensure that you allow enough room in the array size specified for the null character. If you create an array that is larger than required for the string literal along with the null character, then C++ simply fills the remaining elements of the array with null characters.

__String Class__

If the use of character arrays, single quoted characters, and null termination characters are making you think that strings aren't worth the hassle, consider the string class instead. The ISO/ANSI standard helped to expand the string handling capabilities of C++ by adding the string class.

In order to use the string class, you have to include the string header file. We have not covered namespaces yet but to make typing much easier, you would add a using statement as in the following example.

    using namespace std;
    string myString = "Hello!";
    std::string myNewString = "Less typing";

Without the using directive, you would have to type std::string every time you wanted to use the string class in your code, as in the second line above.

### Structures

Arrays can store multiple pieces of data in one compound data type but recall, the data types must all be of the same type. Structures are known as user-defined types. You define the struct by giving it a name and then adding the member data types as in the following example:

    struct coffeeBean
    {
         string name;
         string country;
         int strength;
    };
Recall that in order to use the string data type in our struct, the C++ file that contains the struct must include the string header file. This code snippet also assumes that using namespace std; has also been included.
Once we have defined the structure, we can then use it in our code the same as any other data type. To use the coffeeBean struct in your code, you simply declare a new variable of that type as shown in this example.

    struct coffeeBean
    {
         string name;
         string country;
         int strength;
    };

    coffeeBean myBean = { "Strata", "Colombia", 10 };
    coffeeBean newBean;
    newBean.name = "Flora";
    newBean.country = "Mexico";
    newBean.strength = 9;
    cout << "Coffee bean " + newBean.name + " is from " + newBean.country << endl;
    
   ### Unions
   
   
Curso Module 2 Data Types in C++ Complex Data Types Unions

Unions

A union, in C++, is similar to a structure in that it can store multiple, disparate data types. The differentiation is that a union can only store one piece of data at a time. What does that signify? It's best represented using an example.

    union numericUnion
    {
         int intValue;
         long longValue;
         double doubleValue;
    };
    numericUnion myUnion;
    myUnion.intValue = 3;
    cout << myUnion.intValue << endl;
    myUnion.doubleValue = 4.5;
    cout << myUnion.doubleValue << endl;
    cout << myUnion.intValue; cout << endl;

In this example, we define a union called numericUnion and then create a variable of that type, called myUnion. We first assign the value 3 to the intValue field and then output it. Next we assign the value 4.5 to the doubleValue field and output that. The example shows how the union works when on the second to last line, we try to output the value for intValue again. In the output, it results in 0 rather than 3. The reason is that once we assign a value to doubleValue, what was contained in intValue is lost. The union can only store a value in one of its fields at a time.
For instance, Unions can be used represent a numeric and a string data type internally but only assign the proper data type based on the part number.

### Enumerations

In the topics on variables and constants, it was noted that anytime you want to create a value for use in a program, where the value should never change, you used a constant. An enumeration can be considered a way to create what are known as symbolic constants. The most common example is to use an enum to define the day of the week. There are only seven possible values for days of the week, and you can be reasonably certain that these values will never change.

To create an enum, you declare it in your code file with the following syntax, which demonstrates creating an enum called Day, that contains the days of the week:

    enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

By default enum values start at 0 and each successive member is increased by a value of 1. You can change the default by specifying a starting value for your enum as in the following example.

    enum Day { Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
    payDay = Thursday;
    cout << payDay << endl;

The first line defines the enumeration Day and assigns seven values to the enum. Sunday is listed as the first day of the week and is initialized with the value one.
The second line declares a new variable called payDay which is of the Day enum type. In the third line, payDay is assigned a value from the list of values, in this case Thursday. Finally, the last line outputs the value of payDay (5) to the console window. Internally, the constants in the enum are used as numbers and not as the textual representation you assign to them.

## C++  Control statements
### Operators
Operators are used to perform operations on variables and values. Comparison operators determine if values are equal, greater, or less than each other.  C++ also allows you to use mathematical operators for incrementing values to help control the number of iterations in a loop.  You can also make use of bitwise operators to speed up some operations in your code. 
### Decision Structures
C++ decision structures provide logic in your application code that allows the execution of different sections of code depending on the state of data in the application. You might ask users whether they wish to save any changes to a file that is open in the application. The decision structure permits you to code behavior to execute based on the answer provided by the user. C++ uses conditional statements to achieve this functionality.

__if__:  are concerned with Boolean logic. If the statement is true, the block of code associated with the if statement is executed.  char response = 'y';

    if (response == 'y' || response == 'Y')
    {
        cout << "Positive response received" << endl;
    }
    else if (response == "connection_error")
    {
        // Block of code executes if the value of the response variable is "connection_error".
    }
    else
    {
        // Block of code executes if the value of the response variable is neither above responses.
    }
 
 __switch__: If there are too many else if statements, code can become messy and difficult to follow. In this scenario, a better solution is to use a switch statement. The switch statement simply replaces multiple else if statements. The following sample shows how you can use a switch statement to replace a collection of else if clauses.
switch statements support the following data types as expressions:
*   intrinsic data types such as int or char
*   enumerations

        char response = 'y';
        switch (response)
            {
               case 'y':
                  // Block of code executes if the value of response is y.
                  break;
               case 'Y':
                  // Block of code executes if the value of response is Y.
                  break;
               case 'n':
                  // Block of code executes if the value of response is n.
                  break;
               default:
                  // Block executes if none of the above conditions are met
            }
   ### Repetition Statements
The ability to repeat a series of statements is a core requirement of most application code. C++ provides a number of standard constructs known as loops that you can use to implement iteration logic: for loops, while loops, and do loops. Nesting of loops is possible in C++.  The most common is to nest for loops.
* The for loop executes a block of code repeatedly until the specified expression evaluates to false. You can define a for loop as follows.

    for ([initializer(s)]; [condition]; [iterator])
    {
       // code to repeat goes here
    }

* A while loop enables you to execute a block of code while a given condition is true
string response;
cout << "Enter menu choice " << endl << "More" << endl << "Quit" << endl;
cin >> response;

    while (response != "Quit")
    {
        // Code to execute if Quit is not entered

        // Prompt user again with menu choices until Quit is entered
        cout << "Enter menu choice " << endl << "More" << endl << "Quit" << endl;
        cin >> response;
    }
* A do loop, sometimes also referred to as a do...while loop, is very similar to a while loop, with the exception that a do loop will always execute the body of the loop at least once.
string response;

    do
    {        
         cout << "Enter menu choice " << endl << "More" << endl << "Quit" << endl;
         cin >> response;

         // Process the data.

    } while (response != "Quit");
 
 ## C++ Functions
 
 Functions are a component of a programming language that permit you to break down the behavior of an application into discreet pieces of functionality, hence the name function.  
 A function is essentially a block of C++ code that you give a name and then call from other locations in your application, when you want the computer to perform the instructions contained in that function.
 Functions can also be overload.   This refers to the practice of using the same function name to refer to multiple functions that perform different actions. The compiler will know which function to call, based on the number of arguments passed in.

    int Sum(int x, int y)
    {
         return x + y;
    }

    int Sum(int x, int y, int z)
    {
         return x + y + z;
    }
 A function can accept values that will be used in the statements in the function body.  These values are known as arguments when passed to a function.  The arguments are passed into parameters.  Parameters are the placeholders that are found inside the parentheses of a function declaration .When calling the function, you use the function name, followed by an open parenthesis, the arguments that will be passed into the parameters, and then a closing parenthesis:
    
    int result = Sum(2, 3);
    
 ### Function Prototypes
 
When declaring a function, you specify its storage class, return type, name, and parameters.  Some refer to this as the function signature.  In C++ it is also called a function prototype. In C++, function prototypes belong in header files. 

### Inline Functions

One of the goals for using functions in your code is to create discrete pieces of functionality in your code that is easier to test and maintain.  However, functions also have an impact on application performance.  The reason for this impact results from the operations that must be performed when a function is called. 
This avoids the overhead of making a function call because the contents of the function body are now located at the point where the functionality is required.   Note a couple of points about inline functions:

*    the inline keyword is a compiler directive that is a recommendation only.  The compiler may ignore your request and compile the function normally resulting in function calls anyway.
*    if you are using inline functions and change the function in anyway, the code needs to be recompiled because the code for that function will need to be updated in each location it was used.
*    use inline functions only for small functions that are used frequently, not for large functions.

    inline void swap(int & a, int & b)
    {
         int temp = a;
         a = b;
         b = temp;
    }
 ## Objects and Classes
