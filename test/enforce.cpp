#include <igloo/igloo_alt.h>

#include <goodies/enforce.hpp>

using namespace igloo;

Describe(enforce_helper)
{
    It(should_throw_exception_if_failed)
    {
        AssertThrows(std::runtime_error, ENFORCE(1 == 2, "Math rules are working!"));
        std::cout << LastException<std::runtime_error>().what() << std::endl;
    }
};
