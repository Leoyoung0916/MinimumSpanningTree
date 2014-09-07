
#include "getpoint.h"
#include <QMessageBox>
#include <QtWidgets>
#include <cmath>
#include <QDebug>
#include <memory>


Getpoint::Getpoint( QWidget *parent):
QWidget(parent)
{

    setWindowTitle(tr("Points"));

    pointnum=0;
    sizecoeff=9;

    ifpointloaded=false;
    iflinecaluculated=false;
    ifmousepressed = false;
    ifchangesize=false;

    for (int i=1;i<1000;i++){
        for(int j=1;j<1000;j++){
            pointdistance[i][j]=0;
        }
    }

    for (int t=1;t<1000;t++){
        pointxy[t][0]=pointxy[t][1]=0;

        pointline[t][0]=pointxy[t][1]=0;
    }

    presspoint.setX(0);
    presspoint.setY(0);
    releasepoint.setX(0);
    releasepoint.setY(0);

    movepoint.setX(0);
    movepoint.setY(0);
    changepoint.setX(0);
    changepoint.setY(0);

}

double Getpoint::sizecoefflist[]={0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,
    1.2,1.35,1.5,1.75,2.0};

void Getpoint::loading()
{

    cleanall();
    //初始化
    pointnum=0;


   QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                   "/home",
                                                   tr("Text (*.txt)"));
   if (fileName.isEmpty())
           return;
   QFile file(fileName);
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
           QMessageBox::warning(this, tr("MDI Editor"),
                                tr("Cannot read file %1:\n%2.")
                                .arg(file.fileName())
                                .arg(file.errorString()));
           return;
       }
   QTextStream in(&file);
   in >> pointnum;
   for(int i=1;i<pointnum+1;++i){
       in>>pointxy[i][0]>>pointxy[i][1];
   }


   ifpointloaded=true;
   iflinecaluculated=false;


}


void Getpoint::calculateline()
{
    if(iflinecaluculated){
        return;
    }

        int Infi=10000;
        int n=pointnum;

        if(n==1){
            iflinecaluculated = true;
            return;
        }

        int visited[n+1];
        int i,j,fixedpoint,nextpoint;
        int pointNumVisited=0;
        double mindistance=Infi;

        memset(visited,0,sizeof(visited));

        for (i=1;i<n+1;i++){
            for (j=1;j<n+1;j++){
                pointdistance[i][j]= sqrt(pow((pointxy[i][0]-pointxy[j][0]),2.0)+pow((pointxy[i][1]-pointxy[j][1]),2.0));
            }
        }

        visited[1]=1;

    for (pointNumVisited=1;pointNumVisited<=n;pointNumVisited++){

        mindistance=Infi;
        for (i=1;i<=n;i++){      //历遍所有visted的点
            for (j=1;j<=n;j++){  //历遍所有的新点
                if (visited[i]==1&&visited[j]!=1&&pointdistance[i][j]<mindistance){
                        mindistance=pointdistance[i][j];
                        nextpoint=j;  //不断刷新
                        fixedpoint=i;
                }
            }
        }
        visited[nextpoint]=1;
        pointline[pointNumVisited][0]=fixedpoint;
        pointline[pointNumVisited][1]=nextpoint;

    }


    iflinecaluculated = true;

}



void Getpoint::biggergraph()
{
    sizecoeff += 1;
    ifchangesize=true;
    emit update();
}

void Getpoint::smallergraph()
{
    sizecoeff -= 1;
    ifchangesize=true;
    emit update();
}


void Getpoint::cleanall()
{

    pointnum=0;
    sizecoeff=9;

    ifpointloaded=false;
    iflinecaluculated=true;
    ifmousepressed = false;
    ifchangesize=false;

    for (int i=1;i<1000;i++){
        for(int j=1;j<1000;j++){
            pointdistance[i][j]=0;
        }
    }

    for (int t=1;t<1000;t++){
        pointxy[t][0]=pointxy[t][1]=0;

        pointline[t][0]=pointxy[t][1]=0;
    }

    presspoint.setX(0);
    presspoint.setY(0);
    releasepoint.setX(0);
    releasepoint.setY(0);

    movepoint.setX(0);
    movepoint.setY(0);
    changepoint.setX(0);
    changepoint.setY(0);


    emit update();
    emit setPointnum(0);
}



