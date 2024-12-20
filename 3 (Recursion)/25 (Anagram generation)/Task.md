# Anagrams Generation - Specifications and Instructions

## Overview
The "Anagrams Generation" task is focused on generating anagrams of a given word or phrase by rearranging its letters. An anagram is formed by rearranging all the original letters of a word or phrase exactly once to produce a new valid word or phrase.

The objective is to write a program that takes a string of up to 10 characters and generates all possible anagrams of that string. This task includes generating both all possible permutations and all distinct permutations without duplicates.

## Task Description
1. **Input**: The program takes a string (maximum length of 10 characters) as input from the user.

2. **Output**: The program prints all possible anagrams of the string.

3. **Versions**: There are two versions of the program:
   - The first version prints all possible anagrams, including duplicates.
   - The second version prints only distinct anagrams, avoiding any duplicates.

### Example 1:
- **Input**: "ABC"
- **Output** (both versions produce the same output):
  ```
  ABC ACB BAC BCA CAB CBA
  ```

### Example 2:
- **Input**: "AAC"
- **First Version Output**:
  ```
  AAC AAC ACA ACA CAA CAA
  ```
- **Second Version Output**:
  ```
  AAC ACA CAA
  ```

## Solution Approach
The solution involves the use of recursion to systematically explore each possible combination of letters:

1. **Recursive Function (`generate_r`)**:
   - This function takes the given word, an output array (anagram), a boolean array (`used`) that keeps track of which characters have been used, and generates the anagrams.
   - For each character that has not been used yet, it adds the character to the current position and then makes a recursive call for the next position.

2. **Handling Duplicates**:
   - To handle duplicates in the second version, an additional check is required to ensure that the same character is not used repeatedly in the same position.

## Code Structure
- The code starts by reading the input word from the user.
- The `generate_r()` function is called to generate all possible anagrams by recursively filling each position of the anagram.
- The program prints each generated anagram to standard output.

## Running the Program
1. **Compilation**: Compile the code using a C compiler, for example:
   ```
   gcc anagrams_generation.c -o anagrams_generation
   ```

2. **Execution**: Run the compiled program:
   ```
   ./anagrams_generation
   ```
   The program will prompt for the input word and then generate all possible anagrams.

## Notes
- The recursive approach ensures that all possible anagrams are generated by systematically exploring each character's position.
- The program handles strings of up to 10 characters due to the factorial growth of possible permutations, which can become computationally intensive for longer strings.
- Memory allocation and boundary conditions are handled to ensure the program runs correctly for the given input size.

## Conclusion
This solution to the "Anagrams Generation" problem is an excellent exercise in understanding recursion and combinatorial generation. It demonstrates how to systematically explore all possible combinations of a set of characters and provides an example of both generating all permutations and filtering out duplicates.

