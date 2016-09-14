#include <iostream>
#include <queue>
using namespace std;
class compare {
    public :
bool operator ()( const pair<int, int> &A , const pair<int, int> &B )
{
    if(A.first == B.first){
        return A.second > B.second;
    }
    else
    return A.first > B.first;

}
};


int main()
{
    int A[5000];
    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> Q;
    string a; int b, c;
    cin >> a;
    while(a!="#"){
        cin >> b >> c;
        Q.push(make_pair(c, b));
        cin >> a;
        A[b] = c;
    }
    cin >> b;
    int k, m;
    for(int i = 0; i<b; i++){
        cout << Q.top().second << '\n';
        k = Q.top().first;
        m = Q.top().second;
        Q.pop();
        Q.push(make_pair(k+A[m], m));
    }
}
