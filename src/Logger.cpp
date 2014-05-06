
#include <ctime>
#include <string>
#include <iostream>

#include <goodies/Logger.hpp>

using namespace goodies::log;

std::unique_ptr<Logger> Logger::m_instance;

Logger::Logger(const std::string & loggername)
  : m_outputStream(&std::cout)
  , m_logLevel(LogLevel::PERF)
{}

Logger::~Logger()
{}

std::string getFormattedDate()
{
  time_t rawtime;
  struct tm * timeinfo;
  static char buffer[255];
  time(&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, 255, "%Y-%m-%d %H:%M:%S", timeinfo);

  return buffer;
}

std::ostream& goodies::log::operator<<(std::ostream& out, LogLevel level)
{
  switch(level)
  {
    case LogLevel::CRITICAL: return out << "CRITICAL";
    case LogLevel::ERROR:    return out << "ERROR";
    case LogLevel::WARNING:  return out << "WARNING";
    case LogLevel::INFO:     return out << "INFO";
    case LogLevel::DEBUG:    return out << "DEBUG";
    case LogLevel::FINE:     return out << "FINE";
    case LogLevel::PERF:     return out << "PERF";
  }
  return out << "UNDEF";
}

void Logger::startLog(LogLevel loglevel, const char * file, int line,
                      const char * pretty)
{
  std::string fileStr(file);
  auto lastSlash = fileStr.find_last_of('/');

  getOutputStream() << getFormattedDate() << ' ' <<
                       loglevel << " " <<
                       fileStr.substr(lastSlash+1) << ':' << line << " [" <<
                       pretty << "] ";
}

void Logger::endLog()
{
  getOutputStream() << std::endl;
}

StreamGuard::StreamGuard(Logger & logger, LogDetails details)
  : m_logger(logger)
  , m_details(details)
{}

StreamGuard::~StreamGuard()
{
  m_logger.endLog();
}
