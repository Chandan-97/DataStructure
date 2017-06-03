// ChandyShot
// Select maximum activities that can be selected
// SRC : geeksforgeeks.org
#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define deb(x) cout<<#x<<" = "<<x<<endl;
#define deb2(x, y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define sz 32
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define MX 1000000000
#define MN -MX
#define tc int t; cin>>t; while(t--)
#define hello cout<<"hello"<<endl;
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout<<"Total Number of Jobs"<<endl;
    int n;
    cin>>n;
    vector<pair<int, pair<int, int> > > schedule(n);
    cout<<"start\tend\n";
    for(int i=0; i<n; i++){
        schedule[i].first = i+1;
        cin>>schedule[i].second.first>>schedule[i].second.second;
    }
    

    typedef pair<int, pair<int, int> > pp;
    sort(schedule.begin(), schedule.end(), [](const pp &p1, const pp &p2){  // sort by end time
        if(p1.second.second < p2.second.second) return true;
        if(p1.second.second == p1.second.second) return p1.second.first < p1.second.first;
        return false;
    });


    cout<<"Activity Selected : "<<endl;
    cout<<"id\tStart\tEnd"<<endl;
    // the first activity is always selected
    int i=0;
    cout<<schedule[i].first<<"\t"<<schedule[i].second.first<<"\t"<<schedule[i].second.second<<endl;

    for(int j=1; j<n; j++){
        if(schedule[j].second.first >= schedule[i].second.second){  // if jth job starts after ending job i
            cout<<schedule[j].first<<"\t"<<schedule[j].second.first<<"\t"<<schedule[j].second.second<<endl;
            i = j;
        }
    }
}
