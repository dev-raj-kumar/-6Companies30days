class Solution {
  public:
    int findPosition(int n , int m , int k) {
        // code here
        m = m%n;
        k--;
        k = (k+m-1)%n;
        return k+1;
    }
};
