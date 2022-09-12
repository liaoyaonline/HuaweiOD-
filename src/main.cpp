/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
 */
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> GetQuestionID(int n, int m) {
    int nums = min(n / 2, m);
    map<int, int> easyhash;
    map<int, int> hardhash;
    vector<vector<int>> res(nums + 1, vector<int>(3, 0));
    for (int i = 1; i <= nums; i++) {
      int easynum = 0;
      int hardnum = 0;
      vector<int> tempres;
      while (easynum < 2) {
        int ans = rand() % n + 1;
        if (easyhash[ans] != 1) {
          easynum++;
          easyhash[ans] = 1;
          tempres.push_back(ans);
        }
      }
      while (hardnum < 1) {
        int ans = rand() % m + 1;
        if (hardhash[ans] != 1) {
          hardnum++;
          hardhash[ans] = 1;
          tempres.push_back(ans);
        }
      }
      res[i] = tempres;
    }
    return res;
  }
  vector<string> GetQuestionName(string FileName) {
    ifstream infile;
    infile.open(FileName);
    vector<string> res;
    if (!infile.is_open()) {
      cout << "文件打开失败，请检查文件路径!" << endl;
      return res;
    }
    string Input_Line;
    res.push_back(" ");
    while (!infile.eof()) {
      getline(infile, Input_Line);
      res.push_back(Input_Line);
    }
    return res;
  }
  void OutPutMdFile(string FileName, vector<vector<int>> QuestionID,
                    int daynums, vector<string> QuestionName) {
    ofstream outfile;
    outfile.open(FileName);
    if (!outfile.is_open()) {
      cout << "文件不存在，请检查路径是否正确" << endl;
      return;
    }
    time_t now = time(NULL);
    for (int i = 1; i + 2 < daynums; i = i + 2) {
      if (i > 1) now += 86400;
      tm* t = localtime(&now);
      outfile << "**" << t->tm_mon + 1 << "月" << t->tm_mday << "日刷题**"
              << endl;
      outfile << "上午 9:30-12:00" << endl;
      outfile << "简单" << endl;
      outfile << "- [ ] " << QuestionID[i][0] << "."
              << QuestionName[QuestionID[i][0] + 61] << endl;
      outfile << "- [ ] " << QuestionID[i][1] << "."
              << QuestionName[QuestionID[i][1] + 61] << endl
              << endl;
      outfile << "中等" << endl;
      outfile << "- [ ] " << QuestionID[i][2] << "."
              << QuestionName[QuestionID[i][2]] << endl;
      outfile << endl;
      outfile << "晚上 21:30-00:00" << endl;
      outfile << "简单" << endl;
      outfile << "- [ ] " << QuestionID[i + 1][0] << "."
              << QuestionName[QuestionID[i + 1][0] + 61] << endl;
      outfile << "- [ ] " << QuestionID[i + 1][1] << "."
              << QuestionName[QuestionID[i + 1][1] + 61] << endl
              << endl;
      outfile << "中等" << endl;
      outfile << "- [ ] " << QuestionID[i + 1][2] << "."
              << QuestionName[QuestionID[i + 1][2]] << endl;
      outfile << endl;
    }
    outfile.close();
  }
};
int main() {
  char str[50];
  time_t now = time(NULL);
  Solution a;
  vector<vector<int>> res = a.GetQuestionID(108, 61);
  vector<string> questionname = a.GetQuestionName("../data/questionname.txt");
  a.OutPutMdFile("../data/od刷题日程表.md", res, res.size(), questionname);
  return 0;
}
