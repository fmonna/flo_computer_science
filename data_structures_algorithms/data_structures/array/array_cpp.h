#ifndef ARRAY_CPP_H
#define ARRAY_CPP_H

#include <cstddef>
#include <vector>

/*
 * A dynamic array of ints. Where the C version hand-rolls the contiguous
 * storage and the growth logic, std::vector provides both: it owns a single
 * contiguous slab, grows it amortised-O(1) on push_back, and frees it in its
 * destructor (RAII, so there is no `array_free` here). This class is a thin
 * wrapper that mirrors the C API so the two can be read side by side.
 */
class Array {
public:
    Array() = default;

    void        push(int value);
    int         get(std::size_t index) const;     // throws std::out_of_range
    void        set(std::size_t index, int value);// throws std::out_of_range
    std::size_t len() const;
    void        print() const;

private:
    std::vector<int> data_;
};

#endif // ARRAY_CPP_H