void Getpoint::getcursorpos()
{
    QCursor cursor;
    QPoint globalcursorpoint = cursor.pos();
    QPoint localcursorpoint = mapFromGlobal(globalcursorpoint);

    int x=localcursorpoint.rx();
    int y=localcursorpoint.ry();


    pointxy[pointnum+1][0]=x/sizecoefflist[sizecoeff]-changepoint.rx()/sizecoefflist[sizecoeff];
    pointxy[pointnum+1][1]=y/sizecoefflist[sizecoeff]-changepoint.ry()/sizecoefflist[sizecoeff];
    pointnum += 1;

    iflinecaluculated=false;
    ifpointloaded=true;



    emit repaint();
}


void Getpoint::deletepoint()
{

    QCursor cursor;
    QPoint globalcursorpoint = cursor.pos();
    QPoint localcursorpoint = mapFromGlobal(globalcursorpoint);

    localcursorpoint.setX(localcursorpoint.x()/sizecoefflist[sizecoeff]);
    localcursorpoint.setY(localcursorpoint.y()/sizecoefflist[sizecoeff]);

    localcursorpoint-=(changepoint/sizecoefflist[sizecoeff]);


    for (int i=1;i<=pointnum;i++){

        if((abs(pointxy[i][0]-localcursorpoint.rx())<3)&&(abs(pointxy[i][1]-localcursorpoint.ry())<3)){

            pointxy[i][0]=pointxy[pointnum][0];
            pointxy[i][0]=pointxy[pointnum][0];

            pointxy[pointnum][0]=0;
            pointxy[pointnum][0]=0;

            pointnum-=1;

            iflinecaluculated=false;
        }

    }

    emit update();

}


void Getpoint::paintEvent(QPaintEvent *)
{
    if (!ifpointloaded){
        return;
    }

    calculateline();

    QPainter painter(this);

    QPointF point,p1,p2;

    QPen pointpen(Qt::black, 5,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    QPen linepen(Qt::red,2,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    painter.setRenderHint( QPainter::Antialiasing, true );

    painter.setPen(pointpen);

    QPoint transpoint = changepoint;


    int transx=(transpoint).rx();
    int transy=(transpoint).ry();


    painter.translate(transx,transy);

    painter.scale(sizecoefflist[sizecoeff],sizecoefflist[sizecoeff]);



    for(int i=1;i<pointnum+1;i++)
    {

        point.setX(pointxy[i][0]);
        point.setY(pointxy[i][1]);

        painter.drawPoint(point);

    }

    painter.setPen(linepen);

    for (int t=1;t<=pointnum-1;t++){

        p1.setX(pointxy[(pointline[t][0])][0]);
        p1.setY(pointxy[(pointline[t][0])][1]);
        p2.setX(pointxy[(pointline[t][1])][0]);
        p2.setY(pointxy[(pointline[t][1])][1]);



        painter.drawLine(p1,p2);
    }

    emit setPointnum(pointnum);

}



void Getpoint::mousePressEvent(QMouseEvent *event)
{



    if (event->button() == Qt::LeftButton){

        ifdoubleclick=false;
        ifmousepressed = true;

        QCursor cursor;
        presspoint = cursor.pos();

        emit update();

    }

    if (event->button() == Qt::RightButton){

        deletepoint();

    }


}


void Getpoint::mouseMoveEvent(QMouseEvent *)
{
    if (!ifmousepressed){
        return;
    }

    QCursor cursor;

    nowpoint = cursor.pos()-presspoint;

    changepoint += (nowpoint-movepoint);

    movepoint=nowpoint;


    emit update();


}


void Getpoint::mouseReleaseEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton){

        ifmousepressed = false;

        QCursor cursor;
        releasepoint = cursor.pos();

        presspoint.setX(0);
        presspoint.setY(0);

        movepoint.setX(0);
        movepoint.setY(0);

        emit update();
    }

}



void Getpoint::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        ifdoubleclick=true;
        emit doubleclickmouse();
    }
}



void Getpoint::displaypointnum()
{
    emit setPointnum(pointnum);
}
