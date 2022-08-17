class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
       vector<string>  morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

		set<string> ans;
		int size = words.size();
		for(string word : words)
		{
			string morseString = "";
			for(char c : word)
				morseString += morse[c-'a'];
			ans.emplace(morseString);
		}        
		return ans.size();
    }
};