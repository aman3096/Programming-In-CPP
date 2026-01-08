#include<bits/stdc++.h>
using namespace std;

// Extended I/P O/P method- here output and input data types are different
void solve(int open, int close, string &output, vector<string> &brackets) {
    //base condtion
    if(open==0 && close ==0) {
        brackets.push_back(output);
        return;
    }

    if(open!=0) {
        string op1 = output;
        op1.push_back('(');
        solve(open-1, close, op1, brackets);
    }
    if(close>open) {
        string op2 = output;
        op2.push_back(')');
        solve(open, close-1, op2, brackets);
    }
}

int main() {
    int n;
    cout<<"Input a number";
    cin>>n;
    vector<string> brackets;
    string output = "";
    int open, close;
    open = close = n;
    solve(open, close, output, brackets);
    cout<<"The balanced strings are"<<"\n";
    for( auto bracket: brackets)
        cout<<bracket<<"\n";
    return 0;
}
