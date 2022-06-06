#pragma once

#include <QtWidgets/QWidget>
#include <qfiledialog.h>
#include "ui_cososys_qt.h"

#include "PatternMatching.h"

class cososys_qt : public QWidget
{
    Q_OBJECT

public:
    cososys_qt(QWidget *parent = Q_NULLPTR);
    PatternMatching m_pattern_matching;

private:
    Ui::cososys_qtClass ui;
    QString m_dict_file_paths;
    QString m_text_file_paths;
private slots:
    void on_button_add_dictionary_clicked();
    void on_button_add_text_clicked();
    void on_button_search_clicked();
};
