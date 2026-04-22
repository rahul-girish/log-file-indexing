#include <iostream>
#include <fstream>
#include <string>

#include "tokenize.hxx"
#include "InvertedIndex.hxx"



int main(void)
{
	
	std::string s = "Hello world 123 ABC $6%";
	std::vector<std::string> words = tokenize(s);

	for(size_t i = 0; i < words.size(); i++)
		std::cout << words[i] << std::endl;

	InvertedIndex index;
	for(size_t i = 0; i < words.size(); i++)
	{
		index.add(words[i], 1);
		index.add(words[i], 2);
		index.add(words[i], 3);
	}

	print(index);
	
	index.merge();

	std::cout << "After merging" << std::endl;
	print(index);

	
	return 0;
}

