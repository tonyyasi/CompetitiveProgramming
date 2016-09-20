#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
/*
    1 reads until EOF
    2 resets the contents on AdjList
    3 every position in AdjList is for a number c, pushing its different occurences in a vector.
    4 if there is an a^th occurence, it looks for the number c in AdjList and retrieves the a^th occurence (a-1 as it starts from 0)

*/
int main()
{
    vector<vii> AdjList (1000000);
    int a, b, c;
    //1
    while(scanf("%d %d", &a, &b)!=EOF){
    // 2
    AdjList.clear();
    AdjList.resize(1000000);
    for(int i = 0; i < a; i++){
        cin >> c;
        //3
        AdjList[c].push_back(ii(i+1, c));
    }
    for(int i = 0; i < b; i++){
        cin >> a >> c;
        if(a-1 < AdjList[c].size())
            //4
            cout << AdjList[c][a-1].first << '\n';
        else
            cout << "0\n";
    }
    }
}

