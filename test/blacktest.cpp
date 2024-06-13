#include "../googletest-main/googletest/include/gtest/gtest.h"
#include "../src/graph.h"
#include "../src/readFile.h"

TEST(BLACK, PATH_1) {
    map<string, int> map1;
    map<int, string> map2;
    string str = readFileFromTxt("C://Users//Lenovo//Desktop//lab1-2021111045//src//text.txt", map1, map2);
    Graph graph = Graph(str, map1, map2);
    graph.initGraph();
    graph.storeGraph();
    string word1 = "你好";
    string word2 = "Hello";
    string str1 = graph.calcShortestPath(word1, word2);
    string str2 = "There is no word named \xC4\xE3\xBA\xC3 or Hello";
    EXPECT_EQ(str1, str2);
}

TEST(BLACK, PATH_2) {
    map<string, int> map1;
    map<int, string> map2;
    string str = readFileFromTxt("C://Users//Lenovo//Desktop//lab1-2021111045//src//text.txt", map1, map2);
    Graph graph = Graph(str, map1, map2);
    graph.initGraph();
    graph.storeGraph();
    string word1 = "你好";
    string word2 = "好的";
    string str1 = graph.calcShortestPath(word1, word2);
    string str2 = "There is no word named \xC4\xE3\xBA\xC3 or \xBA\xC3\xB5\xC4";
    EXPECT_EQ(str1, str2);
}

TEST(BLACK, PATH_3) {
    map<string, int> map1;
    map<int, string> map2;
    string str = readFileFromTxt("C://Users//Lenovo//Desktop//lab1-2021111045//src//text.txt", map1, map2);
    Graph graph = Graph(str, map1, map2);
    graph.initGraph();
    graph.storeGraph();
    string word1 = "hello";
    string word2 = "boy";
    string str1 = graph.calcShortestPath(word1, word2);
    string str2 = "There is no word named hello or boy";
    EXPECT_EQ(str1, str2);
}

TEST(BLACK, PATH_4) {
    map<string, int> map1;
    map<int, string> map2;
    string str = readFileFromTxt("C://Users//Lenovo//Desktop//lab1-2021111045//src//text.txt", map1, map2);
    Graph graph = Graph(str, map1, map2);
    graph.initGraph();
    graph.storeGraph();
    string word1 = "hello";
    string word2 = "roc";
    string str1 = graph.calcShortestPath(word1, word2);
    string str2 = "There is no word named hello or roc";
    EXPECT_EQ(str1, str2);
}

TEST(BLACK, PATH_5) {
    map<string, int> map1;
    map<int, string> map2;
    string str = readFileFromTxt("C://Users//Lenovo//Desktop//lab1-2021111045//src//text.txt", map1, map2);
    Graph graph = Graph(str, map1, map2);
    graph.initGraph();
    graph.storeGraph();
    string word1 = "roc";
    string word2 = "hello";
    string str1 = graph.calcShortestPath(word1, word2);
    string str2 = "There is no word named roc or hello";
    EXPECT_EQ(str1, str2);
}

TEST(BLACK, PATH_6) {
    map<string, int> map1;
    map<int, string> map2;
    string str = readFileFromTxt("C://Users//Lenovo//Desktop//lab1-2021111045//src//text.txt", map1, map2);
    Graph graph = Graph(str, map1, map2);
    graph.initGraph();
    graph.storeGraph();
    string word1 = "roc";
    string word2 = "a";
    string str1 = graph.calcShortestPath(word1, word2);
    string str2 = "The shortest path from roc to a:roc->rises->with->the->wind->in->a";
    EXPECT_EQ(str1, str2);
}

