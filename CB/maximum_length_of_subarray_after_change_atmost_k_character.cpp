#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
 
      ios::sync_with_stdio(false);
      cin.tie(0); 
      
      int n,k;
      cin>>n>>k;
      string s;
      cin>>s;
      


     int ans=0;
    

     
     

     for(char x='a';x<='z';x++)
     {
       //test all the character one by one;

       int one=0,two=0;//here two is different character thats not equal to x
     
       int j=0;

      for(int i=0;i<n;i++)
      {
         if(s[i]!=x)
         two++;

        while(two>k&&j<n)
        {   
        	//while different character is greater than k; 
           if(s[j]!=x)
             two--;
            j++;
        }

        ans=max(ans,abs(i-j)+1);

     }
      

      }

     cout<<ans<<endl;
      


     
      
     return 0;           
      
        
}