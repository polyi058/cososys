#include "cososys_qt.h"

cososys_qt::cososys_qt(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

void cososys_qt::on_button_add_dictionary_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open dictionary", QDir::currentPath(), "Text Documents (*.txt)");
    int success = m_pattern_matching.add_dictionary(file_name.toStdString());
    if (success < 0)
        return;
    file_name = file_name.mid(file_name.lastIndexOf("/") + 1);
    m_dict_file_paths.append(file_name + "\n");
    ui.text_dictionary->setPlainText(m_dict_file_paths);
}

void cososys_qt::on_button_add_text_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open dictionary", QDir::currentPath(), "Text Documents (*.txt)");
    int success = m_pattern_matching.add_file_path(file_name.toStdString());
    if (success < 0)
        return;
    file_name = file_name.mid(file_name.lastIndexOf("/") + 1);
    m_text_file_paths.append(file_name + "\n");
    ui.text_text->setPlainText(m_text_file_paths);
}

void cososys_qt::on_button_search_clicked()
{
    int success = m_pattern_matching.search();
    if (success < 0)
        return;
    ui.text_result->setPlainText(QString::fromStdString(m_pattern_matching.getMatchesStr()));
}
