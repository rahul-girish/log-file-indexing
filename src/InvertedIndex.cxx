#include "InvertedIndex.hxx"
#include <algorithm>

void InvertedIndex::add(const std::string& token, int logID)
{
    buffer[token].insert(logID);
}

void InvertedIndex::merge()
{
    for(std::unordered_map<std::string, std::unordered_set<int>>::iterator i = buffer.begin(); i != buffer.end(); i++)
    {
        std::string token = i->first;
        std::unordered_set<int>& set = i->second;

        std::vector<int> buffer_vector(set.begin(), set.end());

        std::sort(buffer_vector.begin(), buffer_vector.end());

        std::vector<int>& index_vector = index[token];

        std::vector<int> merged_vector = merge_and_dedup_vectors(index_vector, buffer_vector);

        index_vector = std::move(merged_vector);

        set.clear();     
    }

    buffer.clear();
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

void print(const std::vector<int>& vector)
{
    bool first = true;
    std::cout << "{";

    for(std::vector<int>::const_iterator i = vector.begin(); i != vector.end(); i++)
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

    std::cout << "Buffer:" << std::endl;
    for (std::unordered_map<std::string, std::unordered_set<int>>::const_iterator i = buffer.begin(); i != buffer.end(); i++)
    {
        std::cout << "\"" << i->first << "\" : "; 
        print(i->second); 
        std::cout << std::endl;
    }

    const std::unordered_map<std::string, std::vector<int>>& storage = index.index;

    std::cout << "Index:" << std::endl;
    for (std::unordered_map<std::string, std::vector<int>>::const_iterator i = storage.begin(); i != storage.end(); i++)
    {
        std::cout << "\"" << i->first << "\" : "; 
        print(i->second); 
        std::cout << std::endl;
    }
}

std::vector<int> merge_and_dedup_vectors(const std::vector<int>& vector1, const std::vector<int>& vector2)
{
    std::vector<int> result;

    if(vector1.empty() && vector2.empty())
        return result;

    result.reserve(vector1.size() + vector2.size());

    size_t i = 0, j = 0;

    if(!(vector1.empty() || vector2.empty()))
    {

        if(vector1[i] < vector2[j])
        {
            result.push_back(vector1[i]);
            i++;
        }
        else
        {
            result.push_back(vector2[j]);
            j++;
        }

        while(i < vector1.size() && j < vector2.size())
        {
            if(vector1[i] < vector2[j])
            {
                if(result.back() != vector1[i])
                    result.push_back(vector1[i]);
                i++;
            }
            else if(vector2[j] < vector1[i])
            {
                if(result.back() != vector2[j])
                    result.push_back(vector2[j]);
                j++;
            }
            else
            {
                if(result.back() != vector1[i])
                    result.push_back(vector1[i]);

                i++;
                j++;
            }
        }
    }

    if (result.empty())
    {
        if (i < vector1.size())
            result.push_back(vector1[i++]);
        else if (j < vector2.size())
            result.push_back(vector2[j++]);
    }

    while(i < vector1.size())
    {
        if(result.back() != vector1[i])
            result.push_back(vector1[i]);
        i++;
    }

    while(j < vector2.size())
    {
        if(result.back() != vector2[j])
            result.push_back(vector2[j]);
        j++;
    }

    return result;
} 