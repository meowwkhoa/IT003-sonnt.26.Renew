#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

unsigned long long countTrees(long long x, long long k, long long m, long long a, long long b){
    return (x - x/k)*a + (x - x/m)*b;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned long long a, k, b, m, n;
    cin>>a>>k>>b>>m>>n;

    long long aDay = ceil((double)n/a) + ceil((double)n/a)/(k-1);
    long long bDay = ceil((double)n/b) + ceil((double)n/b)/(m-1);

    unsigned long long l = 1;
    unsigned long long r = max(aDay, bDay);

    while(l < r)
    {
        long long mid = (l + r)/2;
        if(countTrees(mid, k, m, a, b) >= n)
            r = mid;
        else
            l = mid+1;
    }
    cout<<r;
    return 0;
}
