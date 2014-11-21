#ifndef GOODIES_LOGGER_HPP_INC
#define GOODIES_LOGGER_HPP_INC

#include <utility>
#include <string>
#include <ostream>
#include <memory>
#include <goodies/enforce.hpp>

#ifdef GOODIES_ENABLE_PERF_CRITICAL_LOGS
#  define LOG_PERF LOG_MSG(goodies::log::LogLevel::PERF)
#else
#  define LOG_PERF(...)
#endif

#define LOG_CRITICAL LOG_MSG(goodies::log::LogLevel::CRITICAL)
#define LOG_ERROR LOG_MSG(goodies::log::LogLevel::ERROR)
#define LOG_WARNING LOG_MSG(goodies::log::LogLevel::WARNING)
#define LOG_INFO LOG_MSG(goodies::log::LogLevel::INFO)
#define LOG_DEBUG LOG_MSG(goodies::log::LogLevel::DEBUG)
#define LOG_FINE  LOG_MSG(goodies::log::LogLevel::FINE)


#define LOG_MSG(loglevel) \
  goodies::log::Logger::instance().getGuardedStream( \
      goodies::log::LogDetails{\
        (loglevel), __FILE__, __LINE__, __FUNCTION__} )

namespace goodies
{
    namespace log
    {
        enum class LogLevel
        {
            // user levels
            CRITICAL =  1,
            ERROR    = 10,
            WARNING  = 20,
            INFO     = 30,

            // development levels
            DEBUG    = 40,
            FINE     = 50,
            PERF     = 60,
        };
        std::ostream& operator<<(std::ostream& out, LogLevel level);

        struct LogDetails
        {
            LogLevel loglevel;
            const char* file;
            int line;
            const char* pretty;
        };

        class Logger;
        class StreamGuard
        {
            public:
                StreamGuard(Logger & logger, LogDetails details);
                ~StreamGuard();

                template<typename...Args>
                void operator()(Args&&...args)
                {
                    m_logger(m_details, std::forward<Args>(args)...);
                }
            private:
                Logger & m_logger;
                LogDetails m_details;
        };

        class Logger
        {
            public:
                ~Logger();
                static Logger& instance()
                {
                    ENFORCE(m_instance != nullptr, "Logger singleton instance is not valid!");
                    return *m_instance;
                }

                static void initialize(std::ostream & output)
                {
                    if (m_instance == nullptr) {
                        reinitialize(output);
                        m_instance->setLogLevel(LogLevel::PERF);
                    }
                }

                static void reinitialize(std::ostream & output)
                {
                    m_instance.reset(new Logger("logger"));
                    m_instance->setLogLevel(LogLevel::PERF);
                    m_instance->m_outputStream = &output;
                }

                void resetOutput(std::ostream & output)
                {
                    m_outputStream = &output;
                }

                void setLogLevel(LogLevel newLevel)
                {
                    m_logLevel = newLevel;
                }

                StreamGuard getGuardedStream(LogDetails details)
                {
                    return StreamGuard(*this, details);
                }

                template<typename...Args>
                void operator()(LogDetails details, Args&&...args)
                {
                    if (details.loglevel <= m_logLevel)
                    {
                        startLog(details.loglevel, details.file, details.line, details.pretty);
                        print(std::forward<Args>(args)...);
                    }
                }

                void endLog();

            private:
                Logger(const std::string& loggerName);
                Logger(Logger&) = delete;

                void startLog( LogLevel loglevel, const char * file, int line,
                        const char * pretty);
                std::ostream& getOutputStream()
                {
                    ENFORCE(m_outputStream != nullptr, "Output stream not initialized!");
                    return *m_outputStream;
                }

                template<typename First,typename...Args>
                void print(First&& first, Args&&...args)
                {
                    getOutputStream() << first;
                    print(std::forward<Args>(args)...);
                }

                void print()
                {}

                std::ostream * m_outputStream;
                LogLevel m_logLevel;

                static std::unique_ptr<Logger> m_instance;
        };
    }
}

#endif
