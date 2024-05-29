#pragma once
#ifndef AddMoodDialog_H
#define AddMoodDialog_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>    
#include <QLabel>

class AddMoodDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddMoodDialog(QWidget* parent = nullptr);

private slots:
    void onAccept();
    void onStarClick(int count);

private:
    QPushButton* acceptButton;
    QVBoxLayout* layout;
    QVBoxLayout* starsLayout;
    QLabel* labelRating;
    std::vector<QPushButton*> stars;
    QLabel* labelDescription;
    QLineEdit* lineEditDescription;
};

#endif // AddMoodDialog_H
