#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long multip = 1000000007;

long long multiplying(long long first, long long second) {
    return ((first % multip) * (second % multip)) % multip;
}

int main() {
    int amount, kindaK;
    long long answer = 1;
    long long inpNumbs[100000];

    cin >> amount >> kindaK;

    int i = 0;
    while (i < amount) {
        cin >> inpNumbs[i];
        i++;
    }

    sort(inpNumbs, inpNumbs + amount);

    if (inpNumbs[0] >= 0) {
        int i = amount - 1;
        while (i > amount - kindaK - 1) {
            answer = multiplying(answer, inpNumbs[i]);
            i--;
        }
    }

    else if (inpNumbs[amount - 1] <= 0) {
        if (kindaK % 2 == 0) {
            int i = 0;
            while (i > kindaK) {
                answer = multiplying(answer, inpNumbs[i]);
                i++;
            }
        }
        else {
            int i = amount - 1;
            while (i > amount - kindaK - 1) {
                answer = multiplying(answer, inpNumbs[i]);
                i--;
            }
        }
    }

    else {
        int prev = 0, last = amount - 1;

        while (kindaK > 0) {
            if (kindaK > 1 && (inpNumbs[prev] * inpNumbs[prev + 1]) >= (inpNumbs[last] * inpNumbs[last - 1])) {
                answer = multiplying(answer, multiplying(inpNumbs[prev], inpNumbs[prev + 1]));
                prev += 2;
                kindaK -= 2;
            }
            else {
                answer = multiplying(answer, inpNumbs[last]);
                last--;
                kindaK--;
            }
        }
    }

    answer = (answer + multip) % multip;
    cout << answer;
    return 0;
}