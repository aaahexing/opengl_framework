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
#include "gui/monitor_window.h"

#include "gui/textartdialog.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    // monitor::GLWidget *widget = new monitor::GLWidget();
    // widget->show();
    // monitor::MonitorWindow window;
    // window.show();
    TextArtDialog dialog(QObject::tr("Text Art"));
    dialog.resize(600, 300);
    dialog.show();
    return app.exec();
}
