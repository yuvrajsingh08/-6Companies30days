class Solution {
public:
    int firstUniqChar(string s) {
        int ans=-1;
        queue<char>q;
        int freq[26]={0};
        for(int i=0;i<s.length();i++){
          char ch=s[i];
          freq[ch-'a']++;
          q.push(ch);
        }
        cout<<q.front();
        while(!q.empty()){
            if(freq[q.front()-'a']>1){
                q.pop();
            }
            else{
                return s.find(q.front());
            }
        }
        return -1;
    }
};