/*
    C言語でCNNを作成　ver.2     3×3の簡易版
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

typedef struct Layer {     /* nodeの縦方向のカタマリ */
    Node* node;
    struct Layer* next;
} Layer;

typedef struct Layer_vec {   /* "nodeの縦方向のカタマリ" の横方向のカタマリ */
    Layer* layer;
    struct Layer_vec* next;
} Layer_vec;

typedef struct Edge_layer {     /* "edgeの縦方向のカタマリ" の横方向のカタマリ */
    Edge** edge;          /* edgeの配列を指すポインタを宣言（するだけ） */
    struct Edge_layer* next;
} Edge_layer;


int main(void){

    Node ***nodes = malloc(sizeof(Node*) * 3);       /* Nodeを記録する魔法の場所を確保 */
    for (int i = 0; i < 3; i++) {                    
        Node** tmp = malloc(sizeof(Node) * 3);
        for (int j = 0; j < 3; j++) {
            tmp[j] = malloc(sizeof(Node));
        }
    }
    int k = 2;                 /* 仮の値 */
    for (int i = 0; i < 3; i++) {                    /* 構造体Nodeの n1 のメンバーvalueに実数（仮の値）を代入 */
        for (int j = 0; j < 3; j++) {
            nodes[i][j]->value = k + 1;
            k = (k + 1) % 9;
        }
    }


    Layer** layers = malloc(sizeof(Layer) * 3);       /* Nodeの縦のカタマリを記録する魔法の場所を確保 */
    for (int i = 0; i < 3; i++) {
        layers[i] = malloc(sizeof(Layer));
    }

    Layer_vec* lv1 = malloc(sizeof(Layer_vec));     /* "Nodeの縦方向のカタマリ" の横方向のカタマリを記録する魔法の場所を確保 */


/* Layer（nodevec） */

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            layers[i]->node = nodes[i][j];          /* 構造体Layerの l1 のメンバーnodeに構造体Nodeの n1 を代入 */
            layers[i]->next = layers[i]; 
        }
        lv1->layer = layers[i];                     /* 構造体Layer_vecの lv1 のメンバーlayerに構造体Layerの l1を代入 */
        lv1->next = lv1;                            /*構造体Layer_vecの lv1 のメンバーnextに構造体Layer_vecの lv1を代入 */
    }

    int i, j;
    Edge_layer* el = malloc(sizeof(Edge_layer));      /* "edgeの縦方向のカタマリ" の横方向のカタマリを記録する魔法の場所を確保 */
    int Edge_group[9];                                /* edgeの層（縦方向） */
    Edge* e;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            e = malloc(sizeof(Edge));           /* Edgeを記録する魔法の場所を確保 */

            for (k = 0; k < 3; k++) {
                e->lhs = nodes[i][j];           /* lhs（ポインタ）にnodes（ポインタ）を代入（二重ポインタではない。丸々ぶち込むイメージ） */
                e->rhs = nodes[j + 1][k];       /* エッジの左手右手にノードを渡す感じ */

                Edge_group[(k + 1) * (j + 1)] = e;      /* 配列にeを格納 */
            }
        }
        el->edge = Edge_group;                           /* 構造体Edge_layerの el のメンバーedgeに配列Edge_groupを代入 */
        el->next = el;                                   /* 構造体Edge_layerの el のメンバーnextに構造体Edge_layerの elを代入 */
    }
}