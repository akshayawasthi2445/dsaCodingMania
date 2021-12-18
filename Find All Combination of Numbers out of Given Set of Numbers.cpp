/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void makeNumbersAccordingToDigits(vector<string>&digits,vector<string>& store,int& count,int digitcap,int index,string current){
    if(current.size()==digitcap){
        store.push_back(current);
        count+=1;
        return;
    }
    for(int i=0;i<digits.size();i++){
        current+=digits[i];// "1"
        makeNumbersAccordingToDigits(digits,store,count,digitcap,index,current);
        current.pop_back();// ""
    }
}
void giveNNumbers(vector<string>& digits,vector<string>& store,int& count,int digitcap){
    while(digitcap<=digits.size()){
        string current = "";
        for(int i=0;i<digits.size();i++){
            current+=digits[i];
            makeNumbersAccordingToDigits(digits,store,count,digitcap,i,current);
            current.pop_back();
        }
        digitcap+=1;
    }
}

vector<string> formNNumbers(vector<string>& digits){
    //vector<int> intdigits;
    int count = 0;
    vector<string> store;
    // for(int i=0;i<digits.size();i++){
    //     int intconvertor = stoi(digits[i]);
    //     intdigits.push_back(intconvertor);
    // }
    int digitcap = 1;
    giveNNumbers(digits,store,count,digitcap);
    return store;
}

int main()
{
    vector<string> digits{"1","3","5"};
    vector<string> global = formNNumbers(digits);
    for(int i=0;i<global.size();i++){
        for(int j=0;j<global[i].size();j++)
            cout<<global[i][j];
        cout<<endl;
    }
    return 0;
}
