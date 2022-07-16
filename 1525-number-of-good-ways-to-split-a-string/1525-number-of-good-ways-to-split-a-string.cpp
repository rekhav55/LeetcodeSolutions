class Solution {
public:
    int numSplits(string s) {
         int result=0, letterGoneCnt=0;
        unordered_set<char> leftSet;
        // rightMap => <character in string, count>
        unordered_map<char, int> rightMap;
        
        for(int i=0;i<s.size();i++) {
            rightMap[s[i]] += 1;
        }

        int idx=0;
        while(idx+1 < s.size()) {
            leftSet.insert(s[idx]);
            
            if(rightMap[s[idx]] == 1) {
                letterGoneCnt += 1;
            }
            rightMap[s[idx]] -= 1;
            
            if(leftSet.size() == rightMap.size() - letterGoneCnt) {
                result += 1;
            }

            idx += 1;
        }
        
        return result;
    }
};