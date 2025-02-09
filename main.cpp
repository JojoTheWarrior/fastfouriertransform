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

// struct for complex num: a + bi
struct comp {
    ld a, b;

    comp operator * (const comp &other) const {
        return {a*other.a - b*other.b, a*other.b + b*other.a};
    }

    comp operator + (const comp &other) const {
        return {a + other.a, b + other.b};
    }

    comp pow(int n) const {
        comp ret = {a, b};
        comp base = {a, b};
        n--;
        while (n > 0){
            if (n&1) ret = ret*base;
            base = base*base;
            n >>= 1;
        }
        return ret;
    }
};

// recursive: returns the DFT of p (y0, y1, y2, ..., y2^k);
vector<comp> jojo(vector<ld> p){
    if (p.size() == 1) return {{p[0], 0}};
    // recur
    vector<ld> p_o, p_e;
    for (int i = 0; i < p.size(); i++) (i&1 ? p_o : p_e).push_back(p[i]);
    vector<comp> o = jojo(p_o), e = jojo(p_e);

    comp w = {cos(2*M_PI / p.size()), sin(2*M_PI / p.size())};
    vector<comp> ret(p.size());
    for (int i = 0; i < p.size()/2; i++) ret[i] = {};

    return {};
}

int main(){
    for (int i = 0; i < N; i++) P[i] = gen(rnd);

    vector<comp> gb = jojo(P);
}
