#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



int main()
{
	string S;
	while (cin>>S)
	{
		int Pos_Small(0), Num_Small(0), Pos_Large(0), Num_Large(0);
		int n = S.length();
		transform(S.begin(), S.end(), S.begin(), ::toupper);
		string * p = new string[n];
		string Small=S, Large=S;
		for (int i = 0; i < n; i++)
		{
			if (S.compare(Small) < 0)
			{
				Small = S;
				Pos_Small = i;
			}
			else if (S.compare(Large) > 0)
			{
				Large = S;
				Pos_Large = i;
			}
			p[i] = S;
			char temp = S[0];
			string temps = "";
			temps += temp;
			S.erase(0, 1);
			S.append(temps);
		}
		for (int i = 0; i < n; i++)
		{
			if (p[i].compare(Small) == 0)
				Num_Small++;
			if (p[i].compare(Large) == 0)
				Num_Large++;
		}
		Pos_Large++; Pos_Small++;
		cout << Pos_Small << " " << Num_Small << " " << Pos_Large << " " << Num_Large << endl;
		delete[] p;
	}
//	system("pause");
	return 0;
}