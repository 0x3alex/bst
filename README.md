# bst - Binary Seach Tree
bst is a generic implimentation of an binary search tree in c

# compareFunc
the compareFunc needs to be set **before** creating the vector.
It shall return
```
    0 -> value is less than the node, 
    1 -> value is equal to the node, 
    2 -> value is greate than the node

    1. param is the tree node, 2nd the value to compare to
```
The paramters (see config) depend on the data type, which are given, when calling ``define_bst``.

The compareFunc can be changed after creating the tree, but needs to maintain the return-scheme.

# bst config paramters
```C++
int (*compareFunc_bst_##suffix)(type,type);
bool print_with_ptr_bst_##suffix = false;
```
    
