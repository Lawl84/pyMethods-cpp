#pragma once
#include <string>
#include <vector>
#include "pyVec.h"
namespace pym
{
    class String
    {
    public:
        std::string word;


        String(std::string other)
        {
            word = other;
        }


        std::vector<std::string> split(std::string delim)
        {
            std::vector<std::string> splitList;
            std::size_t rn = 0, prev = 0;
            while (rn < word.length() && prev < word.length())
            {
                rn = word.find(delim, prev);

                if (rn == -1)
                {
                    rn = word.length();
                }
                splitList.push_back(word.substr(prev, rn - prev));
                prev = rn + delim.length();
            }

            return splitList;

        }

        bool startswith(std::string str)
        {
            return word.substr(0, str.length()) == str;
        }


        bool endswith(std::string str)
        {
            return word.substr(word.length() - str.length(), word.length()) == str;
        }

        std::string replace(std::string prev, std::string next)
        {
            pym::String other(word);
            pym::Vector<std::string> exc(other.split(prev));

            return exc.join(next);


        }

        bool isupper()
        {
            bool upper = true;
            for (int i = 0; i < word.length(); i++)
            {
                if (!(toupper(word[i]) == word[i]))
                {
                    upper = false;
                    break;
                }
            }
            return upper;
        }


        bool islower()
        {
            bool lower = true;
            for (int i = 0; i < word.length(); i++)
            {
                if (!(tolower(word[i]) == word[i]))
                {
                    lower = false;
                    break;
                }
            }
            return lower;
        }

        std::string upper()
        {
            std::vector<char> upperChar(word.length());
            for (int i = 0; i < word.length(); i++)
            {
                upperChar[i] = toupper(word[i]);
            }
            pym::Vector<char> uppVector(upperChar);
            return uppVector.join("");
        }

            
        std::string lower()
        {
            std::vector<char> lowerChar(word.length());
            for (int i = 0; i < word.length(); i++)
            {
                lowerChar[i] = tolower(word[i]);
            }
            pym::Vector<char> uppVector(lowerChar);
            return uppVector.join("");
        }


        friend std::ostream& operator<<(std::ostream& out, const pym::String& other)
        {
            out << other.word;
            return out;
        }


    };





};
