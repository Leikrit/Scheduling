#ifndef MEMOWIDGET_H
#define MEMOWIDGET_H

#include <QMainWindow>
#include<QVector>
#include<QLineEdit>
#include<QTextEdit>
#include<QListWidget>
#include<QPushButton>
#include<QListWidgetItem>
#include<QWidget>
#include<QMessageBox>
#include<QDataStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MemoWidget; }
QT_END_NAMESPACE

//[0]创建结构体memo，方便记录备忘录的标题和内容，方便文件读写
struct memo{
    QString name;
    QString content;
    void operator=(memo operand)
    {
        name=operand.name;
        content=operand.content;
    }
};
//[0]

//[1]备忘录窗口类
class MemoWidget : public QWidget
{

    Q_OBJECT

public:
    MemoWidget(QWidget *parent = nullptr);
    ~MemoWidget();

    //从文件读取数据，并在界面中展示
    void showMemoList();

private:
    //创建新窗口，用于添加布局
    QWidget *w;

    //程序中储存备忘录信息
    QVector<memo>memolist;

    Ui::MemoWidget *ui;

    //用于输入笔记标题
    QLineEdit *editName;

    //用于输入笔记内容
    QTextEdit *editContent;

    //用于展示备忘录的窗口
    QListWidget *list;

    //用于判断用户是否选中某条笔记并进入编辑状态
    bool editState=false;

    //记录被选中的笔记在向量中的下标
    int currentItemIndex=0;

    //创建该模块整个窗口的函数
    void createMemoWidget();

    //修改list的视觉效果
    void setUi();

    //点击confirm按钮后触发的槽函数，添加笔记或编辑笔记
    void confirmMemo();

    //双击某条笔记触发的函数，表示进入编辑状态，设置editState和currentItemIndex
    void editMemo();

    //点击delete按钮之后触发的槽函数，删除选中的笔记
    void deleteMemo();

    //将向量memolist写入文件中
    void write();

    //从文件中读取数据到memolist
    void read();

    //重载流插入运算符
    friend QDataStream& operator<<(QDataStream&,memo);

    //重载流提取运算符
    friend QDataStream& operator>>(QDataStream&,memo);
};
//[1]
#endif // MEMOWIDGET_H
