#include <QCoreApplication>
#include "httpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    HttpServer *server = new HttpServer(&a);
    server->startServer(6082);

    return a.exec();
}
