/*
    C言語でCNNを作成　ver.2
*/

#include <stdio.h>

typedef struct node{        /* 一つのnode */
    float value;
} Node;

typedef struct edge{        /* 一本のedge */
    Node* lhs;
    Node* rhs;
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

int edge_group[/* Node* lhs の数と Node* rhs の数の積 */] = {   /* edgeの縦方向のカタマリ */
    
};

int main(void){
    
}