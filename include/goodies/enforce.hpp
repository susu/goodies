#ifndef GOODIES_ENFORCE_HPP_INC
#define GOODIES_ENFORCE_HPP_INC

#include <stdexcept>
#include <goodies/MakeString.hpp>

namespace goodies
{
    class EnforceFailedError : public std::runtime_error
    {
        public:
            EnforceFailedError(const char* conditionStr, const char* file, int line, const std::string & msg)
                : std::runtime_error(goodies::MakeString()<< "ENFORCE '"<<conditionStr<<"'" <<
                                                             " failed in file: " << file << ":" << line <<
                                                             ": " << msg)
            {}
    };

    template<typename E, typename... Arg>
    inline void enforce(bool condition, Arg&&... arg)
    {
        if (!condition)
            throw E(std::forward<Arg&&>(arg)...);
    }
}

#ifndef GOODIES_ENFORCE_FAILURE_EXCEPTION
#define GOODIES_ENFORCE_FAILURE_EXCEPTION goodies::EnforceFailedError
#endif

#define ENFORCE(cond,msg) \
  goodies::enforce<GOODIES_ENFORCE_FAILURE_EXCEPTION>((cond), #cond,__FILE__,__LINE__,goodies::MakeString()<<msg)


#endif
