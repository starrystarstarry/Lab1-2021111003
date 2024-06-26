// Copyright 2024.6.11
#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
using std::cout;
using std::map;
using std::map;
using std::string;
using std::vector;
using std::endl;
using std::stringstream;
using std::ofstream;
using std::cerr;
#define SIZE 100
#define LEN 100
class Graph {
    private:
    int graph[SIZE][SIZE];
    int size;  // graph真实大小
    int str[LEN];
    int len;  // 字符串长度
    map<string, int> map1;
    map<int, string> map2;
    string findMiddleWord(int firstword, int secondword, int choice);
    string chooseOne(string str, int len);
    void dijkstra(int src, int dest, vector<vector<int>>& allPaths, vector<int>& path);
    void findPaths(int src, int dest, vector<vector<int>>& preNodes, vector<int>& path,
                   vector<vector<int>>& allpaths);
    int minDistance(const int dist[], const int sptSet[]);
    void scan(vector<int>& path, int src);

    public:
    // 构造函数
    Graph(string str, map<string, int> _map1, map<int, string> _map2);
    // 析构函数
    ~Graph();
    // 其他函数
    void storeGraph();
    void showStr();
    void showGraph();
    void initGraph();
    string queryBridgeWords(string word1, string word2);
    string generateNewText(string inputText);
    string calcShortestPath(string word1, string word2);
    string randomWalk();
};
#endif // SRC_GRAPH_H_
