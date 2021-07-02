//
// Created by alex on 2021/7/1.
//

#ifndef VISIONCOMPAREBENCH_IMAGESOURCEMANAGER_H
#define VISIONCOMPAREBENCH_IMAGESOURCEMANAGER_H

#include "ToolBasic.h"
#include "utilities.h"
#include "ToolNameLst.h"


class ToolSource : public ToolBase {
public:
    ToolSource() {
        toolInfo.className = "ToolSource";
        toolInfo.nameInToolBox = "ToolSource--aaa-";

//        toolInfo.InFlow_name = "xxxxx";
        toolInfo.InFlow_order = -1;

        toolInfo.InFlow_nameID = "ToolSource--image-pcd-soruce-";
//        toolInfo.InMultiFlows_id = -1;

        filePath = "./tmp.png";  //pcd
        type = 0;//  0 file ;1 camera;2 stereo;3 dir;
    }

    virtual void run() {
        std::cout << "now run: " << toolInfo.nameInToolBox << std::endl;
    }

    std::string filePath;
    int type;//  文件，文件夹，摄像头，体感设备

    //
    void to_json(nlohmann::json &jt) {
        std::cout << "ToolSource exe to_json()." << std::endl;
        ToolSource p = *this;
        //        ,ToolSource  & p
        jt = nlohmann::json{
//                {"InFlow_name",       p.toolInfo.InFlow_name},
                {"className",         p.toolInfo.className},
                {"nameInToolBox",     p.toolInfo.nameInToolBox},
                {"InFlow_nameID", p.toolInfo.InFlow_nameID},
                {"order",             p.toolInfo.InFlow_order},
//                {"id",                p.toolInfo.InMultiFlows_id},

                {"filePath",          p.filePath},
                {"type",              p.type}
        };
        std::cout << "jt   = " << jt << std::endl;
        std::cout << "ToolSource exe to_json()  finish." << std::endl;
        //   jt = *pj ;
    }

    //
    void to_json(nlohmann::json *pjt) {
        std::cout << "ToolSource exe to_json()." << std::endl;
        ToolSource p = *this;
        //   ,ToolSource  & p
        // pjt->at( )
        nlohmann::json *pj = new nlohmann::json{
//                {"InFlow_name",       p.toolInfo.InFlow_name},
                {"className",         p.toolInfo.className},
                {"nameInToolBox",     p.toolInfo.nameInToolBox},
                {"InFlow_nameID", p.toolInfo.InFlow_nameID},
                {"order",             p.toolInfo.InFlow_order},
//                {"id",                p.toolInfo.InMultiFlows_id},

                {"filePath",          p.filePath},
                {"type",              p.type}
        };
        pjt = pj;
        std::cout << " * pjt   = " << *pjt << std::endl;
        std::cout << "ToolSource exe to_json()  finish." << std::endl;
        //  jt = *pj ;
    }


    void from_json(const nlohmann::json &j) {
        ToolSource p = *this;
//        j.at("InFlow_name").get_to(p.toolInfo.InFlow_name);
        j.at("className").get_to(p.toolInfo.className);
        j.at("nameInToolBox").get_to(p.toolInfo.nameInToolBox);
        j.at("InFlow_nameID").get_to(p.toolInfo.InFlow_nameID);

        j.at("order").get_to(p.toolInfo.InFlow_order);
//        j.at("id").get_to(p.toolInfo.InMultiFlows_id);

        j.at("filePath").get_to(p.filePath);
        j.at("type").get_to(p.type);
    }
};


class ToolSaveFile : public ToolBase {
public:
    ToolSaveFile() {
        toolInfo.className = "ToolSaveFile";
        toolInfo.nameInToolBox = "ToolSaveFile--bbb--";

//        toolInfo.InFlow_name = "null";
        toolInfo.InFlow_order = -1;

        toolInfo.InFlow_nameID = "ToolSaveFile--image-pcd-soruce-";
//        toolInfo.InMultiFlows_id = -1;

        saveFilePath = "./tmp.save.png";
        //  type = 0;//  0 file ;1 camera;2 stereo;3 dir;
    }

    virtual void run() {
        std::cout << "now run: " << toolInfo.nameInToolBox << std::endl;
    }

