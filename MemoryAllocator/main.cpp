#include <iostream>
#include <string>
#include <vector>
#include "ROSAllocator.hpp"

int main()
{
    std::string name1 = "foo";
    char test_string1[40] = "a different long string 1";
    
    ROSAllocator pool(name1);
    
    std::pmr::vector<std::pmr::string> vec{ &pool };
    
    vec.emplace_back(test_string1);
    
    return 0;
}
