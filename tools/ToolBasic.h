//
// Created by alex on 2021/7/1.
//

#ifndef VISIONCOMPAREBENCH_TOOLBASIC_H
#define VISIONCOMPAREBENCH_TOOLBASIC_H

#include <stdio.h>

#include <iostream>
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
#include <opencv2/opencv.hpp>
#include <nlohmann/json.hpp>

class ToolBase {
public:
    virtual void run() {};//  = 0;
    virtual void to_json(nlohmann::json &j) {};// = 0;
    virtual void from_json(const nlohmann::json &j) {};// = 0;

    typedef struct stru_tool_info_data {
        std::string className;   // 类名，  用于构造实例
        std::string nameInToolBox;   //  这个是显示在工具栏中的名称，一般是中文  这个名字是固定的
        int InFlow_order;   //  在流程中的序号，是执行的过程
        //  该工具实例的唯一的名称,
        //  order,日期时间 ， className,  nameInToolBox  这个名字一般含有中文
        std::string InFlow_nameID;   // 这个名字作为该工具的唯一凭据  不含有中文
        std::string Inflow_name_show ;    // name show in flow
        stru_tool_info_data() {
            className = "null name";
            nameInToolBox = "null name";
            InFlow_nameID = "null name";
            InFlow_order = 0;
        }

        stru_tool_info_data(
                std::string classNamet, std::string nameInToolBoxt,
                std::string name_uniquet, int orderInFlowt) : className(classNamet), nameInToolBox(nameInToolBoxt),
                                                              InFlow_nameID(name_uniquet),
                                                              InFlow_order(orderInFlowt) {
        }
    } tp_tool_info;


    tp_tool_info toolInfo;

    virtual bool operator<(ToolBase &tbt) const {
        return true;
    }

    std::vector<ToolBase *> *subFlow;
};

#endif //VISIONCOMPAREBENCH_TOOLBASIC_H
