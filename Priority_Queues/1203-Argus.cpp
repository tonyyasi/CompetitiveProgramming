
// 1  To do the problem first we filled up a queue with pairs, containing the queue number and the period.
// 2  We changed the default sorting way of the queue so it id from small to big.
// 3 We also saved the periods on an array
// 4 When we read the last input we do a loop n times printing the data of the one on top of the queue
// 5 We saved the queue number and the period
// 6 Lastly  we popped it from the queue and pushed it again, changing the value of the period


#include <iostream>
#include <queue>
using namespace std;

//2
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
      // 1
        cin >> b >> c;
        Q.push(make_pair(c, b));
        cin >> a;
        //3
        A[b] = c;
    }
    cin >> b;
    int k, m;
    for(int i = 0; i<b; i++){
      //4
        cout << Q.top().second << '\n';
        // 5
        k = Q.top().first;
        m = Q.top().second;
        //6
        Q.pop();
        Q.push(make_pair(k+A[m], m));
    }
}
