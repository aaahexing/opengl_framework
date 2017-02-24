#ifndef MONITOR_MONITOR_WINDOW_H_
#define MONITOR_MONITOR_WINDOW_H_

#include <QMainWindow>

class QMenu;

namespace monitor {

class MonitorWindow : public QMainWindow {
    Q_OBJECT

public:
    MonitorWindow();

public Q_SLOTS:
    void keyPressEvent(QKeyEvent* ke);
    void keyReleaseEvent(QKeyEvent* ke);

private:
    void createStatusBar();
    void createDockWindows();
    void resizeWindow();
    void setStylesheet();

    QMenu* viewMenu_;
};

}  // namespace monitor

#endif  // MONITOR_MONITOR_WINDOW_H_
