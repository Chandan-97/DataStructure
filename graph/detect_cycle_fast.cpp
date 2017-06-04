// ChandyShot
// Detect Cycle Union find with balancing
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

struct subset{
    int parent;
    int rank;
};

struct Graph* createGraph(int V, int E){
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));

    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));

    return graph;
}

int find(struct subset subsets[], int i){
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if(subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to check if a graph contains a cylcle or not
bool isCycle(struct Graph *graph){
    int V = graph->V;
    int E = graph->E;

    struct subset *subsets = (struct subset*)malloc(V * sizeof(struct subset));

    for(int i=0; i<V; i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    for(int e=0; e<E; e++){
        int x = find(subsets, graph->edge[e].src);
        int y = find(subsets, graph->edge[e].dest);

        if(x==y)
            return true;

        Union(subsets, x, y);
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
