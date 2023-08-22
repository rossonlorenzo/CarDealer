// Includes Qt header files
#include <QApplication>
#include <QListWidgetItem>
#include <QListWidget>
#include <QFile>
#include <QLabel>
#include <QFileDialog>

#include "view/MainWindow.h"
#include "products/car.h"
#include "products/linkedlist.h"
#include "products/dataMapper/jsonfile.h"
#include "products/JsonConverter/reader.h"
#include "products/JsonConverter/json.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);    
    std::string path="";
    products::JsonConverter::Reader reader;
    products::JsonConverter::Json converter (reader);
    products::DataMapper::JsonFile jfile(path, converter);
    products::List<const products::Car*>* products = new products::List<const products::Car*>();
    app.setWindowIcon(QIcon(":assets/icon.png"));
    QFile styleSheetFile(":/assets/Diffnes.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    app.setStyleSheet(styleSheet);
    View::MainWindow window(jfile, *products);
    window.resize(1024, 576);
    window.show();
    return app.exec();
}
