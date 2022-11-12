#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdarg.h>

#define define_bst(suffix,type) \
\
    typedef struct s_bst_##suffix { \
        type m_value; \
        struct s_bst_##suffix *ptr_right, *ptr_left; \
    } bst_##suffix; \
\
    /* shall return:
    0 -> value is less than the node, 
    1 -> value is equal to the node, 
    2 -> value is greate than the node

    1. param is the tree node, 2nd the value to compare to*/ \
    int (*compareFunc_bst_##suffix)(type,type) = NULL; \
    bool print_with_ptr_bst_##suffix = false; \
\
    bst_##suffix *find_bst_##suffix(bst_##suffix *root,type val) {  \
        if(root == NULL) return NULL; \
        switch((*compareFunc_bst_##suffix)(root->m_value,val))  { \
            case 0: \
                return find_bst_##suffix(root->ptr_left,val); \
                break; \
            case 1: \
                return root; \
                break; \
            case 2: \
                return find_bst_##suffix(root->ptr_right,val); \
                break; \
        } \
        return NULL; \
    } \
\
    void insert_bst_##suffix(bst_##suffix *root, type val) { \
        if(find_bst_##suffix(root,val) != NULL) return; \
        if((*compareFunc_bst_##suffix)(root->m_value,val) == 0) { \
            if(root->ptr_left != NULL) { \
                insert_bst_##suffix(root->ptr_left,val); \
            }else{ \
                root->ptr_left = (bst_##suffix*)calloc(1,sizeof(bst_##suffix)); \
                root->ptr_left->ptr_left = NULL; \
                root->ptr_left->ptr_right = NULL; \
                root->ptr_left->m_value = val; \
            }\
        }else if((*compareFunc_bst_##suffix)(root->m_value,val) == 2) { \
            if(root->ptr_right != NULL) { \
                insert_bst_##suffix(root->ptr_right,val); \
            }else{ \
                root->ptr_right = (bst_##suffix*)calloc(1,sizeof(bst_##suffix)); \
                root->ptr_right->ptr_left = NULL; \
                root->ptr_right->ptr_right = NULL; \
                root->ptr_right->m_value = val; \
            }\
        } \
    } \
\
    bst_##suffix *new_bst_##suffix(int amout_of_values,...) { \
        if(amout_of_values < 1) return NULL; \
        bst_##suffix *n = (bst_##suffix*)calloc(1,sizeof(bst_##suffix)); \
        assert(n != NULL); \
        va_list argp; \
        va_start(argp,amout_of_values); \
        if(amout_of_values == 1) { \
            n->m_value = va_arg(argp,type); \
            n->ptr_left = NULL; \
            n->ptr_right = NULL; \
            return n; \
        } \
        if(amout_of_values > 1) { \
            for(int i = 0; i < amout_of_values; i++) { \
                if(i == 0) { \
                    n->m_value = va_arg(argp,type); \
                    n->ptr_left = NULL; \
                    n->ptr_right = NULL; \
                    continue; \
                } \
                insert_bst_##suffix(n,va_arg(argp,type)); \
            } \
        } \
        return n; \
    } \
\
    /*
        This function can also be used to destroy substrees.
        The ptr_left or ptr_right of the node above *b needs to be updated manually
    */ \
    void destroy_bst_##suffix(bst_##suffix *root) { \
        if(root->ptr_left != NULL) { \
            destroy_bst_##suffix(root->ptr_left); \
        } \
        if(root->ptr_right != NULL) { \
            destroy_bst_##suffix(root->ptr_right); \
        } \
        free(root); \
    } \
\
    void print_in_order_bst_##suffix(bst_##suffix *root, char *formatter) { \
        if(root != NULL) { \
            print_in_order_bst_##suffix(root->ptr_left,formatter); \
            printf(formatter,root->m_value); \
            if(print_with_ptr_bst_##suffix) { \
                printf("self %p\nright %p\nleft %p\n",root,root->ptr_right,root->ptr_left); \
            } \
            print_in_order_bst_##suffix(root->ptr_right,formatter); \
        } \
    }