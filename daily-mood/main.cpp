#include "dailymood.h"
#include "TodoCard.h"
#include "appData.h"
#include "todo.h"
#include "fileReader.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dailymood w;
    appData applicationData = appData();

    // accessing ui components
    QObject todoScroll = w.findChild<QObject>("todoScroll");

    // getting text data
    fileReader freader = fileReader("data.txt");
    std::vector<std::string> moodTextData = freader.getData();

    //// adding todos and moods
    for (std::string moodT : moodTextData) {
        applicationData.addTodo(moodT);
    }

    // displaying todos and moods
    std::vector<Todo> todos = applicationData.getTodos();
    for (int i = 0; i < todos.size(); i++) {
        TodoCard tcard = TodoCard(&todoScroll, todos[i]);
    }
    



    w.show();
    return a.exec();
}
