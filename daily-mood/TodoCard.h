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
    TodoCard(Todo &todo, QWidget* parent = nullptr);
  

 
private slots:
    void onActionButtonClicked();
private:
    Todo &m_todo; 
    QPushButton* doneButton;
    
};

#endif 
