Overview:
- Rust, a programming language, was developed by Braydon Hoare as a personal project while he was working as a SWE in 2006. After 3 years, his coworkers became interested 
and the project was sponsored by his company and released publicly in 2010. 
- The purpose of the project was to create a programming language as fast as the popular language C++ at the time while also avoiding memory-related bugs. At the time, memory 
management was one of the hardest skills to learn and was punishing in that a single mistake can cascade into tremendous security risks. Java had a safer memory management
through garbage collection but it created more runtime overhead (extra resources a system consumes which reduces speed) and had less direct control of memory. So the promise 
of Rust was the speed and control of C++ with stronger memory safety guarantees by the compiler without more overhead. 

Memory Management:
- In a coding example, you create a variable called old_name that is assigned a string. You assign another variable new_name to be old_name. Rust now prevents use of old_name.
- Rust doesn't need a garbage collector to provide memory safety for ordinary safe Rust code. It uses compile-time checks instead.
- In rust, each value has an owner (a variable). When the ownership moves (new variable is assigned that value), the previous owner cannot access it anymore.
Other parts of the program can temporarily borrow the value under specific rules. When the owner goes out of scope, the value's resources are cleaned up.

Usage: 
- Rust is used where a single memory bug can cause the entire program to shut down. This includes web browsers, Operating Systems, cloud infrastructure, and embedded systems.

Use-After-Free:
