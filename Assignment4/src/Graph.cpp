/**
 * @file Graph.cpp
 * @author Trevor Morris (00876703)
 * @brief Compiled with clang++ using CMake. Should work with any compiler.
 * 
 */


#include "Graph.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>

bool Graph::loadCityInformation(const char* filename)
{
    auto split = [](std::string string, std::string delimiter)
	{
		std::vector<std::string> out;
		size_t position = 0;
		std::string token;
		while ((position = string.find(delimiter)) != std::string::npos)
		{
			out.push_back(string.substr(0, position));
			string.erase(0, position + delimiter.length());
		}
		
		out.push_back(string);
		return out;
	};

    std::ifstream file;
    file.open(filename);
	if(!file.is_open())
		return false;

	std::stringstream loadedFile;
	loadedFile << file.rdbuf();

	std::string line;
	while(std::getline(loadedFile, line))
	{
		std::vector<std::string> temp = split(line, " ");
		if(temp[0].compare("p") == 0)
		{
			this->cityCoordinates.push_back(Point3D(std::atof(temp[1].c_str()), std::atof(temp[2].c_str()), std::atof(temp[3].c_str())));
		}
		else if(temp[0].compare("c") == 0)
		{
			this->cityIndices.push_back(std::atoi(temp[1].c_str()));
			this->cityIndices.push_back(std::atoi(temp[2].c_str()));
			this->cityIndices.push_back(std::atoi(temp[3].c_str()));
		}
		else
			continue;
	}

	return true;
}

void Graph::Generate()
{
	auto connect = [this](int i, int j)
	{
		auto elementI = this->Connectivity.find(i);
		if(elementI != this->Connectivity.end())
		{
			elementI->second.insert(j);
		}
		else
		{
			std::set<int> con;
			con.insert(j);
			this->Connectivity.insert(std::make_pair(i, con));
		}

		auto elementJ = this->Connectivity.find(j);
		if(elementJ != this->Connectivity.end())
		{
			elementJ->second.insert(i);
		}
		else
		{
			std::set<int> con;
			con.insert(i);
			this->Connectivity.insert(std::make_pair(j, con));
		}
	};

	for(int i = 0; i < this->cityIndices.size() / 3; i++)
	{
		connect(this->cityIndices[3 * i], this->cityIndices[3 * i + 1]);
		connect(this->cityIndices[3 * i], this->cityIndices[3 * i + 2]);
	}
}

void Graph::Print()
{
	for (auto pair: this->Connectivity)
	{
		std::cout << "[" << pair.first << " ]";
		for(auto value: pair.second)
		{
			std::cout << value << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::showConnectivity(int a)
{
	std::cout << "Showing Connectivity info for Node " << a << " :" << std::endl;
	for (auto idx: this->Connectivity[a])
	{
		std::cout << "[" << a << "-" << idx << " ]:";
		Point3D pA = this->cityCoordinates[a];
		Point3D pB = this->cityCoordinates[idx];
		std::cout << sqrt(pB.subtractPoints(pA).squarePoint()) << std::endl;
	}
}