#include <iostream>
#include <vector>

using namespace std;

const int thismods = 1e9 + 7;

vector <vector <long long>> vecsMulti(vector<vector<long long>> firstVec, vector<vector<long long>> secondVec)
{
    int thislen = firstVec.size();
    vector<vector<long long>> answr = vector<vector<long long>>(thislen, std::vector<long long>(thislen, 0));

    int i = 0;
    while (i < thislen)
    {
        int j = 0;
        while (j < thislen)
        {
            int k = 0;
            while (k < thislen)
            {
                answr[i][j] += (firstVec[i][k] * secondVec[k][j]) % thismods;
                answr[i][j] %= thismods;
                k++;
            }
            j++;
        }
        i++;
    }

    return answr;
}

vector<vector<long long>> expOfBin(vector<vector<long long>> vec, long long exp)
{
    int thislen = vec.size();
    vector<vector<long long>> answr = vector<vector<long long>>(thislen, std::vector<long long>(thislen, 0));

    int i = 0;
    while (i < thislen)
    {
        answr[i][i] = 1;
        i++;
    }

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            answr = vecsMulti(answr, vec);
            exp -= 1;
        }
        else
        {
            vec = vecsMulti(vec, vec);
            exp /= 2;
        }
    }

    return answr;
}

int main()
{
    int vertex, edge, firstVer, secondVer, numVerFirst, numVerSecond;
    long long lenga;

    cin >> vertex >> edge;
    cin >> firstVer >> secondVer >> lenga;

    vector<vector<long long>> vecNeibahd = vector<vector<long long>>(vertex, vector<long long>(vertex, 0));

    int i = 0;
    while (i < edge)
    {
        cin >> numVerFirst >> numVerSecond;

        if (numVerFirst == numVerSecond)
        {
            vecNeibahd[numVerFirst - 1][numVerSecond - 1] += 2;
        }
        else
        {
            vecNeibahd[numVerFirst - 1][numVerSecond - 1] += 1;
            vecNeibahd[numVerSecond - 1][numVerFirst - 1] += 1;
        }
        i++;
    }

    cout << expOfBin(vecNeibahd, lenga)[firstVer - 1][secondVer - 1];

    return 0;
}