#include "dailymood.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

dailymood::dailymood(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.addTodoButton, &QPushButton::clicked, this, &dailymood::addBtnClicked);
}

dailymood::~dailymood() {}

void dailymood::addBtnClicked() {
    openEventDialog();
}

void dailymood::openEventDialog() {
    EventDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString name = dialog.getName();
        QDate date = dialog.getDate();
        QTime time = dialog.getTime();

        // Format the date to "dd/MM/yyyy"
        QString formattedDate = date.toString("dd/MM/yyyy");

        // Otwieranie pliku do zapisu w trybie dopisywania
        QFile file("data.txt");
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            // Zapisywanie danych do pliku, oddzielone tabulatorami
            QTextStream out(&file);
            out << formattedDate << "\t" << name << "\t" << time.toString() << "\t0\n";
            // Zamykanie pliku
            file.close();
        }
        else {
            QMessageBox::warning(this, "Error", "Failed to open the file for writing.");
        }

        // Wyœwietlanie informacji o dodanym wydarzeniu
        QMessageBox::information(this, "Event Info",
            "Name: " + name + "\nDate: " + formattedDate + "\nTime: " + time.toString());
    }
}
