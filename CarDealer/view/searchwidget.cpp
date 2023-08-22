#include "searchwidget.h"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>

namespace View {

SearchWidget::SearchWidget(QWidget* parent)
    : QWidget(parent)
{
    // Creates widgets
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QLabel* title_label = new QLabel("Search Engine");
    title_label->setObjectName("title");
    title_label->setAlignment(Qt::AlignHCenter);
    vbox->addWidget(title_label);

    QFormLayout* form = new QFormLayout();
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    vbox->addLayout(form);

    query_input = new QSpinBox();
    query_input->setMinimum(1);
    query_input->setMaximum(INT_MAX);
    query_input->setValue(1);
    form->addRow("id", query_input);

    filter_input = new QComboBox();
    filter_input->setObjectName("filter-input");
    filter_input->addItem("sedan");
    filter_input->addItem("super car");
    filter_input->addItem("suv");
    form->addRow("filter", filter_input);

    QPushButton* apply_input = new QPushButton(
        "Apply filter"
    );
    vbox->addWidget(apply_input);

    QPushButton* search_input = new QPushButton(
        "Search id"
    );
    vbox->addWidget(search_input);

    // Connects signals
    connect(search_input, &QPushButton::clicked, this, &SearchWidget::search);
    connect(apply_input, &QPushButton::clicked, this, &SearchWidget::filter);
}

void SearchWidget::search() {
    emit search_event(query_input->value());
}

void SearchWidget::filter() {
    emit filter_event(filter_input->currentText().toStdString());
}

}
