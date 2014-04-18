#include <igloo/igloo.h>
#include <igloo/igloo_alt.h>

#include <goodies/Exception.hpp>

using namespace igloo;

class TestException : public goodies::BaseException
{
    public:
        using goodies::BaseException::BaseException;
};

Describe(ThrowMacro)
{
    It(should_print_data_about_thrown_error)
    {
        std::string fileName = __FILE__;

        // The following line must be just before the GOODIES_THROW line!
        int line = __LINE__ + 1;
        AssertThrows(goodies::BaseException, GOODIES_THROW(TestException, "error"));

        std::string what = LastException<goodies::BaseException>().what();
        AssertThat(what, Contains(fileName));
        AssertThat(what, Contains(std::to_string(line)));
    }
};
