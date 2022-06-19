class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchword) {
       unordered_map<string,vector<string>> m;

    sort(products.begin(),products.end());
    
    for(auto x:products)
    {
         string s="";
        for(int i=0;i<x.size();i++)
        {   
            
            s+=x[i];
            if(m[s].size()<3)
            m[s].push_back(x);
        }
    }
    
    vector<vector<string>> ans;
    
    string s="";
    for(int i=0;i<searchword.size();i++)
    {
        s+=searchword[i];
        ans.push_back(m[s]);
    }
    return ans;   
    }
};