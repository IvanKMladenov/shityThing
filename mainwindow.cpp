#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
//ivz include the drawer here
#include "drawimage.h"

MainWindow::MainWindow() :
    indexBuf(QOpenGLBuffer::IndexBuffer),
    ui(new Ui::MainWindow)
{
    std::cout << "MainWindow c'tor call" << std::endl;
    ui ->setupUi(this);

#if 0 //why is this installing event???
    ui ->lineEdit_1 ->installEventFilter(this);
    ui ->lineEdit_2 ->installEventFilter(this);
    ui ->lineEdit_3 ->installEventFilter(this);
    ui ->lineEdit_4 ->installEventFilter(this);
    ui ->lineEdit_5 ->installEventFilter(this);
    ui ->lineEdit_6 ->installEventFilter(this);
    ui ->lineEdit_7 ->installEventFilter(this);
    ui ->lineEdit_8 ->installEventFilter(this);
#endif
    //ui ->lineEdit_1 ->setText("Enter point e1");
    //ui ->lineEdit_2 ->setText("Enter point e2");
    //ui ->lineEdit_3 ->setText("Enter point e3");
    //ui ->lineEdit_4 ->setText("Enter point e4");
    //ui ->lineEdit_5 ->setText("Enter point e5");
    //ui ->lineEdit_6 ->setText("Enter point e6");
    //ui ->lineEdit_7 ->setText("Enter point e7");
    //ui ->lineEdit_8 ->setText("Enter point e8");

    std::cout << "MainWindow init LineEdits" << std::endl;

    connect( ui ->lineEdit_1, SIGNAL(editingFinished()), this, SLOT(pushMeshVal1()));
    connect( ui ->lineEdit_2, SIGNAL(editingFinished()), this, SLOT(pushMeshVal2()));
    connect( ui ->lineEdit_3, SIGNAL(editingFinished()), this, SLOT(pushMeshVal3()));
    connect( ui ->lineEdit_4, SIGNAL(editingFinished()), this, SLOT(pushMeshVal4()));
    connect( ui ->lineEdit_5, SIGNAL(editingFinished()), this, SLOT(pushMeshVal5()));
    connect( ui ->lineEdit_6, SIGNAL(editingFinished()), this, SLOT(pushMeshVal6()));
    connect( ui ->lineEdit_7, SIGNAL(editingFinished()), this, SLOT(pushMeshVal7()));
    connect( ui ->lineEdit_8, SIGNAL(editingFinished()), this, SLOT(pushMeshVal8()));

    std::cout << "MainWindow connect LineEdits" << std::endl;

    //initGeometry();

    m_pglContext = ui ->openGLWidget; //new DrawImage(this);


    m_pglContext ->setMouseTracking(true);


    connect(ui->draw, SIGNAL(clicked()), this, SLOT(DrawImg()));
}

MainWindow::~MainWindow() {
    arrayBuf.destroy();
    indexBuf.destroy();
    delete ui;
}

float m_mesh[] = {
    -1.0f,-1.0f,-1.0f, // triangle 1 : begin
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f, // triangle 1 : end
    1.0f, 1.0f,-1.0f, // triangle 2 : begin
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f, // triangle 2 : end
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
};

void MainWindow::initGeometry() {
    std::cout << "initGeometry \r\n";
}

void MainWindow::DrawImg() {
    m_pglContext ->SetHexaMesh(m_mesh, 108);
    m_pglContext->CallDraw();
}

void MainWindow::addData (QVector<QStringRef>& data) {
    std::cout << "addData" << std::endl;
    std::cout << data[0].toString().toStdString() << std::endl;
    std::cout << data[1].toString().toStdString() << std::endl;
    std::cout << data[2].toString().toStdString() << std::endl;

    QVector3D smtVec(data[0].toFloat(), data[1].toFloat(), data[2].toFloat());
    smtVec.normalize();
    //m_inputData.push_back(smtVec);
}

void MainWindow::pushMeshVal1() {
    std::cout << "pushMeshVal1" << std::endl;
    if (!ui ->lineEdit_1 ->text().isEmpty()) {
        auto smt = ui ->lineEdit_1 ->text().splitRef(QLatin1Char(','));
        addData(smt);
    }
}

void MainWindow::pushMeshVal2() {
    std::cout << "pushMeshVal2" << std::endl;
    if (!ui ->lineEdit_2 ->text().isEmpty()) {
        auto smt = ui ->lineEdit_2 ->text().splitRef(QLatin1Char(','));
        addData(smt);
    }
}

