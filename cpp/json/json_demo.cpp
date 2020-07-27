#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using nlohmann::json;

int main()
{
	std::ifstream i("file.json");
	json j;
	i>>j;
	double d=j["pi"];
	bool bl = j["happy"];
	std::string name=j["name"];
	std::cout<<d <<","<<bl<<","<<name<<std::endl;
	return 0;
}
