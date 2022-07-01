class Solution {
void helper(vector<int>& counts, int &res)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (counts[i])
            {
                counts[i]--;
                res++;
                helper(counts, res);
                counts[i]++;
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int> counts(26, 0);
        
        for (int i = 0; i < tiles.size(); ++i)
            counts[tiles[i] - 'A']++; 
        
        int res = 0;
        helper(counts, res);
        return res;
    }
};