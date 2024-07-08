class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x==y)return (2*x + z)*2;
        else return (min(x,y)*2 + z + 1)*2;
    }
};