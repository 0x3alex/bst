#include <stdio.h>
#include <bst.h>

define_bst(int,int);

int cmp(int node, int val) {
    if(val < node) return 0;
    if(val == node) return 1;
    if(val > node) return 2;
}

int main(void) {
    compareFunc_bst_int = &cmp;
    bst_int *b = new_bst_int(3,2,1,3);
    insert_bst_int(b->ptr_left,2);
    print_in_order_bst_int(b,"%d\n");
    printf("%p\n",find_bst_int(b,5));
    puts("---");
    destroy_bst_int(b->ptr_left);
    b->ptr_left = NULL;
    print_in_order_bst_int(b,"%d\n");
    destroy_bst_int(b);
    return 0;
}