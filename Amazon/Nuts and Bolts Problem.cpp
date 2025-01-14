class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        char order[] = { '!', '#', '$', '%', '&', '*', '?', '@', '^'};
        int pos = 0;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < n; j++){
                if(order[i] == bolts[j]){
                    swap(bolts[j], bolts[pos]);
                    nuts[pos] = bolts[pos++];
                }
            }
        }
    }
};