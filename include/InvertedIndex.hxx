#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

/**
 *  InvertedIndex
 *  This class wraps around a std::unordered_map<std::string, std::vector<int>>
 *  Stores words along with the IDs of the lines they appear in.
 *  It also provides some useful methods.
 */

class InvertedIndex
{
private:
    std::unordered_map<std::string, std::vector<int>> index;
    std::unordered_map<std::string, std::unordered_set<int>> buffer;

public:
    /**
     *  add
     *  Adds an ID to the buffer for the corresponding token.
     */
    void add(const std::string& token, int logID);

    /**
     *  merge
     *  Merge buffer with index
     */
    void merge();

    friend void print(const InvertedIndex& index);
    friend void print(const std::unordered_set<int>& set);
};

/**
 *  print
 *  Print an std::unordered_set<int>.
 */
void print(const std::unordered_set<int>& set);

/**
 *  print
 *  Print an std::unordered_set<int>.
 */
void print(const std::vector<int>& vector);

/**
 *  print
 *  Print an InvertedIndex.
 */
void print(const InvertedIndex& index);

/**
 *  merge_and_dedup_vectors
 *  Merge two sorted vectors and remove duplicates.
 */
std::vector<int> merge_and_dedup_vectors(const std::vector<int>& vector1, const std::vector<int>& vector2); 