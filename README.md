# bst - Binary Seach Tree
bst is a generic implimentation of an binary search tree in c

The pointer, which is set, when calling
```c
new_bst_...
```
will always point to the root of the tree, except when set to another address manually

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

# License

>MIT License
>
>Copyright (c) 2022 Alex
>
>Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the >Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, >and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
>
>The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
>
>THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A >PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF >CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
    
