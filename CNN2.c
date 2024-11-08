/*
    C言語でCNNを作成　ver.2
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct node {        /* 一つのnode */
    float value;
} Node;

typedef struct edge {        /* 一本のedge */
    Node* lhs;            /* nodeのアドレスを入れる場所 */
    Node* rhs;            /* nodeのアドレスを入れる場所 */
    float weight;
} Edge;

typedef struct nodevec {     /* nodeの縦方向のカタマリ */
    Node* node;
    struct nodevec* next;
} Layer;

typedef struct Layer_vec {   /* "nodeの縦方向のカタマリ" の横方向のカタマリ */
    Layer* layer;
    struct Layer_vec* next;
} Layer_vec;

typedef struct edgevec {     /* "edgeの縦方向のカタマリ" の横方向のカタマリ */
    Edge** edge;          /* edgeの配列を指すポインタ */
    struct edgevec* next;
} Edge_layer;


int main(void){

    Node *n1 = malloc(sizeof(Node));          /* Nodeを記録する魔法の場所を確保 */   
    Node *n2 = malloc(sizeof(Node));
    Node *n3 = malloc(sizeof(Node));
    Node *n4 = malloc(sizeof(Node));
    Node *n5 = malloc(sizeof(Node));
    Node *n6 = malloc(sizeof(Node));
    Node *n7 = malloc(sizeof(Node));
    Node *n8 = malloc(sizeof(Node));
    Node *n9 = malloc(sizeof(Node));

    Layer *l1 = malloc(sizeof(Layer));        /* Nodeの縦のカタマリを記録する魔法の場所を確保 */
    Layer *l2 = malloc(sizeof(Layer));
    Layer *l3 = malloc(sizeof(Layer));

    Layer_vec *lv1 = malloc(sizeof(Layer_vec));   /* "Nodeの縦方向のカタマリ" の横方向のカタマリを記録する魔法の場所を確保 */

/* Node */

    n1->value = 3;                            /*--- 構造体Nodeの n1 のメンバーvalueに 3 を代入（3は仮の値） ---*/
    n2->value = 4;
    n3->value = 5;
    n4->value = 6;
    n5->value = 7;
    n6->value = 8;
    n7->value = 9;
    n8->value = 1;
    n9->value = 2;

/* Layer（nodevec） */

    l1->node = n1;                           /* 構造体Layerの l1 のメンバーnodeに構造体Nodeの n1 を代入 */
    l1->next = l1;                           /*構造体Layerの l1 のメンバーnextに構造体Layerの l1を代入 */

    l1->node = n2;
    l1->next = l1;

    l1->node = n3;
    l1->next = l1;


    l2->node = n4;                           /* 構造体Layerの l2 のメンバーnodeに構造体Nodeの n4 を代入 */
    l2->next = l2;                           /*構造体Layerの l2 のメンバーnextに構造体Layerの l2を代入 */

    l2->node = n5;
    l2->next = l2;

    l2->node = n6;
    l2->next = l2;


    l3->node = n7;                           /* 構造体Layerの l3 のメンバーnodeに構造体Nodeの n7 を代入 */
    l3->next = l3;                           /*構造体Layerの l3 のメンバーnextに構造体Layerの l3を代入 */

    l3->node = n8;
    l3->next = l3;

    l3->node = n9;
    l3->next = l3;


/* Layer_vec */

    lv1->layer = l1;                          /* 構造体Layer_vecの lv1 のメンバーlayerに構造体Layerの l1を代入 */
    lv1->next = lv1;                          /*構造体Layer_vecの lv1 のメンバーnextに構造体Layer_vecの lv1を代入 */

    lv1->layer = l2;
    lv1->layer = lv1;

    lv1->layer = l3;
    lv1->layer = lv1;


    int i = 0;
    // Node *lhs;
    // Node *rhs;
    // Edge_layer *head;
    // Edge_layer *tail;
    // while (lhs != NULL && rhs != NULL) {     /* lhsとrhsのどちらかがNULLならばループを終了 */
    while () {
        Edge *e = malloc(sizeof(Edge));
        Node *lhs = malloc(sizeof(Node));
        Node *rhs = malloc(sizeof(Node));

        lhs->value = 1;
        rhs->value = 2;
        e->lhs = lhs;           /* lhsがn1(?)であることをどこにも定義していない？アドレスしか格納してないと思う。　rhsに関しても同じ */
        e->rhs = rhs;           /* が、それで良い？ */

        // tail->next = tail;

        Edge_layer *el1 = malloc(sizeof(Edge_layer));      /* "edgeの縦方向のカタマリ" の横方向のカタマリを記録する魔法の場所を確保 */

        el1->edge = e;                                     /* 構造体Edge_layerの lv1 のメンバーlayerに構造体Layerの l1を代入 */
        el1->next = el1;                                   /* 構造体Edge_layerの lv1 のメンバーnextに構造体Edge?layerの el1を代入 */

        i++;
    }

    // int edge_group1[i];           /* edgeの層 */

    // Edge_layer *el1 = malloc(sizeof(Edge_layer));

    // el1->edge = e;

    
}