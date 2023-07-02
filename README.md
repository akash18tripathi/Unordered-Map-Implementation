# Unordered-Map-Implementation

This repository contains a C++ implementation of an unordered map that demonstrates how hashing works and the importance of a hash function. The unordered map is generic and can handle different data types such as int, float, char, double, and string. 

### Functions to Implement

The following functions are implemented in the code:

1. `insert(key, value)`: Inserts a key-value pair into the unordered map. If the key already exists, the corresponding value is updated.

2. `erase(key)`: Erases the key from the unordered map if it exists; otherwise, no action is taken.

3. `find(key)`: Returns true if the key exists in the unordered map; otherwise, returns false.

4. `map[key]`: Returns the value associated with the key in the unordered map. If the key does not exist, the default value of the corresponding data type is returned.

### Input Format

The input should follow the specified format:

- The first line should contain a single integer `q` denoting the number of queries.

- Each subsequent line corresponds to a query and consists of two lines:

    - The first line of a query should contain a single integer representing the type of operation:
        - `1` for insert
        - `2` for erase
        - `3` for find
        - `4` for map
        
    - The second line of a query contains the inputs based on the type of operation:
        - For type `1` (insert): two strings denoting the key and value to be inserted.
        - For type `2` (erase): one string denoting the key to be erased.
        - For type `3` (find): one string denoting the key to be found.
        - For type `4` (map): one string denoting the key on which the operation must be applied.
        
### Output Format

The output format depends on the type of operation:

- For type `1` (insert) and type `2` (erase), no output is printed.

- For type `3` (find):
    - If the key exists in the unordered map, `1` is printed.
    - If the key does not exist, `0` is printed.
    
- For type `4` (map), the value associated with the key is printed.

### File Structure

This repository contains a single C++ file named `unordered_map.cpp`. You can find the complete implementation of the unordered map with the required functions in this file.

Please refer to the code file for detailed implementation and usage instructions.


## Problem: Counting Distinct Elements in Subarrays

Using the unordered map implemented in this repository, we are solving the following question for testing the accuracy for implementation:

### Problem Description

You are given an array of size N. Your task is to count the number of distinct elements in every subarray of size K.

#### Input Format

The first line contains two integers N and K, where N denotes the size of the array and K denotes the size of the subarray.

The second line contains N space-separated integers denoting the values of the individual elements in the array.

#### Output Format

A single line that contains N - K + 1 elements denoting the number of distinct elements in each individual subarray.

#### Constraints

1 <= N <= 10^4

1 <= K <= N

#### Sample Input
```shell
7 4
1 2 1 3 4 2 3
```
#### Sample Output
```shell
3 4 4 3
```


#### Explanation

- The first window is {1, 2, 1, 3}, and the count of distinct numbers is 3.

- The second window is {2, 1, 3, 4}, and the count of distinct numbers is 4.

- The third window is {1, 3, 4, 2}, and the count of distinct numbers is 4.

- The fourth window is {3, 4, 2, 3}, and the count of distinct numbers is 3.


## Contribution

Please feel free for suggestions/improvements in the above implementation.
