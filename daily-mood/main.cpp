#include "dailymood.h"
#include "TodoCard.h"
#include "appData.h"
#include "todo.h"
#include "fileReader.h"
#include <QtWidgets/QApplication>


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    dailymood w;

    // accessing ui components
    QWidget* todoScroll = w.findChild<QWidget*>("todosScroll");


    // getting text data
    fileReader freader("data.txt");
    std::vector<std::string> moodTextData = freader.getData();

    //// adding todos and moods
    appData *applicationData = new appData(moodTextData);
    applicationData->displayTodos(todoScroll);


    w.show();
    return a.exec();
}

