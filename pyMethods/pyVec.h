#pragma once

#include <string>
#include <vector>
#include <sstream>
using namespace std;

namespace pym
{
	template<typename T>
	class PyVector
	{
		vector<T> vecInput;
	public:



		PyVector(vector<T>other)
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

}

