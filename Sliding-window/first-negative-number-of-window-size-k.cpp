#include<bits/stdc++.h>
using namespace std;

void findNegativeNumbersOfWindowSize(vector<int> &v, int n, int k, vector<int> &negatives) {
    int start = 0;
    for(int end=0; end<n; end++) {
        if(end-start+1 ==k) {
            bool is_negative_found = false;
            for(int j=start; j<end+1; j++) {
                if(v[j]<0) {
                    negatives.push_back(v[j]);
                    is_negative_found = true;
                    break;
                }
            }
            if(!is_negative_found) {
                negatives.push_back(0);
            }
            start++;
        }
    }
}

int main() {
    vector<int> v = { 1, 2, -1, -7, 8, -15, 30, 16, 28 };
    int k=3;
    vector<int> firstNegatives;
    findNegativeNumbersOfWindowSize(v, v.size(), k, firstNegatives);
    for(int i=0; i<firstNegatives.size(); i++) {
        cout<<firstNegatives[i]<<" ";
    }
    return 0;
}