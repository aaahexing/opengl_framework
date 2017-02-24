#ifndef MONITOR_CAMERA_VIEW_WIDGET_H_
#define MONITOR_CAMERA_VIEW_WIDGET_H_

#include <QLabel>
#include <QPixmap>

namespace monitor {

class CameraViewWidget : public QLabel {
    Q_OBJECT

public:
    CameraViewWidget();
    virtual int heightForWidth(int width) const;
    virtual QSize sizeHint() const;
    QPixmap scaledPixmap() const;

public Q_SLOTS:
    void setPixmap(const QPixmap& p);
    void resizeEvent(QResizeEvent* e);

private:
    QPixmap pix_;
};

}  // namespace monitor

#endif  // MONITOR_CAMERA_VIEW_WIDGET_H_
