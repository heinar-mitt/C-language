#include "../include/assignment1.hpp"
#include <typeinfo>
#include <type_traits>
#include <functional>
#include <vector>
#include <array>
#include <memory>
#include <iostream>

// Määratle klass A
template <typename T>
class A
{
public:
    A(T value) : value(value) {}

    double get_power_of_2() const
    {
        return value * value;
    }

private:
    T value;
};

namespace Homework
{
    // Määratle lambda funktsioon lamall
    auto lamall = [](int a, int b) { return a + b; };

    // Määratle mallifunktsioon fun
    template <typename T1, typename T2>
    auto fun(T1 a, T2 b)
    {
        return a + b;
    }

    // Loo klassi A instants
    A<double> a(5.5);

    // Kasuta liikme funktsiooni get_power_of_2
    auto b = a.get_power_of_2();

    // Määra fun1 väärtuseks fun argumendiga 5 ja 6
    auto fun1 = fun(5, 6);

    // Mallid
    Homework::Tasks Homework::assignment1()
    {
        using namespace std::literals;

        // Kontrolli, et muutujad on õiget tüüpi ja väärtusega
        Tasks results;
        results.reserve(16ull);

        results.push_back({"lamall on lambda funktsioon", (std::is_class_v<decltype(lamall)>) && (std::is_invocable_v<decltype(lamall), int, int>)});
        results.push_back({"lamall tagastab argumendite summa", (lamall(1, 2) == 3)});

        results.push_back({"fun on mallifunktsioon", (std::is_function_v<decltype(fun<int, int>)>)});
        results.push_back({"fun1 väärtus on 30", (fun1 == 30)});

        results.push_back({"A on klass", (std::is_class_v<A<double>>)});
        results.push_back({"A-l on liikme funktsioon get_power_of_2", (std::is_member_function_pointer_v<decltype(&A<double>::get_power_of_2)>)});
        results.push_back({"A get_power_of_2 on const", (std::is_same_v<decltype(&A<double>::get_power_of_2), double (A<double>::*)() const>)});
        results.push_back({"a on tüübiga A", (std::is_same_v<decltype(a), A<double>>)});
        results.push_back({"b väärtus on 30.25", (b == 30.25)});

        return results;
    }
}
