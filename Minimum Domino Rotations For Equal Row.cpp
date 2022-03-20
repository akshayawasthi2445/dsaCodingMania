class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int total = 0;
        map<int,int> top,bottom;
        for(int i=0;i<tops.size();i++){
            if(top.find(tops[i])==top.end()) top[tops[i]] = 1;
            else top[tops[i]]+=1;
        }
        for(int i=0;i<bottoms.size();i++){
            if(bottom.find(bottoms[i])==bottom.end()) bottom[bottoms[i]] = 1;
            else bottom[bottoms[i]]+=1;
        }
        
        pair<int,int> ptop(0,0),pbottom(0,0);
        for(auto iter : top){
            if(iter.second>ptop.second){
                ptop.first = iter.first;
                ptop.second = iter.second;
            }
        }
        for(auto iter : bottom){
            if(iter.second>pbottom.second){
                pbottom.first = iter.first;
                pbottom.second = iter.second;
            }
        }
        
        // highest in tops is 2 occuring 4 times
        // highest in bottoms is 2 occuring 3 times
        
        int prefer = 0;
        if(ptop.second>pbottom.second) prefer=1;
        
        if(prefer==1){
            int target = ptop.first;
            for(int i=0;i<tops.size();i++){
                if(tops[i]==target) continue;
                else if(tops[i]!=target && bottoms[i]!=target) return -1;
                else
                    total+=1;
            }
        }
        else{
            int target = pbottom.first;
            for(int i=0;i<bottoms.size();i++){
                if(bottoms[i]==target) continue;
                else if(bottoms[i]!=target && tops[i]!=target) return -1;
                else
                    total+=1;
            }
        }
        
        return total;

    }
};