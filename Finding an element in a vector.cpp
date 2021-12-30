#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    vector<int> V{10,20,30,40};
    auto it = find(V.begin(),V.end(),50);
    if(it!=V.end()){
        int index = it-V.begin();
        cout<<index;
    }
    else{
        cout<<-1;
    }
    return 0;
}