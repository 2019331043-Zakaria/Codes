#include<bits/stdc++.h>
#define pb push_back
#define s sort
#define test int t; cin>>t; while(t--)
typedef long long ll;
using namespace std;
ll ans(string expr)
{
    int len = expr.length();

	if (len%2)
	return -1;
	stack<char> s;
	for (int i=0; i<len; i++)
	{
		if (expr[i]==')' && !s.empty())
		{
			if (s.top()=='(')
				s.pop();
			else
				s.push(expr[i]);
		}
		else
			s.push(expr[i]);
	}

	int red_len = s.size();
	int n = 0;
	while (!s.empty() && s.top() == '(')
	{
		s.pop();
		n++;
	}
	return (red_len/2 + n%2);
}




int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
       test
       {
              int n;
              cin>>n;
              string expr;
              cin>>expr;
              if(ans(expr))
                cout<<ans(expr)-1<<endl;
              else
                cout<<0<<endl;

       }



 return 0;
}
