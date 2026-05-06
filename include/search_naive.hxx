#pragma once

#include <string>
#include <vector>

/**
 *  search_naive
 *  Return the indices of all occurances of pattern withing string
 *  Uses brute force.
 */
std::vector<size_t> search_naive(const std::string &str, const std::string &pattern);