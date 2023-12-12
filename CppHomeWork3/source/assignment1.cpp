#include "../include/assignment1.hpp"
#include <typeinfo>
#include <type_traits>
#include <functional>
#include <vector>
#include <array>
#include <memory>
#include <iostream>
class A {};
// Lambda funktsioonid
Homework::Tasks Homework::assignment1()
{
    using namespace std::literals;

    // Loo el nimeline argumentideta lambda funktsioon
    auto el = []() {};

    // Loo ilr1 nimeline lambda funktsioon, 
    // mis võtab argumendiks 2 inti (i, j) ja tagastab nende summa
    auto ilr1 = [](int i, int j) {return i+j;};

    // Loo irl2 nimeline lambda funktsioon, 
    // mis võtab argumendiks int viida (i) ja suurendab seda 1 võrra
    auto ilr2 = [](int& i) { ++i; };
    

    // Kontroll, et muutujad on õiget tüüpi ja väärtusega
    Tasks results;
    results.reserve(16ull);

    results.push_back({"el is a lambda", (std::is_class_v<decltype(el)>) && (std::is_invocable_v<decltype(el)>) });
    results.push_back({"ilr1 is lambda", (std::is_class_v<decltype(ilr1)>) && (std::is_invocable_v<decltype(ilr1), int, int>) });
    results.push_back({"ilr1 returns sum of its args", (ilr1(1, 2) == 3)});
    results.push_back({"ilr2 is lambda", (std::is_class_v<decltype(ilr2)>) && (std::is_invocable_v<decltype(ilr2), int&>) });
    int il{ 5 };
    results.push_back({"ilr2 increases given number", (ilr2(il), il == 6)});

    return results;
}

