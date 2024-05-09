/*#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <iomanip>
#include <numeric>
#include <utility>
#include <limits>
#include <climits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <complex>
#include <cstring>

#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  mod         1000000007
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         2000002 

typedef long long ll;
using namespace std;


int main()
{
     
      ios::sync_with_stdio(false);
      cin.tie(0); 
      
      int tt;
      cin>>tt;
      while(tt--)
      {
          
      }
      

return 0;           
              
}

*/
// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to count the minimum number
// of swaps required to make the parity
// of array elements same as their indices
void minimumSwaps(int arr[], int N)
{
     // Stores count of even
     // and odd array elements
     int even = 0, odd = 0;

     // Traverse the array
     for (int i = 0; i < N; i++) {

          // Check if indices and
          // array elements are not
          // of the same parity
          if (arr[i] % 2 != i % 2) {

               // If index is even
               if (i % 2 == 0) {

                    // Update even
                    even++;
               }
               else {

                    // Update odd
                    odd++;
               }
          }
     }

     // Condition for not possible
     if (even != odd) {

          cout << -1;
     }

     // Otherwise
     else {
          cout << even;
     }
}

// Driver Code
int main()
{
     int arr[] = { 1, 1, 1, 2, 2, 2 };
     int N = sizeof(arr) / sizeof(arr[0]);

     minimumSwaps(arr, N);

     return 0;
}
