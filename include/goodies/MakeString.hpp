#ifndef GOODIES_MAKESTRING_HPP_INC
#define GOODIES_MAKESTRING_HPP_INC

#include <sstream>
#include <algorithm>

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

    // TODO maybe not the best place
    inline std::string toUpper(std::string str)
    {
        std::transform(str.begin(), str.end(), str.begin(), [](char c){ return std::toupper(c); });
        return str;
    }

}

#endif
