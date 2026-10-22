#include <iostream>
#include <vector>
#include <stdexcept>

template <class T>
class Table {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    Table(size_t r, size_t c) : rows(r), cols(c) {
        if (r == 0 || c == 0) {
            throw std::out_of_range("Размеры таблицы должны быть больше нуля");
        }
        data = std::vector<std::vector<T>>(r, std::vector<T>(c));
    }

    std::vector<T>& operator[](size_t i) {
        if (i >= rows) {
            throw std::out_of_range("Индекс строки вне диапазона");
        }
        return data[i];
    }

    const std::vector<T>& operator[](size_t i) const {
        if (i >= rows) {
            throw std::out_of_range("Индекс строки вне диапазона");
        }
        return data[i];
    }

    size_t Rows() const {
        return rows;
    }

    size_t Cols() const {
        return cols;
    }
};

int main() {
    auto mas = Table<int>(2, 3);
    mas[0][0] = 4;
    std::cout << "mas[0][0] = " << mas[0][0] << std::endl;

    mas[1][6] = 10;
    std::cout << "mas[1][1] = " << mas[1][1] << std::endl;

    std::cout << "Размер таблицы: " << mas.Rows() << " x " << mas.Cols() << std::endl;

    const auto const_mas = mas;
    std::cout << "const_test[0][0] = " << const_mas[0][0] << std::endl;;

    return 0;
}