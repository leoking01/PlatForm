//
// Created by alex on 2021/7/1.
//

#include "utilities.h"
std::vector <std::string> split_std_string(const std::string &str, const std::string &delim) {
    std::vector <std::string> res;
    if ("" == str) return res;
    //先将要切割的字符串从string类型转换为char*类型
    char *strs = new char[str.length() + 1]; //
    strcpy(strs, str.c_str());

    char *d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while (p) {
        std::string s = p; //分割得到的字符串转换为string类型
        res.push_back(s); //存入结果数组
        p = strtok(NULL, d);
    }
    return res;
}


//判断字符串是否包含某字符串
//@params:str:大的字符串
//@params:contains_str:所包含的字符串
//@return: false:未包含 true：包含
bool IsContainsStr(std::string str, std::string contains_str) {
    std::string::size_type idx = str.find(contains_str);
    if (idx != std::string::npos) {
        return true;
    } else {
        return false;
    }
}

std::vector <std::string> split_std_string(const std::string &s, std::vector <std::string> &res, char delim) {
    std::stringstream ss( s );
    std::string item;
    while (std::getline(ss, item, delim)) {
        res.push_back(item);
    }
    return res;
}



