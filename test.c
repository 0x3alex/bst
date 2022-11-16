#include <stdio.h>
#include <bst.h>

define_bst(int,int);

int cmp(int node, int val) {
    if(val < node) return -1;
    if(val == node) return 0;
    if(val > node) return 1;
}

void intBst() {
    compareFunc_bst_int = &cmp;
    print_with_ptr_bst_int = true;
    bst_int *b = new_bst_int(3,5,1,10);
    insert_bst_int(b,11);
    insert_bst_int(b,9);
    print_in_order_bst_int(b,"%d\n");
    puts("---");
    delete_bst_int(b,10);
    puts("---");
    print_in_order_bst_int(b,"%d\n");
    destroy_bst_int(b);
}

struct point {
        int x,y;
};

int structCmp(struct point *node, struct point *val) {
    if(val->x < node->x) return -1;
    if(val->x == node->x) return 0;
    if(val->x > node->x) return 1;
}

define_bst(s,struct point *);
void structBst() {
    struct point p1 = {
        .x = 1,
        .y = 2
    }, p2 = {
        .x = 10,
        .y = 2
    }, p3 = {
        .x = 12,
        .y = 2
    }, p4 = {
        .x = 11,
        .y = 2
    };
    printf("p1 %p\np2 %p\np3 %p\np4 %p\n\n",&p1,&p2,&p3,&p4);
    compareFunc_bst_s = &structCmp;
    print_with_ptr_bst_s = true;
    bst_s *b = new_bst_s(3,&p2, &p1, &p3);
    insert_bst_s(b,&p4);
    print_in_order_bst_s(b,"\nvalue %p\n");
    puts("--------");
    delete_bst_s(b,&p3);
    print_in_order_bst_s(b,"\nvalue %p\n");
    destroy_bst_s(b);

}

int main(void) {
    //bstInt();
    structBst();
    return 0;
}