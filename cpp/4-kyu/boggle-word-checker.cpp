#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <stack>
#include <cctype>

std::vector<std::pair<int, int>> find_starting_points(const std::vector<std::vector<char>>&board, const char& ch){
    int size = board.size();
    std::vector<std::pair<int, int>> out;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(board[i][j] == ch){
                out.push_back(std::make_pair(i, j));
            }
        }
    }
    return out;
}

std::vector<std::pair<int, int>> find_neighbors(std::vector<std::vector<char>> board, const char& ch, std::pair<int, int> curr){
    std::vector<std::pair<int, int>> out;
    
    return out;
}

bool check_recursive(std::vector<std::vector<char>> board, const std::string& word, int index, std::pair<int, int> currPoint){
    if(index > word.length()){
        return true;
    }

    if(std::islower(board[currPoint.first][currPoint.second])){
        return false;
    }

    board[currPoint.first][currPoint.second] = std::tolower(word[index]);
    std::vector<std::pair<int, int>> neighbors = find_neighbors(board, word[index + 1], currPoint);
    
    if(neighbors.empty()){
        return false;
    }

    for(auto e : neighbors){
        if(check_recursive(board, word, ++index, e)){
            return true;
        }
    }

    return false;
}


bool check_word(const std::vector<std::vector<char>>& board, const std::string& word){
    std::vector<std::pair<int, int>> start = find_starting_points(board, word[0]);
    
    for(auto p : start){
        if(check_recursive(board, word, 1, p)){
            return true;
        }
    } 

    return false;
}

int main(int argc, char* argv[]){
    
    if(argc != 2){
        std::cout << "Usage: ./a.out <string>\n";
        return 1;
    }
    
    std::vector<std::vector<char>> board = {
        { 'I', 'L', 'A', 'W' },
        { 'B', 'N', 'G', 'E' },
        { 'I', 'U', 'A', 'O' },
        { 'A', 'S', 'R', 'L' } };

    if(check_word(board, std::string(argv[1]))){
        std::cout << "Valid\n";
    }else{
        std::cout << "Invalid\n";
    }

    return 0;
}
