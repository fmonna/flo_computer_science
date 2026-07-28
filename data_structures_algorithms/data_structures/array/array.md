# Array

Arrays store elements in contiguous memory locations, resulting in easily
calculable addresses for the elements stored, which allows faster access to an
element at a specific index.

This folder implements a **dynamic** (growable) array of ints in a few languages.
Each version exposes the same API and runs the same demo, printing:

```
[10, 20, 30]
20
[10, 99, 30]
3
```

## Common API

| operation | meaning |
|-----------|---------|
| `new`     | create an empty array |
| `push(v)` | append `v` (amortised O(1)) |
| `get(i)`  | read element at index `i` (O(1), bounds-checked) |
| `set(i,v)`| write `v` at index `i` (O(1), bounds-checked) |
| `len`     | number of elements held |
| `print`   | display as `[a, b, c]` |

Out-of-bounds access is fatal in every version: C `exit(1)`, C++ throws
`std::out_of_range`, Python raises `IndexError`, Rust panics.

## Build & run

```sh
# C
cc array.c -o array && ./array

# C++
c++ array_cpp.cpp -o array_cpp && ./array_cpp

# Python
python3 array.py

# Rust (standalone file, no Cargo needed)
rustc array.rs -o array_rs && ./array_rs
```

## What each language contributes

- **C** — the reference: the contiguous slab, the `realloc`-based growth, the
  manual bounds checks and the manual `free` are all written by hand. Everything
  the other three get from their standard library lives here in plain sight.
- **C++** — `std::vector` owns the slab, grows it and frees it (RAII); `.at()`
  supplies the bounds check.
- **Python** — `list` is the slab (of pointers); bounds checks are built into
  `__getitem__`.
- **Rust** — `Vec` owns the slab, grows it and drops it; indexing panics on
  out-of-bounds. Ownership makes the `free` step automatic and verifiable.
