#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  sof         sizeof
#define  endl        '\n'
#define  eps         1e-6
typedef long long ll;
using namespace std;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const int N = 5e5 + 6;


string Sbox[16][16] = {
	{"63", "7C", "77", "7B", "F2", "6B", "6F", "C5", "30", "01", "67", "2B", "FE", "D7", "AB", "76"},
	{"CA", "82", "C9", "7D", "FA", "59", "47", "F0", "AD", "D4", "A2", "AF", "9C", "A4", "72", "C0"},
	{"B7", "FD", "93", "26", "36", "3F", "F7", "CC", "34", "A5", "E5", "F1", "71", "D8", "31", "15"},
	{"04", "C7", "23", "C3", "18", "96", "05", "9A", "07", "12", "80", "E2", "EB", "27", "B2", "75"},
	{"09", "83", "2C", "1A", "1B", "6E", "5A", "A0", "52", "3B", "D6", "B3", "29", "E3", "2F", "84"},
	{"53", "D1", "00", "ED", "20", "FC", "B1", "5B", "6A", "CB", "BE", "39", "4A", "4C", "58", "CF"},
	{"D0", "EF", "AA", "FB", "43", "4D", "33", "85", "45", "F9", "02", "7F", "50", "3C", "9F", "A8"},
	{"51", "A3", "40", "8F", "92", "9D", "38", "F5", "BC", "B6", "DA", "21", "10", "FF", "F3", "D2"},
	{"CD", "0C", "13", "EC", "5F", "97", "44", "17", "C4", "A7", "7E", "3D", "64", "5D", "19", "73"},
	{"60", "81", "4F", "DC", "22", "2A", "90", "88", "46", "EE", "B8", "14", "DE", "5E", "0B", "DB"},
	{"E0", "32", "3A", "0A", "49", "06", "24", "5C", "C2", "D3", "AC", "62", "91", "95", "E4", "79"},
	{"E7", "C8", "37", "6D", "8D", "D5", "4E", "A9", "6C", "56", "F4", "EA", "65", "7A", "AE", "08"},
	{"BA", "78", "25", "2E", "1C", "A6", "B4", "C6", "E8", "DD", "74", "1F", "4B", "BD", "8B", "8A"},
	{"70", "3E", "B5", "66", "48", "03", "F6", "0E", "61", "35", "57", "B9", "86", "C1", "1D", "9E"},
	{"E1", "F8", "98", "11", "69", "D9", "8E", "94", "9B", "1E", "87", "E9", "CE", "55", "28", "DF"},
	{"8C", "A1", "89", "0D", "BF", "E6", "42", "68", "41", "99", "2D", "0F", "B0", "54", "BB", "16"}
};

string roundconstant[11][4] = {
	{"00", "00", "00", "00"},
	{"01", "00", "00", "00"},
	{"02", "00", "00", "00"},
	{"04", "00", "00", "00"},
	{"08", "00", "00", "00"},
	{"10", "00", "00", "00"},
	{"20", "00", "00", "00"},
	{"40", "00", "00", "00"},
	{"80", "00", "00", "00"},
	{"1B", "00", "00", "00"},
	{"36", "00", "00", "00"},
};

char charxor(char a, char b)
{
	int l = 0;
	int r = 0;
	if (a >= '0' && a <= '9')
		l = a - '0';
	else
		l = a - 'A' + 10;

	if (b >= '0' && b <= '9')
		r = b - '0';
	else
		r = b - 'A' + 10;

	l ^= r;
	// cout<<"here "<<l<<" ";
	char c = '0';
	if (l <= 9)
		c += l;
	else
		c = 'A' + l - 10;

	// cout<<c<<endl;

	return c;
}

string AddingroundkeyXor(string s, string sr)
{
	// cout<<s<<" "<<sr<<endl;
	string pans = "";
	pans += charxor(s[0], sr[0]);
	pans += charxor(s[1], sr[1]);
	return pans;
}


vector<string> XorKey(vector<string>v1, vector<string>v2)
{
	vector<string>pans;
	for (int i = 0 ; i < 4 ; i++)
	{
		pans.push_back(AddingroundkeyXor(v1[i], v2[i]));
	}

	return pans;
}

