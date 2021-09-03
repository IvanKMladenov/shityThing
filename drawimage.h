#ifndef DRAWIMAGE_H
#define DRAWIMAGE_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QMatrix4x4>

#include "mainwindow.h"

//#include "ui_mainwindow.h"

class MainWindow;
QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class DrawImage : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    DrawImage(QWidget *parent = nullptr);
    DrawImage(QVector<float> meshVec, QWidget *parent = nullptr);
    ~DrawImage();

    void CallDraw();

    inline void SetTetraMesh   (float *mesh, GLuint size) {
       for (GLuint i = 0; i < size + 1; ++i) {
           m_tetraMesh[i] = mesh[i];
       }
    }

    inline void SetOctaMesh   (float *mesh, GLuint size) {
       for (GLuint i = 0; i < size + 1; ++i) {
           m_octaMesh[i] = mesh[i];
       }
    }

    inline void SetHexaMesh   (float *mesh, GLuint size) {
       m_meshData = new GLfloat[size];
       m_meshData[size] = {};
       for (GLuint i = 0; i < size + 1; ++i) {
           m_meshData[i] = mesh[i];
       }
    }

    inline void SetDodecaMesh   (float *mesh, GLuint size) {
       for (GLuint i = 0; i < size + 1; ++i) {
           m_dodecaMesh[i] = mesh[i];
       }
    }

    inline void SetIcosaMesh   (float *mesh, GLuint size) {
       for (GLuint i = 0; i < size + 1; ++i) {
           m_icosaMesh[i] = mesh[i];
       }
    }

public slots:
    //void setXRotation(int angle);
    //void setYRotation(int angle);
    //void setZRotation(int angle);
    void cleanup();
protected:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void timerEvent(QTimerEvent *e) override;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
public:
    //void createShaders();
    GLuint initVBO();

private:
    QVector2D m_mousePressPosition;
    QVector3D m_rotationAxis;
    qreal m_angularSpeed = 0;
    QQuaternion m_rotation;

    GLfloat *m_meshData = nullptr;

    //mesh for each platonic solid
    GLfloat m_tetraMesh[36] = {};
    GLfloat m_octaMesh[72] = {};
    GLfloat m_hexaMesh[108] = {};
    GLfloat m_dodecaMesh[324] = {};
    GLfloat m_icosaMesh[180] = {};

    GLuint m_meshVbo;
    QOpenGLShaderProgram *m_program = nullptr;
};

#endif // DRAWIMAGE_H
