class TrieNode{
public:
    TrieNode* children[26];
    int count;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        count=0;
    } 
    TrieNode* get(char ch){
        if(children[ch-'a']==nullptr){
            children[ch-'a']=new TrieNode();
            count++;
        }
        return children[ch-'a'];
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* trie = new TrieNode();
        unordered_map<TrieNode*,int>nodes;
        for(int i=0;i<words.size();i++){
            string word = words[i];
            TrieNode* curr = trie;
            for(int j=word.length()-1;j>=0;j--){
                curr=curr->get(word[j]);
            }
            nodes[curr]=i;
        }
        int ans=0;
         for (const auto& entry : nodes) {
            TrieNode* node = entry.first;
            if (node->count == 0) {
                ans += words[entry.second].length() + 1;
            }
        }

        // Clean up allocated memory
        delete trie;
        for (const auto& entry : nodes) {
            delete entry.first;
        }

        return ans;
    }
};