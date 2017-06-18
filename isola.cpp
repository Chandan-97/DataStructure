// ChandyShot...
// Writing my first bot... Let's see... 
// https://www.hackerearth.com/problem/multiplayer/isola/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout<<#x<<" = "<<x<<endl;
#define deb2(x, y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define sz 7
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
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

istream& operator >> (istream &in, vector<int> &v){
    for(unsigned int i=0; i<v.size(); i++)
        cin>>v[i];
    return in;
}

int state[sz][sz];
int player_id;
pii current;
vector<pii> moves;
bool isvalid(int i, int j){
    if(i >= 0 and i < sz and j >= 0 and j < sz and state[i][j] == 0)
        return true;
    return false;
}

void findMoves(int i, int j){
    if(isvalid(i-1, j-1))
        moves.pb(mp(i-1, j-1));
    if(isvalid(i-1, j))
        moves.pb(mp(i-1, j));
    if(isvalid(i-1, j+1))
        moves.pb(mp(i-1, j+1));
    if(isvalid(i, j-1))
        moves.pb(mp(i, j-1));
    if(isvalid(i, j+1))
        moves.pb(mp(i, j+1));
    if(isvalid(i + 1, j - 1))
        moves.pb(mp(i+1, j-1));
    if(isvalid(i+1, j))
        moves.pb(mp(i+1, j));
    if(isvalid(i+1, j+1))
        moves.pb(mp(i+1, j+1));
}

int main(){
    // freopen("input.in", "r", stdin);
    int n = 7;
    fin fjn cin >> state[i][j];
    cin >> player_id;
    fin fjn if (state[i][j] == player_id) current.first = i, current.second = j;

    findMoves(current.first, current.second); // find all moves available;
    
    if(moves.size() == 0){  // if no moves available
        assert(0);
    }

    // Randomly select one of the available move;
    srand(time(NULL));
    pii next = moves[rand() % (moves.size())];

    // move to that next position
    state[current.first][current.second] = 0;
    state[next.first][next.second] = player_id;
    cout << next.first << " " << next.second << endl;

    moves.clear();


    // Finding valid block to remove
    int opponent_id = 1;
    if(player_id == 1)
        opponent_id = 2;

    pii opponent_pos;
    fin fjn if (state[i][j] == opponent_id) opponent_pos.first = i, opponent_pos.second = j;    // find block for opponent

    findMoves(opponent_pos.first, opponent_pos.second); // find available block to remove
    if (moves.size() == 0){ // if none of the adjacent move is available, find any of the valid move
        fin{
            fjn{
                if(state[i][j] == 0)
                    moves.pb(mp(i, j));
            }
        }

        if(moves.size() == 0){  // if still no move available
            assert(0);
        }

        pii select = moves[rand() % moves.size()];
        state[select.first][select.second] = -1;
        cout << select.first << " " << select.second << endl;
    }

    pii select = moves[rand() % moves.size()];
    state[select.first][select.second] = -1;
    cout << select.first << " " << select.second << endl;

    return 0;
}
