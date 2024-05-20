#include "dailymood.h"
#include <QMessageBox>

dailymood::dailymood(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.addTodoButton, SIGNAL(clicked()), this, SLOT(addBtnClicked()));
}

dailymood::~dailymood()
{}


void dailymood::addBtnClicked() {
    QMessageBox msgBox;
    msgBox.setText("clicked");
    msgBox.setWindowTitle("Komunikat");
    msgBox.exec();
}