class Solution {
public:
bool satisfy(long long d1,long long d2,long long c1,long long  c2,long long mid){
     long long divideByd1=mid/d1;
     long long divideByd2=mid/d2;

     long long notdivideByd1=mid-divideByd1;
      long long notdivideByd2=mid-divideByd2;

      long long notdivideBoth=mid-mid/lcm(d1,d2);

      if(notdivideByd1>=c1 && notdivideByd2>=c2 && notdivideBoth>=(c1+c2)){
           return true;
      }

     return false;
}

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
          long long ans=INT_MAX;
          long long s=1,e=INT_MAX;
          while(s<=e){
              long long mid=s+(e-s)/2;
              if(satisfy(divisor1,divisor2,uniqueCnt1,uniqueCnt2,mid)){
                   ans=min(ans,mid);
                   e=mid-1;
              }
              else{
                  s=mid+1;
              }
          }
          return ans;
    }
};