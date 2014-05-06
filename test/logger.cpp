#include <igloo/igloo_alt.h>

#include <goodies/Logger.hpp>

using namespace igloo;

Describe(ALogger)
{
    std::ostringstream ss;

    void SetUp()
    {
        ss.str("");
        goodies::log::Logger::reinitialize(ss);
        goodies::log::Logger::instance().setLogLevel(goodies::log::LogLevel::DEBUG);
    }

    It(should_log_messages)
    {
        LOG_DEBUG("HALI");

        std::cout << ss.str() << std::endl;
        AssertThat(ss.str(), Contains("HALI"));
    }

    It(should_set_loglevel_at_runtime)
    {
        LOG_DEBUG("msg-test-1");
        AssertThat(ss.str(), Contains("msg-test-1"));

        goodies::log::Logger::instance().setLogLevel(goodies::log::LogLevel::INFO);
        LOG_DEBUG("msg-test-2");
        AssertThat(ss.str(), Is().Not().Containing("msg-test-2"));
    }
};
