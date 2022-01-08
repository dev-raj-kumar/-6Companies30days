bool canPair(vector<int> nums, int k) {
        // Code here.
        if(nums.size()%2)
        return false;
        int hash[k]={0};
        for(auto x : nums){
            hash[x%k]++;
        }
        int i;
        int x = k/2;
        if(k%2 == 0){
            if(hash[x]%2)
            return false;
        x--;
        }
        for(i=1;i<=x;i++){
            if(hash[i] != hash[k-i])
            return false;
        }
        return true;
    }
