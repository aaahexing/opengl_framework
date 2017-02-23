#ifndef GL_WIDGET_H_
#define GL_WIDGET_H_

#include <QGLWidget>

class GLWidget : public QGLWidget {
Q_OBJECT

public:
    explicit GLWidget(QWidget *parent = 0);

    void resizeGL();
    void initializeGL();
    void paintGL();
};

#endif  // GL_WIDGET_H_
