/*
 * Task
 * You are at position [0, 0] in maze NxN and you can only move in one of the 
 * four cardinal directions (i.e. North, East, South, West). Return the minimal 
 * number of steps to exit position [N-1, N-1] if it is possible to reach the 
 * exit from the starting position. Otherwise, return -1.
 *
 * Empty positions are marked .. Walls are marked W. Start and exit positions 
 * are guaranteed to be empty in all test cases.
 */

#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <utility>

int path_finder(std::string maze){
    int n = 0;
    for(; maze[n] != '\n'; n++);
    
    int vInc = n + 1;
    std::vector<int> moves = { -1, -vInc, 1, vInc };

    std::queue<std::pair<int, int>> s;
    s.push(std::make_pair(0, 0));
    
    while(!s.empty()){
        std::pair<int, int> cur = s.front();
        s.pop();
        if(cur.first == maze.size() -1){
            return cur.second;
        } 
        for(int i = 0; i < 4; i++){
            int newPos = cur.first + moves[i];
            if(newPos > 0 && newPos < maze.size() && maze[newPos] != 'x' && maze[newPos] != 'W' && maze[newPos] != '\n'){
                maze[newPos] = 'x';
                s.push(std::make_pair(newPos, cur.second + 1));
            }
        }
    }    

    return -1;
}

int main(){
    std::string maze = "......\n......\n......\n......\n......\n......";
    
    int res = path_finder(maze);
    std::cout << "Res: " << res << std::endl;

    return 0;
}
