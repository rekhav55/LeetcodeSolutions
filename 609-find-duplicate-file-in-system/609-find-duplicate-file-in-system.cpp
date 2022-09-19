class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) 
    {
       vector<vector<string>> ans; 
       unordered_map<string,string> m;               // key-content   value-address
       unordered_map<string,vector<string>> store;   // key-content   value-vector<string> addresses with same content
       
       for(int i=0;i<paths.size();i++)
       {
           int j = 4;
           string s = "root";
           while(j < paths[i].size())
           {
               if(paths[i][j] == ' ')       // means next is txt file
               {
                   j++;
                   string curr = s;            //path till now 
                   curr.push_back('/');
                   while(paths[i][j] != '(')  // to get the name of file
                   {
                       curr.push_back(paths[i][j]);
                       j++;
                   }    
                   j++;
                   string val = "";
                   while(paths[i][j] != ')')  // to get the content of address
                   {
                       val.push_back(paths[i][j]);
                       j++;
                   }
                   if(m[val] != "")                  // means previously some address has same content
                   {
                       if(store[val].size() == 0)    // 1st time means we got two addresses for now
                       {
                           store[val].push_back(m[val]);
                           store[val].push_back(curr);
                       }
                       else               // not 1st time..means we already had 2 addresses...this one is the third or more
                           store[val].push_back(curr);
                   }    
                   m[val] = curr;              // update the content's address
                   j++;
               }
               else      // means next is directory
                    {
                        s.push_back(paths[i][j]);
                        j++;
                    }
           }
       }
       
       for(auto i : store)              // just traverse in 'store' map to get every content's addresses
           ans.push_back(i.second);
  
      return ans;  
    }
};