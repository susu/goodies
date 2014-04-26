#ifndef GOODIES_MAKE_UNIQUE_HPP_INC
#define GOODIES_MAKE_UNIQUE_HPP_INC

#include <memory>

namespace std
{
  template<typename T, typename... Args>
  std::unique_ptr<T> make_unique(Args&&... args)
  {
    static_assert(std::is_array<T>::value == false,
                  "This version of make_unique cannot be applied to arrays");
    return std::unique_ptr<T>(new T(std::forward<Args&&>(args)...));
  }
}

#endif
