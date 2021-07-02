//
// Created by alex on 2021/7/1.
//

#ifndef VISIONCOMPAREBENCH_ToolNameLst_H
#define VISIONCOMPAREBENCH_ToolNameLst_H

#include <iostream>
#include <string>
#include <vector>

class ToolNameLst {
public:
    static  ToolNameLst* getinstance()
    {
        if(!instance)
        {
            instance = new ToolNameLst();
        }
        else return  instance;
    }
    static  std::vector<std::string> getNames ()
    {
        return  instance->names ;
    }
    static   int gettoolNum()
    {
        return  instance->names.size();
    }
private:
   static  ToolNameLst* instance;
    ToolNameLst()
    {
          std::vector<std::string>  nt{
                  "ToolSource",
                  "ToolSaveFile",
                  "ToolBlur"
//                  ,"BlurBox"
//                  , "threshold", "canny", "dilate"
          };
//        nt.push_back(  "aaa"  ) ;
        names = nt;
    }
public:
    std::vector<std::string>   names;
};


#endif //VISIONCOMPAREBENCH_ToolNameLst_H
