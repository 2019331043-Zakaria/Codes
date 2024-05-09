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

#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << "\n\n";}
void err (istream_iterator<string> it) {}
template<typename T, typename... Args>
void err (istream_iterator<string> it, T a, Args... args) {
	cerr << *it << "=" << a << " ! ";
	err (++it, args...);
}

template<class L, class R> ostream& operator << (ostream& out, pair<L, R>& p) { return out << "(" << p.f << ", " << p.s << ")"; }
template<class T> ostream& operator << (ostream& out, vector<T>& v) { out << "["; for (auto it = v.begin (); it != v.end (); ++it) { if (it != v.begin ())out << ", "; out << *it; } return out << "]"; }
template<class T> ostream& operator << (ostream& out, deque<T>& v) { out << "["; for (auto it = v.begin (); it != v.end (); ++it) { if (it != v.begin ())out << ", "; out << *it; } return out << "]"; }
template<class T> ostream& operator << (ostream& out, set<T>& s) { out << "{"; for (auto it = s.begin (); it != s.end (); ++it) { if (it != s.begin ())out << ", "; out << *it; } return out << "}"; }
template<class T> ostream& operator << (ostream& out, multiset<T>& s) { out << "{"; for (auto it = s.begin (); it != s.end (); ++it) { if (it != s.begin ())out << ", "; out << *it; } return out << "}"; }
template<class L, class R> ostream& operator << (ostream& out, map<L, R>& m) { out << "{"; for (auto it = m.begin (); it != m.end (); ++it) { if (it != m.begin ())out << ", "; out << *it; } return out << "}"; }



const int mod = 1e9 + 7;
const int N = 4e5 + 9;
const int LG = 18;

void induced_sort(const vector<int> &vec, int val_range, vector<int> &SA, const vector<bool> &sl, const vector<int> &lms_idx) {
	vector<int> l(val_range, 0), r(val_range, 0);
	for (int c : vec) {
		if (c + 1 < val_range) ++l[c + 1];
		++r[c];
	}
	partial_sum(l.begin(), l.end(), l.begin());
	partial_sum(r.begin(), r.end(), r.begin());
	fill(SA.begin(), SA.end(), -1);
	for (int i = lms_idx.size() - 1; i >= 0; --i)
		SA[--r[vec[lms_idx[i]]]] = lms_idx[i];
	for (int i : SA)
		if (i >= 1 && sl[i - 1]) {
			SA[l[vec[i - 1]]++] = i - 1;
		}
	fill(r.begin(), r.end(), 0);
	for (int c : vec)
		++r[c];
	partial_sum(r.begin(), r.end(), r.begin());
	for (int k = SA.size() - 1, i = SA[k]; k >= 1; --k, i = SA[k])
		if (i >= 1 && !sl[i - 1]) {
			SA[--r[vec[i - 1]]] = i - 1;
		}
}

