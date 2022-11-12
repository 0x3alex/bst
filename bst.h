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
    void insert_bst_##suffix(bst_##suffix *b, type val) { \
        if(b == NULL) return; \
        switch((*compareFunc_bst_##suffix)(b->m_value,val)) { \
            case 0: \
                /*check if it needs to be inserted in between*/ \
                if(b->ptr_left != NULL) { \
                    if((*compareFunc_bst_##suffix)(b->ptr_left->m_value,val) == 2) { \
                        /*value is higher than the left value but less then the current
                        so its in between*/ \
                        bst_##suffix *t = (bst_##suffix*)calloc(1,sizeof(bst_##suffix)); \
                        assert(t != NULL); \
                        t->m_value = val; \
                        t->ptr_left = b->ptr_left; \
                        t->ptr_right = NULL; \
                        b->ptr_left = t; \
                        return; \
                    } else { \
                        /*left is still greater than the value*/ \
                        insert_bst_##suffix(b->ptr_left,val); \
                    } \
                }else{ \
                    /*left node is null, so insert*/ \
                    bst_##suffix *t = (bst_##suffix*)calloc(1,sizeof(bst_##suffix)); \
                    assert(t != NULL); \
                    t->m_value = val; \
                    t->ptr_left = NULL; \
                    t->ptr_right = NULL; \
                    b->ptr_left = t; \
                    return; \
                } \
                break;  \
            case 1: \
                return;/*nothing to do, since its already there*/ \
                break; \
            case 2:  \
                 /*check if it needs to be inserted in between*/ \
                if(b->ptr_right != NULL) { \
                    if((*compareFunc_bst_##suffix)(b->ptr_right->m_value,val) == 0) { \
                        /*value is less than the right value but greater then the current
                        so its in between*/ \
                        bst_##suffix *t = (bst_##suffix*)calloc(1,sizeof(bst_##suffix)); \
                        assert(t != NULL); \
                        t->m_value = val; \
                        t->ptr_right = b->ptr_right; \
                        t->ptr_left = NULL; \
                        b->ptr_right = t; \
                        return; \
                    } else { \
                        /*left is still greater than the value*/ \
                        insert_bst_##suffix(b->ptr_right,val); \
                    } \
                }else{ \
                    /*left node is null, so insert*/ \
                    bst_##suffix *t = (bst_##suffix*)calloc(1,sizeof(bst_##suffix)); \
                    assert(t != NULL); \
                    t->m_value = val; \
                    t->ptr_left = NULL; \
                    t->ptr_right = NULL; \
                    b->ptr_right = t; \
                    return; \
                } \
                break; \
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
    bst_##suffix *find_bst_##suffix(bst_##suffix *b,type val) {  \
        if(b == NULL) return NULL; \
        switch((*compareFunc_bst_##suffix)(b->m_value,val))  { \
            case 0: \
                return find_bst_##suffix(b->ptr_left,val); \
                break; \
            case 1: \
                return b; \
                break; \
            case 2: \
                return find_bst_##suffix(b->ptr_right,val); \
                break; \
        } \
        return NULL; \
    } \
\
    void print_in_order_bst_##suffix(bst_##suffix *b, char *formatter) { \
        if(b != NULL) { \
            print_in_order_bst_##suffix(b->ptr_left,formatter); \
            printf(formatter,b->m_value); \
            if(print_with_ptr_bst_##suffix) { \
                printf("self %p\nright %p\nleft %p\n",b,b->ptr_right,b->ptr_left); \
            } \
            print_in_order_bst_##suffix(b->ptr_right,formatter); \
        } \
    }