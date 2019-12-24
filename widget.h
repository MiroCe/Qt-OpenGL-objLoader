#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL/QtOpenGL>
#include <QtGui>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "objmtlloader.h"


class MyGLWidget : public QGLWidget
{
    Q_OBJECT

public:
    MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

private:
    objmtlloader Boat;
    objmtlloader Patrick;
    objmtlloader Workerman;
    objmtlloader Fish1;
    int flag = 1;
};

#endif // WIDGET_H
