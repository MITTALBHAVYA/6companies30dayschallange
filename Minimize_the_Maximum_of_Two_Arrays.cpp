class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long gcm = __gcd(divisor1,divisor2);
        long long lcm = (long long)((long long)divisor1*(long long)divisor2)/gcm;
        long long count1 = uniqueCnt1 + uniqueCnt1/(divisor1-1);
        long long count2 = uniqueCnt2 + uniqueCnt2/(divisor2-1);
        long long count3 = (uniqueCnt1 + uniqueCnt2) + ((uniqueCnt1 + uniqueCnt2)/(lcm-1)) ;
        //cout<<count1<<" "<<count2<<" "<<count3<<" "<<lcm<<endl;
        if(uniqueCnt1 % (divisor1-1) == 0){
            count1--;
        }
        if(uniqueCnt2 % (divisor2-1) == 0){
            count2--;
        }
        if((uniqueCnt1 + uniqueCnt2) % (lcm-1) == 0){
            count3--;
        }
        //cout<<count1<<" "<<count2<<" "<<count3<<endl;
        return max({count1,count2,count3});
    }
};