string ByteSub(string s)
{
	char l = s[0];
	char r = s[1];

	int p = 0, q = 0;

	if (l >= '0' && l <= '9')
		p = l - '0';

	if (l >= 'A' && l <= 'F')
		p = l - 'A' + 10;

	if (r >= '0' && r <= '9')
		q = r - '0';

	if (r >= 'A' && r <= 'F')
		q = r - 'A' + 10;

	return Sbox[p][q];
}

string decimaltohex(int n)
{

	string ans = "";

	while (n != 0) {
		int rem = 0;

		char ch;
		rem = n % 16;

		if (rem < 10) {
			ch = rem + 48;
		}
		else {
			ch = rem + 55;
		}

		ans += ch;
		n = n / 16;
	}
	int i = 0, j = ans.size() - 1;
	while (i <= j)
	{
		swap(ans[i], ans[j]);
		i++;
		j--;
	}

	reverse(ans.begin(), ans.end());
	while (ans.size() < 2)
		ans += "0";
	reverse(ans.begin(), ans.end());

	return ans;
}


string keyhex[20];
string plainhex[20];

vector<string>wkey[100];
vector<string>roundkey[100];

vector<string>ggkey(int roundnumber, vector<string>v)
{

	// cout<<roundnumber<<"\n";
	// for(auto i:v)
	// 	cout<<i<<" ";
	// cout<<endl;

	for (int i = 0 ; i < v.size() - 1 ; i++)
		swap(v[i], v[i + 1]);

	// for (auto i : v)
	// 	cout << i << " ";
	// cout << endl;


	for (int i = 0 ; i < v.size() ; i++)
	{
		string p = v[i];

		p = ByteSub(p);

		v[i] = p;
	}


	for (int i = 0 ; i < v.size() ; i++)
	{
		string p = AddingroundkeyXor(v[i],
		                             roundconstant[roundnumber][i]);
		v[i] = p;
	}

	// for (auto i : v)
	// 	cout << i << " ";
	// cout << endl;

	return v;
}


void Encrypted(string key, string plaintext)
{
	for (int i = 0 ; i < key.size() ; i++)
	{
		int x = key[i];
		keyhex[i] = decimaltohex(x);
	}


	for (int i = 0 ; i < key.size() ; i++)
		wkey[i / 4].push_back(keyhex[i]);

	cout << "Round " << 0 << ": ";
	for (int i = 0 ; i < key.size() ; i++)
		cout << keyhex[i] << " ", roundkey[0].push_back(keyhex[i]);
	cout << endl;


	for (int round = 1 ; round <= 10 ; round++)
	{

		vector<string>gwkey;
		gwkey = ggkey(round, wkey[(round * 4) - 1]);

		// for(auto i:gwkey)
		// 	cout<<i<<" ";
		// cout<<endl;

		wkey[round * 4] = XorKey(wkey[(round - 1) * 4], gwkey);

		// cout<<(round-1)*4<<" "<<round*4<<endl;
		for (int i = 1 ; i <= 3 ; i++)
		{
			wkey[i + round * 4] = XorKey(wkey[(round - 1) * 4 + i], wkey[-1 + i + round * 4]);
		}

		cout << "Round " << round << ": ";
		for (int i = 0 ; i < 4 ; i++)
		{
			for (auto j : wkey[i + round * 4])
				cout << j << " ", roundkey[round].push_back(j);

		}

		cout << endl;

		// for (int i = 0 ; i < key.size() ; i++)
		// 	roundkey[round].push_back(keyhex[i]);

		// // cout << "Round " << round << ": ";
		// // for (auto i : roundkey[round])
		// // 	cout << i << " ";
		// // cout << endl;

	}

}

void Solve()
{


	string plaintext, key;

	getline(cin, key);
	getline(cin, plaintext);

	Encrypted(key, plaintext);

	// for (int i = 0 ; i <= 10 ; i++)
	// {
	// 	for (auto j : roundkey[i])
	// 		cout << j << " ";
	// 	cout << endl;
	// }




}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);


	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);

	int tt = 1, testcae = 1;

	// cin >> tt;

	while (tt--)
	{

		//cout<<"Case "<<testcae++<<": ";

		Solve();
	}

	return 0;

}