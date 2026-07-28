# Asymptotic Notation

The efficiency of an algorithm depends on the amount of time, storage and other resources required to execute the algorithm. The efficiency is measured with the help of asymptotic notations.

An algorithm may not have the same performance for different types of inputs. With the increase in the input size, the performance will change.

The study of change in performance of the algorithm with the change in the order of the input size is defined as asymptotic analysis.

## Big O Notation

The Big O notation can be used to describe how the running time of an algorithm scales with the growth of the input size, ignoring implementation details such as programming language and computer speed. Specifically, it denotes the upper bound of the growth rate of a function that relates the running time of an algorithm to its input size. It can be used to compare algorithms and determine which one is better.

## Big Theta Notation

If a function has the same Big O and Big Omega, they also become the function's Big Theta. Big Theta is used to describe the exact growth rate of a function. It is denoted by the symbol Θ.

## Big Omega Notation

The Big Omega notation is similar to the Big O notation. The only difference is that it denotes the lower bound on the growth rate of a function.

## Small O

Small o notation, denoted as o(g(n)), defines an upper bound on the growth of a function f(n) that is not asymptotically tight. 
In simpler terms, f(n) is o(g(n)) if, for any positive constant c, there exists a value n₀ such that f(n) is strictly less than c*g(n) for all n greater than n₀. 
This means that g(n) grows strictly faster than f(n) as n approaches infinity.

## Small Omega

Small Omega (ω) notation is used to describe a lower bound on the growth rate of a function. 
Specifically, it indicates that a function g(n) grows strictly slower than another function f(n) as n approaches infinity. 
This means that for any constant c > 0, there exists a value n₀ such that _g(n) < c_f(n)* for all n > n₀. 
In simpler terms, f(n) is a strict lower bound for g(n).
