//
// Created by Lenovo on 2020/12/17.
//

#include "MatrixGraph.h"
#include "DisjointSet.h"
bool MatrixGraph::isConnected() {
    DisjointSet* pDisjointSet= new  DisjointSet();
    pDisjointSet->init();
//    pDisjointSet->find()
    for(int i=0;i<this->rowCnt;i++){
        for(int j=0;j<this->colCnt;j++){

//            this->graph[i][j]
//            pDisjointSet->unite()
        }
    }

}

bool MatrixGraph::isConnectedEdge(int u,int v) {
    return this->graph[u][v];
}
