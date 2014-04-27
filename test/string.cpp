#include <igloo/igloo.h>
#include <igloo/igloo_alt.h>

#include <goodies/MakeString.hpp>

using namespace igloo;

Describe(TheToUpper)
{
    It(should_convert_to_uppercase)
    {
        AssertThat(goodies::toUpper("lorem"), Equals("LOREM"));
    }

    It(should_not_harm_spec_chars)
    {
        AssertThat(goodies::toUpper("lorem ipsum :?%^*"), Equals("LOREM IPSUM :?%^*"));
    }
};
