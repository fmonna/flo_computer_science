#include "array_cpp.h"

#include <cstdio>
#include <vector>

void Array::push(int value) {
    data_.push_back(value);
}

int Array::get(std::size_t index) const {
    // std::vector::at() does the bounds check for us and throws
    // std::out_of_range, the C++ analogue of C's exit(1) / Rust's panic.
    return data_.at(index);
}

void Array::set(std::size_t index, int value) {
    data_.at(index) = value;
}

std::size_t Array::len() const {
    return data_.size();
}

void Array::print() const {
    std::printf("[");
    for (std::size_t i = 0; i < data_.size(); i++) {
        std::printf("%d%s", data_[i], (i + 1 < data_.size()) ? ", " : "");
    }
    std::printf("]\n");
}

/* --- demo: same as the C/Python/Rust examples ---------------------------- */
int main() {
    Array a;
    a.push(10);
    a.push(20);
    a.push(30);
    a.print();                       // [10, 20, 30]

    std::printf("%d\n", a.get(1));   // 20

    a.set(1, 99);
    a.print();                       // [10, 99, 30]

    std::printf("%zu\n", a.len());   // 3
}
