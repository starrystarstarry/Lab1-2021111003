// Copyright 2024.6.11
#ifndef SRC_READFILE_H_
#define SRC_READFILE_H_
#include <map>
#include <string>
using namespace std;

string readFileFromTxt(string filename, map<string, int> &map1, map<int, string> &map2);
void preHandleStr(string &str);
void showMap1(const map<string, int> &_map);
void showMap2(const map<int, string> &_map);

#endif