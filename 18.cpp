#include <iostream>

using namespace std;

int main(){
  int whatyear;
  cin >> whatyear;
  
  if(whatyear%4 || (whatyear%100==0 && whatyear%400)) cout << "NO";
  else cout << "YES";

  return 0;
}