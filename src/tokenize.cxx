#include "tokenize.hxx"
#include <sstream>
#include <cctype>

std::vector<std::string> tokenize(const std::string& str)
{
    std::vector<std::string> words;
    std::string line = str;

    str_to_lower(line);
    str_remove_non_alnum(line);

    std::stringstream ss(line);
    std::string word;
    char del = ' ';

    while (getline(ss, word, del))
    {
        if (!word.empty())
            words.push_back(word);
    }

    return words;
}