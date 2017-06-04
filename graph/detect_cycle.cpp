// ChandyShot
// Detect for cycle in a graph
// SRC : GEEKSFORGEEKS
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

struct Edge{
    int src, dest;
};

struct Graph{
    int V, E;
    struct Edge *edge;
};

struct Graph* createGraph(int V, int E){
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));

    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));

    return graph;
}

int find(int parent[], int i){
    if(parent[i] == -1)
        return i;
    find(parent, parent[i]);
}

void Union(int parent[], int x, int y){
    int xset = find(parent, x);
    int yset = find(parent, y);

    parent[xset] = yset;
}

// Function to check if a graph contains a cylcle or not
bool isCycle(struct Graph *graph){
    int *parent = (int *)malloc(sizeof(int) * graph->V);

    memset(parent, -1, sizeof(int) * graph->V);

    // Iterate over all edges, if both src and dest
    // have same parent, then its a cycle
    for(int i=0; i<graph->E; i++){
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);

        if(x == y)
            return true;

        Union(parent, x, y);
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.in", "r", stdin);
    cout<<"Enter number of vertices and edges : ";
    int v, e;
    cin>>v>>e;

    struct Graph *graph = createGraph(v, e);

    cout<<"Enter the edges : \n";
    cout<<"src\tdest\n";
    for(int i=0; i<v; i++){
        cin>>graph->edge[i].src>>graph->edge[i].dest;
    }

    if(isCycle(graph))
        cout<<"Graph contains cycle"<<endl;
    else
        cout<<"Graph doesnot contain any cycle"<<endl;

    return 0;

}
