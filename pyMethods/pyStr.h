#pragma once
#include <string>
#include <vector>
#include "pyVec.h"
namespace pym
{
	class String
	{
		std::string word;
	public:

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

		friend std::ostream& operator<<(std::ostream& out, const pym::String& other)
		{
			out << other.word;
			return out;
		}
		
		
	};


	


};