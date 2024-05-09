// C++ Program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to count the minimum
// number of subarrays that are
// required to be decremented by 1
int min_operations(vector<int>& A)
{
      // Base Case
      if (A.size() == 0)
            return 0;

      // Initialize ans to first element
      int ans = A[0];

      for (int i = 1; i < A.size(); i++) {

            // For A[i] > A[i-1], operation
            // (A[i] - A[i - 1]) is required
            ans += max(A[i] - A[i - 1], 0);
      }

      // Return the answer
      return ans;
}

// Driver Code
int main()
{
      vector<int> A{ 4, 3, 2 ,1 };

      cout << min_operations(A) << "\n";

      return 0;
}
