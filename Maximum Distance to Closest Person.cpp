class Solution {
public:
    int max(int a,int b){
        if(a>b)return a;
        else return b;
    }
    
    int maxDistToClosest(vector<int>& seats) {
        // 1 0 0 0 1 0 1
        int countOne = 0;
        int maxDistance = 0;
        int optimalPos;
        vector<int>::iterator it1,it2;
        vector<int>::iterator startLimit = seats.begin();
        for(int i=0;i<seats.size();i++)
            if(seats[i]==1) countOne+=1;
        
        it1 = find(startLimit,seats.end(),1); // 3
        if(maxDistance<(it1-seats.begin()+1)){ // 3-0+1 = 4
            maxDistance = it1-seats.begin()+1;
            optimalPos = 0;
            startLimit=it1;
        }
            
        for(int i=0;i<countOne-1;i++){//2 
            it1 = find(startLimit,seats.end(),1); // 3
            startLimit = it1+1;
            it2 = find(startLimit,seats.end(),1); // 7
            if(maxDistance<(it2-it1)){
                maxDistance = it2-it1;
                int pos1 = it1-seats.begin();int pos2 = it2 - seats.begin();
                optimalPos = pos1+(pos2-pos1)/2;
            }
        }
        
        if(seats.end()-it2+1>maxDistance){
            optimalPos = seats.end()-seats.begin()-1;
        }// 7-3
        return optimalPos;
    }
};