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
    print_with_ptr_bst_int = true;
    bst_int *b = new_bst_int(3,5,1,10);
    insert_bst_int(b,11);
    insert_bst_int(b,9);
    print_in_order_bst_int(b,"%d\n");
    puts("---");
    //print_in_order_bst_int(b,"%d\n");
    //print_in_order_bst_int(b,"%d\n");
    printf("%p\n",find_bst_int(b,11));
    //puts("---");
    //printf("%d\n",get_parent_bst_int(b,1)->m_value);
    
    //destroy_bst_int(b->ptr_left);
    //b->ptr_left = NULL;
    //print_in_order_bst_int(b,"%d\n");
    destroy_bst_int(b);
    return 0;
}