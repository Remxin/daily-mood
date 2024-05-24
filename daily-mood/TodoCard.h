#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class TodoCard : public QWidget {
    Q_OBJECT

public:
    explicit TodoCard(QWidget* parent = nullptr);

private slots:
    void onButtonClicked();

private:
    QLabel* label;
    QPushButton* button;
};

#endif // CUSTOMWIDGET_H
