#include <igloo/igloo_alt.h>

#include <goodies/Trace.hpp>

using namespace igloo;

static void traced(std::function<void()> fun)
{
    GOODIES_TRACE_FUNCTION(DEBUG);
    fun();
}

Describe(ATrace)
{
    std::ostringstream logOutput;
    void SetUp()
    {
        logOutput.str("");
        goodies::log::Logger::reinitialize(logOutput);
    }

    It(should_log_if_enters_and_leaves_a_block)
    {
        traced([this]()
        {
            AssertThat(logOutput.str(), Contains("ENTER"));
        });
        AssertThat(logOutput.str(), Contains("LEAVE"));

    }
};
