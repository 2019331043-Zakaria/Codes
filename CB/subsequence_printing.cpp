#include<bits/stdc++.h>
using namespace std;

set<string>st;

void generate_all_subsequence(string str)
{
    for (int i = 0; i < str.length(); i++) 
    {
         
       
        for (int j = str.length(); j > i; j--) 
        {
            string sub_str = str.substr(i, j);
            st.insert(sub_str);
 
         
            for (int k = 1; k < sub_str.length() - 1; k++) 
            {
                string sb = sub_str;

                sb.erase(sb.begin() + k);
                
                generate_all_subsequence(sb);
            }
        }
    }
}


int main()
{
     
     string s;
     s="123456789";
     generate_all_subsequence(s);
     for(auto i:st)
     	cout<<i<<endl;
     return 0;
}