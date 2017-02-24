#include "camera_view_widget.h"

#include <QListWidget>
#include <QtCore>

namespace monitor {

CameraViewWidget::CameraViewWidget() {
    setText("This is a space holder for cameras.");

    setScaledContents(false);
    setFixedSize(300, 300);
}

void CameraViewWidget::setPixmap(const QPixmap& p) {
    pix_ = p;
    QLabel::setPixmap(scaledPixmap());
}

int CameraViewWidget::heightForWidth(int width) const {
    return pix_.isNull() ? this->height() : ((qreal)pix_.height() * width) / pix_.width();
}

QSize CameraViewWidget::sizeHint() const {
    int w = this->width();
    return QSize(w, heightForWidth(w));
}

QPixmap CameraViewWidget::scaledPixmap() const {
    return pix_.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void CameraViewWidget::resizeEvent(QResizeEvent* e) {
    if(!pix_.isNull()) {
        QLabel::setPixmap(scaledPixmap());
    }
}

}  // namespace monitor
