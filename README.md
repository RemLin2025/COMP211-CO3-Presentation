# Overview:
- Rust, a programming language, was developed by Braydon Hoare as a personal project while he was working as a SWE in 2006. After 3 years, his coworkers became interested 
and the project was sponsored by his company and released publicly in 2010. 
- The purpose of the project was to create a programming language as fast as the popular language C++ at the time while also avoiding memory-related bugs. At the time, memory 
management was one of the hardest skills to learn and was punishing in that a single mistake can cascade into tremendous security risks. Java had a safer memory management
through garbage collection but it created more runtime overhead (extra resources a system consumes which reduces speed) and had less direct control of memory. So the promise 
of Rust was the speed and control of C++ with stronger memory safety guarantees by the compiler without more overhead.

# Usage: 
- Rust is used where a single memory bug can cause the entire program to shut down. This includes web browsers, Operating Systems, cloud infrastructure, and embedded systems. These handle large amounts of memory and operations at very fast speeds so even one single memory bug can cause huge security issues since memory vulnerabilities can be exploited by attackers. 

# C Manual Memory Management: 
- Requires manual memory management where you have to explicitly allocate memory and deallocate it.
    - Memory related bugs: memory leak, use-after-free, double free, dangling pointer, etc.
- References have to be deliberate
    - Memory related bugs: data race (accessing same memory at the same time), race conditions, reference outside boundaries, etc.

# Rust Ownership System: 
- Set of rules for who owns the memory, who can access it, and when it should be freed.
    - Every value has an owner. There can only be one owner at a time. When the owner goes out of scope, its value is automatically dropped
    - Enforces that there is only one mutable reference OR multiple immutable reference
- Rust doesn't need a garbage collector to provide memory safety for ordinary safe Rust code. It uses compile-time checks instead.
- In rust, each value has an owner (a variable). When the ownership moves (new variable is assigned that value), the previous owner cannot access it anymore. Should multiple functions need to access the same memory, Rust supports "borrowing" (accessing) the value without changing value. There is both immutable borrowing (reads) and mutable borrowing (write). 
- Other parts of the program can temporarily borrow the value under specific rules. When the owner goes out of scope, the value's resources are cleaned up.

# Use-After-Free:
- In C, the memory bug causes undefined behavior: works normally, random value, segmentation fault (access to restricted data), and corrupt data or introduce security vulnerabilities.
    - The memory is still there after being freed.
- Ex: Program frees memory containing sensitive info. Stops pointing to data and lets it be reused. Another part of the program reuses that memory and read/modify the sensitive data. 
- In Rust, after releasing memory of a pointer using drop(), accessing it again is strictly prohibited by the compiler.

# TLDR:
- Rust has the performance of C/C++ that tracks relationships in compile time to prevent memory bugs. Uses an ownership system. It's not popular because millions programs/products are written in C/C++ and largely have dependencies that rely on that code. 
- Many companies use Rust for new developments : OpenAI, Discord, Figma, Dropbox, Cloudflare, AWS, Meta, Android, Linux Kernel, Windows Kernel, Mozilla Firefox, npm…
