#ifndef TASK_H
#define TASK_H

#endif // TASK_H
#include<QDataStream>
#include<QString>
#include<string>
#include <QSize>
using namespace std;

class Task
{
public:
    //task的名字
    QString name;

    //task的颜色
    QString flag;

    //判断是否完成
    bool isfinished;

    //默认构造器
    Task(){}

    //构造器
    Task(QString name,QString flag, bool isfinished)
    {
        this->name = name;
        this->flag = flag;
        this->isfinished = isfinished;
    }

    //重载QDataStream流输出运算符
    friend QDataStream &operator<<(QDataStream &stream, const Task &item);

    //重载QDataStream流输入运算符
    friend QDataStream &operator>>(QDataStream &stream, Task &item);

};
