# Computer Science Challenge

This repository includes the solutions that I have implemented for various computer science exercises.

## Index
1. [Roman to Integer](#roman-to-integer)
2. [Reverse Linked List](#reverse-linked-list)
3. [Subsets](#subsets)
4. [Reverse Words in a String](#reverse-words-in-a-string)
5. [Reverse Linked List II](#reverse-linked-list-ii)
6. [Rotate Image](#rotate-image)
7. [Shortest Palindrome](#shortest-palindrome)
8. [Longest Valid Parentheses](#longest-valid-parentheses)

---

## Roman to Integer
### 1. Approach
This function converts a Roman numeral string into an integer. The algorithm processes the string character by character, following these key rules:
- Roman numerals have specific values: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000.
- Certain numeral pairs represent subtractive notation (e.g., IV = 4 instead of 6).
- The function checks for these subtractive cases and adds or subtracts accordingly.

### 2. Steps
**2.1 Initialize Variables:**
- `solve` stores the final integer value.
- `n` stores the length of the input string `s`.
- `arr` is a character array copy of `s`.
- `i` is the iterator used to process characters.

**2.2 Iterate through the string:**
- If the current character and the next form a subtractive pair (like "IV", "IX", etc.), add the special value and move forward by two positions.
- Otherwise, just add the normal value and move forward by one position.
- Return the final sum.

### 3. Computational Complexity
**Time Complexity:** 𝑂(𝑛) → The function iterates through the string once, checking conditions at each step.

### 4. Pros and Cons
#### Pros
- Simple and follows the logic of Roman numerals directly.
- Uses minimal additional memory.

#### Cons
- Repeated `if` statements instead of a cleaner approach (e.g., using a hashmap).

---

## Reverse Linked List
### 1. Approach
This function reverses a singly linked list using a recursive approach. Instead of iterating through the list and reversing the links step by step, it relies on recursion to reach the last node and then reconstructs the list in reverse order.

### 2. Steps
**2.1 Base Case:**
- If `head` is `nullptr` (empty list) or if `head->next` is `nullptr` (only one node in the list), return `head` because there’s nothing to reverse.

**2.2 Recursive Call:**
- Recursively call `reverseList(head->next)` until it reaches the last node.
- This last node becomes the new head of the reversed list.

**2.3 Reverse the Links:**
- The `head->next->next = head;` statement makes the next node point back to `head`, effectively reversing the link.
- The `head->next = NULL;` statement ensures that the original head node becomes the new tail of the reversed list.

**2.4 Return the new head (rest):**
- The recursion unwinds, returning the last node (now the first node in the reversed list) as the new head.

### 3. Computational Complexity
**Time Complexity:** 𝑂(𝑛) → The function traverses each node once.

### 4. Pros and Cons
#### Pros
- Simple recursive approach.

#### Cons
- Recursive functions have higher memory overhead compared to iterative solutions.

---

## Subsets
### 1. Approach
This function generates all subsets (power set) of a given array using backtracking (recursion with decision making). The idea is to explore two choices at every step:
- Include the current element in the subset.
- Exclude the current element and move to the next.
By recursively following these choices, the algorithm generates all possible subsets.

### 2. Steps
**2.1 Base Case:**
- If the index `i` reaches the size of `nums`, store the current subset (`vec`) in `solve` and return.

**2.2 Recursive Steps:**
- Include `nums[i]` in `vec` and make a recursive call with `i+1`.
- Exclude `nums[i]` by removing it (`vec.pop_back()`) and making another recursive call with `i+1`.

**2.3 Final Result:**
- The recursive tree explores all possibilities, and `solve` stores all subsets, which is then returned.

### 3. Computational Complexity
**Time Complexity:** 𝑂(2^𝑛) → Each element has two choices (included or not), leading to `2^𝑛` subsets.

### 4. Pros and Cons
#### Pros
- Generates all subsets correctly.
- Uses backtracking efficiently to explore all possibilities.

#### Cons
- Recursive approach consumes extra memory (stack frames).
- Exponential time complexity, which is unavoidable for subset generation.

---

## Reverse Words in a String
### 1. Approach
The function reverses the words in a given string while removing extra spaces. It does this by:
- Extracting words from the string.
- Storing them in a vector (to keep track of the order).
- Reversing the order of words.
- Reconstructing the string from the reversed words.

### 2. Steps
**2.1 Remove extra spaces:**
- Use `istringstream iss(s)` to automatically split the input string into words, removing extra spaces.

**2.2 Store words in a vector:**
- Extract words using `iss >> word` and push them into `words`.

**2.3 Reverse the order of the words:**
- Use `reverse(words.begin(), words.end());` to flip the order of words in place.

**2.4 Reconstruct the string:**
- Use `ostringstream` to build the final string efficiently.
- Append spaces only between words, avoiding leading or trailing spaces.

### 3. Computational Complexity
**Time Complexity:** 𝑂(𝑛)
- Extracting words: 𝑂(𝑛)
- Reversing words: 𝑂(𝑛)
- Constructing the final string: 𝑂(𝑛)
- **Total:** 𝑂(𝑛) linear time.

### 4. Pros and Cons
#### Pros
- No unnecessary loops to process spaces manually.
- Efficient 𝑂(𝑛) complexity with in-place word reversal.

#### Cons
- Uses extra space (𝑂(𝑛)) for the vector, which could be avoided.

---

## Reverse Linked List II
### 1. Approach
This function reverses a sublist of a singly linked list between two given positions (`left` and `right`). Instead of reversing the entire list, it modifies only the portion between `left` and `right` while keeping the rest of the list unchanged.

### 2. Steps
**2.1 Edge Case Handling:**
- If `left == right`, return the head as no reversal is needed.

**2.2 Traverse to the left position**
- Use a loop to move `prev` and `current` to the `left-th` node.

**2.3 Reverse the sublist from `left` to `right`**
- Use a loop to reverse the links within the sublist.

**2.4 Reconnect the reversed sublist**
- Connect the reversed sublist back to the main list.

### 3. Computational Complexity
**Time Complexity:** 𝑂(𝑛)

### 4. Pros and Cons
#### Pros
- Efficient in-place reversal without extra memory.
- Only modifies the required portion, keeping the rest unchanged.

#### Cons
- A bit tricky to understand due to multiple pointer updates.

---
## Rotate Image

### 1. Approach
This function rotates a given 𝑛×𝑛 matrix 90° clockwise in-place. Instead of using extra space, it modifies the matrix directly by following two key steps:
- **Flip Vertically**: Swap elements across the horizontal middle axis.
- **Transpose the Matrix**: Swap elements across the main diagonal.

### 2. Steps

#### 2.1 Find the matrix size (n).

#### 2.2 Flip the matrix vertically:
- Swap the first row with the last, the second row with the second-last, etc.
- Use a loop from `0` to `𝑛/2` and swap elements at `matrix[i][j]` with `matrix[n - 1 - i][j]`.

#### 2.3 Transpose the matrix (swap across the main diagonal):
- Swap `matrix[i][j]` with `matrix[j][i]` for all elements above the diagonal.
- This effectively rotates the matrix by 90°.

### 3. Computational Complexity
**Time Complexity**: 𝑂(𝑛^2)
- The matrix has 𝑂(𝑛^2) elements, and each swap operation runs in constant time.

### 4. Pros and Cons
**Pros**
- In-place solution (no extra memory required).
- Faster than using extra arrays (since we avoid additional memory allocation).

**Cons**
- Code can be tricky to understand if unfamiliar with matrix transpositions.
- Requires careful index manipulation to avoid errors.

---

## Shortest Palindrome

### 1. Approach
This function finds the shortest palindrome by adding the minimum number of characters at the beginning of the given string.
The key idea is to find the longest palindromic prefix in the string and then reverse the remaining suffix and append it in front.

### 2. Steps

#### 2.1 Reverse the given string (`rev`) and compare it with the original:
- If `s == rev`, then `s` is already a palindrome, so return `s`.
  
#### 2.2 Find the longest prefix of `s` that is a palindrome:
- Compare `s.substr(0, i)` with `rev.substr(n - i)` from the end.
- The largest `i` for which they match gives the longest palindromic prefix.
  
#### 2.3 Reverse the remaining suffix (`s.substr(longestPalPrefix)`) and add it in front:
- This ensures we get the shortest palindrome.

### 3. Computational Complexity
**Time Complexity**: 𝑂(𝑛^2)
- Finding the longest palindromic prefix takes 𝑂(𝑛) for each substring check, leading to a worst case of 𝑂(𝑛^2).
- The final reversal and concatenation operations run in 𝑂(𝑛).

### 4. Pros and Cons
**Pros**
- Simple to implement with string operations.
- Does not use extra data structures like a hash table.

**Cons**
- Slow for large strings due to brute-force substring checking.
- There are more optimal approaches (like using the KMP algorithm) that achieve 𝑂(𝑛) time complexity.

---

## Longest Valid Parentheses

### 1. Approach
The goal is to find the length of the longest valid parentheses substring in a given string. This solution uses a stack to track unmatched parentheses positions.

### 2. Steps

#### 2.1 Initialize a stack (`word`) and push `-1` as a base index to handle edge cases.
  
#### 2.2 Iterate through the string:
- If `s[i] == '('`, push the index `i` onto the stack.
- If `s[i] == ')'`, pop the top index from the stack:
  - If the stack becomes empty, push `i` (this acts as a new base).
  - Otherwise, calculate the length of the valid substring as `i - word.top()`.
  
#### 2.3 Return the maximum valid substring length found (`solve`).

### 3. Computational Complexity
**Time Complexity**: 𝑂(𝑛)
- Each character is processed once, making it linear.

### 4. Pros and Cons
**Pros**
- Efficient 𝑂(𝑛) time complexity.
- Uses only a single stack, making it easy to implement.

**Cons**
- Uses extra space 𝑂(𝑛) for the stack.









