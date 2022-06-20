struct Node{
  Node* links[26];

  bool containsKey(char ch){
      return links[ch-'a']!=NULL;
  }
  Node* getNode(char ch){
      return links[ch-'a'];
  }
  void putNode(char ch,Node* node){
      links[ch-'a']=node;
  }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        root=new Node();
    }
    
    void insert(string& str, int& cnt){
        Node* node=root;
        bool flag=false;
        for(char ch: str){
            if(!node->containsKey(ch)){
                flag=true;
                node->putNode(ch, new Node());
            }
            node=node->getNode(ch);
        }
        if(flag) cnt += str.length()+1;
    }
};
class Solution {
public:
    struct compare{
      bool operator()(string& a,string& b){
          return a.size()>b.size();
      }  
    };
    int minimumLengthEncoding(vector<string>& words) {
        Trie *trie = new Trie();
        
        sort(words.begin(), words.end(), compare());
        
        int cnt{};
        
        for(string str: words){
            reverse(str.begin(), str.end());
            trie->insert(str,cnt);
        }
        return cnt;
    }
};