#include "search_naive.hxx"

std::vector<size_t> search_naive(const std::string &str, const std::string &pattern)
{
    std::vector<size_t> indices;

    if(str.size() < pattern.size())
        return indices;

    for(size_t i = 0; i < (str.size() - pattern.size()) + 1; i++)
    {
        size_t j = 0;

        while(j < pattern.size() && str[i + j] == pattern[j])
        {
            j++;
        }

        if(j == pattern.size())
        {
            indices.push_back(i);
        }
    }

    return indices;
}