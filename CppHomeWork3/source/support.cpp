#include "../include/support.hpp"
#include <iostream>
#include <cassert>
#include <algorithm>

void Homework::test_assignment(std::string name, Assignment assignment) {
    
    auto print_list = [](const std::pair<std::string, bool>& answer) {
        std::cout << "  " << answer.first << ": " << 
            (answer.second ? "Success" : "Failure") << '\n';
    };

    auto test_results = assignment();

    std::cout << "TEST RESULTS: " << name << '\n';
    std::for_each(test_results.begin(), test_results.end(), print_list);
    std::cout << '\n';
}
