#include <iostream>
#include <string>
#include <vector>
#include "ROSAllocator.hpp"

PREALLOCATE<4000> buffer;

int main()
{
    std::string name1 = "foo";
    char test_string1[40] = "a different long string 1";
	
    ROSAllocator pool(name1, buffer.data(), buffer.size());
    
    std::pmr::vector<std::pmr::string> vec{ &pool };
    
    vec.emplace_back(test_string1);
    
    return 0;
}
