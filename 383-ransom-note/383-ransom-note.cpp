class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>a(26,0),b(26,0);
        int len=(ransomNote.size()>magazine.size()?ransomNote.size():magazine.size());
        for(int i=0;i<len;++i){
            if(i<ransomNote.size())
                a[int(ransomNote[i])-97]++;
            if(i<magazine.size())
                b[magazine[i]-97]++;
        }
        for(int i=0;i<26;++i){
            if(a[i]>b[i])
                return false;
        }
         
        return true;
    }
};