#include <iostream>
#include <vector>

template <typename T>
T square(T value) {
    return value * value;
}

template <typename T>
void squaring(std::vector<T>& vec) {
    for (auto& elem : vec) {
        elem = square(elem);
    }
}

int main() {
    int x = 4;
    std::cout << "[IN]: " << x << std::endl;
    std::cout << "[OUT]: " << square(x) << std::endl;

    std::vector<int> v = { -1, 4, 8 };
    std::cout << "[IN]: ";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i != v.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    squaring(v);
    std::cout << "[OUT]: ";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i != v.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}