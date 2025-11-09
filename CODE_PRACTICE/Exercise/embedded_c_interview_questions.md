# Embedded C Interview Questions & Practice

## Table of Contents
1. [Beginner Level Questions](#beginner-level)
2. [Intermediate Level Questions](#intermediate-level)
3. [Advanced Level Questions](#advanced-level)
4. [Memory Management](#memory-management)
5. [Bit Manipulation](#bit-manipulation)
6. [System Programming](#system-programming)
7. [Practical Coding Challenges](#practical-coding-challenges)

---

## Beginner Level

### 1. What is the difference between `char *` and `char[]`?
**Answer:**
- `char *` is a pointer to a character (or string)
- `char[]` is an array of characters
- `char *` can be reassigned to point to different strings
- `char[]` cannot be reassigned, but its contents can be modified

### 2. What is the size of `int` on a 32-bit system?
**Answer:** 4 bytes (32 bits)

### 3. What is the difference between `malloc()` and `calloc()`?
**Answer:**
- `malloc()` allocates memory but doesn't initialize it
- `calloc()` allocates memory and initializes it to zero
- `calloc()` takes two parameters: number of elements and size of each element

### 4. What is a volatile keyword in C?
**Answer:** 
`volatile` tells the compiler that the variable can change unexpectedly (e.g., by hardware, interrupts, or other threads), so it shouldn't optimize accesses to it.

### 5. What is the difference between `#define` and `const`?
**Answer:**
- `#define` is a preprocessor directive (text replacement)
- `const` is a C keyword that creates a read-only variable
- `const` has type checking, `#define` doesn't

---

## Intermediate Level

### 6. Explain the difference between stack and heap memory.
**Answer:**
- **Stack**: Automatic memory management, LIFO, faster access, limited size
- **Heap**: Manual memory management, dynamic allocation, larger size, slower access

### 7. What is a function pointer? Give an example.
**Answer:**
A function pointer stores the address of a function.

```c
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

int (*operation)(int, int) = add;  // Function pointer
int result = operation(5, 3);     // Calls add(5, 3)
```

### 8. What is the purpose of `__attribute__((packed))`?
**Answer:**
It tells the compiler to pack structure members tightly without padding, useful for memory-mapped I/O and network protocols.

### 9. Explain the difference between `static` and `extern` keywords.
**Answer:**
- `static`: Limits scope to current file, retains value between function calls
- `extern`: Declares a variable/function defined in another file

### 10. What is a union? When would you use it?
**Answer:**
A union allows different data types to share the same memory location. Used for:
- Memory optimization
- Type punning
- Implementing variant types

---

## Advanced Level

### 11. What is a memory leak? How do you prevent it?
**Answer:**
Memory leak occurs when allocated memory isn't freed. Prevention:
- Always pair `malloc()` with `free()`
- Use tools like Valgrind
- Implement RAII patterns
- Use smart pointers (C++)

### 12. Explain the difference between little-endian and big-endian.
**Answer:**
- **Little-endian**: Least significant byte stored first
- **Big-endian**: Most significant byte stored first
- Important for network protocols and cross-platform compatibility

### 13. What is a race condition? How do you prevent it?
**Answer:**
Race condition occurs when multiple threads access shared resources simultaneously. Prevention:
- Mutexes
- Semaphores
- Atomic operations
- Critical sections

### 14. What is the difference between `volatile` and `const`?
**Answer:**
- `volatile`: Variable can change unexpectedly, don't optimize
- `const`: Variable cannot be modified after initialization

### 15. Explain interrupt service routines (ISRs) in embedded systems.
**Answer:**
ISRs are functions that execute when hardware interrupts occur. They should be:
- Short and fast
- Non-blocking
- Not call standard library functions
- Use volatile variables for shared data

---

## Memory Management

### 16. What happens if you don't free allocated memory?
**Answer:**
Memory leak - allocated memory remains unavailable until program termination, leading to eventual system resource exhaustion.

### 17. What is the difference between `malloc()` and `realloc()`?
**Answer:**
- `malloc()`: Allocates new memory
- `realloc()`: Resizes existing allocated memory, may move it to a new location

### 18. How do you implement a custom memory allocator?
**Answer:**
```c
typedef struct block {
    size_t size;
    int free;
    struct block *next;
} block_t;

void* custom_malloc(size_t size) {
    // Implementation details...
}
```

### 19. What is memory fragmentation?
**Answer:**
Memory fragmentation occurs when free memory is broken into small, non-contiguous blocks, making it difficult to allocate large contiguous blocks.

### 20. Explain the difference between static and dynamic memory allocation.
**Answer:**
- **Static**: Memory allocated at compile time (global variables, static variables)
- **Dynamic**: Memory allocated at runtime (`malloc`, `calloc`, `realloc`)

---

## Bit Manipulation

### 21. How do you set a specific bit?
**Answer:**
```c
int set_bit(int num, int pos) {
    return num | (1 << pos);
}
```

### 22. How do you clear a specific bit?
**Answer:**
```c
int clear_bit(int num, int pos) {
    return num & ~(1 << pos);
}
```

### 23. How do you toggle a specific bit?
**Answer:**
```c
int toggle_bit(int num, int pos) {
    return num ^ (1 << pos);
}
```

### 24. How do you check if a bit is set?
**Answer:**
```c
int is_bit_set(int num, int pos) {
    return (num & (1 << pos)) != 0;
}
```

### 25. Count the number of set bits in an integer.
**Answer:**
```c
int count_set_bits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}
```

---

## System Programming

### 26. What is the difference between a process and a thread?
**Answer:**
- **Process**: Independent execution unit with its own memory space
- **Thread**: Lightweight process sharing memory space with other threads

### 27. What is a semaphore?
**Answer:**
A synchronization primitive that controls access to shared resources. Types:
- Binary semaphore (mutex)
- Counting semaphore

### 28. Explain the difference between polling and interrupt-driven I/O.
**Answer:**
- **Polling**: CPU continuously checks device status (wastes CPU cycles)
- **Interrupt-driven**: Device notifies CPU when ready (more efficient)

### 29. What is DMA (Direct Memory Access)?
**Answer:**
DMA allows hardware to transfer data directly to/from memory without CPU intervention, improving performance for bulk data transfers.

### 30. What is a watchdog timer?
**Answer:**
A hardware timer that resets the system if the software doesn't periodically "feed" it, used to recover from software hangs or crashes.

---

## Practical Coding Challenges

### Challenge 1: Implement a Circular Buffer
```c
typedef struct {
    int *buffer;
    int head;
    int tail;
    int size;
    int count;
} circular_buffer_t;

int cb_init(circular_buffer_t *cb, int size);
int cb_write(circular_buffer_t *cb, int data);
int cb_read(circular_buffer_t *cb, int *data);
```

### Challenge 2: Implement a Linked List
```c
typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t* create_node(int data);
void insert_at_beginning(node_t **head, int data);
void delete_node(node_t **head, int data);
```

### Challenge 3: Implement String Functions
```c
int my_strlen(const char *str);
char* my_strcpy(char *dest, const char *src);
char* my_strcat(char *dest, const char *src);
int my_strcmp(const char *str1, const char *str2);
```

### Challenge 4: Bit Manipulation Functions
```c
int count_set_bits(int num);
int find_missing_number(int arr[], int n);
int reverse_bits(int num);
int is_power_of_two(int num);
```

### Challenge 5: Memory Management
```c
void* my_malloc(size_t size);
void my_free(void *ptr);
void* my_realloc(void *ptr, size_t size);
```

---

## Quick Practice Questions

### True/False Questions:
1. `sizeof('a')` is always 1. (False - it's `sizeof(int)`)
2. A pointer can point to another pointer. (True)
3. `malloc(0)` always returns NULL. (False - implementation defined)
4. `volatile` prevents compiler optimization. (True)
5. Arrays and pointers are the same thing. (False - similar but different)

### Multiple Choice Questions:
1. What is the output of `printf("%d", sizeof("Hello"));`?
   a) 5 b) 6 c) 4 d) 8
   **Answer: b) 6 (including null terminator)**

2. Which is faster: `malloc()` or `calloc()`?
   a) `malloc()` b) `calloc()` c) Same d) Depends
   **Answer: a) `malloc()` (no initialization)**

3. What happens when you dereference a NULL pointer?
   a) Returns 0 b) Segmentation fault c) Undefined behavior d) Compiler error
   **Answer: c) Undefined behavior**

---

## Tips for Embedded C Interviews

1. **Know your target platform** (ARM, x86, etc.)
2. **Understand memory constraints** (RAM, Flash)
3. **Be familiar with real-time systems**
4. **Know common embedded protocols** (SPI, I2C, UART)
5. **Practice with actual hardware** when possible
6. **Understand power management**
7. **Know debugging techniques** (JTAG, oscilloscope, logic analyzer)

---

## Resources for Further Study

- "The C Programming Language" by Kernighan & Ritchie
- "Embedded Systems Programming" by Steve Heath
- ARM Cortex-M documentation
- Linux kernel development
- Real-time operating systems (FreeRTOS, Zephyr)

---

*Good luck with your embedded C interview preparation! Practice these concepts regularly and try to implement the coding challenges.*
