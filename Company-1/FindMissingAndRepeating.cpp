vector<int> Solution::repeatedNumber(const vector<int> &a) {
    int x = 0;
    int i;
    int n = a.size();
    for(i=1;i<=n;i++){
        x ^= a[i-1];
        x ^= i;
    }

    int p = 0; int q = 0;
    for(i=0;i<n;i++){
        if(x & (1 << i))
        break;
    }
    int j = 1 << i;
   // cout << x << " and " << j << "\n";
    for(i=0;i<n;i++){
        if(j & (x & a[i]))
        p ^= a[i];
        else
        q ^= a[i];

        if(j & (x & (i+1)))
        p ^= (i+1);
        else
        q ^= (i+1);
    }

    vector<int> v(2);
    for(i=0;i<n;i++){
        if(a[i] == p){
            v[0]=p;v[1]=q;
            break;
        }
        else if(a[i] == q){
            v[0]=q;v[1]=p;
            break;
        }
    }
    return v;
}

