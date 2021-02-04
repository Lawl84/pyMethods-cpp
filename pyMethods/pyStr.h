#pragma once
#include <string>
#include <vector>
using namespace std;

class PyString
{
	string word;
public:

	PyString(string other)
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


	


};