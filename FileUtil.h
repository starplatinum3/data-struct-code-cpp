//
// Created by Lenovo on 2021/1/10.
//

#ifndef DATASTRUCT_FILEUTIL_H
#define DATASTRUCT_FILEUTIL_H

#include <string>
using  namespace std;
#include<fstream>

class FileUtil{

  static void write(const string& filename,const string& data);
};
#endif //DATASTRUCT_FILEUTIL_H
