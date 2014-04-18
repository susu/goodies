#ifndef GOODIES_EXCEPTION_HPP_INC
#define GOODIES_EXCEPTION_HPP_INC

#include <stdexcept>
#include <goodies/MakeString.hpp>

namespace goodies
{
    class BaseException : public std::runtime_error
    {
        public:
            BaseException(const char * file, int line, const std::string & msg)
                : std::runtime_error(MakeString() << "thrown at " << file << ':' << line << ": " << msg)
            {}
    };
}

#define GOODIES_THROW(exctype,msg) \
    throw exctype(__FILE__,__LINE__,goodies::MakeString()<<msg)

#endif
