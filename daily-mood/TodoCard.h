#ifndef TODOCARD_H
#define TODOCARD_H

#include <QWidget>
#include "todo.h" // Include the Todo class
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

class TodoCard : public QWidget {
    Q_OBJECT

public:
    TodoCard(Todo todo, QWidget* parent = nullptr);
    // Constructor taking Todo object

signals:
    void todoMarkedAsDone(const Todo& todo); // Signal emitted when the todo is marked as done

private:
    Todo m_todo; // Member variable to store the Todo object
    QPushButton* doneButton;
};

#endif // TODOCARD_H
