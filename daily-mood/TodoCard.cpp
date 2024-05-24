#include "TodoCard.h"


TodoCard::TodoCard(QWidget* parent) : QWidget(parent) {
    label = new QLabel("This is a custom widget", this);
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