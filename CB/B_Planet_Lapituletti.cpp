/*
* @Author: Zakaria 
* @Date:   2023-02-22 19:12:02
* @Last Modified time: 2023-02-22 20:12:56
*/
#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  sof         sizeof
#define  endl        '\n'
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int mod = 1e9+7;
const int N = 2e5+6;


int h, m;
string s;
string pans;


bool ok(int start)
{
	// cout<<start<<endl;
	 int temphour = start/m;
	 int tempmin = start%m;
     
    //  cout<<temphour<<" "<<tempmin<<endl;
     // cout<<"after "<<endl;

     temphour%=h;
     tempmin%=m;

	// cout<<temphour<<" "<<tempmin<<endl;

	 pans="";
	 pans+=(char)((tempmin%10)+'0');

	 tempmin/=10;

	 pans+=(char)((tempmin%10)+'0');

	 swap(tempmin, temphour);

	 pans+=(char)((tempmin%10)+'0');

	 tempmin/=10;

	 pans+=(char)((tempmin%10)+'0');

	 //cout<<pans<<endl;

     
	 for(auto &i : pans)
	 {
	 	if(i=='1' || i=='0' || i=='8' || i=='2' || i=='5')
	 	{
	 		if(i=='2')
	 			i='5';
	 		else if(i=='5')
	 			i='2';
	 		continue;
	 	}

	 	return 0;
	 }

	 int curh = (pans[0]-'0')*10 + pans[1]-'0';
	 int curm = (pans[2] -'0' ) *10 + pans[3]-'0';

	 // cout<<"here"<<endl;
	 // cout<<pans<<endl;
	 // cout<<curh<<" "<<curm<<endl;
     
     // cout<<endl;

	 if(curh>=h || curm>=m)
	 	return 0;

	

	 reverse(pans.begin(), pans.end());

	 for(auto &i : pans)
	 {
	 	if(i=='1' || i=='0' || i=='8' || i=='2' || i=='5')
	 	{
	 		if(i=='2')
	 			i='5';
	 		else if(i=='5')
	 			i='2';
	 		continue;
	 	}

	 	return 0;
	 }

	

	 return 1;

}

void Solve()
{
        
       
       cin>>h>>m;


       
       cin>>s;

       

       int hour = (s[0]-'0')*10 + s[1]-'0';
       int minute = (s[3]-'0')*10 + s[4] - '0';

      // cout<<hour<<" "<<minute<<endl;

       int tot = h*m;


       int start = hour*m + minute;

     //  cout<<start<<endl;

       while(1)
       {
       	 //  cout<<start<<endl;
       	   if(ok(start))
       	   {
       	   	   cout<<pans[0]<<pans[1]<<":"<<pans[2]<<pans[3]<<endl;
       	   	  
       	   	   return ;
       	   }

       	    start++;
       	    start%=tot;
       }
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 