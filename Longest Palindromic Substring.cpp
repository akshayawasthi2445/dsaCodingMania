class Solution {
public:
    
    string showString(string s,int finalstart,int finalend){
        string str = "";
        for(int i=finalstart;i<=finalend;i++){
            str+=s[i];
        }
        return str;
    }
    
    vector<int> count(string s,int low,int high,int length){
        while(low<=high && low>=0 && high<length && s[low]==s[high]){
            low--;
            high++;
        }
        vector<int> V;
        if(low+1<=high-1){
            V.push_back(low+1);
            V.push_back(high-1);
        }
        else{
            V.push_back(high);
            V.push_back(high);
        }
        return V;
    }
    
    string longestPalindrome(string s) {
        
        if(s.size()==1){string str = ""; str+=s[0];return str;}
        int finalstart=0,finalend=0,length = s.size(),currstart,currend;
        int maxlen = 0;
        for(int i=0;i<s.size();i++){
            vector<int> V1 = count(s,i,i,length);  // 0 2
            vector<int> V2 = count(s,i-1,i,length);// 1 1 
            
            int length1 = V1[1] - V1[0] + 1;
            int length2 = V2[1] - V2[0] + 1;
            
            if(length1 >= length2){
                currstart = V1[0];
                currend = V1[1];
            }
            else{
                currstart = V2[0];
                currend = V2[1];
            }
            
            if((currend-currstart+1)>maxlen){
                maxlen = currend-currstart+1;
                finalstart = currstart;
                finalend = currend;
            }
        }
        return showString(s,finalstart,finalend);
    }
};