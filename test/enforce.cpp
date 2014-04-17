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

    It(should_concatenate_message)
    {
        AssertThrows(std::runtime_error, ENFORCE(false, "Never true! " << 42));
        std::string what = LastException<std::runtime_error>().what();
        std::cout << what << std::endl;
        AssertThat(what, Contains("Never true! 42"));
    }
};
