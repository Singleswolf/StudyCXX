#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "student_info.h"
#include "grade.h"
#include <cctype>
#include <Vec.h>
#include <Str.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void printEnterName() {
    cout << "Please enter your name: ";
    string name;
    cin >> name;
    string greeting = "Hello, " + name + "!";

    // 空白间隔
    const int pad = 1;
    // 行数
    const int rows = pad * 2 + 3;
    // 列数
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    for (int r = 0; r != rows; r++) {
        string::size_type c = 0;
        while (c != cols) {
            if (r == pad + 1 && c == pad + 1) {
                cout << greeting;
                c += greeting.size();
            } else {
                if (c == 0 || r == 0 || c == cols - 1 || r == rows - 1) {
                    cout << "*";
                } else {
                    cout << " ";
                }
                c++;
            }
        }
        cout << endl;
    }
}

using std::setprecision;
using std::streamsize;

void printPrecisionNum() {
    double num = 12.5647896;
    streamsize prec = cout.precision(); // 返回原来的精度值
    cout << "精度为3 num = " << setprecision(3) /* 设置精度为3 */ << num << setprecision(prec) /* 恢复原来的精度 */ << endl;
    cout << "初始精度 num = " << num << endl;

    // 把进度设为4，并返回原来的进度
    streamsize prec2 = cout.precision(4);
    cout << "精度为4 num = " << num << endl;
    cout.precision(prec2); // 把精度设置初始值
    cout << "初始精度 num = " << num << endl;
}

using std::vector;
typedef vector<double>::size_type vec_sz;

void testVec();

void calcMedian() {
    cout << "Please enter double num list:";

    vector<double> vec;
    double x;
    while (cin >> x) {
        vec.push_back(x);
    }
    vec_sz size = vec.size();
    if (size == 0) {
        cout << "you must enter double num";
        return;
    }

    std::sort(vec.begin(), vec.end());

    vec_sz mid = size / 2;

    double median = mid % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];

    cout << "median = " << median << endl;
}

void inputAndPrintStudentInfo() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while (read(cin, record)) {
        maxlen = std::max(maxlen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    vector<Student_info> fails = extra_fails(students);

    cout << "print sgrade students" << endl;
    for (vector<Student_info>::size_type i = 0; i < students.size(); i++) {
        cout << std::setw(maxlen + 1) << students[i].name << ": ";

        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        }
        catch (const std::exception &e) {
            cout << e.what();
        }

        cout << endl;
    }

    cout << "print fgrade students" << endl;
    for (vector<Student_info>::size_type i = 0; i < fails.size(); i++) {
        cout << std::setw(maxlen + 1) << fails[i].name << ": ";

        try {
            double final_grade = grade(fails[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        }
        catch (const std::exception &e) {
            cout << e.what();
        }

        cout << endl;
    }
}

// 字符串单词分割
vector<string> split(const string &s) {
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != s.size()) {
        while (i != s.size() && isspace(s[i]))
            ++i;

        string_size j = i;
        while (j != s.size() && !isspace(s[j]))
            ++j;

        if (i != j) {
            ret.push_back(s.substr(i, j));
            i = j;
        }
    }
    return ret;
}

void testVec() {
    Vec<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    cout << "size=" << vec.size() << endl;
    vec.print_vec(cout);
    vec.erase(vec.begin());
    cout << "size=" << vec.size() << endl;
    vec.print_vec(cout);
}
void testStr() {
    Str str;
    Str str1;
    cin >> str >> str1;
    cout << str << endl;
    cout << str1 << endl;
    Str s = str + str1;
    cout << s << endl;
}

int main(int, char **) {
    // 打印输入字符串
    //  printEnterName();

    // 数字打印精度控制
    //  printPrecisionNum();

    // 排序计算中值
    //  calcMedian();

    // 输入学生成绩和打印最终成绩结果
    // inputAndPrintStudentInfo();

    // Vec test
    // testVec();

//    Str test
//    testStr();
    return 0;
}
