#pragma once
#include <string>
#include <vector>
#include "pyVec.h"
using namespace std;
namespace pym
{
	class String
	{
		string word;
	public:

		String(string other)
		{
			word = other;
		}


		vector<string> split(string delim)
		{
			vector<string> splitList;
			size_t rn = 0, prev = 0;
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

		bool startswith(string str)
		{
			return word.substr(0, str.length()) == str;
		}


		bool endswith(string str)
		{
			return word.substr(word.length() - str.length(), word.length()) == str;
		}

		string replace(string prev, string next)
		{
			pym::String other(word);
			pym::Vector<string> exc(other.split(prev));

			return exc.join(next);


		}
		
		/*string operator <<(pym::String& other)
		{
			return other.word;
		}*/
	};


	


};