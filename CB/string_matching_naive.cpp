#include <bits/stdc++.h>
using namespace std;

int main()
{


	string pattern;
	cin>>pattern;

	for(int i=0 ; i<4 ; i++)
	{
		string text;
		cin>>text;

		if(pattern==text)
		{
			cout<<"N"<<endl;
			continue;
		}
		string temp = pattern;
		sort(temp.begin(), temp.end());
		sort(text.begin(), text.end());

		if(temp==pattern)
		{
			cout<<"N"<<endl;
		}
		else
			cout<<"Y"<<endl;
	}




	return 0;
}