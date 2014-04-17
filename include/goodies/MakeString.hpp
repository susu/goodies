#ifndef GOODIES_MAKESTRING_HPP_INC
#define GOODIES_MAKESTRING_HPP_INC

#include <sstream>

namespace goodies
{
    class MakeString
    {
        public:
            template<typename T>
            MakeString& operator<<(const T& value)
            {
                m_out << value;
                return *this;
            }

            operator std::string() const
            {
                return m_out.str();
            }

        private:
            std::ostringstream m_out;
    };
}

#endif
