#include <arba/stdx/stdx.hpp>
#include <arba/stdx/version.hpp>
#include <cstdlib>
#include <iostream>

int main()
{
    std::cout << stdx::libname() << std::endl;
    std::cout << "TEST PACKAGE SUCCESS" << std::endl;
    return EXIT_SUCCESS;
}
