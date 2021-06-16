#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int arrayOfNumbas[100001];
vector <pair <int, pair <int, int>>> leftSorterRequest;
vector <pair <int, pair <int, int>>> rightSorterRequest;

multiset <int> answerSet;

int main() {
    int firstN, secondM;
    cin >> firstN >> secondM;

    int i = 0;
    while (i < 100001) {
        arrayOfNumbas[i] = 0;
        i++;
    }

    i = 0;
    while (i < secondM) {
        int firstL, secondR, thirdV;
        cin >> firstL >> secondR >> thirdV;
        leftSorterRequest.push_back(pair <int, pair <int, int>>(thirdV, pair <int, int>(firstL, secondR)));
        rightSorterRequest.push_back(pair <int, pair <int, int>>(thirdV, pair <int, int>(firstL, secondR)));
        i++;
    }

    sort(leftSorterRequest.begin(), leftSorterRequest.end(),[](const pair <int, pair <int, int>> varka,const pair <int, pair <int, int>> varkaSecond) {return varka.second.first < varkaSecond.second.first; });
    sort(rightSorterRequest.begin(), rightSorterRequest.end(),[](const pair <int, pair <int, int>> varka,const pair <int, pair <int, int>> varkaSecond) {return varka.second.second < varkaSecond.second.second;});

    vector <bool> alreadySetted(secondM, false);
    int firstLP = 0;
    int secondRP = 0;

    i = 0;
    while (i < firstN) {
        while (firstLP < secondM && i + 1 >= leftSorterRequest[firstLP].second.first) {
            answerSet.insert(leftSorterRequest[firstLP].first);
            firstLP++;
        }
        while (secondRP < secondM && i + 1 > rightSorterRequest[secondRP].second.second) {
            answerSet.erase(answerSet.lower_bound(rightSorterRequest[secondRP].first));
            secondRP++;
        }
        if (answerSet.size() > 0) {
            arrayOfNumbas[i] = *(--answerSet.end());
        }
        i++;
    }

    i = 0;
    while (i < firstN) {
        cout << arrayOfNumbas[i] << " ";
        i++;
    }

    return 0;
}