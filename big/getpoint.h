#ifndef GETPOINT_H
#define GETPOINT_H

#include <QString>
#include <QObject>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QPointF>
#include <QPainter>
#include <QWidget>
#include <QCursor>

class Getpoint: public QWidget
{
    Q_OBJECT

public:
    Getpoint(QWidget *parent = 0);
    void calculateline();
    void deletepoint();

signals:

    void setPointnum(int);
    void doubleclickmouse();



public slots:
    void loading();
    void displaypointnum();
    void getcursorpos();
    void biggergraph();
    void smallergraph();
    void cleanall();



private:

    double pointdistance[1000][1000];
    double pointxy[1000][2];
    int pointnum;
    int pointline[1000][2];
    int sizecoeff;
    static double sizecoefflist[16];
    bool ifpointloaded;
    bool iflinecaluculated;
    bool ifmousepressed;
    bool ifchangesize;
    bool ifdoubleclick;
    QPoint presspoint;
    QPoint releasepoint;
    QPoint movepoint;
    QPoint changepoint;
    QPoint nowpoint;

protected:
    void paintEvent(QPaintEvent *event);
    void mouseDoubleClickEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);


};

#endif // GETPOINT_H

