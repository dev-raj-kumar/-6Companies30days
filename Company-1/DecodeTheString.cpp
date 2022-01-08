class Solution {
public:
    string fun(int id,string & s){
        if(id >= s.length()){
            return "";
        }
       // cout << "for id " << id << "\n";
        string ans = "";
        int i;int ct = 0;
        for(i=id;i<s.length();i++){
            if(s[i] == '['){
                string p = fun(i+1,s);
              //  cout << p << "\n";
                while(ct > 0){
                    ct--;
                    ans += p;
                }
                ct = 1;i++;
                while(ct > 0){
                    if(s[i] == '[')
                        ct++;
                    else if(s[i] == ']')
                        ct--;
                    i++;
                }
                i--;
            }
            else if((s[i]-48) >= 0 && (s[i]-48) <= 9){
                ct *= 10;
                ct += (s[i]-48);
            }
            else if(s[i] == ']')
                return ans;
            else{
                ans += s[i];
            }
            
        }
        return ans;
    }
    string decodeString(string s) {
        return fun(0,s);
    }
};
