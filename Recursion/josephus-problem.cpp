#include<bits/stdc++.h>
using namespace std;

void lastManStanding(vector<int> &azadBande, int n, int k, int start, int &ans) {
    if(azadBande.size()==1) {
        ans = azadBande[0];
        return;
    }
    int index = (start + k) % azadBande.size();
    azadBande.erase(azadBande.begin()+index);
    lastManStanding(azadBande, n-1, k, index, ans);
}

int main() {
    int n;
    int k;
    cout<<"Enter the number of persons"<<"\n";
    cin>>n;
    cout<<"Enter the k sword value"<<"\n";
    cin>>k;
    k--;
    int start = 0;
    int ans =-1; 
    vector<int> azadBande;
    for(int i=1; i<n+1; i++) {
        azadBande.push_back(i);
    }
    lastManStanding(azadBande,n, k, start, ans);
    cout<<"The last man standing is "<<ans<<"\n";
    return 0;
}