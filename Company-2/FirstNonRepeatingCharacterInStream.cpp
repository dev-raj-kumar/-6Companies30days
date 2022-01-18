
string FirstNonRepeating(string s){
		    // Code here
		    int hash[26];
		    for(int i=0;i<26;i++){
		        hash[i]=-1;
		    }
		    string p = "";
		    p += s[0];
            int n = s.size();
		    hash[s[0]-97]=0;
		
		    for(int i=1;i<n;i++){
		         if(hash[s[i]-97] == -1){
		             hash[s[i]-97]=i;
		         }
		         else
		         hash[s[i]-97]=n;
		         
		         int j;int pp = n;char x = '#';
		         for(j=0;j<26;j++){
		            // cout << hash[j] << " ";
		             if(hash[j] != -1 && hash[j] < pp)
		             pp=hash[j],x=(char)(97+j);
		         }
		        // cout << "\n";
		         
		         p += x;
		    }
		    return p;
		}
