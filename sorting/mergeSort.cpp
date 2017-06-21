// MergeSort
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

void merge(vector <int> &v, vector <int> &temp, int start, int mid, int end){
    int left_curr = start;
    int left_end = mid-1;
    int right_curr = mid;
    int right_end = end;   
    int current_pos = start;
    int size = right_end - left_curr + 1;

    while(left_curr <= left_end and right_curr <= right_end){
        if(v[left_curr] < v[right_curr]){
            temp[current_pos] = v[left_curr];
            left_curr++;
            current_pos++;
        }
        else{
            temp[current_pos] = v[right_curr];
            right_curr++;
            current_pos++;
        }
    }

    while(left_curr <= left_end){
        temp[current_pos] = v[left_curr];
        left_curr++;
        current_pos++;
    }

    while(right_curr <= right_end){
        temp[current_pos] = v[right_curr];
        right_curr++;
        current_pos++;
    }

    current_pos--;
    for(int i=right_end; i>= start; i--){
        v[i] = temp[current_pos];
        current_pos--;
    }
}

void mSort(vector <int> &v, vector <int> &temp, int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        mSort(v, temp, start, mid);
        mSort(v, temp, mid+1, end);
        merge(v, temp, start, mid+1, end);
    }
}

void mergeSort(vector <int> &v){
    int start = 0;
    int end = v.size() - 1;
    vector <int> temp(v.size());
    mSort(v,temp, start, end);
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
    mergeSort(v);
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}
