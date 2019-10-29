#include <iostream>
#include <regex>
int main() {

    std::regex pattern("([\\w]+)@(\\w+).com");
    std::string str="whoever@qq.com";
    std::smatch result;
    bool is_match=std::regex_match(str,result,pattern);
    if(is_match){
        std::cout<<"匹配成功:\t"<<result[0]<<std::endl;
        for(size_t i=1;i<result.size();i++){
            std::cout<<result[i]<<std::endl;
        }
    }else{
        std::cout<<"匹配失败"<<std::endl;
    }

    return 0;
}