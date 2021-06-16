#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector <vector <pair <int, int>>> graph;
vector <pair <int, int>> item;

long long answer[100001];
bool checkedVertex[100001];

struct Vertex {
    int thisNumba;
    long long thisWeigth;

    bool operator<(const Vertex& anth) const {
        return thisWeigth > anth.thisWeigth;
    }
};

int main() {
    int vertexCter, edgesCter;
    cin >> vertexCter >> edgesCter;
    priority_queue <Vertex> ourWeigth;

    int i = 0;
    while (i <= vertexCter) {
        graph.push_back(item);
        answer[i] = 1000000000000;
        checkedVertex[i] = false;
        i++;
    }

    i = 0;
    while ( i < edgesCter) {
        int firstVertex, secondVertex, vertexWeigth;
        cin >> firstVertex >> secondVertex >> vertexWeigth;

        graph[firstVertex].push_back(pair<int, int>(secondVertex, vertexWeigth));
        graph[secondVertex].push_back(pair<int, int>(firstVertex, vertexWeigth));

        i++;
    }

    int initVrtx, finalVrtx;
    cin >> initVrtx >> finalVrtx;

    ourWeigth.push(Vertex{ initVrtx, 0 });
    answer[initVrtx] = 0;

    int j = 0;
    while (j < vertexCter) {
        Vertex myVertex;

        while (true) {
            myVertex = ourWeigth.top();
            ourWeigth.pop();

            if (checkedVertex[myVertex.thisNumba]) continue;

            checkedVertex[myVertex.thisNumba] = true;
            break;
        }

        int i = 0;
        while (i < (int)graph[myVertex.thisNumba].size()) {
            long long verify = myVertex.thisWeigth + graph[myVertex.thisNumba][i].second;

            if (answer[graph[myVertex.thisNumba][i].first] > verify) {
                answer[graph[myVertex.thisNumba][i].first] = verify;
                ourWeigth.push(Vertex{ graph[myVertex.thisNumba][i].first, verify });
            }
            i++;
        }
        j++;
    }

    cout << answer[finalVrtx];

    return 0;
}