#include "status_widget.h"

#include <QtGui>
#include <QtCore>
#include <QWidget>

namespace monitor {

StatusWidget::StatusWidget() {
    QFormLayout* system_layout = new QFormLayout();
    system_layout->addRow(new QLabel(tr("Heading")), new QLabel("23.01"));
    system_layout->addRow(new QLabel(tr("RTK")), new QLabel("Y"));
    setLayout(system_layout);

    setFixedWidth(300);
}

}  // namespace monitor
