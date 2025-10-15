#include <bits/stdc++.h>
using namespace std;

// Code based on https://cp-algorithms.com/algebra/binary-exp.html
int binpow(int a, int n) {
    if (n == 0)
        return 1;
    
    int ans = binpow(a, n / 2);
    if (n % 2)
        return ans * ans * a;
    else
        return ans * ans;
}
 
int main() {
    binpow(2, 10);
}