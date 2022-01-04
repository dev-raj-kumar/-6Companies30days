class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& s) {
        //code here
        vector<vector<string>> v;
        int i;vector<pair<string,int>> ve;
        for(i=0;i<s.size();i++){
            string ss = s[i];
            sort(ss.begin(),ss.end());
             ve.push_back({ss,i});
        }
        sort(ve.begin(),ve.end());
        int j;
        for(i=0;i<ve.size();i++){
            vector<string> vv;
            vv.push_back(s[ve[i].second]);
            j=i+1;
            while(j<ve.size() && ve[j].first == ve[i].first){
                vv.push_back(s[ve[j].second]);
                j++;
            }
            i=j-1;
            v.push_back(vv);
        }
        return v;
    }
};
