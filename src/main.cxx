#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main(void)
{
	std::string line;
	std::ifstream log_file("./data/Apache.log");

	std::regex pattern(R"(\[(.*?)\]\s+\[(.*?)\]\s+\[client\s+([\d\.]+)\]\s+(.*?):\s+(.*))");

	std::smatch match;
	
	for(int i = 0; i < 100; i++)
	{
		std::getline(log_file, line);

		if (std::regex_search(line, match, pattern)) 
		{
		    std::string datetime = match[1];
		    std::string level = match[2];
		    std::string ip = match[3];
		    std::string message = match[4];
		    std::string path = match[5];

		    std::cout << ip << std::endl;
		}		
	}

	log_file.close();

	return 0;
}