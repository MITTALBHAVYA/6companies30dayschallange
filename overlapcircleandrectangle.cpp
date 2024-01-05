class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xa = x1-xCenter,xb=x2-xCenter;
        int ya = y1-yCenter,yb=y2-yCenter;
        //required minimum of x^2 and min of y^2;
        int minX=0;
        if(xa*xb>0)
        {
            minX=min(xa*xa,xb*xb);
        }
        int minY=0;
        if(ya*yb>0)
        {
            minY=min(ya*ya,yb*yb);
        }
        return minX + minY <= radius*radius;
    }
};