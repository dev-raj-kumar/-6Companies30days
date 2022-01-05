string encode(string s)
{     
  //Your code here 
  string a = "";
  int n = s.length();
  int i;
  for(i=0;i<n;i++){
      int j = i+1;
      while(j<n && s[j]==s[i]){
          j++;
      }
      a += s[i];
      a += to_string(j-i);
      i=j-1;
  }
  return a;
}     
