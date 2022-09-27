class Solution {
public:
void RL(int start, int end, string& s){
while(start<end){
s[start++]='R';
s[end--]='L';
}
}
void bothsame(int start, int end, string& s, char c){
for(int i=start; i<end; i++){
s[i]=c;
}
}
string pushDominoes(string dominoes) {
vector<pair<char, int>> v;
int sz= dominoes.size();
for(int i=0; i<sz; i++){
if(dominoes[i]=='L' || dominoes[i]=='R'){
v.push_back({dominoes[i], i});
}
}
int vsize= v.size();
if(vsize>0 && v[0].first=='L'){
int i=0;
while(i!=v[0].second){
dominoes[i++]='L';
}
}
if(vsize>0 && v[vsize-1].first=='R'){
int i=v[vsize-1].second;
while(i!=sz){
dominoes[i++]='R';
}
}
for(int i=0; i<vsize-1; i++){
char curr= v[i].first;
char next= v[i+1].first;
int currind= v[i].second;
int nextind= v[i+1].second;
if(curr==next){
bothsame(currind, nextind, dominoes, curr);
}
else if(curr=='R' && next=='L'){
RL(currind, nextind, dominoes);
}
else{
continue;
}
}
return dominoes;
}
};