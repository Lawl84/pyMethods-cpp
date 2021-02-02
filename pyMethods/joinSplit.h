#pragma once
#include <string>
#include <vector>
#include <sstream>
using namespace std;

template<typename T>
class Pyjoin
{
public:

	vector<T> vecInput;

	Pyjoin(vector<T>& other)
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

	vector<T> split(string delim)
	{

	}
};