TEST(BLACK, PATH_7) {
    map<string, int> map1;
    map<int, string> map2;
    string str = readFileFromTxt("C://Users//Lenovo//Desktop//lab1-2021111045//src//text.txt", map1, map2);
    Graph graph = Graph(str, map1, map2);
    graph.initGraph();
    graph.storeGraph();
    string word1 = "up";
    string word2 = "a";
    string str1 = graph.calcShortestPath(word1, word2);
    string str2 = "Do not have a path from up to a";
    EXPECT_EQ(str1, str2);
}

TEST(WHITE, bridgeWords_1) {
    map<string, int> map1;
    map<int, string> map2;
    string str = readFileFromTxt("C://Users//Lenovo//Desktop//lab1-2021111045//src//text.txt", map1, map2);
    Graph graph = Graph(str, map1, map2);
    showMap2(map2);
    graph.initGraph();
    graph.storeGraph();
    string result = graph.queryBridgeWords("experience", "idea");
    string str2 = "No 'experience' and 'idea' in the graph!";
    EXPECT_EQ(result, str2);
}

TEST(WHITE, bridgeWords_2) {
    map<string, int> map1;
    map<int, string> map2;
    string str = readFileFromTxt("C://Users//Lenovo//Desktop//lab1-2021111045//src//text.txt", map1, map2);
    Graph graph = Graph(str, map1, map2);
    showMap2(map2);
    graph.initGraph();
    graph.storeGraph();
    string result = graph.queryBridgeWords("experience", "wants");
    string str2 = "No 'experience' in the graph!";
    EXPECT_EQ(result, str2);
}

TEST(WHITE, bridgeWords_3) {
    map<string, int> map1;
    map<int, string> map2;
    string str = readFileFromTxt("C://Users//Lenovo//Desktop//lab1-2021111045//src//text.txt", map1, map2);
    Graph graph = Graph(str, map1, map2);
    showMap2(map2);
    graph.initGraph();
    graph.storeGraph();
    string result = graph.queryBridgeWords("always", "idea");
    string str2 = "No 'idea' in the graph!";
    EXPECT_EQ(result, str2);
}

TEST(WHITE, bridgeWords_4) {
    map<string, int> map1;
    map<int, string> map2;
    string str = readFileFromTxt("C://Users//Lenovo//Desktop//lab1-2021111045//src//text.txt", map1, map2);
    Graph graph = Graph(str, map1, map2);
    showMap2(map2);
    graph.initGraph();
    graph.storeGraph();
    string result = graph.queryBridgeWords("wants", "always");
    string str2 = "it ";
    EXPECT_EQ(result, str2);
}

TEST(WHITE, bridgeWords_5) {
    map<string, int> map1;
    map<int, string> map2;
    string str = readFileFromTxt("C://Users//Lenovo//Desktop//lab1-2021111045//src//text.txt", map1, map2);
    Graph graph = Graph(str, map1, map2);
    showMap2(map2);
    graph.initGraph();
    graph.storeGraph();
    string result = graph.queryBridgeWords("like", "backward");
    string str2 = "traveling hell ";
    EXPECT_EQ(result, str2);
}

TEST(WHITE, bridgeWords_6) {
    map<string, int> map1;
    map<int, string> map2;
    string str = readFileFromTxt("C://Users//Lenovo//Desktop//lab1-2021111045//src//text.txt", map1, map2);
    Graph graph = Graph(str, map1, map2);
    showMap2(map2);
    graph.initGraph();
    graph.storeGraph();
    string result = graph.queryBridgeWords("like", "a");
    string str2 = " ";
    EXPECT_EQ(result, str2);
}

TEST(WHITE, bridgeWords_7) {
    map<string, int> map1;
    map<int, string> map2;
    string str = readFileFromTxt("C://Users//Lenovo//Desktop//lab1-2021111045//src//text.txt", map1, map2);
    Graph graph = Graph(str, map1, map2);
    showMap2(map2);
    graph.initGraph();
    graph.storeGraph();
    string result = graph.queryBridgeWords("up", "a");
    string str2 = " ";
    EXPECT_EQ(result, str2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
