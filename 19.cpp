#include <iostream>
#include <vector>

using namespace std;

void sortAndMerge(int* orderian, int beginChar, int endChar, long* reverse)
{
    if (beginChar < endChar)
    {
        int mediumChar = (beginChar + endChar) / 2;

        sortAndMerge(orderian, beginChar, mediumChar, reverse);
        sortAndMerge(orderian, mediumChar + 1, endChar, reverse);

        int* kindaT = new int[endChar - beginChar + 1];
        int temp1 = beginChar, temp2 = mediumChar + 1, temp3 = 0;

        while (temp1 <= mediumChar && temp2 <= endChar)
        {
            if (orderian[temp1] <= orderian[temp2])
            {
                kindaT[temp3] = orderian[temp1];
                temp1++;
            }
            else
            {
                kindaT[temp3] = orderian[temp2];
                temp2++;
                *reverse += mediumChar - temp1 + 1;
            }
            temp3++;
        }

        while (temp1 <= mediumChar)
        {
            kindaT[temp3] = orderian[temp1];
            temp3++;
            temp1++;
        }

        while (temp2 <= endChar)
        {
            kindaT[temp3] = orderian[temp2];
            temp3++;
            temp2++;
        }

        int i = beginChar, j = 0;
        while (i <= endChar)
        {
            orderian[i] = kindaT[j];
            i++; 
            j++;
        }

        delete[] kindaT;
    }
}

int main()
{
    int amount;
    cin >> amount;

    int* order = new int[amount];

    int n = 0;
    while (n < amount)
    {
        cin >> order[n];
        n++;
    }

    long reversals = 0;
    sortAndMerge(order, 0, amount - 1, &reversals);

    cout << reversals;
    return 0;
}