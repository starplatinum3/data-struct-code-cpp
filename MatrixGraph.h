//
// Created by Lenovo on 2020/12/17.
//

#ifndef DATASTRUCT_MATRIXGRAPH_H
#define DATASTRUCT_MATRIXGRAPH_H


class MatrixGraph {
    const int MAX_N = 1e3 + 7;
    int rowCnt;
    int colCnt;
    int **graph;

    bool isConnected();

    bool isConnectedEdge(int u, int v);
};


#endif //DATASTRUCT_MATRIXGRAPH_H
