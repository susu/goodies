#ifndef GOODIES_TRACE_HPP_INC
#define GOODIES_TRACE_HPP_INC

#include <goodies/Logger.hpp>

namespace goodies
{
    class Trace
    {
        public:
            Trace(log::LogLevel level, const char * file, int line, const char * func)
            {
                m_details.loglevel = level;
                m_details.line = line;
                m_details.file = file;
                m_details.pretty = func;
                log::Logger::instance().getGuardedStream(m_details)("ENTER");
            }

            ~Trace()
            {
                log::Logger::instance().getGuardedStream(m_details)("LEAVE");
            }
        private:
            log::LogDetails m_details;
    };
}

#define GOODIES_TRACE_FUNCTION(loglevel) \
    goodies::Trace _xa9f8s19pj_trace_logger(goodies::log::LogLevel::loglevel,__FILE__,__LINE__,__FUNCTION__);

#endif
