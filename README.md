# Concept #

A C++ library providing features extending the standard library.

# Install #
## Requirements ##

Binaries:

- A C++20 compiler (ex: g++-13)
- CMake 3.26 or later

Testing Libraries (optional):

- [Google Test](https://github.com/google/googletest) 1.14 or later (optional)

## Clone

```
git clone https://github.com/arapelle/arba-stdx
```

## Quick Install ##
There is a cmake script at the root of the project which builds the library in *Release* mode and install it (default options are used).
```
cd /path/to/arba-rand
cmake -P cmake/scripts/quick_install.cmake
```
Use the following to quickly install a different mode.
```
cmake -P cmake/scripts/quick_install.cmake -- TESTS BUILD Debug DIR /tmp/local
```

## Uninstall ##
There is a uninstall cmake script created during installation. You can use it to uninstall properly this library.
```
cd /path/to/installed-arba-stdx/
cmake -P uninstall.cmake
```

# How to use
## Example - Erase an element of a vector quickly (The sequence of elements is *not* preserved. )
```c++
#include <arba/stdx/algorithm/unstable_erase.hpp>
#include <vector>
#include <cstdlib>
#include <iostream>

int main()
{
    std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7 };
    const auto iter = vec.begin();
    stdx::unstable_erase(vec, iter, stdx::not_last_element);
    for (const auto& element : vec)
        std::cout << element << ' '; // 7 1 2 3 4 5 6
    std::cout << std::endl << "EXAMPLE SUCCESS" << std::endl;
    return EXIT_SUCCESS;
}
```

# License

[MIT License](./LICENSE.md) © arba-stdx
