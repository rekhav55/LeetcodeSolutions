class TrieNode{
    public:
    char data;
    TrieNode** children;
    int idx;
    TrieNode(char c){
        data=c;
        children=new TrieNode*[27];
        for(int i=0; i<27; i++){
            children[i]=NULL;
        }
        idx=INT_MIN;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root= new TrieNode('\0');
    }
    void insertHelper(TrieNode* root, string word, int index){
        // BASE CASE
        if(word.size()==0){
            return;
        }
        
        char c=word[0]; int idx;
        if(c=='#'){idx=26;} else{ idx=c-'a'; }
        
        TrieNode* child;
        if((*root).children[idx] == NULL){
            child= new TrieNode(c);
            (*root).children[idx]=child;
        }
        else{
            child=(*root).children[idx];
        }
        int temp=(*child).idx;
        (*child).idx=max(temp, index);
        
        insertHelper(child, word.substr(1), index);
    }
    void insert( string word , int index ){
        insertHelper(this->root, word, index);
    }
    
    int val=-1;
    void searchHelper(TrieNode* root, string word){
        // BASE CASE
        if(word.size()==0){
            return;
        }
        
        char c=word[0]; int idx;
        if(c=='#'){idx=26;} else{ idx=c-'a'; }
        
        if((*root).children[idx] == NULL){
            val=-1; return;
        }
        val=(*root).children[idx]->idx;
        
        searchHelper((*root).children[idx], word.substr(1));
    }
    int search( string word ){
        val=-1;
        searchHelper(this->root, word);
        return val;
    }
};
class WordFilter {
public:
    Trie t;
    WordFilter(vector<string>& word) {
        for(int i=0; i<word.size(); i++){
            string tmp=word[i];
            while(tmp.size()!=0){
                string str="";
                str+=tmp;
                str+='#';
                str+=word[i];
                
                t.insert(str, i);
                
                tmp=tmp.substr(1);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string str="";
        str+=suffix;
        str+='#';
        str+=prefix;
        return t.search(str);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */