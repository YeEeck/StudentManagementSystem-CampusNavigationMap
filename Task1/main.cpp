//This code run in C++11 standard
//Code by YeEeck

#include <iostream>
#include <set>
#include <windows.h>

using namespace std;

typedef struct Student {
    string num;//学号
    string name;//姓名
    int age;//年龄
    double score;//成绩
    Student *next;
} Student;

class StudentsList {
private:
    Student *head;
    int length;

public:
    StudentsList();

    int listSize();

    void insertStudent();

    void delStudent();

    void findStudent();

    void display();

    void sortPrint();

    void countE();
};

StudentsList::StudentsList() {
    head = new Student;
    head->next = NULL;
    length = 0;
}

int StudentsList::listSize() {
    return length;
}

void StudentsList::insertStudent() {
    Student *r = head->next;
    string num, name;
    int age, score;
    cout << "请输入学生学号:";
    cin >> num;
    cout << "\n请输入学生姓名:";
    cin >> name;
    cout << "\n请输入学生年龄:";
    cin >> age;
    cout << "\n请输入学生成绩:";
    do {
        cin >> score;
        if (score < 0) {
            cout << "学生成绩不能为负数，请重新输入:";
        }
    } while (score < 0);
    while (r) {
        if (r->num == num) {
            cout << "错误:学号已存在" << endl;
            return;
        }
        r = r->next;
    }
    Student *nStu = new Student;
    nStu->num = num;
    nStu->name = name;
    nStu->age = age;
    nStu->score = score;
    nStu->next = NULL;
    r = nStu;
    length++;
}

void StudentsList::delStudent() {
    cout << "请输入要删除的学生学号:";
    string num;
    cin >> num;
    Student *r = head->next;
    Student *p = head;
    while (r) {
        if (r->num == num) {
            p->next = r->next;
            delete (r);
            return;
        }
        r = r->next;
        p = p->next;
    }
}

void StudentsList::findStudent() {
    cout << "请输入要查找的学生学号:";
    string num;
    cin >> num;
    Student *r = head->next;
    while (r) {
        if (r->num == num) {
            cout << "学生学号:" << r->num << endl;
            cout << "学生姓名:" << r->name << endl;
            cout << "学生年龄:" << r->age << endl;
            cout << "学生成绩:" << r->score << endl;
            return;
        }
    }
    cout << "未找到该学生" << endl;
}

void StudentsList::display() {
    Student *r = head->next;
    while (r) {
        cout << "学生学号:" << r->num << endl;
        cout << "学生姓名:" << r->name << endl;
        cout << "学生年龄:" << r->age << endl;
        cout << "学生成绩:" << r->score << endl << endl;
    }
    cout << "--------打印完毕--------" << endl;
}

void StudentsList::sortPrint() {
    set<string> set1;
    cout << "是否对学生信息按学生成绩排列并输出(Y/N):";
    char t;
    cin >> t;
    t = toupper(t);
    if (t == 'Y') {
        for (int i = 0; i < length; ++i) {
            Student *r = head->next;
            string maxNum, maxName;
            int maxAge = 0, flag = 0;
            double maxScore = -1;
            while (r) {
                if (set1.count(r->num)) {
                    continue;
                }
                if (r->score > maxScore) {
                    maxNum = r->num;
                    maxName = r->name;
                    maxAge = r->age;
                    maxScore = r->score;
                    flag = 1;
                    break;
                }
                r = r->next;
            }
            if (!flag) {
                cout << "学生列表为空" << endl;
                return;
            }
            cout << "学生学号:" << maxNum << endl;
            cout << "学生姓名:" << maxName << endl;
            cout << "学生年龄:" << maxAge << endl;
            cout << "学生成绩:" << maxScore << endl << endl;
            set1.insert(r->num);
        }
    }
}

void StudentsList::countE() {
    Student *r = head->next;
    int num = 0;
    while (r) {
        if (r->score < 60) {
            num++;
        }
    }
    cout << "不及格的有" << num << "人" << endl;
}



void printPanel() {
    cout << "----------学生信息管理系统----------" << endl;
    cout << "| 1.添加学生                       |" << endl;
    cout << "| 2.删除学生                       |" << endl;
    cout << "| 3.显示所有学生                   |" << endl;
    cout << "| 4.查找学生信息                   |" << endl;
    cout << "| 5.获取学生个数                   |" << endl;
    cout << "| 6.将学生成绩从大到小输出并排序   |" << endl;
    cout << "| 7.获取不及格人数                 |" << endl;
    cout << "| 8.退出系统                       |" << endl;
    cout << "------------------------------------" << endl;
}

int main() {
    StudentsList sList;
    int first = 0;
    while (true) {
        if (first){
            system("pause");
            system("cls");
        }
        first = 1;
        printPanel();
        int num;
        cout << endl << "请输入要执行的选项序号:";
        cin >> num;
        switch (num) {
            case 1: {
                sList.insertStudent();
                cout << "插入完毕" << endl;
                continue;
            }
            case 2: {
                sList.delStudent();
                cout << "删除完毕" << endl;
                continue;
            }
            case 3: {
                sList.display();
                continue;
            }
            case 4: {
                sList.findStudent();
                continue;
            }
            case 5: {
                cout << "系统内存在 " << sList.listSize() << " 个学生";
                continue;
            }
            case 6: {
                sList.sortPrint();
                continue;
            }
            case 7: {
                sList.countE();
            }
            case 8: {
                goto exit;
            }
            default: {
                cout << "无法识别的选项序号，请重新输入" << endl;
                continue;
            }
        }
    }
    exit:;
    return 0;
}