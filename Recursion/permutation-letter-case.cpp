#include<bits/stdc++.h>
using namespace std;

void solve(string input, string output, set<string> &result) {
    if(input.size()==0) {
        result.insert(output);
        return;
    }
    char temp = input[0];
    bool isNumeric = isdigit(temp);
    string op1;
    string op2;
    string lowerTemp = "";
    string upperTemp = "";
    if(!isNumeric) {
        lowerTemp.push_back(tolower(temp));
        upperTemp.push_back(toupper(temp));
    }
    op1 = isNumeric ? (output + temp) : (output + lowerTemp);
    op2 = isNumeric ? (output + temp) : (output + upperTemp);
    input.erase(input.begin()+0);
    solve(input, op1, result);
    solve(input, op2, result);  
    
}

int main() {
    string input = "a1B2";
    string output = "";
    set<string> results;
    solve(input, output, results);
    for(auto result: results) {
        cout<<result<<" ";
    }
    return 0;
}