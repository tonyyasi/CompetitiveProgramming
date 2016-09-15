#include <iostream>
#include <queue>
#include <stack>
#include <vector>
/*
    1 Initializes the DS (queue, stack, priority_queue)
    2 Simulates the process of pushing an object into every DS.
    3 Simulates the process of retrieving an object from every DS, verifying if is not empty or different to the expected.
    4 Compares the flags for every DS to print the type.
*/
using namespace std;

int main()
{
    int n, b, c; string a;
    while(cin >> n){
        //1
        stack<int> A;
        queue<int> B;
        priority_queue<int, vector<int>> C;
        bool fa,fb,fc;
        fa=fb=fc=true;
        for(int i = 0; i < n; i++){
            //2
            cin >> b >> c;
            if(b==1){
                if(fa)
                    A.push(c);
                if(fb)
                    B.push(c);
                if(fc)
                    C.push(c);
            }
            //3
            else{
                if(fb)
                    if(B.empty() || B.front()!=c)
                        fb = false;
                    else
                        B.pop();
                if(fc)
                    if(C.empty() || C.top()!=c)
                        fc = false;
                    else
                        C.pop();

                if(fa)
                    if(A.empty() || A.top()!=c)
                        fa = false;
                    else
                        A.pop();
            }
        }
        //4
        if(!fc && !fa && !fb){
                    cout << "impossible\n";
                }
        else if((fa&&fb || fb&&fc || fa&&fc)){
            cout << "not sure\n";
        }
        else if(fa)
            cout << "stack\n";
        else if(fb)
            cout << "queue\n";
        else if (fc)
            cout << "priority queue\n";
    }
}


