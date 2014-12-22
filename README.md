MVariant
========

Smart polymorphic Variant class for arithmetic operations with POD-data types.

Polymorphy is a great thing. But in C++, polymorphy is (only) related to virtual methods / abstract classes.

What if you don't know which POD (Plain Old Data) type is the right or it may be to be changed at run time?
Primitive data types are not polymorphic, through, my `class Variant` is.

Features:
===

* My class `Variant` implements the most important arithmetic operation for all this POD-types:
 * char
 * unsigned char
 * short
 * unsigned short
 * int
 * unsigned int
 * long
 * unsigned long
 * long long
 * unsigned long long
 * float
 * double
 * long double
* Say the programm at **Run Time** which type to save.
* Switch and **convert types** at run time.
* Use standard **input and output streams**.
* Do operations on `Variant` objects like an arithmetic god!
* You only have to `#include "MVariant.h"`.
* You might want to have a look at **[example.cpp](example.cpp)**.

License
===

The code is licensed under a [MIT License](LICENSE).
