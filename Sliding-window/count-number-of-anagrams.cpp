#include<bits/stdc++.h>
using namespace std;

void findNumberOfAnagrams(string s, string pattern, int &ans) {
    unordered_map<char, int> freq;
    int count = 0;
    int n = s.size();

    for(char c: pattern) {
        freq[c]++;
    }
    int i=0; int j=0;
    count = freq.size();
    int k = pattern.size();

    while(j<n) {
        if(freq.find(s[j]) != freq.end()) {
            freq[s[j]]--;
            if(freq[s[j]]==0)
                count--;
        }
        if((j-i+1)<k) {
            j++;
        } 
        else if(j-i+1 == k) {
            if(count == 0) {
                ans++;
            }

            if(freq.find(s[i]) != freq.end()) {
                if(freq[s[i]] == 0)
                    count++;
                freq[s[i]]++;
            }
            i++;
            j++;
        }
    }
    return;
}

int main() {
    string s = "aabaabaa";
    string pattern = "aaba";
    int ans = 0;
    findNumberOfAnagrams(s, pattern, ans); 
    cout<<"The number of anagrams are "<<ans<<"\n"; 
    return 0;
}