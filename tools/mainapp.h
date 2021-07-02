#ifndef MAINAPP_H
#define MAINAPP_H

#include "ImageSourceManager.h"
#include "ToolProducer.h"

class MainApp {
public:

private:
    MainApp() {
    }

public:
    static MainApp *getInstance() {
        if (!instance) {
            std::map<int, ToolBase *> *flowData_t = new std::map<int, ToolBase *>();
            instance = new MainApp();
            instance->flowData = flowData_t;
        } else
            return instance;
    }

    ~MainApp() {
        if (instance) {
            if (flowData) {
                for (std::map<int, ToolBase *>::iterator it = flowData->begin(); it != flowData->end(); it++) {
                    ToolBase * ptool =  it->second ;
                    if ( ptool  )
                        delete ptool;
                }
                flowData->clear();
                delete instance->flowData;
            }
            delete instance;
        }
    }
public:
    std::map<int, ToolBase *> *flowData;

private:
    static MainApp *instance;
public:
    bool addToolItem_from_ui(
            int order, std::string tool_name,
            std::string str_time, std::string &soleName
//            , std::map<int, ToolBase * > &flowData
    ) {
        ToolFactory *fac = new ToolFactory;
        fac->order = order;
        fac->nameInToolBox = tool_name;
        fac->str_time = str_time;
        ToolBase *absTool = fac->generate_by_nameInToolBox();
        if (!absTool) return false;
        soleName = fac->soleName;
        try {
            if (1) {
                //  flowData.insert(std::pair<int, ToolBase *>(order, absTool));
                if (1)
                    (*flowData)[order] = absTool;
            }
        } catch (std::exception ex) {
            std::cout << "ex.what() = " << ex.what() << std::endl;
        }
//        std::map<int, ToolBase *> ppa;
//        ppa.insert(std::pair<int, ToolBase *>(order, absTool));
//        if (1) {
//            std::map<int, ToolBase *> *pp = new std::map<int, ToolBase *>();
//            pp->insert(std::pair<int, ToolBase *>(order, absTool));
//        }
        delete fac;
        return true;
    }


    bool addToolItem_from_json(std::string &soleName
//            , std::map<int, ToolBase *> &flowData
    ) {
        ToolFactory fac;
        fac.soleName = soleName;
        //fac.nameInToolBox = tool_name;
        //fac.str_time = str_time;
        ToolBase *absTool = fac.generate_by_soleName();
        if (!absTool) return false;
        flowData->insert(std::pair<int, ToolBase *>(fac.order, absTool));
        return true;
    }


public:
#if 0
    void to_json(nlohmann::json* j) {
        std::cout << "\n\n_______________________to_json__________________________" << std::endl;
        std::cout << "this->flowData.size() = " << this->flowData.size() << std::endl;//'\n';
        if (this->flowData.size() <= 0)return;
        for (std::map<  int, ToolBase*    >::iterator it = flowData.begin();
             it != flowData.end(); it++)
        {
            //            nlohmann:: json j_tmp;
            //            ((ToolSource*)  it->second)->to_json( j_tmp         );
            //            j->push_back( j_tmp    ) ;
            //            std::cout <<"j_tmp  = "<<  j_tmp << std::endl;
            nlohmann::json* pjs = new nlohmann::json();
            ((ToolSource*)it->second)->to_json(pjs);
            j->push_back(*pjs);
            std::cout << "* pjs  = " << *pjs << std::endl;
        }
        std::cout << "j  = " << j << std::endl;
    }
#endif

    void to_json(nlohmann::json &j
//            , std::map<int, ToolBase *> &flowData
    ) {
        std::cout << "________________to_json______________" << std::endl;
        std::cout << " flowData.size() = " << flowData->size() << std::endl;//'\n';
        //  return;
        if ((flowData)->size() <= 0)return;
        for (std::map<int, ToolBase *>::iterator it = flowData->begin();
             it != flowData->end(); it++) {
            nlohmann::json j_tmp;
            (it->second)->to_json(j_tmp); //(ToolSource*)
            j.push_back(j_tmp);
            std::cout << "j_tmp  = " << j_tmp << std::endl;
        }
        std::cout << "j  = " << j << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }


    bool from_json(nlohmann::json &j
//            , std::map<int, ToolBase *> &flowData
    ) {
        std::cout << "_________from_json________" << std::endl;
        //for(  int i)
        std::cout << "j.size() = " << j.size() << std::endl;//'\n';
        if (j.size() <= 0)
            return false;

        flowData->clear();
        for (nlohmann::json::iterator it = j.begin(); it != j.end(); ++it) {
            std::cout << "*it = " << *it << std::endl;//'\n';

            ToolFactory fac;
            std::string soleName_fromFile = (*it)["InFlow_nameID"];
            std::string str_time;
            //            std::  string  str_soleName;
            int order = -1;
            fac.soleName = soleName_fromFile;
            ToolBase *pt = fac.generate_by_soleName();

            // this-> flowData.insert(std:: pair< int ,ToolBase* > ( id , pt ) ) ;
            bool res = this->addToolItem_from_json(fac.soleName
//                    , flowData
            );
            if (!res) {
                std::cout << "add  tool failure. " << std::endl;
                return false;
            } else std::cout << "add  tool success. " << std::endl;
        }

        std::cout << std::endl;
        std::cout << std::endl;
        return true;
    }
};


//extern  MainApp   theMainApp;
#endif // MAINAPP_H
