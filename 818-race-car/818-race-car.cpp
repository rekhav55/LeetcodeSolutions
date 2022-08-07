class Solution {
public:
    int racecar(int tar) {
        queue<pair<int,int>> qu;
    
    //Initially car at position 0 with speed 1
    qu.push({0,1});
    
    //Creating Hash Map for storing visited position and speed
    unordered_map<string,bool> mp;
    mp[to_string(0)+","+to_string(1)]=true;
    
    int ans = 0;
    while(!qu.empty()){
        int size = qu.size();
        while(size--){
            int pos = qu.front().first;
            int speed = qu.front().second;
            qu.pop();
            
            //Return current layer if target is reached
            if(pos==tar) return ans;
            
            string key = to_string(pos+speed)+","+to_string(speed*2);
            
            //Tuning Condition => |tar - nextPos| < tar
            if(!mp[key] && abs(tar-(speed+pos))<tar){
                mp[key]=true;
                qu.push({pos+speed,2*speed});
            }
            
            //Two method of tuning for this case :
            //1. nextpos > tar then reverse back OR Going backward and tar is ahead then go forward
            //2. |tar - nextPos| < tar
            if(pos+speed>tar || (speed<0 && pos+speed<tar)){
                speed = speed>0?-1:1;
                key = to_string(pos)+","+to_string(speed);
                if(!mp[key] && abs(tar-pos)<tar){
                    mp[key]=true;
                    qu.push({pos,speed});
                }
            }
            
        }
        ans++;
    }
    return -1;
        // return f(target,0,1,0);
    }
};