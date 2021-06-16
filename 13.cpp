#include <iostream>
#include <vector>

using namespace std;

vector <int> graph[10001];
bool isVisited[10001];
int vertexCter, edgesCter;

void depthFSearch(int vertex) {
    isVisited[vertex] = true;
    int i = 0;
    while (i < graph[vertex].size()) {
        int nextVertex = graph[vertex][i];
        if (!isVisited[nextVertex])
            depthFSearch(nextVertex);
        i++;
    }
}

bool connectionChecker() {
    depthFSearch(1);
    int i = 2;
    while (i < vertexCter) {
        if (!isVisited[i]) return false;
        i++;
    }
    return true;
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
    connectionChecker() ? cout << edgesCter - vertexCter + 1 : cout << -1;

    return 0;
}