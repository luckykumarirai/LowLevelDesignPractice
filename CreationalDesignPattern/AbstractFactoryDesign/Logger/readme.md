# g++ -c infoLogger.cpp errorLogger.cpp

# ar rcs logger_library.a infoLogger.o errorLogger.o

# g++ -o client client.cpp logger_library.a

<--client.cpp is your C++ source file.
library.a is a precompiled static library.
g++ -o client client.cpp library.a compiles client.cpp, links it with library.a, and produces an executable named client.-->

# ./client

# Abstract Factory Design Pattern

The Abstract Factory design pattern provides an interface for creating families of related or dependent objects without specifying their concrete classes.

### Explanation:

- **Client**: Uses the abstract factory to create products.
- **Abstract Factory**: Declares the `create` method for creating abstract products.
- **ILoggerFactory**: A concrete implementation of the abstract factory, creating different types of loggers (Error, Info, Debugger).
- **ILogger**: Abstract product interface that all specific loggers implement.
- **ErrorLogger, InfoLogger, DebuggerLogger**: Concrete products that implement the `ILogger` interface.
- **ErrorFactory, InfoFactory, DebuggerFactory**: Factories that produce specific types of loggers.

---

```mermaid
graph TD;
    Client-->AbstractFactory;
    AbstractFactory-->ILoggerFactory;
    ILoggerFactory-->ErrorFactory;
    ILoggerFactory-->InfoFactory;
    ILoggerFactory-->DebuggerFactory;
    Client-->ILogger;
    ILogger-->ErrorLogger;
    ILogger-->InfoLogger;
    ILogger-->DebuggerLogger;

