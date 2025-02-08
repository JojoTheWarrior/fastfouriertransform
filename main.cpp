#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
// for example, 16 coefficients
int N = (1<<4);
// P is degree 15 polynomial
vector<ld> P(15);

// this is a seed
mt19937 rnd(0xdeadbeef);
uniform_int_distribution<int> gen(1, 100);

// recursive: returns the DFT of p (y0, y1, y2, ..., y2^k);
vector<ld> jojo(vector<ld> p){

}

int main(){
    for (int i = 0; i < N; i++) P[i] = gen(rnd);

    vector<ld> gb = jojo(P);
}
