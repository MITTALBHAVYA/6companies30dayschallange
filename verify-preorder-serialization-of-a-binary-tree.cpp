class Solution {
public:
    bool isValidSerialization(string preorder) {
        int nodes=1;
        preorder+=',';
        for(int i=0;i<preorder.size();i++){
            if(preorder[i]!=',')continue;
            nodes--;
            if(nodes<0)return false;
            if(preorder[i-1]!='#')nodes+=2;
        }
        return nodes==0;
    }
};