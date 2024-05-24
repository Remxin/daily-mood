#include "dailymood.h"
#include "TodoCard.h"
#include "appData.h"
#include "todo.h"
#include "fileReader.h"
#include <QtWidgets/QApplication>

#include "TodoCard.h" // Include the TodoCard header file

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    dailymood w;
    appData applicationData;

    // accessing ui components
    QWidget* todoScroll = w.findChild<QWidget*>("todosScroll");

    if (todoScroll) {
        // Create a QVBoxLayout for the todoScroll widget
        QVBoxLayout* layout = new QVBoxLayout(todoScroll);

        // getting text data
        fileReader freader("data.txt");
        std::vector<std::string> moodTextData = freader.getData();

        //// adding todos and moods
        for (const std::string& moodT : moodTextData) {
            applicationData.addTodo(moodT);
        }

        // displaying todos and moods
        std::vector<Todo> todos = applicationData.getTodos();
        for (const Todo& todo : todos) {
            // Create a TodoCard object for each todo
            TodoCard* todoCard = new TodoCard(todo); // Assuming TodoCard takes Todo and appData as parameters

            // Add the todoCard to the layout
            layout->addWidget(todoCard);
        }

        // Set the layout to todoScroll
        todoScroll->setLayout(layout);
    }
    else {
        qDebug() << "todoScroll object not found.";
    }

    w.show();
    return a.exec();
}

