// ChandyShot
// Kruskal MST algoorithm
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
    int src, dest, weight;
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

int cmp(const void* a, const void* b){
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;

    return a1->weight > b1->weight;
}

void KruskalMst(struct Graph *graph){
    int V = graph->V;
    struct Edge result[V];
    int e = 0, i = 0;

    qsort(graph->edge, graph->E, sizeof (graph->edge[0]), cmp);

    struct subset *subsets = (struct subset*)malloc(sizeof(struct subset) * V);

    for(int v=0; v<V; v++){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while(e < V-1){
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if(x!=y){
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    cout<<"Following are the selected edges of MST : "<<endl;
    for(i=0; i<e; i++)
        cout<<result[i].src<<" -- "<<result[i].dest<<" == "<<result[i].weight<<endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.in", "r", stdin);
    cout<<"Enter number of vertices and edges : ";
    int v, e;
    cin>>v>>e;

    struct Graph *graph = createGraph(v, e);

    cout<<"Enter the edges : \n";
    cout<<"src\tdest\tweight\n";
    for(int i=0; i<e; i++){
        cin>>graph->edge[i].src>>graph->edge[i].dest>>graph->edge[i].weight;
    }

    KruskalMst(graph);

    return 0;

}
