class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum=0;
        int ans;
        for(int i=0;i<chalk.size();i++) sum+=chalk[i];
        long long int temp=k%sum;
        for(int i=0;i<chalk.size();i++){
            if(chalk[i]>temp){
                ans=i;
                break;
            }
            else{
                temp-=chalk[i];
            }
        }
        return ans;
    }
};