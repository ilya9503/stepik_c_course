/*
    Compile time refers to the period during which a program's source code is translated into machine code
        by a compiler, before it is executed.
    Runtime refers to the period during which a program is executing after being compiled.

    Phases of Compilation
    When you compile a C++ (or any compiled language) program, the compiler goes through several stages:

    1. Preprocessing 📝
        Handles #include, #define, and macros.
        Removes comments and expands macros.

    2. Compilation 🎯
        Converts source code (.cpp) into assembly code (.s).
        Checks for syntax errors and type correctness.

    3. Assembly ⚙️
        Translates assembly code into machine code (.o or .obj file).
        This file contains low-level instructions for the CPU.

    4. Linking 🔗
        Combines multiple object files (.o or .obj) into a final executable.
        Resolves external dependencies (e.g., function calls to external libraries).
*/