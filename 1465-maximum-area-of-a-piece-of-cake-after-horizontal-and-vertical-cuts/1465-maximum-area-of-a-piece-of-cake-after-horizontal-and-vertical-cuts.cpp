class Solution {
public:
    int MOD=1e9+7;
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        vector<int>hcuts;
        vector<int>vcuts;
        hcuts.push_back(0);
        hcuts.push_back(h);
        vcuts.push_back(0);
        vcuts.push_back(w);
        for(int i=0;i<hc.size();i++){
            hcuts.push_back(hc[i]);
        }
        for(int i=0;i<vc.size();i++){
            vcuts.push_back(vc[i]);
        }
        sort(hcuts.begin(),hcuts.end());
        sort(vcuts.begin(),vcuts.end());
        long long int length=0, width=0;
        for(int i=1;i<hcuts.size();i++){
            length = max(length%MOD, (long long)(hcuts[i]-hcuts[i-1])%MOD);
        }
        for(int i=1;i<vcuts.size();i++){
            width = max(width%MOD, (long long)(vcuts[i]-vcuts[i-1])%MOD);
        }
        
        return ((length%MOD)*(width%MOD))%MOD;
    }
};