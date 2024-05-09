/*
* @Author: Zakaria 
* @Date:   2022-09-09 09:08:33
* @Last Modified time: 2022-09-09 09:45:54
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
#define  MAX         200002
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int N = 1e5+6;

void work(string ans, int a, int b, int c, int d)
{
	   for(auto i:ans)
       {
       	  if(i=='4')
       	  	a--;
       	  else if(i=='7')
       	  	b--;
       }

       if(a<0 || b<0)
       {
       	  cout<<-1<<endl;
       	  return ;
       }

       string temp="";

       string remain="";

       for(int i=0 ; i<ans.size() ; i++)
       {
       	   if(ans[i]!='4')
       	   	temp+=ans[i];
       	   else
       	   {
       	   	   for(int j=i ; j<ans.size() ; j++)
       	   	   	remain+=ans[j];
       	   	   break;
       	   }
       }
       while(a--)
       	temp+="4";

       ans=temp+remain;

       temp="";
       while(b--)
       	temp+="7";

       int indx=0;

       for(int i=0 ; i<ans.size() ; i++)
       {
       	   if(ans[i]=='7')
       	   	indx=i;
       }

       for(int i=0 ; i<ans.size() ; i++)
       {
       	  cout<<ans[i];
       	  if(i==indx)
       	  	cout<<temp;
       }
       cout<<endl;

}

void Solve()
{
        
       int a, b, c, d;

       cin>>a>>b>>c>>d;

       if(abs(c-d)>1)
       {
       	   cout<<-1<<endl;
       	   return ;
       }
       
       string ans="";

       if(c==d)
       {
       	   
	            for(int i=0 ; i<c ; i++)
	            	ans+="47";
	                ans+="4";

                int tempa=a, tempb=b;
                for(auto i:ans)
                {
                	if(i=='4')
                		tempa--;
                	else
                		tempb--;
                }


                if(tempb>=0 && tempa>=0)
                {
                	work(ans, a, b, c, d);
                	return ;
                }

                ans="";

           	   for(int i=0 ; i<c ; i++)
	            	ans+="74";
	                ans+="7";

	             tempa=a, tempb=b;

	             for(auto i:ans)
                {
                	if(i=='4')
                		tempa--;
                	else
                		tempb--;
                }
                if(tempb>=0 && tempa>=0)
                {
                	work(ans, a, b, c, d);
                	return ;
                }

                cout<<-1<<endl;
                return ;

           
       }
       else if(c>d)
       {
       	    for(int i=0 ; i<c ; i++)
       	    	ans+="47";
       }
       else
       {
       	    for(int i=0 ; i<d ; i++)
       	    	ans+="74";
       }
       
      // cout<<ans<<endl;

 

       for(auto i:ans)
       {
       	  if(i=='4')
       	  	a--;
       	  else if(i=='7')
       	  	b--;
       }

       if(a<0 || b<0)
       {
       	  cout<<-1<<endl;
       	  return ;
       }

       string temp="";

       string remain="";

       for(int i=0 ; i<ans.size() ; i++)
       {
       	   if(ans[i]!='4')
       	   	temp+=ans[i];
       	   else
       	   {
       	   	   for(int j=i ; j<ans.size() ; j++)
       	   	   	remain+=ans[j];
       	   	   break;
       	   }
       }
       while(a--)
       	temp+="4";

       ans=temp+remain;

       temp="";
       while(b--)
       	temp+="7";

       int indx=0;

       for(int i=0 ; i<ans.size() ; i++)
       {
       	   if(ans[i]=='7')
       	   	indx=i;
       }

       for(int i=0 ; i<ans.size() ; i++)
       {
       	  cout<<ans[i];
       	  if(i==indx)
       	  	cout<<temp;
       }
       cout<<endl;


      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
    //    cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 