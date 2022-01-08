class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int l =0;int r =0;
        int s =0;
        int n = nums.size();
        int mm = n+1;
        while(r<n || l<r){
            while(r<n && s<t){
                s += nums[r];
                r++;
            }
            if(s >= t){
                mm = min(mm,r-l);
            }
           // cout << r << " " << l << " and " << s << "\n";
            s -= nums[l];l++;
        }
        if(mm == (n+1))
            return 0;
        return mm;
    }
};
