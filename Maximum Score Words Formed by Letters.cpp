class Solution {
public:
    int calculate(vector<string>& words,map<char,int>& mp, vector<int>& score, int index){
        if(index == words.size()) return 0;
        
        int sno = calculate(words,mp,score,index+1);
        
        bool wordvalidity = true;
        int wordscore = 0;
        for(int i=0;i<words[index].size();i++){
            if(mp[words[index][i]]==0) wordvalidity = false;
            mp[words[index][i]]-=1;
            wordscore+=score[words[index][i]-'a'];
        }
        
        int syes = 0;
        if(wordvalidity){
            syes = wordscore + calculate(words,mp,score,index+1);
        }
        
        for(int i=0;i<words[index].size();i++){
            mp[words[index][i]]+=1;
        }
            
        return max(syes,sno);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char,int> mp;
        for(int i=0;i<letters.size();i++){
            if(mp.find(letters[i])==mp.end())
                mp[letters[i]] = 1;
            else
                mp[letters[i]]+=1;
        }
        
        return calculate(words,mp,score,0);
    }
};