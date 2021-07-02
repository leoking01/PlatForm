//
// Created by alex on 2021/7/1.
//

#ifndef VISIONCOMPAREBENCH_UTILITIES_H
#define VISIONCOMPAREBENCH_UTILITIES_H

#include <stdio.h>

#include <iostream>
#include <fstream>
#include <strstream>

#include <string>

#include <list>
#include <set>
#include <map>
#include <vector>

#include <algorithm>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

#include <string.h>
#include <sstream>


class utilities {

};

std::vector<std::string> split_std_string(const std::string &str, const std::string &delim);

bool IsContainsStr(std::string str, std::string contains_str);

std::vector<std::string> split_std_string(const std::string &s, std::vector<std::string> &res, char delim);


#endif //VISIONCOMPAREBENCH_UTILITIES_H
