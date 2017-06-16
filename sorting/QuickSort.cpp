// ChandyShot...
// Quick-Sort implementation

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout<<#x<<" = "<<x<<endl;
#define deb2(x, y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define sz 100010
#define szz 30
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define MX 1000000000
#define MN -MX
#define tc int t; cin>>t; while(t--)
#define hello cout<<"hello"<<endl;
#define clr(x) memset(x, 0, sizeof (x))
#define fill(x) memset(x, -1, sizeof(x))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define f(i, j, k, l) for(int (i)=(j); (i)<(k); (i)+=(l))
#define ff(i, j, k, l) for(int (i)=(j); (i)<=(k); (i)+=(l))
#define fin f(i, 0, n, 1)
#define fjn f(j, 0, n, 1)
#define fiin ff(i, 1, n, 1)
#define fjjn f(j, 1, n, 1)
using namespace std;

istream& operator >> (istream &in, vector<int> &v){
    for(unsigned int i=0; i<v.size(); i++)
        cin>>v[i];
    return in;
}

void quick(vector<int> &v, int start, int end){
    if(start >= end)
        return;
    int st = start;
    int nd = end;
    int pivot = v[start];

    while(start < end){
        while(v[start] <= pivot)
            start++;
        while(v[end] > pivot)
            end--;
        if(start < end)
            swap(v[start], v[end]);
    }

    v[st] = v[end];
    v[end] = pivot;

    quick(v, st, end - 1);
    quick(v, end + 1, nd);
}

void quicksort(vector<int> &v)
{
    int start = 0;
    int end = v.size()-1;
    quick(v, start, end);
}

int main(){
    int n;
    vector<int> v;
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
    #endif

    cin >> n;
    v.resize(n);
    cin >> v;

    quicksort(v);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