void MainWindow::pushMeshVal3() {
    std::cout << "pushMeshVal3" << std::endl;
    if (!ui ->lineEdit_3 ->text().isEmpty()) {
        auto smt = ui ->lineEdit_3 ->text().splitRef(QLatin1Char(','));
        addData(smt);
    }
}

void MainWindow::pushMeshVal4() {
    std::cout << "pushMeshVal4" << std::endl;
    if (!ui ->lineEdit_4 ->text().isEmpty()) {
        auto smt = ui ->lineEdit_4 ->text().splitRef(QLatin1Char(','));
        addData(smt);
    }
}

void MainWindow::pushMeshVal5() {
    std::cout << "pushMeshVal5" << std::endl;
    if (!ui ->lineEdit_5 ->text().isEmpty()) {
        auto smt = ui ->lineEdit_5 ->text().splitRef(QLatin1Char(','));
        addData(smt);
    }
}

void MainWindow::pushMeshVal6() {
    std::cout << "pushMeshVal6" << std::endl;
    if (!ui ->lineEdit_6 ->text().isEmpty()) {
        auto smt = ui ->lineEdit_6 ->text().splitRef(QLatin1Char(','));
        addData(smt);
    }
}

void MainWindow::pushMeshVal7() {
    std::cout << "pushMeshVal7" << std::endl;
    if (!ui ->lineEdit_7 ->text().isEmpty()) {
        auto smt = ui ->lineEdit_7 ->text().splitRef(QLatin1Char(','));
        addData(smt);
    }
}

void MainWindow::pushMeshVal8() {
    std::cout << "pushMeshVal8" << std::endl;
    if (!ui ->lineEdit_8 ->text().isEmpty()) {
        auto smt = ui ->lineEdit_8 ->text().splitRef(QLatin1Char(','));
        addData(smt);
    }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
    if (watched == ui ->lineEdit_1) {
        if (event ->type() == QEvent::FocusIn) {
            ui ->lineEdit_1 ->setText("");
        //} else if (event ->type() == QEvent::FocusOut) {
        //    QString smt = ui ->lineEdit_1 ->text();
        //    ui ->lineEdit_1 ->setText("kurac22");
        }
    }
    if (watched == ui ->lineEdit_2) {
        if (event ->type() == QEvent::FocusIn) {
            ui ->lineEdit_2 ->setText("");
        //} else if (event ->type() == QEvent::FocusOut) {
        //    ui ->lineEdit_2 ->setText("kurac22");
        }
    }
    if (watched == ui ->lineEdit_3) {
        if (event ->type() == QEvent::FocusIn) {
             ui ->lineEdit_3 ->setText("");
        //} else if (event ->type() == QEvent::FocusOut) {
        //     ui ->lineEdit_3 ->setText("kurac22");
        }
    }
    if (watched == ui ->lineEdit_4) {
        if (event ->type() == QEvent::FocusIn) {
             ui ->lineEdit_4 ->setText("");
        //} else if (event ->type() == QEvent::FocusOut) {
        //     ui ->lineEdit_4 ->setText("kurac22");
        }
    }
    if (watched == ui ->lineEdit_5) {
        if (event ->type() == QEvent::FocusIn) {
             ui ->lineEdit_5 ->setText("");
        //} else if (event ->type() == QEvent::FocusOut) {
        //     ui ->lineEdit_5 ->setText("kurac22");
        }
    }
    if (watched == ui ->lineEdit_6) {
        if (event ->type() == QEvent::FocusIn) {
             ui ->lineEdit_6 ->setText("");
        //} else if (event ->type() == QEvent::FocusOut) {
        //     ui ->lineEdit_6 ->setText("kurac22");
        }
    }
    if (watched == ui ->lineEdit_7) {
        if (event ->type() == QEvent::FocusIn) {
             ui ->lineEdit_7 ->setText("");
        //} else if (event ->type() == QEvent::FocusOut) {
        //     ui ->lineEdit_7 ->setText("kurac22");
        }
    }
    if (watched == ui ->lineEdit_8) {
        if (event ->type() == QEvent::FocusIn) {
             ui ->lineEdit_8 ->setText("");
        //} else if (event ->type() == QEvent::FocusOut) {
        //     ui ->lineEdit_8 ->setText("kurac22");
        }
    }
    return QWidget::eventFilter(watched,event);
}
