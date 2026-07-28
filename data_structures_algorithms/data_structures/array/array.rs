//! A dynamic array of ints.
//!
//! `Vec<i32>` is Rust's contiguous, growable array: it owns a single heap
//! slab, grows amortised-O(1) on `push`, drops its storage automatically when
//! it goes out of scope (no `free` needed), and bounds-checks every index
//! access — panicking on out-of-bounds, the Rust analogue of C's exit(1).
//!
//! This struct is a thin wrapper so the API matches the C/C++/Python examples;
//! in real Rust you'd use `Vec` directly.

struct Array {
    data: Vec<i32>,
}

impl Array {
    fn new() -> Self {
        Array { data: Vec::new() }
    }

    fn push(&mut self, value: i32) {
        self.data.push(value);
    }

    /// Panics if `index` is out of bounds.
    fn get(&self, index: usize) -> i32 {
        self.data[index]
    }

    /// Panics if `index` is out of bounds.
    fn set(&mut self, index: usize, value: i32) {
        self.data[index] = value;
    }

    fn len(&self) -> usize {
        self.data.len()
    }

    fn print(&self) {
        println!("{:?}", self.data);
    }
}

fn main() {
    let mut a = Array::new();
    a.push(10);
    a.push(20);
    a.push(30);
    a.print();              // [10, 20, 30]

    println!("{}", a.get(1));   // 20

    a.set(1, 99);
    a.print();              // [10, 99, 30]

    println!("{}", a.len());    // 3
}
