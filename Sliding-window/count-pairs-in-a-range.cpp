#include <bits/stdc++.h>
using namespace std;

int countPairWithLessThanOrEqualsTargetSum(vector < int > & arr, int target) {
    int n = arr.size();
    int cnt = 0;
    int left = 0;
    int right = n-1;
    
    while(left<right) {
        if(arr[left]+arr[right]<=target) {
            cnt += (right-left);
            left++;
            
        } else {
            right--;
        }
    }
    return cnt;
    
}

int countPairsWithGivenSumInRange(vector < int > & arr, int L, int R) {
    sort(arr.begin(), arr.end());
    int rightSum = countPairWithLessThanOrEqualsTargetSum(arr, R);
    int leftSum = countPairWithLessThanOrEqualsTargetSum(arr,L-1);
    return rightSum - leftSum;
}

int main() {
    // your code goes here
    vector < int > arr = {
        1,
        5,
        3,
        2
    };
    int L = 4;
    int R = 6;
    cout<<countPairsWithGivenSumInRange(arr, L, R)<<" \n";
    return 0;
}