#include "TodoCard.h"
#include "todo.h"
#include <string>


TodoCard::TodoCard(QObject* parent, Todo todo) {
    std::string name = todo.getName();
    QString qname = QString::fromStdString(name);
    label = new QLabel(qname, this);
    button = new QPushButton("Click Me", this);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &TodoCard::onButtonClicked);

    setLayout(layout);
}

void TodoCard::onButtonClicked() {
    label->setText("Button Clicked!");
}