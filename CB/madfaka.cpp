// C++ program to find the N-th character
// in the string "1234567891011.."
#include <bits/stdc++.h>
using namespace std;

// Function that returns the N-th character
char NthCharacter(int n)
{
	// initially null string
	string s = "";

	// starting integer
	int c = 1;

	// add integers in string
	for (int i = 1;; i++) {

		// one digit numbers added
		if (c < 10)
			s += char(48 + c);

		// more than 1 digit number, generate
		// equivalent number in a string s1
		// and concatenate s1 into s.
		else
		{
			string s1 = "";
			int dup = c;

			// add the number in string
			while (dup) {
				s1 += char((dup % 10) + 48);
				dup /= 10;
			}

			// reverse the string
			reverse(s1.begin(), s1.end());

			// attach the number
			s += s1;
		}
		c++;

		// if the length exceeds N
		if (s.length() >= n) {
			return s[n - 1];
		}
	}
}

// Driver Code
int main()
{
	int n = 100;

	cout << NthCharacter(n);

	return 0;
}

