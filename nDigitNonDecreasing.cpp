// ChandyShot...
// http://www.geeksforgeeks.org/total-number-of-non-decreasing-numbers-with-n-digits/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define sz 10
#define szz 30
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define MX 1000000000
#define MN -MX
#define tc int t; cin >> t; while (t--)
#define hello cout << "hello" << endl;
#define clr(x) memset(x, 0, sizeof(x))
#define fill(x) memset(x, -1, sizeof(x))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define f(i, j, k, l) for (int(i) = (j); (i) < (k); (i) += (l))
#define ff(i, j, k, l) for (int(i) = (j); (i) <= (k); (i) += (l))
#define fin f(i, 0, n, 1)
#define fjn f(j, 0, n, 1)
#define fiin ff(i, 1, n, 1)
#define fjjn f(j, 1, n, 1)
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

istream &operator>>(istream &in, vector<int> &v)
{
	for (unsigned int i = 0; i < v.size(); i++)
		cin >> v[i];
	return in;
}


int nonDecrease(int input1)
{
	//Write code here
	int n = input1 + 10;
	if (input1 == 0)
		return 0;
	if (input1 == 1)
	{
		return 10;
	}
	if (input1 == 2)
		return 55;

	ll dp[n][10];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < sz; j++)
			dp[i][j] = 0;
	}

	for (int i = 0; i < sz; i++)
	{
		dp[0][i] = 0;
		dp[1][i] = 1;
		dp[2][i] = i + 1;
	}

	for (int i = 3; i < n; i++)
	{
		ll sum = 0;
		for (int j = 0; j < sz; j++)
		{
			sum += dp[i - 1][j];
			dp[i][j] = sum;
		}
	}

	ll ans = 0;
	for (int i = 0; i < sz; i++)
	{
		ans += dp[input1][i];
	}

	return (int)ans;
}

int main(){
	int n;
	cin >> n;
	cout << nonDecrease(n) << endl;
}
