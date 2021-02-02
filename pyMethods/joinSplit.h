#pragma once
#include <string>
#include <vector>
using namespace std;






class Pystr
{
public:
	vector<string>vecInput;

	Pystr(vector<string>& other)
	{
		vecInput = other;
	}

	string join(string joiner)
	{
		string outPut;
		for (string& item : vecInput)
		{
			outPut += item;
			outPut += joiner;
		}
		return outPut.substr(0, outPut.length() - joiner.length());
	}
};

class Pyint
{
public:
	vector<int>vecInput;

	Pyint(vector<int>& other)
	{
		vecInput = other;
	}

	string join(string joiner)
	{
		string output;
		for (int& i : vecInput)
		{
			output += to_string(i);
			output += joiner;
		}
		return output.substr(0, output.length() - joiner.length());
	}
};
