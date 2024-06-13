// Copyright 2024.6.11
#include "readFile.h"
void preHandleStr(string &str) {
    int len = str.size();
    for (int i = 0; i < len; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z') && str[i] != ' ') {
            str[i] = '.';
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 'a' - 'A';
        }
    }
    char target = '.';
    str.erase(remove(str.begin(), str.end(), target), str.end());
}

string readFileFromTxt(string filename, map<string, int> &map1, map<int, string> &map2) {
    ifstream INFILE;

    INFILE.open(filename);
    if (!INFILE.is_open()) {
        cout << "can not open the file" << endl;
        exit(EXIT_FAILURE);
    }
    string temp_str;
    string str;
    int i = 0;
    while ((INFILE >> temp_str)) {
        preHandleStr(temp_str);
        if (temp_str != "") {
            if (map1.find(temp_str) == map1.end()) {
                map1[temp_str] = i;
                map2[i] = temp_str;
                i++;
            }
            str = str + " " + temp_str;
        }
    }
    cout << str << endl;
    return str;
}

void showMap1(const map<string, int> &_map) {
    map<string, int>::const_iterator end = _map.end();
    for (map<string, int>::const_iterator it = _map.begin(); it != end; ++it) {
        cout << it->first << ":" << it->second << endl;
    }
}
void showMap2(const map<int, string> &_map) {
    map<int, string>::const_iterator end = _map.end();
    for (map<int, string>::const_iterator it = _map.begin(); it != end; ++it) {
        cout << it->first << ":" << it->second << endl;
    }
}
