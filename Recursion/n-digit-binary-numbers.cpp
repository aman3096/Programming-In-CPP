/* 
Print all N digit binary # where #1s> #0s in all prefixes
Ip=3 OP - 101, 110, 111 as here all prefixes have 1s greater than zeroes
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int n, int zeroes, int ones, string output, vector<string> &results) {
    if(n==0) {
        if(output[0]!='0')
            results.push_back(output);
        return;
    }
    string op1 = output;
    op1.push_back('0');
    if(ones>zeroes)
        solve(n-1, zeroes+1, ones, op1, results);
    
    string op2 = output;
    op2.push_back('1');
    solve(n-1, zeroes, ones+1, op2, results);
    
}

int main() {
    int n;
    cout<<"Please enter a number"<<"\n";
    cin>>n;
    int zeroes, ones;
    zeroes = ones = 0;
    string output="";
    vector<string> results;
    cout<<"The results are "<<"\n";
    solve(n, zeroes, ones, output, results);
    for(auto result: results) {
        cout<<result<<" ";
    }
    return 0;
}