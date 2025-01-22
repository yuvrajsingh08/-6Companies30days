class Solution {
public:
    bool isPos(long long d1, long long d2, long long u1, long long u2, long long x) {
        long long A = x / d1;  // A = # of numbers divisible by d1
        long long A_ = x - A;  // A' = # of numbers not divisible by d1
        long long B = x / d2;	// B = # of numbers divisible by d2
        long long B_ = x - B;	// B' = # of numbers not divisible by d2
        long long AIB = x / lcm(d1, d2); // A Intersection B = # of numbers divisible by BOTH d1 AND d2
        long long AuB = A + B - AIB;	// A Union B = # of numbers divisible by EITHER d1 OR d2
        long long A_I_B_ = x - (AuB);	// (A' Union B') = (A Intersection B)' = # of numbers not divisible by NEITHER OF THEM

        // needA = # of numbers needed to have atleast u1 numbers of set1, these numbers
        // don't include (A' Union B')
        long long needA = (A_ - A_I_B_ >= u1) ? 0 : u1 - (A_ - A_I_B_);

        // needB = # of numbers needed to have atleast u2 numbers of set2, these numbers
        // don't include (A' Union B')
        long long needB = (B_ - A_I_B_ >= u2) ? 0 : u2 - (B_ - A_I_B_);

        /*
        Why not consider (A' Union B') ?
        -> I will assign those numbers to whichever set needs it.
        */

        // Available (A' Union B') value should be more than the needed # of values to make sets
        return (A_I_B_ >= needA + needB);
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long s = 2;
        long long e = 1e17;
        long long ans = -1;
        while(s <= e) {
            long long mid = (s+e)>>1;
            if(isPos(divisor1, divisor2, uniqueCnt1, uniqueCnt2, mid)) {
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
};