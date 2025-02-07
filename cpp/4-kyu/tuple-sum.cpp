#include <iostream>
#include <vector>

#include <tuple>
#include <typeinfo>
#include <type_traits>

template<typename T>
double to_double(const T& arg){
    if constexpr (std::is_arithmetic_v<T> && !std::is_same_v<T, char>){
        return arg;
    }else{
        return 0;
    }
}

template<typename... Ts>
double tuple_sum(const std::tuple<Ts...>& tpl){
    return std::apply([](const auto&... args){
                return (0 + ... + to_double(args));
            }, tpl);    
}

int main(){
    auto tuple = std::make_tuple(3.14, 42, "test", 'a' );

    std::cout << tuple_sum(tuple) << std::endl;

   return 0; 
}

