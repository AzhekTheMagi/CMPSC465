# CMPSC 465 Assignment 1

## Name: Anthony Vallin		PSU Username: aav5195

## Format Requirement

- Algorithms in pseudo code **MUST** be placed in code blocks/fences (5%), and use either the `cpp` or `java` syntax highlighter. 


- Algorithms should follow the pseudo code standard described in handout 1. (2%)
- Do NOT change the template except the answer portion. (5%)
- Formulas and equations should be in math mode using Latex math symbols. (5%)
  - Markdown math tutorial: http://tug.ctan.org/info/undergradmath/undergradmath.pdf 
  - Two ways to enter math mode:
    - Insert a pair of dollar signs: \$ your equations go here \$. This is the inline math mode.
    - Insert a pair of double-dollar signs: \$\$ your equations go here \$\$, which produces a standalone equation/formula set.
- Export your work to a **pdf** file for submission 

## Problem Set

### Problem 1

Design an algorithm in pseudo code for computing $\lfloor \sqrt n \rfloor$ for any positive integer $n$. Besides assignment and comparison, your algorithm may only use the four basic arithmetical operations, namely addition/subtraction/multiplication/division. 

#### Answer

```c++
Algorithm F(n) {
    // Computes Floor of sqrt(n)
    // Input: A nonnegative integer n
    // Output: Value of sqrt(n) 
    int x, y
    if n == 0 return 1
    else
        x <- n / 2  // Initial guess
        y <- x + 1  // Convergence factor
        while x != y do
                y <- x
                x <- (x + (n / x)) / 2
    return x
}
```



------

### Problem 2

Find `gcd(31415, 14142)` by applying the Euclid’s algorithm. Please show detailed steps. 

#### Answer

` gcd(14142, 3131) = gcd(3131, 1618) = gcd(1618, 1513) = gcd(1513, 105) = gcd(105, 43) =`

` gcd(43, 19) = gcd(19, 5) = gcd(5, 4) = gcd(4, 1) = gcd(1, 0) = 1 `

------

### Problem 3

Estimate how many times faster it will be to find `gcd(31415, 14142)` by the Euclid’s algorithm compared with the algorithm based on checking consecutive integers from `min{m, n}` down to `gcd(m, n)`. 

hint: to compare the performance, you may count the number of divisions each algorithm takes. 

#### Answer

Euclid's algorithm is


$$
(14142 * 2) / 10 \approx 2828
$$
times faster. Ten divisions occur in Euclid's algorithm compared to 28284 divisions for checking consecutive integers ( m = 14142 divisions, n = 14142 divisions).

### Problem 4

Describe the algorithm in pseudo code for finding the binary representation of a positive decimal integer.

Your code should be placed in a code block, for example:

```c++
Algorithm int2binary(num) {
  // finding the binary representation of a positive decimal integer
  // input: num - a positive decimal integer
  // ouput: Bin - an array of binary digits stroing the binary form of num
  // to be completed
}
```

#### Answer

```c++
Algorithm int2binary(num) {
  // finding the binary representation of a positive decimal integer
  // input: num - a positive decimal integer
  // ouput: Bin - an array of binary digits storing the binary form of num
  stack<int> r
  
  while num != 0 do
      r.push(num mod 2)
      num <- num / 2
  return r
}
```



------

### Problem 5

Describe how one can implement each of the following operations on an array so that the time it takes does not depend on the array’s size n.
a. Delete the $i$th element of an array ($1\leq i \leq n$).
b. Delete the $i$th element of a sorted array (the remaining array has to stay sorted, of course).

#### Answer

a. Swap the ith element with the last element in the array and reduce length of array by one. 
b. Replace the ith element with a value not found in the array, e.g., replace integer 2 in array to -1 in an array holding positive integers.

------

### Problem 6

If you have to solve the searching problem for a list of n numbers, how can you take advantage of the fact that the list is known to be sorted? Give separate answers for
a. lists represented as arrays.
b. lists represented as linked lists.

#### Answer

a. A binary search (half interval search) can be performed to search a sorted array. 

b. A linear search, checking consecutive nodes, can be used to take advantage of a sorted linked list. 

------

### Problem 7

Show the stack after each operation of the following sequence that starts with the empty stack:
`push(a), push(b), pop, push(c), push(d), pop`

#### Answer

a, ab, a, ac, acd, ac

------

### Problem 8

Show the queue after each operation of the following sequence that starts with the empty queue:
`enqueue(a), enqueue(b), dequeue, enqueue(c), enqueue(d), dequeue`

#### Answer

a, ab, b, bc, bcd, cd

------

### Problem 9:

For each of the following applications, indicate the most appropriate data structure:
a. answering telephone calls in the order of their known priorities
b. sending backlog orders to customers in the order they have been received
c. implementing a calculator for computing simple arithmetical expressions

#### Answer

a. Queue

b. Queue

c. Stack

------

