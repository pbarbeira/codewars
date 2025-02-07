#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

std::string vec_to_str(const std::vector<int>& v){
    std::stack<int> st;
    for(const auto& i : v){
        st.push(i);
    }
    std::stringstream ss;
    while(!st.empty()){
        ss << st.top();
        st.pop();
    }
    return ss.str();
}

std::vector<int> num_to_vec(int num, int trail = 0){
    std::vector<int> out;
    if(num == 0){
        out.push_back(0);
    }
    while(trail != 0){
        out.push_back(0);
        trail--;
    }
    while(num != 0){
        out.push_back(num % 10);
        num /= 10;
    }
    return out;
}

std::vector<int> multiply(std::vector<int> n1, std::vector<int> n2){
    std::vector<int> out;
    int carry = 0;
    for(int i = 0; i < n2.size(); i++){
        int j = 0;
        for(j = 0; j < n1.size(); j++){
            int val = carry + n2[i] * n1[j];
            if(out.size() == i + j){
                out.push_back(val % 10);
            }else{
                val += out[i + j];
                out[i + j] = val % 10;
            }
            carry = val / 10;
        }
        if(carry){
            out.push_back(carry);
        }
        carry = 0;
    }
    return out;
}

std::string factorial(int factorial){
    if(factorial == 0 || factorial == 1){
        return "1";
    }
    std::vector<int> acc = num_to_vec(factorial--);
    do{
        acc = multiply(acc, num_to_vec(factorial--));
    }while(factorial != 0);
    return vec_to_str(acc); 
}

bool validate(char* arg){
    int i = 0;
    while(arg[i] != '\0'){
        if(!std::isdigit(arg[i])){
            return false;
        }
        i++;
    }
    return true;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        std::cout << "Usage:: ./a.out <integer>\n";
        return 1;
    }

    if(!validate(argv[1])){
        std::cout << "Usage:: ./a.out <integer>\n";
        return 1;
    }

    int number = std::atoi(argv[1]);
    std::cout << factorial(number) << std::endl;

    return 0;
}
