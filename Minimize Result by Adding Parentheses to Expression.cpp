class Solution {
public:
    string minimizeResult(string expression) {
        string str11 = "", str22 = "";
        int flag = 0;
        
        for(int i=0;i<expression.size();i++){
            if(expression[i]!='+' && flag==0) {
                str11+=expression[i];
            }
            else if(expression[i]=='+') flag=1;
            else if(expression[i]!='+' && flag==1){
                str22+=expression[i];
            }
        }
        
        int num1 = stoi(str11);
        int num2 = stoi(str22);
        
        
        vector<pair<int,int>> num1info,num2info;
        
        int quotient = num1;
        int remainder = 0;
        int k=0;
        
        
        // 24   7
        // 2    47
        // 0    247
        while(quotient>0){  
            int localremainder = quotient%10;
            quotient/=10;
            remainder+=localremainder*pow(10,k++);
            num1info.push_back(make_pair(quotient,remainder));
        }
        
        quotient = num2;
        remainder = 0;
        k=0;
        
        // 3  8
        // 0  38
        while(quotient>0){
            int localremainder = quotient%10;
            quotient/=10;
            remainder+=localremainder*pow(10,k++);
            num2info.push_back(make_pair(quotient,remainder));
        }
        
        
        int minres = INT_MAX;
        vector<int> finalscore;
        // 24 7      3 8
        // 2 47      0 38
        // 0 247
        
        for(int i=0;i<num1info.size();i++){
            for(int j=0;j<num2info.size();j++){
                int localres;
                if(num2info[j].first==0)
                    if(num1info[i].first==0)
                        localres = num1info[i].second+num2info[j].second;
                    else
                        localres = num1info[i].first*(num1info[i].second+num2info[j].second);
                else
                    if(num1info[i].first==0)
                        localres = (num1info[i].second+num2info[j].first)*num2info[j].second;
                    else
                        localres = num1info[i].first*(num1info[i].second+num2info[j].first)*num2info[j].second;
                
                if(localres<minres){
                    minres = localres;
                    if(finalscore.size()>0){
                        finalscore.clear();
                    }
                    
                    finalscore.insert(finalscore.end(),{num1info[i].first,num1info[i].second,num2info[j].first,num2info[j].second});
                }
            }
        }
        
        string finalstring = "";
        flag = 0;
        
        string str1 = to_string(finalscore[0]);
        string str2 = to_string(finalscore[1]);
        string str3 = to_string(finalscore[2]);
        string str4 = to_string(finalscore[3]);
        
        // 1 247 1 38
        if(str3[0]=='0'){
            if(str1[0]=='0')
                finalstring+='(' + str2 + '+' + str4 + ')';
            else
                finalstring = str1 + '(' + str2 + '+' + str4 + ')';
        }
        else{
            if(str1[0]=='0')
                finalstring+='(' + str2 + '+' + str3 + ')' + str4;
            else
                finalstring+=str1 + '(' + str2 + '+' + str3 + ')' + str4;
        }
        
        return finalstring;
    }
};