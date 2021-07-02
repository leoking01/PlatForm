#include "mainapp.h"

#pragma execution_character_set("utf-8")
MainApp *MainApp::instance = NULL;

#include "utilities.h"




#if   0
int nameInFlows_to_idx__from_flow_list(std::string InFlow_name) {
    int idx = -1;
    std::cout << "nameInFlows_to_nameInToolBox = " << InFlow_name << std::endl;
    // std::spli
    std::vector<std::string> res;
    split_std_string(InFlow_name, res, ',');
    if (res.size() >= 2) {
        //          std:: res[0]
        idx = std::stoi(res[1]);
    } else
        idx = -1;
    return idx;
}

//---------------------------------------------------------------
int soleName_to_className(std::string soleName, std::string &className) {
    int idx = -1;
    std::cout << "soleName = " << soleName << std::endl;
    // std::spli
    std::vector<std::string> res;
    split_std_string(soleName, res, ',');
    if (res.size() >= 3) {
        // std:: res[0]
        idx = std::stoi(res[0]);
        className = res[2];
    } else {
        idx = -1;
        className = "";
    }
    return idx;
}
#endif
