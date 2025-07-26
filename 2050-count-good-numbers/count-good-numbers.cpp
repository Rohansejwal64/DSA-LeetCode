class Solution {
public:
int MOD = 1e9 + 7;

long long power(long long x, long long y) {
    long long ans = 1;
    x = x % MOD;  // handle large base
    while (y > 0) {
        if (y % 2 == 1) {
            ans = (ans * x) % MOD;  // apply mod after multiplication
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return ans;
}

int countGoodNumbers(long long n) {
    long long even = power(5, (n + 1) / 2);  // 5^(ceil(n/2))
    long long odd = power(4, n / 2);         // 4^(floor(n/2))
    return (even * odd) % MOD;
}

};