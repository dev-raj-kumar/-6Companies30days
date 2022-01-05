class Solution{
  public:
    long long countSubArrayProductLessThanK(const vector<int>& nums, int n, long long k) {
        long long ct = 0;
        long long s = 1;
        long long l =0;long long r =0;
        
        for(r=0;r<n;r++){
            s *= nums[r];
            while(s >= k && l<=r){
                ct += (r-l);
                s /= nums[l];
                l++;
            }
        }
        long long x = r-l;
        if(x > 0){
            ct += ((x*(x+1))/2);
        }
        return ct;
    }
};
