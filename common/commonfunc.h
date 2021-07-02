#ifndef COMMONFUNC_H
#define COMMONFUNC_H

#include <stdio.h>
#include <time.h>

#include <string>
#include <ctime>

#include <chrono>
#include <thread>
#include <mutex>

#include <algorithm>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

#include <iostream>
#include <iomanip>
#include <fstream>

#include <opencv2/opencv.hpp>

#include <QTextCodec>
#include <QLabel>
#include <QtWidgets/QTextBrowser>

#include <nlohmann/json.hpp>
// for convenience
using json = nlohmann::json;

//class CommonFunc {
//public:
//    CommonFunc();
//};

std::string getDatetimeStr();

std::string getDatetimeStr_forID();

void load_json(nlohmann::json &j, std::string file);

void save_json(nlohmann::json j22, std::string file);

void displayResult(cv::Mat matt, QLabel *label_2);

void print_cvMat_info(cv::Mat img, QTextBrowser *pt = NULL);

#endif // COMMONFUNC_H
