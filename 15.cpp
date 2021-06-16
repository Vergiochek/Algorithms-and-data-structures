#include <iostream>

using namespace std;

int main() {
    int amount;
    long int checknumber, biggestnumber, answer = 0;
    cin >> amount;
    cin >> checknumber;

    int* numbers = new int[amount];
    for (int i = 1; i < amount; i++) {
        cin >> numbers[i];
    }

    biggestnumber = checknumber;
    for (int i = 1; i < amount; i++) {
        if (numbers[i] > biggestnumber) {
            answer += (numbers[i] - biggestnumber);
            biggestnumber = numbers[i];
        }
        else if (numbers[i] < checknumber) answer += (checknumber - numbers[i]);

        checknumber = numbers[i];
    }
    cout << answer;

    delete[] numbers;
    return 0;
}