#include <iostream>
#include <vector>

using namespace std;

vector <int> graph[10001];
bool isVisited[10001];
int vertexCter, edgesCter;
int addedEdges = 0;

void depthFSearch(int ver) {
    isVisited[ver] = true;

    int i = 0;
    while (i < (int)graph[ver].size()) {
        int nextVertex = graph[ver][i];
        if (!isVisited[nextVertex])
            depthFSearch(nextVertex);
        i++;
    }
}

int main() {
    cin >> vertexCter >> edgesCter;

    int i = 0;
    while (i < edgesCter) {
        int firstVertex, secondVertex;
        cin >> firstVertex >> secondVertex;
        graph[firstVertex].push_back(secondVertex);
        graph[secondVertex].push_back(firstVertex);
        i++;
    }

    i = 1;
    while (i <= vertexCter) {
        if (!isVisited[i]) {
            depthFSearch(i);
            addedEdges++;
        }
        i++;
    }

    cout << addedEdges - 1;
    return 0;
}