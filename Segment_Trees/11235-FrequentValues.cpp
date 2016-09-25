#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

class SegmentTree{
    private:
    vi st, A;
    int n;
    int left(int p){
        return p << 1;
    }
    int right(int p){
        return (p<<1)+1;
    }

    void build(int p, int L, int R){
        if(L == R)
            st[p] = L;
        else{
            build(left(p), L, (L+R)/2);
            build(right(p), (L+R)/2 + 1, R);
            int p1 = st[left(p)];
            int p2 = st[right(p)];
            st[p] = (A[p1] > A[p2]) ? p1 : p2; //change for larger or smaller.
        }
    }

    int rmq(int p, int L, int R, int i, int j){
        if(i > R || j < L) return -1;
        if(L >= i && R<=j) return st[p];

        int p1 = rmq(left(p), L, (L+R)/2, i, j);
        int p2 = rmq(right(p), (L+R)/2+1, R, i, j);

        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1] > A[p2]) ? p1 : p2;
    }

    public:
        SegmentTree(const vi &_A){
            A = _A;
            n = (int)A.size();
            st.assign(4*n, 0);
            build(1,0,n-1);
        }
        int rmq(int i, int j){
            return rmq(1,0,n-1,i,j);
        }
    };

int main(){
    int n, a, q, x, y, j;
    while(cin >> n && n!=0){
      cin >> q;
      x = 1;
      int A[n], B[n];
      cin >> y;
      B[0] = y;
      for(int i = 1; i < n; i++){
        cin >> a;
        B[i] = a;
        if(a==y)
            x++;
        else{
            for(j = i-x; j < i; j++){
                A[j] = x;
            }
            x = 1;
            y = a;
            }
        }
        for(int i = j; i < n; i++){
            A[i] = x;
        }
        vi V(A, A+n);
        SegmentTree st(V);
        for(int i = 0; i < q; i++){
            cin >> x >> y;
            x--;y--;
            int j, k, c = 1;
            if(B[x]==B[y]){
                cout << y-x+1 << '\n';}
            else if(B[x]!=B[x-1] && B[y]!=B[y+1]){
                cout << V[st.rmq(x, y)] << '\n';
                }
            else if(B[x] == B[x-1]&&B[y]!=B[y+1]){
                for(j=x; j < y-1; j++){
                    if(B[j] != B[j+1])
                        break;
                }
                cout << max(j-x+1, V[st.rmq(j+1, y)]) << '\n';
            }
            else if(B[x]!=B[x-1] && B[y]==B[y+1]){
                for(j=y; j > x+1; j--){
                    if(B[j] != B[j-1])
                        break;
                }
                cout << max(y-j+1, V[st.rmq(x, j-1)]) << '\n';
            }
            else if(B[x]==B[x-1] && B[y]==B[y+1]){
                for(j=x; j < y-1; j++){
                    if(B[j] != B[j+1])
                        break;
                }
                for(k=y; k > x+1; k--){
                    if(B[k] != B[k-1])
                        break;
                }
                cout << max(max(j-x+1, y-k+1), V[st.rmq(j+1, k-1)]) << '\n';
            }
        }
    }
}
