#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

typedef vector<ii> vii;
/*
    1 resets alist and verts
    2 initializes array size 26 (26 possible letters) of visited elements with -1 (unvisited)
    3 feeds the adjList with data
    4 feeds the vert vector with vertices
    5 if the vertice exists and the letter has not been visited by the dfs
    6 sets the letter as visited
    7 iterates through the current letter's connections and calls dfs on them (if they are unvisited)


*/
int nodes = 0;
vector<vi> alist(26);
int visited[26];
vi verts;

void dfs(int n){
    if(find(verts.begin(), verts.end(), n) != verts.end()){
        nodes++;
        //6
        visited[n] = 1;
        //7
        for(int i = 0; i < alist[n].size(); i++){
            if(visited[alist[n][i]]==-1){
                dfs(alist[n][i]);
            }
        }
    }
    else{
        return;
    }
}
int main()
{

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
    //1
    alist.clear();
    alist.resize(26);
    verts.clear();

    int u = 0;
    //2
    for(int i = 0 ; i < 26; i++){
        visited[i] = -1;
    }

    int trees = 0, acorn = 0;
        string m;

        cin >> m;
        while(m[0] != '*'){
            int n1 = m[1]-65;
            int n2 = m[3]-65;
            //3
            alist[n1].push_back(n2);
            alist[n2].push_back(n1);
            cin >> m;
        }
        cin >> m;
        for(int j = 0; j < m.size(); j+=2){
            //4
            int n1 = m[j]-65;
            verts.push_back(n1);
        }
        for( int j = 0; j < alist.size(); j++){
            //5
            if(find(verts.begin(), verts.end(), j) != verts.end() && visited[j]==-1){
                nodes = 0;
                dfs(j);
                if(nodes > 1){
                    trees++;
                }
                else{
                    acorn++;
                }
            }
        }
        cout << "There are " << trees << " tree(s) and " << acorn << " acorn(s).\n";
    }

}

