/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    void cleanRoom(Robot& robot) {
        vector<vector<int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
        unordered_set<string>vis;
        cleanRoomRecursively(robot,vis,0,0,0,dir);
    }

    void cleanRoomRecursively(Robot& robot,unordered_set<string>& vis, int curDir, int curX, int curY, vector<vector<int>>&dir){
        vis.insert(to_string(curX)+","+to_string(curY));
        robot.clean();
        for(int i=0;i<4;i++){
            int newDir=(curDir+i)%4;
            int newX=curX+dir[newDir][0];
            int newY=curY+dir[newDir][1];
            if(vis.find(to_string(newX)+","+to_string(newY))==vis.end() && robot.move()){
                cleanRoomRecursively(robot,vis,newDir,newX,newY,dir);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
        }
    }
};