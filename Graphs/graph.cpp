#include <iostream>
#include <queue>
using namespace std;

void printDFS(int** &edges, int n, int sv, bool * visited){
    cout<<sv<<" ";
    visited[sv] = true;
    for(int  i = 0; i<n; i++){
        if(i == sv){
            continue;
        }
        if(edges[sv][i] == 1){
            if(visited[i]){
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}
void printBFS(int** edges, int n, int sv, bool * visited){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        int currentvertex = q.front();
        q.pop();
        cout<<currentvertex<<" ";
        for(int i = 0; i<n; i++){
            if(i == currentvertex){
                continue;
            }
            if(edges[currentvertex][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(int ** edges, int n){
    bool * visited = new bool[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            printDFS(edges, n, i, visited);
        }
    }
    delete [] visited;
}

void BFS(int ** edges, int n){
    bool * visited = new bool[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            printBFS(edges, n, i, visited);
        }
    }
    delete [] visited;
}

bool hasPath(int** &edges, int n, int sv, int ev, bool * visited){
    bool ans = false;
    visited[sv] = true;
    if(sv == ev){
        return true;
    }
    for(int  i = 0; i<n; i++){
        if(i == sv){
            continue;
        }
        if(edges[sv][i] == 1){
            if(visited[i]){
                continue;
            }
            ans = ans | hasPath(edges, n, i, ev, visited);
        }
    }
    return ans;
}

bool haspath(int **edges, int n, int start, int end){
    bool * visited = new bool[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }
    bool ans = hasPath(edges, n, start, end, visited);
    delete [] visited;
    return ans;
}
int getpathdfs(int ** edges, int n, int sv, int ev, bool * visited, vector<int> &path){
    visited[sv] = true;
    path.push_back(sv);
    if(sv == ev){
        return 1;
    }
    for(int  i = 0; i<n; i++){
        if(i == sv){
            continue;
        }
        if(edges[sv][i] == 1 && !visited[i]){
            if(getpathdfs(edges, n, i, ev, visited, path) != 1){
                return 0;
            }
            getpathdfs(edges, n, i, ev, visited, path);
        }
    }
    return 0;
}

void getpathDFS(int ** edges, int n, int sv, int ev){
    bool * visited = new bool[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }
    vector<int> ans;
    getpathdfs(edges, n, sv, ev, visited, ans);
    delete [] visited;
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    int n;
    int e;
    cin>>n>>e;
    int ** edges = new int*[n];
    for(int i = 0; i<n; i++){
        edges[i] = new int[n];
        for(int j = 0; j<n; j++){
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i<e; i++){
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    cout<<"DFS"<<endl;
    DFS(edges, n);
    cout<<"\nBFS"<<endl;
    BFS(edges, n);
    cout<<endl;
    cout<<"is present "<<haspath(edges, n, 1, 3)<<endl;
    cout<<"present DFS path ";
    getpathDFS(edges, n, 0, 3);



    for(int i = 0; i<n; i++){
        delete [] edges[i];
    }
    delete [] edges;
}