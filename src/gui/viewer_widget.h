#ifndef MONITOR_VIEWER_WIDGET_H_
#define MONITOR_VIEWER_WIDGET_H_

#include <QtGui>

class QGridLayout;
class QLabel;

namespace monitor {

using namespace Qt;

class ViewerWidget : public QWidget {
Q_OBJECT

public:
    ViewerWidget();
    ~ViewerWidget();

public Q_SLOTS:

private:
    void setWindowLayout();

    QWidget* left_widget_;
    QWidget* right_widget_;
};

}  // namespace monitor

#endif  // MONITOR_VIEWER_WIDGET_H_
