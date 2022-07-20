class Solution {
public:
   map<char, pair<int, int>> mp; 
int countPalindromicSubsequence(string s) {
//     vector<vector<int>> vis(26, vector<int> (26, 0));
//     for(int i=0;i<s.length();i++){
//         if(mp.find(s[i]) != mp.end()){
//             mp[s[i]].second = i;
//         }
        
//         else{
//             mp[s[i]].first = i;
//             mp[s[i]].second = i;
//         }
//     }
    
//     int ans = 0;
//     for(int i=1;i<s.length()-1;i++){
//         for(auto j: mp){
//             if(vis[j.first-'a'][s[i]-'a'] == 0){
//                 if(j.second.first < i && j.second.second > i){
//                     ans++;
//                     vis[j.first-'a'][s[i]-'a'] = 1;
//                 }
//             }
//         }
//     }
    
//     return ans;
    int count=0;
        for(char ch='a';ch<='z';ch++)  //O(26*N)
        {
            int i=0,j=s.length()-1;
            while(i<j && s[i]!=ch) i++;
            while(j>i && s[j]!=ch) j--;
            //count unique  characters between i and j
            unordered_map<char,int> mp;
            for(int k=i+1;k<j;k++)
            {
                mp[s[k]]++;
            }
            count+=mp.size();
        }
        return count;
}  
};