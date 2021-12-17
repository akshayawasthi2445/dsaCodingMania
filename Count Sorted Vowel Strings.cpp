class Solution {
public:
    void findWords(string& current,string& str,int n,int& index,int& count){
        if(current.size()==n){
            count+=1;
            return;
        }
        for(int i=index;i<=4;i++){
            current+=str[i];
            findWords(current,str,n,i,count);
            current.pop_back();
        }
    }
    int countVowelStrings(int n) {
        string str="aeiou";
        int count=0;
        string current = "";
        int index = 0;
        findWords(current,str,n,index,count);
        return count;
    }
};