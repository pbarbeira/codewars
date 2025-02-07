#include <iostream>
#include <string>

int MINUTE = 60;
int HOUR = 60 * MINUTE;
int DAY = 24 * HOUR;
int YEAR = 365 * DAY;

std::string format_duration(int seconds){
    if(!seconds){
        return "now";
    }

    int divisors[4] = { YEAR, DAY, HOUR, MINUTE };
    int values[5] = { 0, 0, 0, 0, 0 };
    std::string units[5] = { "year", "day", "hour", "minute", "second" };

    for(int i = 0; i < 5; i++){
        if(i == 4){
            values[i] = seconds;
            continue;
        }
        
        int divisor = divisors[i];

        values[i] = seconds / divisor;
        seconds %= divisor;
    }

    std::string out = "";

    for(int i = 0; i < 5; i++){
        int value = values[i];
        if(value){
            if(!out.empty()){
                bool last = true;
                for(int j = i + 1; j < 5; j++){
                    if(values[j] != 0){
                        last = false;
                        break;
                    }
                }
                if(last || i == 4){
                    out += " and ";
                }else{
                    out += ", ";
                }
            }
            out += std::to_string(value) + " " + (value == 1 ? units[i] : (units[i] + "s"));
        }
    }

    return out; 
}

int main(){
    std::cout << format_duration(3660) << std::endl;
}
