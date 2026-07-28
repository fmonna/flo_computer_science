# Hello World

## Rust (standalone file)
Enter the following commands to compile and run the file

$ rustc main_rs.rs
$ ./main_rs
Hello, world!

## Rust (Cargo project)
The same program lives in `hello_cargo/` as a Cargo-managed project, which is
how real Rust code is built. From inside that directory:

$ cargo run
   Compiling hello_cargo v0.1.0
    Finished dev [unoptimized + debuginfo] target(s) in 0.0s
     Running `target/debug/hello_cargo`
Hello, world!

The two `main.rs` files are identical; the point of keeping both is the contrast
between invoking the compiler by hand (`rustc`) and letting the package manager
(`cargo`) handle the build.
