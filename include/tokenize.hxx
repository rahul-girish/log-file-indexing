#pragma once

#include <vector>
#include <string>

/**
 *  str_to_lower
 *  Convert a string to lowercase.
 */

static inline void str_to_lower(std::string& str)
{
    for(size_t i = 0; i < str.length(); i++)
    {
        str[i] = std::tolower(static_cast<unsigned char>(str[i]));
    }
}

/**
 *  str_remove_non_alnum
 *  Remove all non-alnum, i.e. special, characters from a string.
 */

static inline void str_remove_non_alnum(std::string& str)
{
    for(size_t i = 0; i < str.length(); i++)
    {
        if(!std::isalnum(static_cast<unsigned char>(str[i])))
        {
            str[i] = ' ';
        }
    }
}

/**
 *  tokenize
 *  Convert a string into a list of words.
 *  All uppercase letters become lowercase.
 *  Special characters are removed.
 */
std::vector<std::string> tokenize(const std::string& line);