vector<int> SA_IS(const vector<int> &vec, int val_range) {
	const int n = vec.size();
	vector<int> SA(n), lms_idx;
	vector<bool> sl(n);
	sl[n - 1] = false;
	for (int i = n - 2; i >= 0; --i) {
		sl[i] = (vec[i] > vec[i + 1] || (vec[i] == vec[i + 1] && sl[i + 1]));
		if (sl[i] && !sl[i + 1]) lms_idx.push_back(i + 1);
	}
	reverse(lms_idx.begin(), lms_idx.end());
	induced_sort(vec, val_range, SA, sl, lms_idx);
	vector<int> new_lms_idx(lms_idx.size()), lms_vec(lms_idx.size());
	for (int i = 0, k = 0; i < n; ++i)
		if (!sl[SA[i]] && SA[i] >= 1 && sl[SA[i] - 1]) {
			new_lms_idx[k++] = SA[i];
		}
	int cur = 0;
	SA[n - 1] = cur;
	for (size_t k = 1; k < new_lms_idx.size(); ++k) {
		int i = new_lms_idx[k - 1], j = new_lms_idx[k];
		if (vec[i] != vec[j]) {
			SA[j] = ++cur;
			continue;
		}
		bool flag = false;
		for (int a = i + 1, b = j + 1;; ++a, ++b) {
			if (vec[a] != vec[b]) {
				flag = true;
				break;
			}
			if ((!sl[a] && sl[a - 1]) || (!sl[b] && sl[b - 1])) {
				flag = !((!sl[a] && sl[a - 1]) && (!sl[b] && sl[b - 1]));
				break;
			}
		}
		SA[j] = (flag ? ++cur : cur);
	}
	for (size_t i = 0; i < lms_idx.size(); ++i)
		lms_vec[i] = SA[lms_idx[i]];
	if (cur + 1 < (int)lms_idx.size()) {
		auto lms_SA = SA_IS(lms_vec, cur + 1);
		for (size_t i = 0; i < lms_idx.size(); ++i) {
			new_lms_idx[i] = lms_idx[lms_SA[i]];
		}
	}
	induced_sort(vec, val_range, SA, sl, new_lms_idx);
	return SA;
}
vector<int> suffix_array(const string &s, const int LIM = 128) {
	vector<int> vec(s.size() + 1);
	copy(begin(s), end(s), begin(vec));
	vec.back() = '$';
	auto ret = SA_IS(vec, LIM);
	ret.erase(ret.begin());
	return ret;
}
struct SuffixArray {
	int n;
	string s;
	vector<int> sa, rank, lcp;
	vector<vector<int>> t;
	vector<int> lg;
	SuffixArray() {}
	SuffixArray(string _s) {
		n = _s.size();
		s = _s;
		sa = suffix_array(s);
		rank.resize(n);
		for (int i = 0; i < n; i++) rank[sa[i]] = i;
		costruct_lcp();
		prec();
		build();
	}
	void costruct_lcp() {
		int k = 0;
		lcp.resize(n - 1, 0);
		for (int i = 0; i < n; i++) {
			if (rank[i] == n - 1) {
				k = 0;
				continue;
			}
			int j = sa[rank[i] + 1];
			while (i + k < n && j + k < n && s[i + k] == s[j + k])  k++;
			lcp[rank[i]] = k;
			if (k)  k--;
		}
	}
	void prec() {
		lg.resize(n, 0);
		for (int i = 2; i < n; i++) lg[i] = lg[i / 2] + 1;
	}
	void build() {
		int sz = n - 1;
		t.resize(sz);
		for (int i = 0; i < sz; i++) {
			t[i].resize(LG);
			t[i][0] = lcp[i];
		}
		for (int k = 1; k < LG; ++k) {
			for (int i = 0; i + (1 << k) - 1 < sz; ++i) {
				t[i][k] = min(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
			}
		}
	}
	int query(int l, int r) { // minimum of lcp[l], ..., lcp[r]
		int k = lg[r - l + 1];
		return min(t[l][k], t[r - (1 << k) + 1][k]);
	}
	int get_lcp(int i, int j) { // lcp of suffix starting from i and j
		if (i == j) return n - i;
		int l = rank[i], r = rank[j];
		if (l > r) swap(l, r);
		return query(l, r - 1);
	}
	int lower_bound(string &t) {
		int l = 0, r = n - 1, k = t.size(), ans = n;
		while (l <= r) {
			int mid = l + r >> 1;
			if (s.substr(sa[mid], min(n - sa[mid], k)) >= t) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		return ans;
	}
	int upper_bound(string &t) {
		int l = 0, r = n - 1, k = t.size(), ans = n;
		while (l <= r) {
			int mid = l + r >> 1;
			if (s.substr(sa[mid], min(n - sa[mid], k)) > t) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		return ans;
	}
	// occurrences of s[p, ..., p + len - 1]
	pair<int, int> find_occurrence(int p, int len) {
		p = rank[p];
		pair<int, int> ans = {p, p};
		int l = 0, r = p - 1;
		while (l <= r) {
			int mid = l + r >> 1;
			if (query(mid, p - 1) >= len) ans.first = mid, r = mid - 1;
			else l = mid + 1;
		}
		l = p + 1, r = n - 1;
		while (l <= r) {
			int mid = l + r >> 1;
			if (query(p, mid - 1) >= len) ans.second = mid, l = mid + 1;
			else r = mid - 1;
		}
		return ans;
	}

};

int Table[N][20], a[N];

void Build(vector<int>lcp)
{
	int n = lcp.size();
	for (int i = 1 ; i <= n ; i++)
		Table[i][0] = lcp[i - 1];

	for (int k = 1 ; k < 20 ; k++)
	{
		for (int i = 1 ; i + (1 << k) - 1 <= n ; i++)
			Table[i][k] = min(Table[i][k - 1], Table[i + (1 << (k - 1))][k - 1]);
	}

}

int Query(int l, int r)
{
	l++, r++;
	int k = log2(r - l + 1);
	return min(Table[l][k], Table[r - (1 << k) + 1][k]);
}



pair<int, int>FindRight(int low, int high, int val) // Find maximum R such that lcp(low, low+1...)>Val and return lcp(low, R)
{
	int l = low, r = high, mid;
	int ans = low - 1 ;
	while (l <= r)
	{
		mid = (l + r) / 2;

		if (Query(low , mid) > val)
		{
			ans = mid, l = mid + 1;
		}
		else
			r = mid - 1;
	}

	if (ans == low - 1)
		return {low, -1};
	else
		return {ans + 1, Query(low, ans)};
}

void Solve()
{

	string s;
	cin >> s;

	SuffixArray ehhe(s);

	ll n = s.size();


	vector<int>p = ehhe.sa;

	vector<int>lcp;

	lcp = ehhe.lcp;

	Build(lcp);

	ll ans = 0;

	for (int i = 0 ; i < n ; i++)
	{
		int high = n - 1;
		int pans = i ? lcp[i - 1] : 0;
		int len = n - p[i];

		while (pans < len)
		{
			pair<int, int> pt = FindRight(i, high, pans); // pt = {maximum r such that lcp(i, r)>val, lcp(i, r)}
			int right = pt.f;

			ll templ = right - i + 1;

			if (pt.f == i)
				pt.s = len;

			ll contr = (pt.s - pans);

			ans += (contr * (templ * (templ)));  // len of contr occurs templ times

			high = pt.f;
			pans = pt.s;

		}


	}

	cout << ans << endl;




}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);


	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);

	int tt = 1, testcae = 1;

	cin >> tt;

	while (tt--)
	{

		//cout<<"Case "<<testcae++<<": ";

		Solve();
	}

	return 0;

}

// Problem link : https://codeforces.com/contest/802/problem/I