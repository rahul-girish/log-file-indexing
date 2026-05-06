#include "search_kmp.hxx"

std::vector<size_t> search_kmp(const std::string& str, const std::string& pattern)
{
    size_t i = 0, j = 0;

    std::vector<size_t> lps(pattern.size());
    std::vector<size_t> result;

    compute_lps(pattern, lps);    

    while(i < str.size())
    {
        if(str[i] == pattern[j])
        {
            i++;
            j++;

            if(j == pattern.size())
            {
                result.push_back(i - j);
                j = lps[j - 1];
            }
        }
        else
        {
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return result;
}