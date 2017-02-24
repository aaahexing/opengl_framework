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
#include "gui/monitor_window.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    monitor::MonitorWindow *window = new monitor::MonitorWindow();
    window->show();
    return app.exec();
}
