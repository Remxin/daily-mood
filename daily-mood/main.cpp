#include "dailymood.h"
#include "TodoCard.h"
#include "appData.h"
#include "fileReader.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dailymood w;
    fileReader freader = fileReader("data.txt");
    std::vector<std::string> moodTextData;
    moodTextData = freader.getData();
    appData applicationData = appData();

    for (int i = 0; i < moodTextData.size(); i++) {
        applicationData.addTodo(moodTextData[i]);
    }
    



    w.show();
    return a.exec();
}