    void to_json(nlohmann::json &j) {
        std::cout << "ToolSaveFile exe to_json()." << std::endl;
        ToolSaveFile p = *this;
        j = nlohmann::json{
//                {"InFlow_name",       p.toolInfo.InFlow_name},
                {"className",         p.toolInfo.className},
                {"nameInToolBox",     p.toolInfo.nameInToolBox},
                {"InFlow_nameID", p.toolInfo.InFlow_nameID},

                {"order",             p.toolInfo.InFlow_order},
//                {"id",                p.toolInfo.InMultiFlows_id},

                {"saveFilePath",      p.saveFilePath}
                //        {"type", p.type}
        };

    }

    void from_json(const nlohmann::json &j) {
        ToolSaveFile p = *this;
//        j.at("InFlow_name").get_to(p.toolInfo.InFlow_name);
        j.at("className").get_to(p.toolInfo.className);
        j.at("nameInToolBox").get_to(p.toolInfo.nameInToolBox);
        j.at("InFlow_nameID").get_to(p.toolInfo.InFlow_nameID);

        j.at("order").get_to(p.toolInfo.InFlow_order);
//        j.at("id").get_to(p.toolInfo.InMultiFlows_id);

        j.at("saveFilePath").get_to(p.saveFilePath);
        //        j.at("type").get_to(p.type);
    }

    std::string saveFilePath;

};


class ToolBlur : public ToolBase {
public:
    ToolBlur() {
        toolInfo.className = "ToolBlur";
        toolInfo.nameInToolBox = "ToolBlur--fff";

//        toolInfo.InFlow_name = "null";
        toolInfo.InFlow_order = -1;

        toolInfo.InFlow_nameID = "ToolBlur--image-pcd-soruce-";
//        toolInfo.InMultiFlows_id = -1;

        blur_size = 3;

        m_img_input = cv::imread("./1.jpg");

        m_data.push_back(10);
        m_data.push_back(22);

        m_data_mat.push_back(m_data);

        m_pt.x = 2;
        m_pt.y = 22;
        m_pt.z = 23;

        dataA[0] = 42;
        dataA[1] = 22;
        dataA[2] = 12;
    }

    virtual void run() {
        std::cout << "now run: " << toolInfo.nameInToolBox << std::endl;
    }

    void to_json(nlohmann::json &j) {
        std::cout << "ToolBlur exe to_json()." << std::endl;
        ToolBlur p = *this;
        j = nlohmann::json{
//                {"InFlow_name",       p.toolInfo.InFlow_name},
                {"className",         p.toolInfo.className},
                {"nameInToolBox",     p.toolInfo.nameInToolBox},
                {"InFlow_nameID", p.toolInfo.InFlow_nameID},

                {"order",             p.toolInfo.InFlow_order},
//                {"id",                p.toolInfo.InMultiFlows_id},

                {"m_data",            p.m_data},
                {"m_data_mat",        p.m_data_mat},
                //                   {"m_pt", p.m_pt},
                {"dataA",             p.dataA},
                {"blur_size",         p.blur_size}
                //                 {"m_img_input", p.m_img_input}
                //  {"saveFilePath", p.saveFilePath}
                //        {"type", p.type}
        };
    }

    void from_json(const nlohmann::json &j) {
        ToolBlur p = *this;
//        j.at("InFlow_name").get_to(p.toolInfo.InFlow_name);
        j.at("className").get_to(p.toolInfo.className);
        j.at("nameInToolBox").get_to(p.toolInfo.nameInToolBox);
        j.at("InFlow_nameID").get_to(p.toolInfo.InFlow_nameID);

        j.at("order").get_to(p.toolInfo.InFlow_order);
//        j.at("id").get_to(p.toolInfo.InMultiFlows_id);

        j.at("m_data").get_to(p.m_data);
        j.at("m_data_mat").get_to(p.m_data_mat);
        //             j.at("m_pt").get_to(p.m_pt);
        j.at("dataA").get_to(p.dataA);
        j.at("blur_size").get_to(p.blur_size);
        //  j.at("m_img_input").get_to(p.m_img_input);
        //        j.at("saveFilePath").get_to(p.saveFilePath);
        //        j.at("type").get_to(p.type);
    }

    int blur_size;
    //  int blur_type;
    cv::Mat m_img_input;
    cv::Mat m_img_output;

    std::vector<int> m_data;

    std::vector<std::vector<int> > m_data_mat;

    typedef struct pt3 {
        float x;
        float y;
        float z;
    } tp_Pt3;


    tp_Pt3 m_pt;
    int dataA[3];
};

//class ImageSourceManager {
//
//};


#endif //VISIONCOMPAREBENCH_IMAGESOURCEMANAGER_H
