class Solution {
public:
    double myPow(double x, int n) {
    double ans = 1;

    if(n < 0){
        x = 1 / x;
        ans *= x;
        n++;
        n = -n;
    }

    while(n){
        if(n % 2 == 1) ans *= x;
        x *= x;
        n /= 2;
    }

    return ans;
}

};