#include <iostream>

using namespace std;

int main()
{
	string str;
	int query;
	bool conversion = false;
	cin >> str;
	cin >> query;

	int* LR = new int[2];
	bool* pointLR = new bool[str.length() + 1]{ false };
	int i = 0;
	while (i < query)
	{
		cin >> LR[0];
		cin >> LR[1];
		if (LR[0] > LR[1]) swap(LR[0], LR[1]);
		LR[0]--;
		pointLR[LR[0]] = !pointLR[LR[0]];
		pointLR[LR[1]] = !pointLR[LR[1]];
		
		i++;
	}

	i = 0;
	while (i < str.length())
	{ 
		conversion ^= pointLR[i];
		if (conversion)
		{
			if (islower(str[i])) str[i] = toupper(str[i]);
			else str[i] = tolower(str[i]);
		}
		i++;
	}
	cout << str;

	return(0);
}