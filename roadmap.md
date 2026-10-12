# 🗺️ Roadmap for Mastering C (Aligned with K&R "The C Programming Language", ANSI C)

A prerequisite-based learning path for the [`LearningC`](https://github.com/KofiWoodlock/LearningC.git) repository. Each stage lists the **skills to master**, **why they matter**, and **projects to build** to prove your understanding before moving on.

---

## 📌 How to Use This Roadmap

1. Work stages **in order** — later skills assume mastery of earlier ones.
2. For every skill, write at least one small program in the repo (e.g. `stage-01/basics/hello.c`).
3. Complete the **stage project** before advancing.
4. Cross-reference each stage with the matching K&R chapter(s).
5. Compile with strict flags to catch mistakes early:
   ```sh
   gcc -std=c89 -Wall -Wextra -Wpedantic -Wshadow -Wconversion -O2 file.c -o file
   ```

---

## 🧭 Skill Dependency Map

```
                       ┌──────────────────────┐
                       │ 1. Environment & I/O │
                       └──────────┬───────────┘
                                  │
                       ┌──────────▼───────────┐
                       │ 2. Types, Operators, │
                       │    Expressions       │
                       └──────────┬───────────┘
                                  │
                       ┌──────────▼───────────┐
                       │ 3. Control Flow      │
                       └──────────┬───────────┘
                                  │
                       ┌──────────▼───────────┐
                       │ 4. Functions & Scope │
                       └──────────┬───────────┘
                                  │
                       ┌──────────▼───────────┐
                       │ 5. Arrays & Strings  │
                       └──────────┬───────────┘
                                  │
                       ┌──────────▼───────────┐
                       │ 6. Pointers          │◄── the "gateway" skill
                       └──────────┬───────────┘
                                  │
                ┌─────────────────┼──────────────────┐
                │                 │                  │
    ┌───────────▼─────┐ ┌─────────▼───────┐ ┌────────▼─────────┐
    │ 7. Structs &    │ │ 8. Dynamic Mem  │ │ 9. File I/O      │
    │    Unions       │ │  (malloc/free)  │ │  (stdio, fd)     │
    └───────────┬─────┘ └─────────┬───────┘ └────────┬─────────┘
                └─────────────────┼──────────────────┘
                                  │
                       ┌──────────▼───────────┐
                       │ 10. Data Structures  │
                       │  (lists, trees, ht)  │
                       └──────────┬───────────┘
                                  │
                       ┌──────────▼───────────┐
                       │ 11. Preprocessor,    │
                       │  Multi-file, Make    │
                       └──────────┬───────────┘
                                  │
                       ┌──────────▼───────────┐
                       │ 12. Debugging,       │
                       │  Testing, Valgrind   │
                       └──────────┬───────────┘
                                  │
                ┌─────────────────┼──────────────────┐
                │                 │                  │
    ┌───────────▼─────┐ ┌─────────▼───────┐ ┌────────▼─────────┐
    │ 13. Systems     │ │ 14. Concurrency │ │ 15. Networking   │
    │  (POSIX, syscalls)│ │ (pthreads)    │ │  (sockets)       │
    └───────────┬─────┘ └─────────┬───────┘ └────────┬─────────┘
                └─────────────────┼──────────────────┘
                                  │
                       ┌──────────▼───────────┐
                       │ 16. Capstone: build  │
                       │  a real-world system │
                       └──────────────────────┘
```

---

# 🟢 STAGE 1 — Beginner Foundations

Goal: Get comfortable reading, writing, compiling, and reasoning about small C programs.

## Chapter alignment: K&R Ch. 1

### Skills to master
- **1. Toolchain & environment**
  - `gcc`/`clang`, compiler flags, `stdin`/`stdout`/`stderr`
  - Reading compiler warnings as first-class feedback
- **2. Types, operators & expressions** (K&R Ch. 2)
  - `int`, `char`, `float`, `double`, `long`, `short`, signedness
  - Integer promotion, implicit conversions, casting
  - Bitwise operators: `& | ^ ~ << >>`
- **3. Control flow** (K&R Ch. 3)
  - `if`/`else`, `switch`, `while`, `do-while`, `for`, `break`, `continue`, `goto`

### Projects
| # | Project | Skills exercised |
|---|---------|-----------------|
| 1 | Hello world + build script | Toolchain |
| 2 | Temperature conversion table (K&R §1.2) | Loops, `printf` formatting |
| 3 | Character counter / word counter (K&R §1.5) | `getchar`, state machines |
| 4 | Simple calculator (`+ - * /`) | Expressions, switch |
| 5 | Bit-printer: print binary of any `int` | Bitwise ops |

---

# 🟢 STAGE 2 — Functions, Arrays & Strings

Goal: Decompose problems into small functions and manipulate arrays/strings safely.

## Chapter alignment: K&R Ch. 1.7–1.10, Ch. 4

### Skills to master
- **4. Functions & scope**
  - Declaration vs definition, prototypes, return types
  - Automatic vs static vs extern storage, block scope
  - Recursion (and when to prefer iteration)
- **5. Arrays & C-strings**
  - Fixed-size arrays, indexing, off-by-one bugs
  - Null-terminated strings, `<string.h>` (`strlen`, `strcpy`, `strncpy`, `strcmp`)
  - Why unsafe functions (`gets`, `strcpy`) are dangerous

### Projects
| # | Project | Skills exercised |
|---|---------|-----------------|
| 6 | Reimplement `strlen`, `strcmp`, `strcpy`, `strcat` | Arrays, functions |
| 7 | Reverse a string in place | Two-pointer technique |
| 8 | Recursive & iterative factorial / Fibonacci | Recursion tradeoffs |
| 9 | ROT13 / Caesar cipher | Char arithmetic |
| 10 | Number-base converter (bin ↔ dec ↔ hex) | Loops, arrays |

---

# 🟡 STAGE 3 — Pointers (the gateway skill)

Goal: Truly *understand* memory addressing. Everything above depends on this.

## Chapter alignment: K&R Ch. 5

### Skills to master
- **6. Pointers**
  - `&`, `*`, pointer arithmetic, `NULL`
  - Pointers vs arrays: `a[i]` ≡ `*(a + i)`
  - Pointers to functions
  - `const` correctness (`const char *` vs `char * const`)
  - Reading declarations right-to-left ("spiral rule")
  - Argument passing by value vs by pointer

### Projects
| # | Project | Skills exercised |
|---|---------|-----------------|
| 11 | Reimplement `memcpy`, `memmove`, `memset` | Pointer arithmetic |
| 12 | `qsort`-style generic sort using function pointers | Function pointers |
| 13 | `argv` parser: mini `grep` (substring match on stdin) | `char **`, pointer walking |
| 14 | Command-line calculator using RPN (stack via array + pointer) | Pointers as cursors |

---

# 🟡 STAGE 4 — Structs, Dynamic Memory & File I/O

Goal: Build programs that model real data and persist it to disk.

## Chapter alignment: K&R Ch. 6, 7, 8

### Skills to master
- **7. Structs, unions, enums, typedefs**
  - `struct`, `->` operator, nested structs, bitfields
  - `union`, `enum`, `typedef` idioms
- **8. Dynamic memory**
  - `malloc`, `calloc`, `realloc`, `free`
  - Ownership rules; who frees what?
  - Common bugs: leaks, double-free, use-after-free, dangling pointers
- **9. File I/O**
  - `fopen`, `fclose`, `fread`, `fwrite`, `fgets`, `fprintf`, `fscanf`
  - Text vs binary mode, `EOF` handling
  - Low-level `open`/`read`/`write`/`close` (POSIX)

### Projects
| # | Project | Skills exercised |
|---|---------|-----------------|
| 15 | Contact book stored in a binary file | Structs + file I/O |
| 16 | Reimplement `cat`, `wc`, `head`, `tail` | Streams, buffers |
| 17 | Dynamic string type (`mystr_t` with grow/append) | `realloc` patterns |
| 18 | CSV parser → array of structs | Parsing, memory ownership |

---

# 🟠 STAGE 5 — Data Structures From Scratch

Goal: Build the classic data structures using only the standard library.

### Skills to master
- **10. Core data structures**
  - Singly & doubly linked lists
  - Dynamic arrays (vector)
  - Stacks & queues (array- and list-backed)
  - Hash tables (open addressing + chaining)
  - Binary search trees, then AVL or red-black (bonus)
  - Heaps / priority queues

### Projects
| # | Project | Skills exercised |
|---|---------|-----------------|
| 19 | Generic `vec_t` (like C++ `std::vector`) using `void *` | Generics via `void *` |
| 20 | Hash-map based word frequency counter | Hashing, collisions |
| 21 | JSON-lite parser producing an AST of structs | Recursive descent |
| 22 | Undo-redo text buffer (doubly linked list of edits) | List manipulation |

---

# 🟠 STAGE 6 — Preprocessor, Multi-file Projects & Build Systems

Goal: Ship non-trivial projects with clean module boundaries.

## Chapter alignment: K&R Ch. 4.11, Appendix A

### Skills to master
- **11. Preprocessor & modularity**
  - `#include`, header guards, `#pragma once`
  - `#define`, macros, `##`, `#`, X-macros
  - Separation of interface (`.h`) and implementation (`.c`)
  - `static` for internal linkage
  - `Makefile` fundamentals: rules, variables, phony targets, dependency tracking
- **12. Debugging & correctness**
  - `gdb` basics: `break`, `run`, `step`, `next`, `print`, `bt`
  - `valgrind`/AddressSanitizer for leaks & UB
  - Writing tests without a framework (asserts + a `make test` target)
  - Static analysis: `-Wall -Wextra -Wpedantic`, `clang-tidy`, `cppcheck`

### Projects
| # | Project | Skills exercised |
|---|---------|-----------------|
| 23 | Refactor an earlier project into `src/`, `include/`, `tests/` with a Makefile | Modularity |
| 24 | Minimal unit-test framework (`ASSERT_EQ`, `RUN_TEST`) as a header | Macros, X-macros |
| 25 | Zero-warning, zero-Valgrind-error pass on all previous projects | Discipline |

---

# 🔴 STAGE 7 — Systems Programming

Goal: Talk to the operating system directly.

### Skills to master
- **13. POSIX systems programming**
  - Processes: `fork`, `exec`, `wait`, exit codes, `errno`
  - File descriptors vs `FILE *`; `dup`, `dup2`, `pipe`
  - Signals: `signal`, `sigaction`, safe handlers
  - Time: `time`, `clock_gettime`, monotonic vs wall clock

### Projects
| # | Project | Skills exercised |
|---|---------|-----------------|
| 26 | Mini shell (`msh`) — parse commands, `fork`+`exec`, pipes, redirection | Processes, fds |
| 27 | `tail -f` clone | fds, sleep, signals |
| 28 | `time` clone that prints wall/user/sys time | Timing, `wait4` |

---

# 🔴 STAGE 8 — Concurrency

Goal: Write correct multi-threaded C.

### Skills to master
- **14. Concurrency**
  - `pthread_create`, `pthread_join`
  - Mutexes, condition variables, read/write locks
  - Data races, deadlocks, starvation
  - Atomics (`<stdatomic.h>`), memory ordering (intro level)
  - Thread pools & producer-consumer patterns

### Projects
| # | Project | Skills exercised |
|---|---------|-----------------|
| 29 | Thread-safe bounded queue | Mutex + condvar |
| 30 | Parallel word count over many files | Thread pool |
| 31 | Concurrent hash map (bucket-level locking) | Fine-grained locking |

---

# 🔴 STAGE 9 — Networking

Goal: Build networked services in raw C.

### Skills to master
- **15. Sockets**
  - TCP vs UDP, `socket`, `bind`, `listen`, `accept`, `connect`
  - Byte-order (`htons`, `ntohs`), `sockaddr_in`
  - Blocking vs non-blocking I/O, `select`/`poll`/`epoll`/`kqueue`
  - Framing protocols (length-prefixed vs delimiter-based)

### Projects
| # | Project | Skills exercised |
|---|---------|-----------------|
| 32 | TCP echo server (one-thread-per-client) | Sockets basics |
| 33 | Chat server with `epoll`/`poll` and broadcast | Event loop |
| 34 | Minimal HTTP/1.0 static-file server | Parsing + sockets |

---

# 🏆 STAGE 10 — Capstone Projects (Advanced)

Pick **one** capstone to demonstrate mastery. Each requires nearly every skill above.

1. **`tinydb`** — an append-only key/value store with a B-tree index and a REPL.
2. **`myshell`** — a POSIX shell with pipes, redirection, job control, and history.
3. **`memalloc`** — your own `malloc`/`free`/`realloc` on top of `sbrk`/`mmap`, with a test suite.
4. **`c-lox`** — a bytecode VM for a small language (à la *Crafting Interpreters* Part III).
5. **`httpd`** — a multi-threaded HTTP/1.1 server with keep-alive, chunked encoding, and a plugin API.
6. **`raytracer`** — a CPU ray tracer with scene files and PPM output.

**Capstone requirements**
- ✅ Multi-file project with a real `Makefile` (or CMake)
- ✅ Unit tests + CI (GitHub Actions running `-Wall -Wextra -Werror` + Valgrind/ASan)
- ✅ Clean `README.md` with build/run instructions and architecture notes
- ✅ Zero leaks, zero UB warnings under sanitizers

---

## 📁 Suggested Repository Layout

```
LearningC/
├── README.md
├── roadmap.md              ← this file
├── Makefile                ← top-level: `make all`, `make test`, `make clean`
├── stage-01-basics/
├── stage-02-functions-arrays/
├── stage-03-pointers/
├── stage-04-structs-memory-io/
├── stage-05-data-structures/
├── stage-06-modules-build/
├── stage-07-systems/
├── stage-08-concurrency/
├── stage-09-networking/
└── capstone/
    └── <chosen-project>/
```

Each stage folder should contain its own `README.md` linking back to this roadmap, plus one subdirectory per exercise with its own `Makefile` and tests.

---

## 📚 Companion Resources

- **Primary**: Kernighan & Ritchie, *The C Programming Language*, 2nd ed. (ANSI C)
- Zed Shaw, *Learn C the Hard Way* — practical exercises
- Robert Seacord, *Effective C* — modern best practices
- Ben Klemens, *21st Century C* — tooling & idioms
- Beej's Guides — Network Programming, IPC
- *Crafting Interpreters* (Part III) — for the `c-lox` capstone
- `man 2` / `man 3` pages — read them constantly

---

## ✅ Milestone Checklist

- [ ] Stage 1: Beginner Foundations
- [ ] Stage 2: Functions, Arrays & Strings
- [ ] Stage 3: Pointers
- [ ] Stage 4: Structs, Memory & File I/O
- [ ] Stage 5: Data Structures
- [ ] Stage 6: Modules & Build Systems
- [ ] Stage 7: Systems Programming
- [ ] Stage 8: Concurrency
- [ ] Stage 9: Networking
- [ ] Stage 10: Capstone shipped 🎉

> "The only way to learn a new programming language is by writing programs in it." — K&R, Ch. 1
