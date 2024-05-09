#include<bits/stdc++.h>
using namespace std;
int main()
{
    
//go through the array and remove elements from it that are greater than N
//we use sorting for O (N) + unique O(N)
//we go through the sequence in the line and look at the first one that does not correspond to the number in the array
//Example: n = 9, 0 3 5 7 2 4 1 10 19

//delete (>= n) 0 3 5 7 2 4 1 //get unique elements 

//sorting 0 1 2 3 4 5 7  // got unique array 

//analysis of 0-index

//0 in 0 position, 1 in 1 position ... 5 in 5 position, 7 in 6 position

//then the answer is 6

	cout<<"paichi";

	return 0;
}