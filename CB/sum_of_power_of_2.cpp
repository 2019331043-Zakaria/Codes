// CPP program to find k numbers that 
// are power of 2 and have sum equal 
// to N 
#include <bits/stdc++.h> 
using namespace std; 

// function to print numbers 
void printNum(int n, int k) 
{ 
  // Count the number of set bits 
  int x = __builtin_popcount(n); 

  // Not-possible condition 
  if (k < x || k > n) { 
    cout << "-1"; 
    return; 
  } 

  // Stores the number 
  priority_queue<int> pq; 

  // Get the set bits 
  int two = 1; 
  while (n) { 
    if (n & 1) { 
      pq.push(two); 
    } 

    two = two * 2; 
    n = n >> 1; 
  } 

  // Iterate till we get K elements 
  while (pq.size() < k) { 

    // Get the topmost element 
    int el = pq.top(); 
    pq.pop(); 

    // Push the elements/2 into 
    // priority queue 
    pq.push(el / 2); 
    pq.push(el / 2); 
  } 

  // Print all elements 
  int ind = 0; 
  while (ind < k) { 
    cout << pq.top() << " "; 
    pq.pop(); 
    ind++; 
  } 
} 

// Driver Code 
int main() 
{ 
  int n = 5, k = 2; 
  printNum(n, k); 
  return 0; 
} 
