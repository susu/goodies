#ifndef GOODIES_ENUM_HELPERS_HPP_INC
#define GOODIES_ENUM_HELPERS_HPP_INC

#include <type_traits>
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
}

#endif
