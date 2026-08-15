# matrix-rain

A terminal-based Matrix digital rain simulator built in pure C++ using only the standard library. 

### Why this exists
I am building this to learn and break the core mechanics of C++20 coroutines (`co_yield`) before jumping into heavier multithreaded projects. 

### What it does
- Uses stateful coroutines to track independent, cascading column streams.
- Prints 24-bit RGB colors into the terminal using `std::format` and ANSI escape sequences.
- Keeps frames locked and smooth using `<chrono>` and standard random engines.
