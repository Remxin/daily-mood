#include "dailymood.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>


dailymood::dailymood(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // accessing ui components
    QWidget* todoScroll = ui.todosScroll;

    QCalendarWidget* calendar = ui.calendarWidget;
    std::string selectedDate = calendar->selectedDate().toString("dd/MM/yyyy").toStdString();


    // getting text data
    fileReader freader("data.txt");
    std::vector<std::string> moodTextData = freader.getData();

    //// adding todos and moods
    this->applicationData = new appData(moodTextData, selectedDate);
    this->applicationData->displayTodos(todoScroll);

    connect(calendar, &QCalendarWidget::selectionChanged, this, &dailymood::onDateChanged);
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
            this->applicationData->addTodo(formattedDate.toStdString() + "\t" + name.toStdString() + "\t" + time.toString().toStdString() + "\t" + "0");
            // Zamykanie pliku
            file.close();
            this->onDateChanged();
        }
        else {
            QMessageBox::warning(this, "Error", "Failed to open the file for writing.");
        }

        // Wyœwietlanie informacji o dodanym wydarzeniu
        QMessageBox::information(this, "Event Info",
            "Name: " + name + "\nDate: " + formattedDate + "\nTime: " + time.toString());
    }
}

void dailymood::onDateChanged() {
    QCalendarWidget* calendar = ui.calendarWidget;
    QString selectedDate = calendar->selectedDate().toString("dd/MM/yyyy");
    this->applicationData->setDate(selectedDate.toStdString());
    this->applicationData->clearTodos();
    this->applicationData->displayTodos();
    //updateTodoCards(selectedDate);
}

