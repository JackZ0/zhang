
#include <QStringList>
#include <QTextStream>


static QTextStream cout(stdout, QIODevice::WriteOnly);
int main(int argc, char *argv[])
{
    QString str = "1,2,3,4,5,6,7,8,9";
    QStringList strList;

    strList = str.split(",");

    cout << "String list item count: " << strList.size() << endl;

    for(int i = 0; i < strList.size(); i++)
        cout << i + 1 << ":" << strList[i] << endl;

    QString str2;
    str2 = strList.join(",");

    cout << str2 << endl;

    return 0;
}
