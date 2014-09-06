#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    connect(ui->action_Load,SIGNAL(triggered()),ui->getpoint,SLOT(loading()));
    connect(ui->getpoint,SIGNAL(setPointnum(int)),ui->pointNumber,SLOT(display(int)));
    connect(ui->getpoint,SIGNAL(doubleclickmouse()),ui->getpoint,SLOT(getcursorpos()));
    connect(ui->action_bigger,SIGNAL(triggered()),ui->getpoint,SLOT(biggergraph()));
    connect(ui->action_smaller,SIGNAL(triggered()),ui->getpoint,SLOT(smallergraph()));
    connect(ui->cleanallbutton,SIGNAL(clicked()),ui->getpoint,SLOT(cleanall()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
