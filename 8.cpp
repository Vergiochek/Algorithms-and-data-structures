#include <iostream>

using namespace std;

int main(){
    string S;
    cin >> S;
    int leng = (int)S.length();
    
    bool checkexist = true;
	for (int i = 0, j = leng -1 ; i < j + 1 ; i++, j--) {
	    if (S[i] != S[0] || S[j] != S[0]) checkexist = false;
	}
	
	if (checkexist){
	    cout << "-1";
	    return 0;
	}

	bool checkpalindrome = true;
	for (int i = 0, j = leng - 1; i < j+1; i++, j--) {
	    if (S[i] != S[j]) checkpalindrome = false;
	}
	
	if(checkpalindrome) cout << leng-1;
    else cout << leng;
   
    return 0;
}