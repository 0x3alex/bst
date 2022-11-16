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
    -1 -> value is less than the node, 
    0 -> value is equal to the node, 
    1 -> value is greate than the node

    1. param is the tree node, 2nd the value to compare to*/ \
    static int (*compareFunc_bst_##suffix)(type,type) = NULL; \
    static bool print_with_ptr_bst_##suffix = false; \
\
    static bst_##suffix *find_bst_##suffix(bst_##suffix *root,type val) {  \
        if(root == NULL) return NULL; \
        switch((*compareFunc_bst_##suffix)(root->m_value,val))  { \
            case -1: \
                return find_bst_##suffix(root->ptr_left,val); \
                break; \
            case 0: \
                return root; \
                break; \
            case 1: \
                return find_bst_##suffix(root->ptr_right,val); \
                break; \
        } \
        return NULL; \
    } \
\
    static void insert_bst_##suffix(bst_##suffix *root, type val) { \
        if(find_bst_##suffix(root,val) != NULL) return; \
        switch((*compareFunc_bst_##suffix)(root->m_value,val)) { \
            case -1: /*less*/ \
                if(root->ptr_left != NULL) \
                    insert_bst_##suffix(root->ptr_left,val); \
                else { \
                    root->ptr_left = (bst_##suffix*)calloc(1,sizeof(bst_##suffix)); \
                    root->ptr_left->ptr_left = NULL; \
                    root->ptr_left->ptr_right = NULL; \
                    root->ptr_left->m_value = val; \
                } \
                break; \
            case 1: /*more*/ \
                if(root->ptr_right != NULL) \
                    insert_bst_##suffix(root->ptr_right,val); \
                else { \
                    root->ptr_right = (bst_##suffix*)calloc(1,sizeof(bst_##suffix)); \
                    root->ptr_right->ptr_left = NULL; \
                    root->ptr_right->ptr_right = NULL; \
                    root->ptr_right->m_value = val; \
                }\
                break; \
            default: \
                break; \
        } \
    } \
\
    static bst_##suffix *new_bst_##suffix(const unsigned int amout_of_values,...) { \
        if(amout_of_values < 1) return NULL; \
        bst_##suffix *n = (bst_##suffix*)calloc(1,sizeof(bst_##suffix)); \
        assert(n != NULL); \
        va_list argp; \
        va_start(argp,amout_of_values); \
        if(amout_of_values == 1) { \
            n->m_value = va_arg(argp,type); \
            n->ptr_left = NULL; \
            n->ptr_right = NULL; \
            va_end(argp); \
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
        va_end(argp); \
        return n; \
    } \
\
    /*
        This function can also be used to destroy substrees.
        The ptr_left or ptr_right of the node above *b needs to be updated manually
    */ \
    static void destroy_bst_##suffix(bst_##suffix *root) { \
        if(root->ptr_left != NULL) { \
            destroy_bst_##suffix(root->ptr_left); \
        } \
        if(root->ptr_right != NULL) { \
            destroy_bst_##suffix(root->ptr_right); \
        } \
        free(root); \
    } \
\
    static bst_##suffix *get_min_bst_##suffix(bst_##suffix *root) { \
        bst_##suffix *c = root; \
        while(c->ptr_left != NULL) c = c->ptr_left; \
        return c; \
    } \
\
    static bst_##suffix *find_parent_bst_##suffix(bst_##suffix *root, type val) { \
        bst_##suffix *c = root,*p = NULL; \
        p = c; \
        while(c != NULL) { \
            switch((*compareFunc_bst_##suffix)(c->m_value,val)) { \
                case -1: \
                    p = c; \
                    c = c->ptr_left; \
                    break; \
                case 0: \
                    return p; \
                    break; \
                case 1: \
                    p = c; \
                    c = c->ptr_right; \
                    break; \
            } \
        } \
        return p; \
    } \
\
    static bool is_leaf_bst_##suffix(bst_##suffix *n) { \
        return n->ptr_left == NULL && n->ptr_right == NULL; \
    } \
\
    static void delete_bst_##suffix(bst_##suffix *root, type val) { \
        bst_##suffix *k = find_bst_##suffix(root,val); \
        if(k == NULL) return; \
        bst_##suffix *p = find_parent_bst_##suffix(root,val); \
        if(is_leaf_bst_##suffix(k)) { \
            if(root == k) destroy_bst_##suffix(root); \
            else { \
                if(p->ptr_left == k) p->ptr_left = NULL; \
                else p->ptr_right = NULL; \
                free(k); \
            } \
        }else if(k->ptr_left != NULL && k->ptr_right != NULL)  { \
            bst_##suffix *s = get_min_bst_##suffix(k->ptr_right); \
            type v = s->m_value; \
            delete_bst_##suffix(root,v); \
            k->m_value = v; \
        }else{ \
            bst_##suffix *c = k->ptr_left != NULL ? k->ptr_left : k->ptr_right; \
            if(k != root) { \
                if(p->ptr_left == k) { \
                    p->ptr_left = c; \
                }\
                else p->ptr_right = c; \
                printf("a   %p\n",p); \
                printf("a   %p\n",k); \
            }else{ \
                root = c; \
            } \
            free(k); \
        } \
    } \
\
    static void print_in_order_bst_##suffix(bst_##suffix *root, char *formatter) { \
        if(root != NULL) { \
            print_in_order_bst_##suffix(root->ptr_left,formatter); \
            printf(formatter,root->m_value); \
            if(print_with_ptr_bst_##suffix) { \
                printf("self %p\nright %p\nleft %p\n",root,root->ptr_right,root->ptr_left); \
            } \
            print_in_order_bst_##suffix(root->ptr_right,formatter); \
        } \
    }