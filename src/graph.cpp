// Copyright 2024.6.11
#include "graph.h"

#include <limits.h>

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

#include "readFile.h"
using std::cout;
using std::endl;
// 构造函数
Graph::Graph(string str, map<string, int> const _map1, map<int, string> const _map2) {
    len = 0;
    map1 = _map1;
    map2 = _map2;
    stringstream STR(str);
    string word;
    while (STR >> word) {
        this->str[len++] = map1[word];
    }
    this->size = map1.size();
    initGraph();
}

void Graph::showStr() {
    for (int i = 0; i < len; i++) {
        cout << this->str[i] << " ";
    }
    cout << endl;
}
void Graph::showGraph() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            cout << this->graph[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::storeGraph() {
    ofstream file("./graph.txt");  // 替换为你的文件名

    if (!file.is_open()) {
        cerr << "Unable to open file!" << endl;
        return;  // 文件打开失败
    }

    // 写入节点个数
    file << size << endl;
    // 写入图
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file << graph[i][j] << " ";
        }
        file << endl;
    }
    // 写入map2
    for (int i = 0; i < size; i++) {
        file << i << " " << map2[i] << endl;
    }
    // 关闭文件
    file.close();

    return;
}

void Graph::initGraph() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->graph[i][j] = 0;
        }
    }
    for (int i = 0; i < this->len - 1; i++) {
        int index1 = this->str[i];
        int index2 = this->str[i + 1];
        this->graph[index1][index2] += 1;
    }
}

Graph::~Graph() {}

string Graph::queryBridgeWords(string word1, string word2) {
    int flag1 = 1;
    int flag2 = 1;
    if (map1.find(word1) == map1.end()) {
        flag1 = 0;
    }
    if (map1.find(word2) == map1.end()) {
        flag2 = 0;
    }
    string s = "";
    if (flag1 == 0 && flag2 == 0) {
        s = s + "No" + " '" + word1 + "' and '" + word2 + "' in the graph!";
    } else if (flag1 == 0) {
        s = s + "No" + " '" + word1 + "' in the graph!";
    } else if (flag2 == 0) {
        s = s + "No" + " '" + word2 + "' in the graph!";
    } else {
        // 存在word1与word2，查询图
        s = findMiddleWord(map1[word1], map1[word2], 1);
    }
    return s;
}
string Graph::findMiddleWord(int firstword, int secondword, int choice) {
    string resultStr = "";
    int flag = 0;
    for (int middleword = 0; middleword < size; middleword++) {
        if (graph[firstword][middleword] != 0) {
            if (graph[middleword][secondword] != 0) {
                flag = 1;
                resultStr = resultStr + map2[middleword] + ",";
            }
        }
    }
    switch (choice) {
        case 0: {
            if (flag == 0) {
                resultStr = resultStr + "No bridge words from " + "\"" + map2[firstword] + " \"to \"" +
                            map2[secondword] + "\"!";
            } else {
                resultStr[resultStr.size() - 1] = '.';
                string s = "";
                resultStr = s + "The bridge words from " + "\"" + map2[firstword] + " \"to \"" +
                            map2[secondword] + "\" are:" + resultStr;
            }
            break;
        }
        // 返回中间词或者空
        case 1: {
            if (flag == 0) {
                resultStr = " ";
            } else {
                int count = 0;
                for (size_t i = 0; i < resultStr.size(); i++) {
                    if (resultStr[i] == ',') {
                        resultStr[i] = ' ';
                        count++;
                    }
                }
                // 选择一个桥接词
                resultStr = chooseOne(resultStr, count);
            }
            break;
        }
    }
    return resultStr;
}
string Graph::chooseOne(string str, int len) {
    srand(static_cast<unsigned int>(time(nullptr)));
    int random_number = (rand()) % len;
    // 选择合适的一个桥接词
    stringstream STR(str);
    string word;
    for (int i = 0; i <= random_number; i++) {
        STR >> word;
    }
    return word;
}

string Graph::generateNewText(string inputText) {
    // 已经获得用户输入文本，对文本做处理
    preHandleStr(inputText);
    stringstream inputStream(inputText);
    string currentWord;
    string nextWord;
    string resultStr = "";
    int step = 0;
    // 读取第一个存在 currentWord
    while (inputStream >> currentWord) {
        resultStr += currentWord + ' ';
        if (map1.find(currentWord) != map1.end()) {
            break;
        }
    }
    string tempStr;
    while (inputStream >> nextWord) {
        if (map1.find(nextWord) == map1.end()) {
            resultStr += nextWord + ' ';
            step = 1;
            continue;
        }
        if (step != 0) {
            resultStr += nextWord + ' ';
            step = 0;
            currentWord = nextWord;
            continue;
        }
        tempStr = findMiddleWord(map1[currentWord], map1[nextWord], 1);
        resultStr = tempStr == " " ? resultStr + nextWord + ' ' : resultStr + tempStr + ' ' + nextWord + ' ';
        currentWord = nextWord;
    }
    return resultStr;
}

