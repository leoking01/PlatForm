//
// Created by alex on 2021/7/1.
//

#ifndef VISIONCOMPAREBENCH_TOOLPRODUCER_H
#define VISIONCOMPAREBENCH_TOOLPRODUCER_H

#include "ImageSourceManager.h"

//class ToolProducer {
//
//};

//  设计名字：   order,日期时间，name,
class ToolFactory {
public:
    std::string soleName;
    int order;

    std::string str_time;
    std::string nameInToolBox;

    std::string className;

public:
    ToolBase *generate_by_soleName() {
        ToolBase *pt = NULL;
        std::cout << "generate_by_soleName: soleName: " << soleName << std::endl;
        if (soleName.empty()) return NULL;

        std::cout << "soleName.compare(nameInToolBoxset[0] =  " << soleName.find(ToolNameLst::getNames()[0]) << std::endl;

        //IsContainerPartition
        if (soleName.find(ToolNameLst::getNames()[0]) >= 0) {
            pt = new ToolSource();
            std::vector<std::string> res;
            split_std_string(soleName, res, ',');

            //读取
            if (res.size() >= 3) {
                int idx = std::stoi(res[0]);
                this->str_time = res[1];
                this->className = res[2];
                this->nameInToolBox = className_to_nameInToolBox(this->className);
                this->order = idx;

                ((ToolSource *) pt)->toolInfo.InFlow_order = order;
                ((ToolSource *) pt)->toolInfo.className = "ToolSource";
                (pt)->toolInfo.nameInToolBox = this->nameInToolBox;
                ((ToolSource *) pt)->toolInfo.InFlow_nameID = soleName;
//                (pt)->toolInfo.InFlow_nameID = soleName;
            } else
                return NULL;
        } else if (soleName.find(ToolNameLst::getNames()[1]) >= 0) {
            pt = new ToolSaveFile();
            std::vector<std::string> res;
            split_std_string(soleName, res, ',');
            if (res.size() >= 3) {
                int idx = std::stoi(res[0]);
                this->str_time = res[1];
                this->className = res[2];
                this->nameInToolBox = className_to_nameInToolBox(this->className);
                this->order = idx;

                (pt)->toolInfo.InFlow_order = order;
                (pt)->toolInfo.className = "ToolSaveFile";
                (pt)->toolInfo.nameInToolBox = this->nameInToolBox;
                (pt)->toolInfo.InFlow_nameID = soleName;
//                (pt)->toolInfo.InFlow_nameID = soleName;
            }
        } else if (soleName.find(ToolNameLst::getNames()[2]) >= 0) {
            pt = new ToolBlur();

            std::vector<std::string> res;
            split_std_string(soleName, res, ',');
            if (res.size() >= 3) {
                int idx = std::stoi(res[0]);
                this->str_time = res[1];
                this->className = res[2];
                this->nameInToolBox = className_to_nameInToolBox(this->className);
                this->order = idx;

                (pt)->toolInfo.InFlow_order = order;
                (pt)->toolInfo.className = "ToolBlur";
                (pt)->toolInfo.nameInToolBox = this->nameInToolBox;
                (pt)->toolInfo.InFlow_nameID = soleName;
//                (pt)->toolInfo.InFlow_nameID = soleName;
            }
        }

        if (!pt) {
            std::cout << "gennerate  tool failure. " << std::endl; //return  false;
        } else {
            std::cout << "gennerate  tool sucess. " << std::endl; //return  false;
        }
        return pt;
    }

    //==============================================
    std::string make_soleName() {
        return std::to_string(order) + "," +
               str_time + "," +
               className + ",aaa9";// +"," +
        // nameInToolBox;
    }

    std::string
    className_to_nameInToolBox(std::string className) {
        std::string str_nameInToolBox = "";
        if (nameInToolBox.compare(ToolNameLst::getNames()[0]) >= 0) {
            str_nameInToolBox = "ToolSource";  //  ToolSaveFile   ToolBlur
        }
        if (nameInToolBox.compare(ToolNameLst::getNames()[1]) >= 0) {
            str_nameInToolBox = "ToolSaveFile";  //  ToolSaveFile   ToolBlur
        }
        if (nameInToolBox.compare(ToolNameLst::getNames()[2]) >= 0) {
            str_nameInToolBox = "ToolBlur";  //  ToolSaveFile   ToolBlur
        }
        return str_nameInToolBox;
    }

    ToolBase *generate_by_nameInToolBox() {
        ToolBase *pt = NULL;
        std::cout << "generate_by_nameInToolBox: nameInToolBox: " << nameInToolBox << std::endl;
        if (nameInToolBox.compare(ToolNameLst::getNames()[0]) >= 0) {
            this->className = "ToolSource";
            this->soleName = make_soleName();

            pt = new ToolSource();
            (pt)->toolInfo.InFlow_order = this->order;
            (pt)->toolInfo.InFlow_nameID = this->soleName;
            (pt)->toolInfo.className = this->className;
//            (pt)->toolInfo.InFlow_name = this->soleName;
        } else if (nameInToolBox.compare(ToolNameLst::getNames()[1]) >= 0) {
            this->className = "ToolSaveFile";
            this->soleName = make_soleName();
            pt = new ToolSaveFile();
            (pt)->toolInfo.InFlow_order = this->order;
            (pt)->toolInfo.InFlow_nameID = this->soleName;
            (pt)->toolInfo.className = this->className;
//            (pt)->toolInfo.InFlow_name = this->soleName;
        } else if (nameInToolBox.compare(ToolNameLst::getNames()[2]) >= 0) {
            this->className = "ToolBlur";
            this->soleName = make_soleName();
            pt = new ToolBlur();
            (pt)->toolInfo.InFlow_order = this->order;
            (pt)->toolInfo.InFlow_nameID = this->soleName;
            (pt)->toolInfo.className = this->className;
//            (pt)->toolInfo.InFlow_name = this->soleName;
        } else {
            //  std::cout << "gennerate  tool failure. " << std::endl;
            //   return  NULL;
        }

        if (!pt) {
            std::cout << "gennerate  tool failure. " << std::endl; //return  false;
        } else {
            std::cout << "gennerate  tool sucess. " << std::endl; //return  false;
        }
        return pt;
    }
private:
};

#endif //VISIONCOMPAREBENCH_TOOLPRODUCER_H
