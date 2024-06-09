#include "dailymood.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

dailymood::dailymood(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    applyStyleSheet();

    QScrollArea* todoScrollArea = ui.todosScroll;
    QWidget* todoScrollContent = new QWidget(); // Utworzono nowy QWidget jako zawartość scrolla
    todoScrollArea->setWidget(todoScrollContent); // Ustawienie todoScrollContent jako widgetu QScrollArea
    todoScrollArea->setWidgetResizable(true); // Ustawienie scrolla jako resizable

    QVBoxLayout* moodScroll = ui.moodScroll;
    moodScroll->setObjectName("moodContainer");

    QCalendarWidget* calendar = ui.calendarWidget;
    std::string selectedDate = calendar->selectedDate().toString("dd/MM/yyyy").toStdString();

    fileReader freader;
    this->freader = &freader;

    this->applicationData = new appData(freader.getTodoData(), freader.getMoodData(), selectedDate, todoScrollContent);
    this->applicationData->displayTodos();
    this->applicationData->displayMood(moodScroll);

    connect(calendar, &QCalendarWidget::selectionChanged, this, &dailymood::onDateChanged);
    connect(ui.updateMoodBtn, SIGNAL(clicked()), this, SLOT(openUpdateMoodDialog()));
    connect(ui.addTodoButton, &QPushButton::clicked, this, &dailymood::addTodoBtnClicked);
}

dailymood::~dailymood() {
    this->applicationData->sort();
    this->freader->writeTodos(this->applicationData->getTodos());
    this->freader->writeMoods(this->applicationData->getMoods());
}

void dailymood::addTodoBtnClicked() {
    openAddTodoDialog();
}

void dailymood::openAddTodoDialog() {
    EventDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString name = dialog.getName();
        QDate date = dialog.getDate();
        QTime time = dialog.getTime();

        QString formattedDate = date.toString("dd/MM/yyyy");

        QFile file("data.txt");
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << formattedDate << "\t" << name << "\t" << time.toString() << "\t0\n";
            this->applicationData->addTodo(formattedDate.toStdString() + "\t" + name.toStdString() + "\t" + time.toString().toStdString() + "\t" + "0");
            file.close();
            this->onDateChanged();
        }
        else {
            QMessageBox::warning(this, "Error", "Cannot open file for writing");
        }

        QMessageBox::information(this, "Success",
            "Successfully added new todo");
    }
}

void dailymood::onDateChanged() {
    QCalendarWidget* calendar = ui.calendarWidget;
    QString selectedDate = calendar->selectedDate().toString("dd/MM/yyyy");
    this->applicationData->setDate(selectedDate.toStdString());
    this->applicationData->clearTodos();
    this->applicationData->displayTodos();
    this->applicationData->displayMood();
}

void dailymood::openUpdateMoodDialog() {
    AddMoodDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        this->applicationData->addMood(date::getTodaysDateStr(), dialog.getRating(), dialog.getDescription());
    }
}

void dailymood::applyStyleSheet() {
    QString styleSheet = R"(
        QWidget {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            font-size: 14px;
            background-color: #FAF3E0;  
            color: #333333;
        }

        QMainWindow {
            background-color: #FAF3E0;  
        }

        QPushButton {
            background-color: #4CAF50;
            border: none;
            color: white;
            padding: 10px 24px;
            text-align: center;
            text-decoration: none;
            display: inline-block;
            font-size: 14px;
            margin: 4px 2px;
            cursor: pointer;
            border-radius: 12px;
            font-weight: bold;
        }
         QPushButton:disabled {
             background-color: #d4d4d4;
             color: #a0a0a0;
        }

        QPushButton:hover {
            background-color: #45a049;
        }

        

        QPushButton#starButton {
            background-color: white;
        } 

        QCalendarWidget {
            border: 1px solid #d4d4d4;
            background-color: white;  
            border-radius: 6px;  
        }

        QCalendarWidget QAbstractItemView:enabled {
            color: black;
            background-color: #ffffff;  
            selection-background-color: #4CAF50;
            selection-color: white;
        }

        QCalendarWidget QToolButton {
            background-color: #4CAF50;  
            color: white;
            border: none;
            border-radius: 6px;
            padding: 5px;
        }

        QCalendarWidget QToolButton:hover {
            background-color: #45a049;
        }

        QCalendarWidget QToolButton::menu-indicator {
            image: none;  
        }

        QCalendarWidget QWidget#qt_calendar_navigationbar {
            background-color: #4CAF50;  
        }

        QCalendarWidget QSpinBox {
            width: 50px;
            background-color: #ffffff;
        }

        QCalendarWidget QSpinBox::up-button, QCalendarWidget QSpinBox::down-button {
            background-color: #4CAF50;
            border: none;
            border-radius: 6px;
        }

        QCalendarWidget QSpinBox::up-arrow, QCalendarWidget QSpinBox::down-arrow {
            color: white;
        }

        QWidget#appTitle {
            font-size: 36px;
            font-weight: bold;
            color: #4CAF50;
        }

        #moodContainer {
            position: relative;
            width: 100%;
            padding: 20px;
        }
        
        #moodTitle {
            width: 100%;
            text-align: center;
            font-size: 20px;
            color: #4CAF50;
            font-weight: bold;
        }
  
        #moodDate {
            color: gray;
            font-size: 12px;
        }

        #moodRating {
            font-size: 18px;
            font-weight: bold;
            color: black;
        }

        #moodDescription {
            font-size: 10px;
            
        }
        

        QScrollArea {
            border: none;
        }

       

        QMessageBox {
            background-color: #ffffff;
        }

        QMessageBox QPushButton {
            background-color: #4CAF50;
            color: white;
            padding: 5px 10px;
            border-radius: 5px;
        }

        QMessageBox QPushButton:hover {
            background-color: #45a049;
        }

        QDialogButtonBox QPushButton {
                    background-color: #4CAF50;
                    color: white;
                    border: none;
                    padding: 10px 24px;
                    text-align: center;
                    text-decoration: none;
                    display: inline-block;
                    font-size: 14px;
                    margin: 4px 2px;
                    cursor: pointer;
                    border-radius: 12px;
        }

        QDialogButtonBox QPushButton:disabled {
            background-color: #d4d4d4;
            color: #a0a0a0;
        }
    )";

    this->setStyleSheet(styleSheet);
}

