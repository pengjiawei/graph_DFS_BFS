#include <iostream>
#include <queue>
#include <stack>

typedef char vertexType;
typedef int edgeType;
#define MAXEDGE 15
#define MAXVEX 9
typedef struct {
    vertexType vexs[MAXVEX];    //顶点表
    edgeType arc[MAXVEX][MAXVEX];   //邻接矩阵，也可以采用邻接表的方式来表示图
    int numVertex, numEdges;
} Graph;
bool visited[MAXVEX];

int getNum(char c) {
    if (c == 'a')
        return 0;
    if (c == 'b')
        return 1;
    if (c == 'c')
        return 2;
    if (c == 'd')
        return 3;
    if (c == 'e')
        return 4;

}

//递归实现的深度优先遍历
void DFS(Graph &g, int i) {
    visited[i] = true;
    printf("vertex : %c\n", g.vexs[i]);
    for (int j = 0; j < g.numVertex; ++j) {
        if (g.arc[i][j] == 1 && !visited[j]) {
            DFS(g, j);
        }
    }
}

void DFSTraverse(Graph g) {
    for (int i = 0; i < g.numVertex; ++i) {
        visited[i] = false;
    }
    for (int j = 0; j < g.numVertex; ++j) {
        if (!visited[j]) {
            DFS(g, j);
        }
    }
}

void DFS_NotR(Graph g) {
    std::stack<vertexType> s1;
    for (int i = 0; i < g.numVertex; ++i) {
        visited[i] = false;
    }
    int j = 0;
    s1.push(g.vexs[j]);
    visited[j] = true;

    while (!s1.empty()) {
        vertexType v1 = s1.top();
        printf("vertex: %c\n", v1);
        s1.pop();
        for (int i = 0; i < g.numVertex; ++i) {
            //寻找current node的邻节点
            if (g.arc[getNum(v1)][i] == 1 && !visited[i]) {
                s1.push(g.vexs[i]);
            }
        }
    }
}

//广度优先照我的理解有点像层次遍历
void BFSTraverse(Graph g) {
    std::queue<vertexType> q1;
    for (int i = 0; i < g.numVertex; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < g.numVertex; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            q1.push(g.vexs[i]);
            while (!q1.empty()) {
                vertexType v = q1.front();
                printf("vertex : %c\n", v);
                q1.pop();
                for (int j = 0; j < g.numVertex; ++j) {
                    if (g.arc[i][j] == 1 && !visited[j]) {
                        visited[j] = true;
                        q1.push(g.vexs[j]);
                    }
                }
            }
        }
    }
}

int main() {
    Graph g;
    g.numVertex = 5;
    g.numEdges = 4;
    g.vexs[0] = 'a';
    g.vexs[1] = 'b';
    g.vexs[2] = 'c';
    g.vexs[3] = 'd';
    g.vexs[4] = 'e';
    g.arc[0][1] = 1;
    g.arc[1][2] = 1;
    g.arc[0][3] = 1;
    g.arc[2][4] = 1;
    DFSTraverse(g);
    printf("\n");
    BFSTraverse(g);
    printf("\n");
    DFS_NotR(g);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}