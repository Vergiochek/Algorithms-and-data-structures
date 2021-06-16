#include <iostream>
#include <vector>

using namespace std;

const long mods = 1e7 + 7;

int depthFSearch(vector <vector <pair<int, int>>>& graph, int base, int vertex, long long& answer)
{
    int size = 1;

    int i = 0;
    while (i < graph[vertex].size())
    {
        int brat = graph[vertex][i].first;
        int massBrat = graph[vertex][i].second;
        if (brat != base)
        {
            long nextCtr = depthFSearch(graph, vertex, brat, answer);
            size += nextCtr;
            answer += (2 * nextCtr * massBrat * (graph.size() - nextCtr));
            answer %= mods;
        }
        i++;
    }

    return size;
}

int main()
{
    int vertex, firstVertex, secondVertex, leng;
    long long answ = 0;
    cin >> vertex;

    vector <vector <pair<int, int>>> graph(vertex, vector<pair<int, int>>());

    int i = 0;
    while (i < vertex - 1)
    {
        cin >> firstVertex >> secondVertex >> leng;
        graph[firstVertex - 1].push_back(make_pair(secondVertex - 1, leng));
        graph[secondVertex - 1].push_back(make_pair(firstVertex - 1, leng));
        i++;
    }

    i = 0;
    while (i < graph[0].size())
    {
        int batr = graph[0][i].first;
        int massBatr = graph[0][i].second;
        long nextCtr = depthFSearch(graph, 0, batr, answ);
        answ += (2 * nextCtr * massBatr * (graph.size() - nextCtr));
        answ %= mods;
        i++;
    }

    cout << answ;

    return 0;
}