#include<bits/stdc++.h>
using namespace std;

int arrangeBuildings(int plots){
    int ob = 1;
    int os = 1;
    
    for(int i=2; i<=plots; i++){
        int nb = os;
        int ns = os+ob;

        os = ns;
        ob = nb;
    }
    int total = os+ob;
    return total*total;
}

int main(){
    cout<<arrangeBuildings(5);
}