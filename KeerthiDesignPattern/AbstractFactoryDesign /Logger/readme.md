# g++ -c infoLogger.cpp errorLogger.cpp

# ar rcs logger_library.a infoLogger.o errorLogger.o

# g++ -o client client.cpp logger_library.a

<--client.cpp is your C++ source file.
library.a is a precompiled static library.
g++ -o client client.cpp library.a compiles client.cpp, links it with library.a, and produces an executable named client.-->

# ./client

                            Client 
                               | 
    ............................................................
    |                                                          |
Abstract Fatory                                             ILogger
    |                                                           |           |           |
ILoggerFactory                                             ErrorLogger   InfoLogger DebuggerLogger
|                   |            |
ErrorFactory   InforFactory    DebuggerFactory 