// 最短路径计算
void Graph::calcShortestPath(string startWord, string endWord) {
    string resultStr = "";
    vector<vector<int>> allPaths;
    vector<int> path;
    if (map1.find(startWord) == map1.end() || (map1.find(endWord) == map1.end() && !endWord.empty())) {
        if (!endWord.empty()) {
            resultStr += "There is no word named " + startWord + " or " + endWord;
            cout << resultStr << endl;
        } else {
            resultStr += "There is no word named " + startWord;
            cout << resultStr << endl;
        }
    } else if (endWord.empty()) {  // 只输入了一个单词
        for (int j = 0; j < size; j++) {
            if (j != map1[startWord]) {
                cout << "The shortest path from " << startWord << " to " << map2[j] << " : ";
                path.clear();
                allPaths.clear();
                dijkstra(map1[startWord], j, allPaths, path);
                if (allPaths.empty()) {
                    resultStr = "Do not have a path from " + startWord + " to " + map2[j];
                    cout << resultStr << endl;
                } else {
                    for (const auto& p : allPaths) {
                        for (size_t i = 0; i < p.size(); ++i) {
                            cout << map2[p[i]];
                            if (j != p[i]) {
                                cout << " -> ";
                            }
                        }
                        cout << endl;
                    }
                }
            }
        }
    } else {  // 输入了两个单词
        dijkstra(map1[startWord], map1[endWord], allPaths, path);
        cout << "The shortest path from " << startWord << " to " << endWord << " : ";
        if (allPaths.empty()) {
            resultStr = "Do not have a path from " + startWord + " to " + endWord;
            cout << resultStr << endl;
        } else {
            for (const auto& p : allPaths) {
                for (size_t i = 0; i < p.size(); ++i) {
                    cout << map2[p[i]];
                    if (map1[endWord] != p[i]) {
                        cout << " -> ";
                    }
                }
                cout << endl;
            }
        }
    }
}

int Graph::minDistance(const int dist[], const int sptSet[]) {
    // 初始化最小距离为无穷大
    int min = INT_MAX, min_index = 0;

    for (int v = 0; v < size; v++)
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    return min_index;
}

void Graph::dijkstra(int src, int dest, vector<vector<int>>& allpaths, vector<int>& path) {
    vector<int> dist(size, INT_MAX);  // dist[i] 将保存从源点到顶点 i 的最短路径长度
    vector<int> sptSet(size, 0);  // sptSet[i] 为真，如果顶点 i 包含在最短路径树中或最短路径已被确定
    vector<vector<int>> preNodes(size);

    for (int i = 0; i < size; ++i) {
        if (graph[src][i] != 0) {
            dist[i] = graph[src][i];
            preNodes[i].push_back(src);
        }
    }
    dist[src] = 0;
    sptSet[src] = 1;

    for (int count = 0; count < size - 1; ++count) {
        int u = minDistance(dist.data(), sptSet.data());
        sptSet[u] = 1;

        for (int v = 0; v < size; ++v) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                preNodes[v].clear();
                preNodes[v].push_back(u);
            } else if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] == dist[v]) {
                preNodes[v].push_back(u);
            }
        }
    }
    // 根据每个节点的前驱节点得到从 src 到 dest 的最短路径
    findPaths(src, dest, preNodes, path, allpaths);
}

void Graph::findPaths(int src, int dest, vector<vector<int>>& preNodes, vector<int>& path,
                      vector<vector<int>>& allpaths) {
    path.push_back(dest);
    if (dest == src) {
        vector<int> temp = path;
        reverse(temp.begin(), temp.end());
        allpaths.push_back(temp);
    } else {
        for (int i = 0; i < preNodes[dest].size(); i++) {
            findPaths(src, preNodes[dest][i], preNodes, path, allpaths);
        }
    }
    path.pop_back();
}

// 随机游走
string Graph::randomWalk() {
    vector<int> traversalPath;
    // 随机选择一个节点遍历，如果对应边已经走过，则把i,j设置为true
    srand(static_cast<unsigned int>(time(nullptr)));
    int randomNode = rand() % size;
    cout << "randomNode: " << randomNode << endl;
    scan(traversalPath, randomNode);
    int pathSize = traversalPath.size();
    string resultStr = "";
    for (int i = 0; i < pathSize; i++) {
        resultStr += map2[traversalPath[i]] + " ";
    }
    return resultStr;
}

// 随机游走
void Graph::scan(vector<int>& path, int src) {
    // 使用vector 动态分配内存
    vector<vector<bool>> visitedEdges(size, vector<bool>(size, false));
    path.push_back(src);
    while (true) {
        string concatenatedWords = "";
        int edgeCount = 0;
        // 随机游走
        for (int i = 0; i < size; i++) {
            if (graph[src][i] != 0) {
                concatenatedWords += map2[i] + " ";
                edgeCount++;
            }
        }
        if (edgeCount != 0) {
            concatenatedWords = chooseOne(concatenatedWords, edgeCount);
            if (visitedEdges[src][map1[concatenatedWords]]) {
                src = map1[concatenatedWords];
                path.push_back(src);
                break;
            } else {
                visitedEdges[src][map1[concatenatedWords]] = true;
                src = map1[concatenatedWords];
                path.push_back(src);
            }
        } else {
            break;
        }
    }
}
