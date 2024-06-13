// Copyright 2024.6.11
#ifndef SRC_READFILE_H_
#define SRC_READFILE_H_
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using std::cout;
using std::map;
using std::map;
using std::string;
using std::vector;
using std::endl;
using std::ifstream;
using std::cin;
using std::ofstream;
string readFileFromTxt(string filename, map<string, int> &map1, map<int, string> &map2);
void preHandleStr(string &str);
void showMap1(const map<string, int> &_map);
void showMap2(const map<int, string> &_map);

#endif // SRC_READFILE_H_
