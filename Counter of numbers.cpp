#include <iostream>
#include <vector>

class Counternum {
private:
    size_t sum;
    size_t count;

public:
    Counternum() : sum(0), count(0) {}

    void operator()(int value) {
        if (value % 3 == 0) {
            sum += value;
            ++count;
        }
    }
    size_t get_sum() const { return sum; }
    size_t get_count() const { return count; }
};

int main() {
    std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };
    Counternum counter;
    std::cout << "[IN]: ";

    for (int n : numbers) {
        std::cout << n << " ";
        counter(n);
    }
    std::cout << std::endl;

    std::cout << "[OUT]: get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << counter.get_count() << std::endl;
    return 0;
}