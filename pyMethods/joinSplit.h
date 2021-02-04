#pragma once

#include <string>
#include <vector>
#include <sstream>
using namespace std;

template<typename T>
class PyVector
{
public:

	vector<T> vecInput;

	PyVector(vector<T>& other)
	{
		vecInput = other;
	}

	string join(string joiner)
	{
		string output;
		for (T& i : vecInput)
		{
			stringstream ss;
			ss << i;
			output += ss.str();
			output += joiner;
		}
		return output.substr(0, output.length() - joiner.length());
	}
};

class PyString
{
public:
	string word;
	PyString(string& other)
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


};

