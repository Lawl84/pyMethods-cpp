#pragma once

#include <string>
#include <vector>
#include <sstream>


namespace pym
{
    template<typename T>
    class Vector
    {
    public:
        std::vector<T> vecInput;




        Vector(std::vector<T>other)
        {
            vecInput = other;
        }


        std::string join(std::string joiner)
        {
            std::string output;
            for (T& i : vecInput)
            {
                std::stringstream ss;
                ss << i;
                output += ss.str();
                output += joiner;
            }
            return output.substr(0, output.length() - joiner.length());
        }

        std::vector<T> reverse()
        {
            std::vector<T> vOutput(this->vecInput.size());
            if (this->vecInput.size() > 1)
            {
                for (int i = this->vecInput.size() - 1; i >= 0; i--)
                {
                    vOutput.push_back(this->vecInput[i]);
                }
            }
            else
                throw std::runtime_error("Reversing this vector is useless.");
            return vOutput;
        }

        friend std::ostream& operator<<(std::ostream& out, pym::Vector<T>& other)
        {
            out << "{" << other.join(",") << "}";
            return out;
        }

    };

}