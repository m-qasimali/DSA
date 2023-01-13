#include<bits/stdc++.h>
using namespace std;

int main(){
    string data = "test";
    data.append("ad");
    // data.assign("4");
    // cout<<data.at(0)<<endl;
    // cout<<data<<endl;
    // cout<<data.substr(0,1);
    // cout<<data.find_first_of('t');
    // cout<<data.find_last_of('t');
    data.insert(2,5,'a');
    // data.erase(3,4);
    // data.pop_back();
    data.push_back('4');
    cout<<data;
}