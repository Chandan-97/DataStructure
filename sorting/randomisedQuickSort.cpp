// Randomised QuickSort
// Because You Look Gorgeous in Black...
// ChandyShot...

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define sz 100005
#define szz 30
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define MX 1000000000
#define MN -MX
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

int r_partition(vector <int> &v, int start, int end){
    int st = start;
    int nd = end;
    int n = end - start + 1;
    srand(time(NULL));
    int pivot_idx = start + (rand() % n);
    swap(v[start], v[pivot_idx]);
    int pivot = v[start];

    while(start < end){
        while(start <= end and v[start] <= pivot)
            start++;
        while(end >= 0 and v[end] > pivot)
            end--;
        if(start < end)
            swap(v[start], v[end]);
    }
    v[st] = v[end];
    v[end] = pivot;
    return end;
}

void r_quickSort(vector <int> &v, int start, int end){
    if(start < end){
        int pivot = r_partition(v, start, end);
        r_quickSort(v, start, pivot-1);
        r_quickSort(v, pivot+1, end);
    }
}

void r_quick(vector <int> &v){
    int start = 0;
    int end = v.size() - 1;
    r_quickSort(v, start, end);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.in", "r", stdin);
    int n;
    cin>>n;
    vector <int> v;
    v.resize(n);
    cin>>v;
    r_quick(v);
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}
