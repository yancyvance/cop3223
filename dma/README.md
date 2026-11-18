# Dynamic Memory Allocation in C

These Intro to C demos start with a single dynamically allocated integer and build up to arrays of structures and arrays of pointers to structures.

## `01 dma.c`

Allocate space for one `int` with `malloc(sizeof(int))` and for five consecutive integers with `malloc(N * sizeof(int))`. Use an `int *` to access the allocated values. The demo shows that `arr[i]` and `*(arr + i)` access the same element and that one call to `free(arr)` releases the entire array. At the end, it deliberately demonstrates a leak by overwriting the only pointer to an allocated block before freeing it. The final block is also left unfreed.

## `02 dma.c`

Use `create_array` to allocate an array, read five integers into it, and pass it to `print_array` with its size. The array remains available after `create_array` returns. Pairing `create_array` with `destroy_array` gives the caller a clear place to release the memory and helps prevent leaks.

## `03 dma.c`

Allocate one `Person` with an embedded `char name[101]` array. The allocation for the structure includes the name array and the `year` member. Use `p1->name` to access the name through the pointer and `free(p1)` to release the entire structure.

## `04 dma.c`

Allocate one `Person` and allocate its name string separately. The `char *name` member stores the address of the characters. Allocate `strlen(buffer) + 1` bytes so the copied name has room for the null terminator. Free the name before freeing the structure.

## `05 dma.c`

Declare a local `Person p1` and dynamically allocate its name string. Use `p1.name` to access the pointer member. Free the name string when finished. The local structure's lifetime ends when `main` returns.

## `06 dma.c`

Allocate one contiguous array of `Person` values using a `Person *`. Each `people[i]` is a structure, so use `people[i].name` to access its separately allocated name. Free each name, then free the array once.

## `07 dma.c`

Allocate an array of `Person *` pointers using a `Person **`. Allocate each `Person` separately and then allocate its name. Each `people[i]` is a pointer, so use `people[i]->name`. Free each name and its `Person`, then free the pointer array.

## Dynamic Allocation Patterns

Start by asking **what will this block hold?** Match the pointer type and the `sizeof` expression to the type stored in the block. For `N` values of type `T`, request `N * sizeof(T)` bytes and use a `T *` to access them. This same pattern works for integers, doubles, structures, and pointer elements. An array of `Person *` has elements of type `Person *`, so its first element's address has type `Person **`.

### Key takeaways

- **Identify what already has storage.** Declaring a local `Person` gives you space for the structure. Allocating an array of `Person` values gives you space for every structure in the array. An embedded `char name[101]` comes with its structure.
- **Allocate the missing blocks.** A `char *name` member has room for an address. If you want it to hold the address of its own dynamically allocated string, allocate space for the characters separately. Similarly, an array of `Person *` provides pointer slots. In our demo, each slot gets the address of a separately allocated `Person`.
- **Allocate from the outside in.** In the pointer-array example, allocate the array first, then each `Person`, then each name string. Each step gives you a place to store the address from the next allocation.
- **Trace allocations and cleanup together.** For each successful `malloc`, identify who will free that block and when. Keep its original address until cleanup. Free each block once, free inner blocks before the blocks that store their addresses, and stop using the memory after `free`.
