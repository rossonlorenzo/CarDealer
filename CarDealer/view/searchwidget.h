#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>


namespace View {

class SearchWidget: public QWidget {
    Q_OBJECT
  private:
    QSpinBox* query_input;
    QComboBox* filter_input;

  public:
    explicit SearchWidget(QWidget* parent = 0);

  signals:
    void search_event(unsigned int query);
    void filter_event(std::string type);

  public slots:
    void search();
    void filter();
};

}

#endif
