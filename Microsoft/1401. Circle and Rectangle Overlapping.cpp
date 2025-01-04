class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // let rectangle overlaps the center of circle
        int x = xCenter;  
        int y = yCenter;

        if(xCenter > x1 && xCenter > x2) x = x2; // rectanlge is right side of the circle
        else if(xCenter < x1 && xCenter < x2) x = x1;  // rectanlge is left side of the circle

        if(yCenter > y1 && yCenter > y2) y = y2;  // rectanlge is bottom of the circle
        else if(yCenter < y1 && yCenter < y2) y = y1; // rectanlge is at top of the circle

        int dist = (x-xCenter)*(x-xCenter) + (y-yCenter)*(y-yCenter);
        return dist <= radius*radius;
    }
};