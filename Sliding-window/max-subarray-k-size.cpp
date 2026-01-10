#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int>& v, int k) {
    int n = v.size();
    int sum = 0;
    int maxSum = INT_MIN;

    int start = 0;

    for (int end = 0; end < n; end++) {
        sum += v[end];   // add element entering window

        if (end - start + 1 == k) {
            maxSum = max(maxSum, sum);  // update answer
            sum -= v[start];            // remove element leaving window
            start++;                    // slide window
        }
    }
    return maxSum;
}

int main() {
    vector<int> v = { 2,3,5,2,9,7,1 };
    int k = 3;
    int ans = 0;
    ans =  maxSubarraySum(v, k);

    cout<<"the max sum is "<<ans<<"\n";
    return 0;
}