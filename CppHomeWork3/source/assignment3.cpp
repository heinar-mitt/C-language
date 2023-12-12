#include "../include/assignment3.hpp"
#include <typeinfo>
#include <type_traits>
#include <functional>
#include <vector>
#include <array>
#include <memory>
#include <iostream>

namespace Homework {

    // Definition for class Op
    class Op {
        float number;

    public:
        // Default constructor
        Op() : number(0.0) {}

        // Constructor with float argument
        Op(float i) : number(i) {}

        // Copy constructor
        Op(const Op& other) : number(other.number) {}

        // Move constructor
        Op(Op&& other) noexcept : number(std::exchange(other.number, 0.0)) {}

        // Copy assignment operator
        Op& operator=(const Op& other) {
            if (this != &other) {
                number = other.number;
            }
            return *this;
        }

        // Move assignment operator
        Op& operator=(Op&& other) noexcept {
            if (this != &other) {
                number = std::exchange(other.number, 0.0);
            }
            return *this;
        }

        // Comparison operators
        bool operator==(const Op& other) const {
            return number == other.number;
        }

        bool operator!=(const Op& other) const {
            return !(*this == other);
        }

        // Less than operator
        bool operator<(const Op& other) const {
            return number < other.number;
        }

        // Destructor
        ~Op() = default;
    };

    // Definition for class Default
    class Default {
        int value;

    public:
        // Default constructor
        Default() : value(0) {}

        // Constructor with int argument
        Default(int i) : value(i) {}

        // Copy constructor
        Default(const Default& other) : value(other.value) {}

        // Move constructor (not allowed)
        Default(Default&&) = delete;

        // Copy assignment operator
        Default& operator=(const Default& other) {
            if (this != &other) {
                value = other.value;
            }
            return *this;
        }

        // Move assignment operator (not allowed)
        Default& operator=(Default&&) = delete;

        // Comparison operators
        bool operator==(const Default& other) const {
            return value == other.value;
        }

        bool operator!=(const Default& other) const {
            return !(*this == other);
        }

        // Less than operator
        bool operator<(const Default& other) const {
            return value < other.value;
        }

        // Destructor
        ~Default() = default;
    };

    using Tasks = std::vector<std::pair<std::string, bool>>;

    // Assignment3 function
    Tasks assignment3() {
        // Creating objects for testing
        Default a;
        Default b(1);
        Default c(b);
        Op d;
        Op e(1.f);

        // Testing
        Tasks results;

        results.push_back({"Default is class", (std::is_class_v<Default>)});
        results.push_back({"Default is default constructed", (std::is_default_constructible_v<Default>)});
        results.push_back({"Default is copy constructable", (std::is_copy_constructible_v<Default>)});
        results.push_back({"Default is copy assignable", (std::is_copy_assignable_v<Default>)});
        results.push_back({"Default is not move constructable", (!std::is_move_constructible_v<Default>)});
        results.push_back({"Default is not move assignable", (!std::is_move_assignable_v<Default>)});
        results.push_back({"Default is destructable", (std::is_destructible_v<Default>)});
        results.push_back({"Default is equality comparable", (a == b)});
        results.push_back({"Default is less than comparable", (a < b)});

        results.push_back({"a is of type Default", (std::is_same_v<decltype(a), Default>)});
        results.push_back({"b is of type Default", (std::is_same_v<decltype(b), Default>)});
        results.push_back({"c is of type Default", (std::is_same_v<decltype(c), Default>)});
        results.push_back({"a == a", (a == a)});
        results.push_back({"a != b", (a != b)});
        results.push_back({"a < b", (a < b)});
        results.push_back({"c == b", (c == b)});

        results.push_back({"Op is class", (std::is_class_v<Op>)});
        results.push_back({"Op is default constructed", (std::is_default_constructible_v<Op>)});
        results.push_back({"Op is copy constructable", (std::is_copy_constructible_v<Op>)});
        results.push_back({"Op is copy assignable", (std::is_copy_assignable_v<Op>)});
        results.push_back({"Op is move constructable", (std::is_move_constructible_v<Op>)});
        results.push_back({"Op is move assignable", (std::is_move_assignable_v<Op>)});
        results.push_back({"Op is destructable", (std::is_destructible_v<Op>)});
        results.push_back({"Op is equality comparable", (d == e)});
        results.push_back({"Op is less than comparable", (d < e)});
        results.push_back({"d is of type Op", (std::is_same_v<decltype(d), Op>)});
        results.push_back({"e is of type Op", (std::is_same_v<decltype(e), Op>)});
        results.push_back({"d == d", (d == d)});
        results.push_back({"d != e", (d != e)});
        results.push_back({"d < e", (d < e)});

        return results;
    }

}  // namespace Homework


//Tegin kõik inglise keelde, et oleks lihtsam arusaada. 