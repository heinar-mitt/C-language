#include "../include/assignment2.hpp"
#include <typeinfo>
#include <type_traits>
#include <functional>
#include <vector>
#include <array>
#include <memory>
#include <iostream>

// Klassid
Homework::Tasks Homework::assignment2()
{
    using namespace std::literals;

    // Define constructors for classes A and B
    class A {
    public:
        A(int a) {}
    };
    
    class B {
    public:
        B(int b) {}
    };

    // Define struct D with members
    struct D {
        int a;
        int i;
    };

    // Define struct E with members and member functions
    struct E {
        int e;

        int get_number() const {
            return e;
        }

        void set_number(int new_number) {
            e = new_number;
        }
    };

    // Instantiate objects of A, B, D, and E
    A a(1);
    B b(2);
    D d{1, 2};
    D d1{};

    E eStruct;
    eStruct.e = 3;

    // Type checks and assignments
    Tasks results;
    results.reserve(32ull);

    results.push_back({"A is a class", (std::is_class_v<A>)});
    results.push_back({"B is a class", (std::is_class_v<B>)});
    results.push_back({"A is base of B", (std::is_base_of_v<A, B>)});
    results.push_back({"D is a class", (std::is_class_v<D>)});
    results.push_back({"D has member A", (std::is_member_object_pointer_v<decltype(&D::a)>)});
    results.push_back({"D has member int", (std::is_member_object_pointer_v<decltype(&D::i)>)});
    results.push_back({"E is a class", (std::is_class_v<E>)});
    results.push_back({"E has member function get_number", (std::is_member_function_pointer_v<decltype(&E::get_number)>)});
    results.push_back({"E has member function set_number", (std::is_member_function_pointer_v<decltype(&E::set_number)>)});
    results.push_back({"E's get_number is const", (std::is_same_v<decltype(&E::get_number), int (E::*)() const>)});

    results.push_back({"a is of type A", (std::is_same_v<decltype(a), A>)});
    results.push_back({"b is of type B", (std::is_same_v<decltype(b), B>)});
    results.push_back({"d is of type D", (std::is_same_v<decltype(d), D>)});
    results.push_back({"d1 is of type D", (std::is_same_v<decltype(d1), D>)});
    results.push_back({"e is of type E", (std::is_same_v<decltype(eStruct), E>)});

    results.push_back({"d1.i is 1", (d1.i == 1)});
    results.push_back({"e.get_number() is 3", (eStruct.get_number() == 3)});
    results.push_back({"e.set_number(5)", (eStruct.set_number(5), eStruct.get_number() == 5)});

    return results;
}
