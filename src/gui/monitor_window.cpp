#include "monitor_window.h"

#include <QDockWidget>
#include <QListWidget>
#include <QtCore>
#include <QStatusBar>
#include <QListWidget>
#include <QStringList>
#include <QAction>
#include <QtGui>
#include "camera_view_widget.h"
#include "status_widget.h"
#include "gl_widget.h"

namespace monitor {
namespace {
// Constant for monitor style.
constexpr char kMonitorWindowStyle[] =
    "QGroupBox { border:1px solid gray; margin-top: 0.5em; }"
    "QGroupBox::title {"
        "subcontrol-origin: margin; left: 10px; padding: 0 3px 0 3px; } ";
}

MonitorWindow::MonitorWindow() {
    setWindowTitle(tr("AV Monitor"));
    // Set central view window.
    GLWidget* widget = new GLWidget();
    setCentralWidget(widget);

    viewMenu_ = menuBar()->addMenu(tr("&View"));

    createStatusBar();
    createDockWindows();
    setStylesheet();
    resizeWindow();
}

void MonitorWindow::keyPressEvent(QKeyEvent* ke) {
}

void MonitorWindow::keyReleaseEvent(QKeyEvent* ke) {
    if (ke->key() == Qt::Key_Escape) {
        close();
    }
}

void MonitorWindow::resizeWindow() {
    QSize newSize = QDesktopWidget().availableGeometry(this).size() * 0.9;
    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            newSize,
            qApp->desktop()->availableGeometry()
        )
    );
}

void MonitorWindow::createStatusBar() {
    statusBar()->showMessage(tr("Ready"));
}

void MonitorWindow::createDockWindows() {
    // The status dock window to show whether the AV system is healthy or not.
    QDockWidget* status_dock = new QDockWidget(tr("System Status"));
    StatusWidget* status_widget = new StatusWidget();
    status_dock->setWidget(status_widget);
    addDockWidget(Qt::RightDockWidgetArea, status_dock);

    // The camera dock window shows the image streams in realtime.
    QDockWidget* camera_dock = new QDockWidget(tr("Cameras"), this);
    CameraViewWidget* camera_widget = new CameraViewWidget();
    camera_dock->setWidget(camera_widget);
    addDockWidget(Qt::RightDockWidgetArea, camera_dock);

    QDockWidget* log_dock = new QDockWidget(tr("Log"), this);
    QListWidget* edges_widget = new QListWidget();
    for (int i = 0; i < 30; ++i) {
        edges_widget->addItem("Valid!!");
    }
    log_dock->setWidget(edges_widget);
    addDockWidget(Qt::BottomDockWidgetArea, log_dock);

    QDockWidget* dock = new QDockWidget(tr("Data"), this);
    QTableWidget* table_widget = new QTableWidget();
    dock->setWidget(table_widget);
    tabifyDockWidget(log_dock, dock);
}

void MonitorWindow::setStylesheet() {
    qApp->setStyleSheet(kMonitorWindowStyle);
}

}  // namespace monitor
