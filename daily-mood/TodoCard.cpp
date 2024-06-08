#include "TodoCard.h"


TodoCard::TodoCard(Todo &todo, QWidget* parent) : QWidget(parent), m_todo(todo)
{
    // Create layout for the TodoCard
    QHBoxLayout* layout = new QHBoxLayout(this);

    // Create labels for displaying Todo details
    QLabel* titleLabel = new QLabel(QString::fromStdString(todo.getName())); 
    titleLabel->setObjectName("todoName");
    titleLabel->setStyleSheet("QLabel#todoName {"
        "color: black;"
        "font-size: 13px;"
        "}");
    QLabel* timeLabel = new QLabel(QString::fromStdString(todo.getTime()));
    timeLabel->setObjectName("todoTime");
    timeLabel->setStyleSheet("QLabel#todoTime {"
        "color: gray;"
        "font-size: 10px;"
        "font-weight: light;"
    "}");

    // Create button for interaction (e.g., mark as done)
    QPushButton* doneButton = new QPushButton(todo.getDone() ? "Undo" : "Done");
    doneButton->setObjectName("toggleTodoBtn");
    doneButton->setStyleSheet("QPushButton#toggleTodoBtn {"
        "    background-color: #63BF93;"
        "    color: white;"
        "    border: 0.5px solid black;"
        "    border-radius: 5px;"
        "    padding: 5px 10px;"
        "    font-weight: bold;"
        "    font-size: 13px;"
        "    transition: 0.3s all;"  
        "}"
        "QPushButton#toggleTodoBtn:hover {"
        "    background-color: #245741;"
        "}");;


    this->doneButton = doneButton;
    this->m_todo = todo;
    connect(doneButton, SIGNAL(clicked()), this, SLOT(onActionButtonClicked()));

    // Add widgets to layout
    layout->addWidget(titleLabel);
    layout->addWidget(timeLabel);
    layout->addWidget(doneButton);

    // Set layout to the widget
    setLayout(layout);
}

void TodoCard::onActionButtonClicked() {

    if (!this->m_todo.getDone()) {
        this->doneButton->setText("Undo");
    }
    else {
        this->doneButton->setText("Done");
    }
    this->m_todo.toggleDone();

}

