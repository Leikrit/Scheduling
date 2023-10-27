#ifndef DETECTAREA_H
#define DETECTAREA_H

#include <QWidget>
#include<QPaintEvent>

class DetectArea : public QWidget
{
    Q_OBJECT
public:
    explicit DetectArea(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);

signals:

};

#endif // DETECTAREA_H
