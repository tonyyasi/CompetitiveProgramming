#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
    1 Sorts priority queue from in ascending order.
    2 Pushes the data into a priority queue.
    3 Extracts two values, sums them in x, sums x to y and pushes x to the queue.
    4 prints y, the total cost.
*/

//1
class compare {
    public :
bool operator ()( const int &A , const int &B )
{
    return A > B;

}
};

int main()
{
    int n, a, x = 0, y = 0;
    cin >> n;
    //2
    while(n!= 0){
        priority_queue<int, vector<int>, compare> A;
        y = 0;
        x = 0;
        for(int i = 0; i < n; i++){
        cin >> a;
        A.push(a);
        }

        //3
       while(A.size() > 1){
            x = A.top();
            A.pop();
            x += A.top();
            A.pop();
            y += x;
            A.push(x);
       }
       //4
        cout << y << '\n';
        cin >> n;
    }

}


