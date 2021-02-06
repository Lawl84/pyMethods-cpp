#pragma once

#include <string>
#include <vector>
#include <sstream>

namespace pym
{
	template<typename T>
	class Vector
	{
		std::vector<T> vecInput;
	public:



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
	};

}

