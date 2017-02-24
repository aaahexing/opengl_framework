// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
using namespace glm;

#include <QApplication>
#include "gui/gl_widget.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    GLWidget *widget = new GLWidget();
    widget->show();
    return app.exec();
}
