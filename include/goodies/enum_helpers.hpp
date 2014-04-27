#ifndef GOODIES_ENUM_HELPERS_HPP_INC
#define GOODIES_ENUM_HELPERS_HPP_INC

#include <type_traits>
#include <set>
#include <string>
#include <sstream>

namespace goodies
{
    template<typename T>
    auto to_underlying_cast(T value) -> typename std::underlying_type<T>::type
    {
      return static_cast<typename std::underlying_type<T>::type>(value);
    }

    template<typename T>
    T from_underlying_cast(typename std::underlying_type<T>::type value)
    {
      return static_cast<T>(value);
    }

    template<typename T>
    std::string flagsetToString(const std::set<T> & flagset)
    {
        static_assert(std::is_enum<T>::value == true, "T must be enum!");
        std::ostringstream os;
        os << "{";
        for (auto flag : flagset)
        {
            os << flag << ", ";
        }
        os << "}";
        return std::move(os.str());
    }

    template<typename T>
    auto flagsetToValue(const std::set<T> & flagset) -> typename std::underlying_type<T>::type
    {
        typename std::underlying_type<T>::type ret = 0;
        for (auto flag : flagset)
            ret |= to_underlying_cast(flag);
        return ret;
    }


}

#endif
