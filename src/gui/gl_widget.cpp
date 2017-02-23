#include "gl_widget.h"

#include <QGLWidget>
#include <QtGui>
#include <QWidget>

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) {
}

void GLWidget::resizeGL() {
}

void GLWidget::initializeGL() {
    qglClearColor(QColor(Qt::black));
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
