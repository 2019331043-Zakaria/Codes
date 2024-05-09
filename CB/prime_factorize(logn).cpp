/*
* @Author: Zakaria 
* @Date:   2022-12-06 15:21:24
* @Last Modified time: 2023-04-12 21:03:37
*/
#define sz 10000010
bool siv[sz];
int spf[sz];

void seive()
{
    int  limit = sqrt(sz+1);
    
    for(int i=1 ; i<sz ; i++)
        spf[i] = i;

    for(int i=2 ; i<sz ; i+=2)
        spf[i] = 2;

    for (int  i=3; i<=limit; i+=2)
        if(!siv[i])
            for (int  j = i*i; j<sz; j+=i+i)
                siv[j] = 1, spf[j] = min(spf[j], i);
}