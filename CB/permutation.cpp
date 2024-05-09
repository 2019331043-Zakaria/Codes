// C++ program to print all permutations with
// duplicates allowed using next_permutation
#include <bits/stdc++.h>
using namespace std;

// Function to print permutations of string str
// using next_permutation
void permute(string str)
{
	int cnt=0;
	// Sort the string in lexicographically
	// ascennding order
	sort(str.begin(), str.end());
     reverse(str.begin(),str.end());
	// Keep printing next permutation while there
	// is next permutation
	do {
	      cnt++;
	       if(cnt==4)
           {
               cout<<str<<endl;
           }
	} while (prev_permutation(str.begin(), str.end()));
}

// Driver code
int main()
{
	string str = "bbaaa";
	permute(str);
	return 0;
}
