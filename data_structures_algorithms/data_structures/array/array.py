"""A dynamic array of ints.

Python's built-in ``list`` is already a dynamic array: a contiguous array of
pointers to PyObject that grows amortised-O(1) on ``append``. This class is a
thin wrapper that mirrors the API of the C/C++/Rust examples so they can be
read side by side; in real Python you would just use a ``list`` directly.

Out-of-bounds access raises ``IndexError`` — the Python analogue of C's exit(1)
or Rust's panic.
"""

from __future__ import annotations


class Array:
    def __init__(self) -> None:
        self._data: list[int] = []

    def push(self, value: int) -> None:
        self._data.append(value)

    def get(self, index: int) -> int:
        return self._data[index]  # raises IndexError if index >= len

    def set(self, index: int, value: int) -> None:
        self._data[index] = value  # raises IndexError if index >= len

    def len(self) -> int:
        return len(self._data)

    def print(self) -> None:
        print(self._data)


# --- demo: same as the C/C++/Rust examples --------------------------------
if __name__ == "__main__":
    a = Array()
    a.push(10)
    a.push(20)
    a.push(30)
    a.print()          # [10, 20, 30]

    print(a.get(1))    # 20

    a.set(1, 99)
    a.print()          # [10, 99, 30]

    print(a.len())     # 3
