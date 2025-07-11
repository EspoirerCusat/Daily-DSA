**LLD**

* Breaking down or designing the real logic into extensible, testable, readable code.

SOLID Principle

=> Single Responsibility Principle (SRP)
  - A class should only have one responsibility
  - A class should have only one reason to change

=> Open / Close Principle (OCP)
  - A Class should be open for extension but closed for modification

=> Liskov Substitution Principle (LSP)
  - A subtypes must be suitable for their base type

=> Interface Segregation Principle (ISP) 
  - Clients should not be forced to depend on interface that they do not use.

=> Dependency Inversion Principle (DIP)
  - High level module should not depend on low level modules.
  - Both should be abstractions (Like interface)
  - interface Logger (class FileLogger, class DBLogger)
