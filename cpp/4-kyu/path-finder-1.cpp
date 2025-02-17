/*
 * Task
 * You are at position [0, 0] in maze NxN and you can only move in one of the 
 * four cardinal directions (i.e. North, East, South, West). Return true if you 
 * can reach position [N-1, N-1] or false otherwise.
 *
 * - Empty positions are marked ..
 * - Walls are marked W.
 * - Start and exit positions are empty in all test cases.
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>

bool path_finder(std::string maze){
    int n = 0;
    while(maze[n] != '\n') n++;
    int pos = 0, max = maze.size() - 1, vInc = n+1;
    std::vector<int> movements = { -1, -vInc, 1, vInc };
    std::stack<int> q;
    q.push(pos);
    while(!q.empty()){
        int cur = q.top();
        maze[cur] = 'x';
        q.pop();
        for(int i = 0; i < movements.size(); i++){
            int newPos = cur + movements[i];
            if(newPos == max) return true;
            if(newPos > 0 && newPos < max && maze[newPos] != 'x' && maze[newPos] != '\n' && maze[newPos] != 'W'){
                q.push(newPos);
            }
        }
    }

    return false; 
}

int main(){
    std::string maze = ".....\n.....\n.....\n....W\n...W.";
    if(path_finder(maze)){
        std::cout << "Success\n";
    }else{
        std::cout << "Failure\n";
    }
    
    return 0;
}
