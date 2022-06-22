struct Node{
    Node* links[26];
    bool flag=false;
    int wc=0;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
};

class Trie{
    private: Node* root;
    public:
      Trie(){
          root=new Node();
      }
    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->wc++;
        }
        node->setEnd();
    }
    string count(string word, int n){
        Node* node=root;
        string res="";
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                break;
            }
            else{
                node = node->get(word[i]);
                if(node->wc==n){
                    res+=word[i];
                }
                else{
                    break;
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        Trie t;
        for(int i=0;i<strs.size();i++){
            t.insert(strs[i]);
        }
        
        return t.count(strs[0],n);
    }
};