//
// Created by Lenovo on 2021/1/10.
//

#include "FileUtil.h"
//#include <>
#include <iostream>
void FileUtil::write(const string& filename, const string& data) {
    std::ofstream fout(filename);
    fout << data;
//    std::cout<<data<<"\n";
    fout << std::flush;
    fout.close();
}

