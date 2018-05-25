#ifndef EXPORT_H
#define EXPORT_H
#include<QString>
#include<QVector>

using namespace std;
class Export
{
public:
    Export();
    bool copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist);
    bool searchSchedule(QString ID,QVector<QString> &buf_out );
};

#endif // EXPORT_H
