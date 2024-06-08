#include "errors.h"

void errors::display(QString msg) {

    QMessageBox msgBox;
    msgBox.critical(0, "Error", msg);
    msgBox.setFixedSize(500, 200);

}