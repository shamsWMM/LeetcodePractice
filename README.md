# LeetcodePractice

### Coped notes from LeetCode for C Submissions
Compiled with gcc 14 using the gnu11 standard.

Your code is compiled with level one optimization (-O2). AddressSanitizer is also enabled to help detect out-of-bounds and use-after-free bugs.

Most standard library headers are already included automatically for your convenience.

For hash table operations, you may use uthash. "uthash.h" is included by default. Below are some examples:

1. Adding an item to a hash.

struct hash_entry {
    int id;            /* we'll use this field as the key */
    char name[10];
    UT_hash_handle hh; /* makes this structure hashable */
};

struct hash_entry *users = NULL;

void add_user(struct hash_entry *s) {
    HASH_ADD_INT(users, id, s);
}
2. Looking up an item in a hash:

struct hash_entry *find_user(int user_id) {
    struct hash_entry *s;
    HASH_FIND_INT(users, &user_id, s);
    return s;
}
3. Deleting an item in a hash:

void delete_user(struct hash_entry *user) {
    HASH_DEL(users, user);  
}