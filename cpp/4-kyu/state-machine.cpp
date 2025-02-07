#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

enum State{
    CLOSED, LISTEN, SYN_SENT, SYN_RCVD, ESTABLISHED, CLOSE_WAIT, LAST_ACK, FIN_WAIT_1, FIN_WAIT_2, CLOSING, TIME_WAIT, ERROR
};

std::string print_state(State state){
    std::vector<std::string> states = {
        "CLOSED", "LISTEN", "SYN_SENT", "SYN_RCVD", "ESTABLISHED", "CLOSE_WAIT", "LAST_ACK", "FIN_WAIT_1", "FIN_WAIT_2", "CLOSING", "TIME_WAIT", "ERROR"
    };
    return states[state];
}

State handle_closed(const std::string& ev){
    if(ev == "APP_PASSIVE_OPEN") return LISTEN;
    if(ev == "APP_ACTIVE_OPEN") return SYN_SENT;
    return ERROR;   
}

State handle_listen(const std::string& ev){
    if(ev == "RCV_SYN") return SYN_RCVD;
    if(ev == "APP_SEND") return SYN_SENT;
    if(ev == "APP_CLOSE") return CLOSED;
    return ERROR;   
}

State handle_syn_sent(const std::string& ev){
    if(ev == "RCV_SYN") return SYN_RCVD;
    if(ev == "RCV_SYN_ACK") return ESTABLISHED;
    if(ev == "APP_CLOSED") return CLOSED;
    return ERROR;   
}

State handle_syn_rcvd(const std::string& ev){
    if(ev == "APP_CLOSE") return CLOSED;
    if(ev == "RCV_ACK") return ESTABLISHED;
    return ERROR;   
}

State handle_established(const std::string& ev){
    if(ev == "APP_CLOSE") return FIN_WAIT_1;
    if(ev == "RCV_FIN") return CLOSE_WAIT;
    return ERROR;   
}

State handle_close_wait(const std::string& ev){
    if(ev == "APP_CLOSE") return LAST_ACK;
    return ERROR;   
}

State handle_last_ack(const std::string& ev){
    if(ev == "RCV_ACK") return CLOSED;
    return ERROR;   
}

State handle_fin_wait_1(const std::string& ev){
    if(ev == "RCV_FIN") return CLOSING;
    if(ev == "RCV_FIN_ACK") return TIME_WAIT;
    if(ev == "RCV_ACK") return FIN_WAIT_2;
    return ERROR;   
}

State handle_fin_wait_2(const std::string& ev){
    if(ev == "RCV_FIN") return TIME_WAIT;
    return ERROR;   
}

State handle_closing(const std::string& ev){
    if(ev == "RCV_ACK") return TIME_WAIT;
    return ERROR;   
}

State handle_time_wait(const std::string& ev){
    if(ev == "APP_TIMEOUT") return CLOSED;
    return ERROR;   
}

std::unordered_map<State, std::function<State(std::string)>> transitions = {
    { CLOSED, handle_closed },
    { LISTEN, handle_listen },
    { SYN_SENT, handle_syn_sent },
    { SYN_RCVD, handle_syn_rcvd },
    { ESTABLISHED, handle_established },
    { CLOSE_WAIT, handle_close_wait },
    { LAST_ACK, handle_last_ack },
    { FIN_WAIT_1, handle_fin_wait_1 },
    { FIN_WAIT_2, handle_fin_wait_2 },
    { CLOSING, handle_closing },
    { TIME_WAIT, handle_time_wait }
};


std::string traverse_TCP_states(const std::vector<std::string> &events){
    State curr = CLOSED;  
    for(const auto& e : events){
       auto it = transitions.find(curr);
       if(it == transitions.end()){
          return "ERROR";
       }
       curr = it->second(e); 
    } 
    return print_state(curr);
}

int main(){
    using vs = std::vector<std::string>;
          
    vs test1 = {"APP_ACTIVE_OPEN","RCV_SYN_ACK","RCV_FIN"};
    vs test2 = {"APP_PASSIVE_OPEN",  "RCV_SYN","RCV_ACK"};
    vs test3 = {"APP_ACTIVE_OPEN","RCV_SYN_ACK","RCV_FIN","APP_CLOSE"};
    vs test4 = {"APP_ACTIVE_OPEN"};
    vs test5 = {"APP_PASSIVE_OPEN","RCV_SYN","RCV_ACK","APP_CLOSE","APP_SEND"};

    std::cout << "[test1]::" << traverse_TCP_states(test1) << std::endl;
    std::cout << "[test2]::" << traverse_TCP_states(test2) << std::endl;    
    std::cout << "[test3]::" << traverse_TCP_states(test3) << std::endl;    
    std::cout << "[test4]::" << traverse_TCP_states(test4) << std::endl;    
    std::cout << "[test5]::" << traverse_TCP_states(test5) << std::endl;
    
    return 0;
}
