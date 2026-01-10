#include<bits/stdc++.h>
using namespace std;

void findNegativesInKWindow(vector<int> v, int n, int k, vector<int> &results) {
    vector<int> negatives;
    int i=0;
    int j=0;
    while(j < n) {
        if(v[j]<0) {
            negatives.push_back(v[j]);
        }
        if(j-i+1 < k) {
            j++;
        }
        else if(j-i+1 == k) {
            if(negatives.size()==0) {
                results.push_back(0);
            } else {
                results.push_back(negatives.front());
                
                if(!negatives.empty() && v[i]==negatives.front())
                    negatives.erase(negatives.begin()+0);
            }
            i++;
            j++;
        }

    }
}

int main() {
    vector<int> v = { 12, -1, -7, 8, -15, 30, 16, 28 };
    vector<int> results;
    int k = 3; 
    findNegativesInKWindow(v, v.size(), k, results);
    for(auto result: results) {
        cout<<result<<" ";
    }
    return 0;
}