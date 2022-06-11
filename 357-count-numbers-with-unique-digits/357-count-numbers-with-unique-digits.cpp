class Solution {
public:
    	int f(int n){
			int res = 1;
			for(int i=1; i<=n; i++){
				res = res*i;
			}
			return res;
		}

		int countNumbersWithUniqueDigits(int n) {
			int res = 0;
			for(int i=1; i<=n; i++){
				res += (9*f(9))/f(10-i);
			}
			return res+1;
		}
};