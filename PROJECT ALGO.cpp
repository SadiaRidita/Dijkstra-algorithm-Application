#include<bits/stdc++.h>
using namespace std;
#define maxSize 110 //maximum size
#define infinity 1000000000        //reset// distance array k infinity te initiate korte hbe

struct node{  //custom datatype use korchi
    int VALUE;
    int Cost;
};

// 1 -> {2, 5}, {4, 10}
// 2 -> {5, 40}, {3, 45}

vector < node > G[maxSize];
bool Visited[maxSize];    //visited array
int dist[maxSize];     //distance array

void reset(){
    for (int i = 0; i < maxSize; i++){
        G[i].clear();
        Visited[i] = 0;
        dist[i] = infinity;
    }
}

class comparator{
public:
    bool operator() (node &A, node &B){                 //2 ta node type data compare korbe
        if (A.Cost > B.Cost) return true;                           //street week ordering priority quque maintain kore,tai if A>B hole true return korbe
        return false;                    //jehetu miinimum priority queue ,cost dekhtesi.tai jar cost joto boro she shober sheshe pop hobe
    }
};

void dijkstra(int source){
    priority_queue<node, vector<node>,comparator > PQ;                       //priority queue dijkstrar jnno lagbe,cmp hocche comparetor
    PQ.push({source, 0});                                                   //source push korbo,r source er nijer shathe nijer distance 0

    while(!PQ.empty()){                     // jotokkhon priority queue ta empty na hobe totkkkhn loop ta cholbe
        node current = PQ.top();           //top e jei node ache sheta current node
        PQ.pop();                      //top e jeta ase,remove kore dibo,karon remove na korle infinity r moto cholte thakbe

        int VALUE = current.VALUE;                   //value cost alada  variable e nilam
        int Cost = current.Cost;

        if (Visited[VALUE] == 1) continue; // if visited, then we do not work with that node
                                             //noyto distance ta jei cost niye priority q te push hoyechilo ota update kore dibo
        dist[VALUE] = Cost; // cost is finalized here
        Visited[VALUE] = 1;                //visited+shortest distance calculate hoye geche,r update korbona

        for (int i = 0; i < G[VALUE].size(); i++){   //jegulo unvisited,shegulo priority key te push korbo
            int nxt = G[VALUE][i].VALUE;
            int nxtCost = G[VALUE][i].Cost;

            if (Visited[nxt] == 0){
                PQ.push({nxt, Cost + nxtCost});                          //next noder dis calculate kori,current node er cos+next node e jawar cost
            }
        }
    }
}

int main()
{

    reset();

    int nodes, edges;
    cin >> nodes >> edges;

    // u theke v te,cost w
    for (int i = 1; i <= edges; i++){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }

    cout << "Enter The Source: ";
    int source; cin >> source;

    dijkstra(source);
    for (int i = 1; i <= nodes; i++){
        cout << "Node: " << i << " Distance: ";
        if (dist[i] == infinity) cout << "Distance is infinity" << "\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}
