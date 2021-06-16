#include <iostream>

using namespace std;

int main(){
    string X;
    cin >> X;

    if (X[X.length() - 1] == '0') cout << "NO";
    else cout << X[X.length() - 1];

    return 0;
}