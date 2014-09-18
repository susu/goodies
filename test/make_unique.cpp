#include <igloo/igloo.h>
#include <igloo/igloo_alt.h>

#include <goodies/make_unique.hpp>

using namespace igloo;

Describe(std_make_unique)
{
    It(should_create_unique_ptr)
    {
        std::unique_ptr<int> ptr = std::make_unique<int>();
    }
};
