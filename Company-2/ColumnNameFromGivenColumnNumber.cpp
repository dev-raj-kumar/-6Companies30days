class Solution{
    public:
    #define ll long long int
    string colName (long long int n)
    {
        // your code here
       string s = "";
       while(n > 0){
           n--;
           s += char(n%26 + 65);
           n /= 26;
       }
       reverse(s.begin(),s.end());
       return s;
    }
};
