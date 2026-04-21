#include "InvertedIndex.hxx"

void InvertedIndex::add(const std::string& token, int logID)
{
    buffer[token].insert(logID);
}

void print(const std::unordered_set<int>& set)
{
    bool first = true;
    std::cout << "{";

    for(std::unordered_set<int>::const_iterator i = set.begin(); i != set.end(); i++)
    {
        if (!first)
            std::cout << ", ";
        std::cout << *i;
        first = false;
    }
    
    std::cout << "}";        
}

void print(const InvertedIndex& index)
{
    const std::unordered_map<std::string, std::unordered_set<int>>& buffer = index.buffer;

    for (std::unordered_map<std::string, std::unordered_set<int>>::const_iterator i = buffer.begin(); i != buffer.end(); i++)
    {
        std::cout << "\"" << i->first << "\" : "; 
        print(i->second); 
        std::cout << std::endl;
    }
}