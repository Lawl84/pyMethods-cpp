#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


namespace pym
{
	template <typename T>
	class File
	{
	public:
		std::string filename;



 
		File(std::string filename)
		{
			this->filename = filename;
		}

		std::vector<T> readlines()
		{
			std::vector<T> vOut;
			std::ifstream f(this->filename);
			T in;
			while (std::getline(f, in))
			{
				vOut.push_back(in);
			}
			return vOut;
			
		}
		std::vector<T> read()
		{
			std::vector<T> vOut;
			std::ifstream f(this->filename);
			T in;
			while (f >> in)
			{
				vOut.push_back(in);
			}
			return vOut;
		}

		
		void write(const T& contents)
		{
			std::ofstream f(this->filename);
			
			f << contents;
		}


		void writelines(std::vector<T> contents)
		{
			std::ofstream f(this->filename);
			for (T& i : contents)
			{
				f << i << "\n";
			}
		}

		void close()
		{
			std::ofstream f(this->filename);
			f.close();
		}

	};
}