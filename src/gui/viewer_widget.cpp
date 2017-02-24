#include "viewer_widget.h"

#include <QtGui>
#include <cstdio>
#include <iostream>

namespace monitor {

ViewerWidget::ViewerWidget() {
    // Set layout.
    setWindowLayout();
}

ViewerWidget::~ViewerWidget() {
}

void ViewerWidget::setWindowLayout() {
    // Main layout.
    QHBoxLayout* main_layout = new QHBoxLayout();
    // Left layout
    left_widget_ = new QLabel("Left");
    right_widget_ = new QLabel("Right");
    main_layout->addWidget(left_widget_);
    main_layout->addWidget(right_widget_);
    // Use the specified layout.
    setLayout(main_layout);
}

}  // namespace monitor
