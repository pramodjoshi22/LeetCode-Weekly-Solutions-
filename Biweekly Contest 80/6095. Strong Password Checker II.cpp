//6095. Strong Password Checker II


class Solution {
public:
    bool strongPasswordCheckerII(string password) 
    {
        int n=password.length();
        if(n<8)
        {
            return false;
        }
        int l=0,u=0,d=0,s=0;
        for(int i=0;i<n-1;i++)
        {
            if(password[i]>='a' && password[i]<='z')
            {
                l++;
            }
            else if(password[i]>='A' && password[i]<='Z')
            {
                u++;
            }
            else if(password[i]>='0' && password[i]<='9')
            {
                d++;
            }
            else if(password[i]=='!' || password[i]=='@' || password[i]=='#' || password[i]=='$' || password[i]=='%' || 
                    password[i]=='^' || password[i]=='&' || password[i]=='*' || password[i]=='(' || password[i]==')' ||
                    password[i]=='-' || password[i]=='+')
            {
                s++;
            }
            if(password[i]==password[i+1])
            {
                return false;
            }
        }
        if(password[n-1]>='a' && password[n-1]<='z')
        {
            l++;
        }
        else if(password[n-1]>='A' && password[n-1]<='Z')
        {
            u++;
        }
        else if(password[n-1]>='0' && password[n-1]<='9')
        {
            d++;
        }
        else if(password[n-1]=='!' || password[n-1]=='@' || password[n-1]=='#' || password[n-1]=='$' || password[n-1]=='%' || 
                    password[n-1]=='^' || password[n-1]=='&' || password[n-1]=='*' || password[n-1]=='(' || password[n-1]==')' ||
                    password[n-1]=='-' || password[n-1]=='+')
        {
            s++;
        }
        if(s==0 || l==0 || u==0 || d==0)
        {
            return false;
        }
        return true;
    }
};
