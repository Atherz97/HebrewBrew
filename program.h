#ifndef PROGRAM_H
#define PROGRAM_H

#include <QString>
#include <QMap>
#include <QArrayData>
#include <QMessageBox>
#include <QInputDialog>
#include <QErrorMessage>
#include <QIODevice>
#include <QFile>

#define FILENAME "dict.dat"

#define AND 1
#define PLURFEM 2
#define NOT 3
#define PREP 4
#define PLURMASC 5
#define YOUR 6
#define OUR 7
#define ITS 8
#define THEIR 9
#define THE 10
#define FORTO 11
#define TONOUN 12
#define TOPERSON 13
#define FROM 14

class Program
{
public:
    Program();
    int saveDictionary(QString filename);
    int loadDictionary(QString filename);
    int clearDict();
    QString present(QString input, int mod);
    static QString spell();
    QList<QString> getKeys();
    QString getValue(QString key);
    QString getValue(int key);
    QString AddToDictionary(QString hebrewWord, QString meaning);
    int removeFromDictionary(QString englishWord);
    static int calculateGematria(QString phrase);
    static int cval(QChar c);
    static QString pronounce(QString c);
private:
    QString rootWord = "";
    static QString numberToLetter(int number);
    static QString charToLetter(QString ch);
    QString wordToRootForm(QString englishWord);
    QMap<QString,QString> dictionary;
    static QString generateChars(QString shortChars);
};

#endif // PROGRAM_H
