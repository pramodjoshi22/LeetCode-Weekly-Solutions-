//2232. Minimize Result by Adding Parentheses to Expression.


class Solution {
public:
    string minimizeResult(string expression) {
        bool plus = false;
        string a = "",b="";
        for(char ch : expression){
            if(ch == '+'){
                plus = true;
            }
            if(!plus) a+=ch;
            else b+=ch;
        }
        
        int n = a.length();
        int m = b.length();
        string ans;
        int maxi = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                int left;
                if(i==0) left = 1;
                else left = stoi(a.substr(0,i));
                
                int middle = stoi(a.substr(i,n-i))+stoi(b.substr(0,j+1));
                
                int right;
                if(j==m-1)right = 1;
                else right = stoi(b.substr(j+1,m-j-1));
                
                if(left*middle*right < maxi){
                    maxi = left*middle*right;
                    ans = a.substr(0,i) + "("+ a.substr(i,n-i) + b.substr(0,j+1) + ")" + b.substr(j+1,m-j-1);
                }
            }
        }
        return ans;
    }
};