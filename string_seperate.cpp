//  Taking input whole line, space included, and then take each word ans sort them lexicographically
//  then take unique words and print

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define sz 1000005
#define szz 30
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define MX 1000000000
#define MN -MX
#define hello cout << "hello" << endl;
#define tc int t; cin>>t; while(t--)
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

istream &operator>>(istream &in, vector<ll> &v)
{
for (unsigned int i = 0; i < v.size(); i++)
    cin >> v[i];
return in;
}

istream &operator>>(istream &in, vector<int> &v)
{
for (unsigned int i = 0; i < v.size(); i++)
    cin >> v[i];
return in;
}

int n;
set <string> st;
int main(){
    ios_base::sync_with_stdio(false);
    // freopen("input.in", "r", stdin);
    cin.tie(NULL);
    string str;
    cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++){
        getline(cin, str);
    
        for(int j=0; j<str.length(); j++){
            if(isalpha(str[j]))
                str[j] = tolower(str[j]);
            else
                str[j] = ' ';
        }
        stringstream s(str);
        string temp;
        while(s >> temp){
            st.insert(temp);
        }
    }

    cout<<st.size()<<endl;
    for(set <string> ::iterator it = st.begin(); it != st.end(); it++)
        cout<< *it <<endl;
    return 0;
}
