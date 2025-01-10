class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int i=0;
        int j=1;
        int n = arr.size();
        int maxVal = 0;
        bool isdown = false;
        while( j< n) {
            // solvable condion check kro
            if(arr[j-1] < arr[j]) {
                // inValid
                if(isdown) {
                    i = j-1;
                    isdown = false;
                }
               
            }
            else if(arr[j-1] > arr[j]) {
                // yahan se downfall aa gya check kro ki valid h ki nhi
                if(i == j-1) {
                    // not valid
                    i = j;
                }
                else {
                    // valid h okay
                    maxVal = max(maxVal,j-i+1);
                    isdown = true;
                }
            }
            else {
                // means dono equal not valid
                isdown = false;
                i = j;
            }
            j++;
        }
        return maxVal;
    }
    // check this case for better understandin
    // [875,884,239,731,723,685]
};