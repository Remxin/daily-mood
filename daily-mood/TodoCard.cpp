#include "TodoCard.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

TodoCard::TodoCard(Todo todo, QWidget* parent) : QWidget(parent), m_todo(todo)
{
    // Create layout for the TodoCard
    QHBoxLayout* layout = new QHBoxLayout(this);

    // Create labels for displaying Todo details
    QLabel* titleLabel = new QLabel(QString::fromStdString(todo.getName())); // Using QString for conversion
    QLabel* dateLabel = new QLabel(QString::fromStdString(todo.getDate())); // Using QString for conversion
    QLabel* timeLabel = new QLabel(QString::fromStdString(todo.getTime())); // Using QString for conversion

    // Create button for interaction (e.g., mark as done)
    QPushButton* doneButton = new QPushButton("Done");
    connect(doneButton, &QPushButton::clicked, this, [this]() {
        // Emit signal to notify that the todo is marked as done
        emit todoMarkedAsDone(m_todo);
        });

    // Add widgets to layout
    layout->addWidget(titleLabel);
    layout->addWidget(dateLabel);
    layout->addWidget(timeLabel);
    layout->addWidget(doneButton);

    // Set layout to the widget
    setLayout(layout);
}
