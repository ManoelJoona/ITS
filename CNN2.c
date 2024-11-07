/*
    C言語でCNNを作成　ver.2
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct node{        /* 一つのnode */
    float value;
} Node;

typedef struct edge{        /* 一本のedge */
    Node* lhs;   /* nodeのアドレスを入れる場所 */
    Node* rhs;   /* nodeのアドレスを入れる場所 */
    float weight;
} Edge;

typedef struct nodevec{     /* nodeの縦方向のカタマリ */
    Node* node;
    Layer* next;
} Layer;

typedef struct Layer_vec{   /* "nodeの縦方向のカタマリ" の横方向のカタマリ */
    Layer* layer;
    Layer_vec* next;
} Layer_vec;

typedef struct edgevec{     /* "edgeの縦方向のカタマリ" の横方向のカタマリ */
    Edge** edge;
    Edge_layer* next;
} Edge_layer;


int main(void){

    Node *n1 = malloc(sizeof(Node));          /* Nodeを記録する魔法の場所を確保 */   
    Node *n2 = malloc(sizeof(Node));
    Node *n3 = malloc(sizeof(Node));

    Layer *l1 = malloc(sizeof(Layer));        /* Nodeの縦のカタマリを記録する魔法の場所を確保 */
    Layer *l2 = malloc(sizeof(Layer));
    Layer *l3 = malloc(sizeof(Layer));

    Layer_vec *lv1 = malloc(sizeof(Layer));   /* "Nodeの縦方向のカタマリ" の横方向のカタマリを記録する魔法の場所を確保 */
    Layer_vec *lv2 = malloc(sizeof(Layer));
    Layer_vec *lv3 = malloc(sizeof(Layer));


    n1->value = 3;                            /*--- 構造体Nodeの n1 のメンバーvalueに 3 を代入（3は仮の値） ---*/
    n2->value = 5;
    n3->value = 7;


    l1->node = n1;                            /* 構造体Layerの l1 のメンバーnodeに構造体Nodeの n1を代入 */
    l2->node = n2;
    l3->node = n3;

    l1->next = l2;                            /*構造体Layerの l1 のメンバーnextに構造体Layerの l2を代入 */
    l2->next = l3;

    lv1->layer = l1;                          /* 構造体Layer_vecの lv1 のメンバーlayerに構造体Layerの l1を代入 */
    lv2->layer = l2;
    lv3->layer = l3;

}