#include <igloo/igloo_alt.h>

#include <goodies/Logger.hpp>

using namespace igloo;

Describe(ALogger)
{
    It(should_log_messages)
    {
        std::ostringstream ss;
        goodies::log::Logger::initialize(ss);
        LOG_DEBUG("HALI");

        std::cout << ss.str() << std::endl;
        AssertThat(ss.str(), Contains("HALI"));
    }
};
