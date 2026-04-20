#include <iostream>
#include <fstream>
#include <string>
#include "tokenize.hxx"

int main(void)
{
	std::string s = "Hello world 123 ABC $6%";
	std::vector<std::string> words = tokenize(s);

	for(size_t i = 0; i < words.size(); i++)
		std::cout << words[i] << std::endl;

	return 0;
}