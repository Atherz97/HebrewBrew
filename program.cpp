#include "program.h"

#include <QFile>

Program::Program()
{

}

QString Program::wordToRootForm(QString englishWord)
{

    if (englishWord == "") return "";

    QString w = englishWord;
    QString r = ""; // root word in Hebrew (letters)
    QList<qint16> a = QList<qint16>();

    // we take this english word and directly link it to whatever we find in dictionary
    if (dictionary.contains(w)) {
        r = dictionary[w];
    }
    else {
        // we inquire user if not found, and thus add to dictionary so that this grows with time.
        QMessageBox *q = new QMessageBox();
        q->setText("This word is not available in the dictionary.");
        q->setInformativeText("Would you like to add it?");
        q->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        q->setDefaultButton(QMessageBox::Ok);

        // yes? no?
        int _r = q->exec();
        if (_r == QMessageBox::Ok) {
            // we let them choose the characters, and then add to the dictionary
            bool ok = false;
            QString text = QInputDialog::getText(q, "Add to Dictionary",
                "Characters:\nA B G D H V Z CH TS Y\nK L M N S AY P TZ Q R\nSH T", QLineEdit::Normal,
                "", &ok);
            if (ok) {
                r = AddToDictionary(text,w);
            }
        }
    }

    return r;
}

QString Program::AddToDictionary(QString hebrewWord, QString meaning)
{
    // Hebrew word = single or double letter consonants
    QString w = generateChars(hebrewWord);

    // add the word to the dictionary
    dictionary.insert(dictionary.end(),meaning,w);
    return w;
}

int Program::removeFromDictionary(QString englishWord) {
    int r = dictionary.remove(englishWord);
    return r == 0;
}

int Program::calculateGematria(QString phrase)
{
    int i = 0;
    for (QChar c : phrase) {
        if (c == "א") i += 1; else
        if (c == "ב") i += 2; else
        if (c == "ג") i += 3; else
        if (c == "ד") i += 4; else
        if (c == "ה") i += 5; else
        if (c == "ו") i += 6; else
        if (c == "ז") i += 7; else
        if (c == "ח") i += 8; else
        if (c == "ט") i += 9; else
        if (c == "י") i += 10; else
        if (c == "כ" || c == "ך" ) i += 20; else
        if (c == "ל") i += 30; else
        if (c == "מ" || c == "ם" ) i += 40; else
        if (c == "נ" || c == "ן" ) i += 50; else
        if (c == "ס") i += 60; else
        if (c == "ע") i += 70; else
        if (c == "פ" || c == "ף" ) i += 80; else
        if (c == "צ" || c == "ץ" ) i += 90; else
        if (c == "ק") i += 100; else
        if (c == "ר") i += 200; else
        if (c == "ש") i += 300; else
        if (c == "ת") i += 400; else
        i += 0;
    }
    return i;
}

int Program::cval(QChar c)
{
    if (c == "א") return 0; else
    if (c == "ב") return 1; else
    if (c == "ג") return 2; else
    if (c == "ד") return 3; else
    if (c == "ה") return 4; else
    if (c == "ו") return 5; else
    if (c == "ז") return 6; else
    if (c == "ח") return 7; else
    if (c == "ט") return 8; else
    if (c == "י") return 9; else
    if (c == "כ" || c == "ך" ) return 10; else
    if (c == "ל") return 11; else
    if (c == "מ" || c == "ם" ) return 12; else
    if (c == "נ" || c == "ן" ) return 13; else
    if (c == "ס") return 14; else
    if (c == "ע") return 15; else
    if (c == "פ" || c == "ף" ) return 16; else
    if (c == "צ" || c == "ץ" ) return 17; else
    if (c == "ק") return 18; else
    if (c == "ר") return 19; else
    if (c == "ש") return 20; else
    if (c == "ת") return 21; else
    if (c == " ") return -1; else
    return -2;
}

QString Program::pronounce(QString c)
{
    QString p = "";
    for (QChar h : c) {
        // letter pronounces
        if (h == "א") p = p + ""; else
        if (h == "ב") p = p + "B"; else
        if (h == "ג") p = p + "G"; else
        if (h == "ד") p = p + "D"; else
        if (h == "ה") p = p + "H"; else
        if (h == "ו") p = p + "V"; else
        if (h == "ז") p = p + "Z"; else
        if (h == "ח") p = p + "Ch"; else
        if (h == "ט") p = p + "Ts"; else
        if (h == "י") p = p + "Y"; else
        if (h == "כ" || h == "ך" ) p = p + "K"; else
        if (h == "ל") p = p + "L"; else
        if (h == "מ" || h == "ם" ) p = p + "M"; else
        if (h == "נ" || h == "ן" ) p = p + "N"; else
        if (h == "ס") p = p + "S"; else
        if (h == "ע") p = p + ""; else
        if (h == "פ" || h == "ף" ) p = p + "F"; else
        if (h == "צ" || h == "ץ" ) p = p + "Tz"; else
        if (h == "ק") p = p + "Q"; else
        if (h == "ר") p = p + "R"; else
        if (h == "ש") p = p + "S"; else
        if (h == "ת") p = p + "T"; else

        // spaces, hyphens, end sentence pronounces
        if (h == " ") p = p + " "; else
        if (h == "־" || h == "-") p = p + "-"; else
        if (h == ":") p = p + ". "; else

        // nekudot pronounces
        if (h == "ֵ") p = p + "ay"; else
        if (h == "ִ") p = p + "ee"; else
        if (h == "ֶ" | h == "ֱ" | h == "ֽ") p = p + "eh"; else
        if (h == "ּ") p = p + ""; else
        if (h == "ׁ") p = p + "h"; else
        if (h == "ֻ") p = p + "oo"; else
        if (h == "ֹ" | h == "ׄ") p = p + "oh"; else
        if (h == "ַ" | h == "ָ" | h == "ֳ" | h == "ֲ") p = p + "ah"; else
        if (h == "ְ" | h == "ׂ") p = p + "";
    }

    p = p + " ";

    // G-d name corrections
    p = p.replace("YHVahH","AhDohNai");

    // Vav corrections
    p = p.replace("V","oo");
    p = p.replace(" oo"," V");
    if (p.startsWith("oo"))
        p = p.replace(0,2,"V");

    // Multi-vowel corrections
    p = p.replace("aheh","ah");
    p = p.replace("ahah","ah");
    p = p.replace("oooh","oh");
    p = p.replace("eeeh","eh");

    return p;
}

int Program::saveDictionary(QString filename)
{
    QFile f(filename);
    if (!f.open(QIODevice::WriteOnly)) {
        QErrorMessage().showMessage("Failed.");
        return 1;
    }
    QDataStream s(&f);
    s << dictionary;
    f.close();
    return 0;
}

int Program::loadDictionary(QString filename)
{
    QFile f(filename);
    if (!f.open(QIODevice::ReadOnly)) {
        QErrorMessage().showMessage("Failed.");
        return 1;
    }
    QDataStream s(&f);
    s >> dictionary;
    f.close();
    return 0;
}

int Program::clearDict()
{
    // we place confirm dialog...
    QMessageBox *q = new QMessageBox();
    q->setText("Clear dictionary?");
    q->setInformativeText("You will lose all unsaved work.");
    q->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    q->setDefaultButton(QMessageBox::Ok);

    // yes? no?
    int _r = q->exec();
    if (_r == QMessageBox::Ok) {
        // clear the dictionary.
        dictionary.clear();
        return 0;
    }

    return 1;
}

///
/// \brief Program::present
/// \param input The root word
/// \return The translated text
///
QString Program::present(QString input, int mod)
{
    QString s;

    s = wordToRootForm(input);

    switch (mod) {
        // we add modifiers to the stack to form the fill translated word
        case AND:
            s = charToLetter("V") + s;
            break;
        case PLURFEM:
            s = s + charToLetter("V") + charToLetter("K");
            break;
        case PLURMASC:
            s = s + charToLetter("Y") + charToLetter("M");
        break;
        case NOT:

            break;
        case THEIR:

            break;
        case OUR:
            s = s + charToLetter("N") + charToLetter("V");
            break;
        case ITS:

            break;
        case YOUR:
            s = s + charToLetter("K");
            break;
        case PREP:
            s = charToLetter("B") + s;
            break;
        case THE:
            s = charToLetter("H") + s;
            break;
        case FORTO:
            s = charToLetter("L") + s;
            break;
        case FROM:
            s = charToLetter("M") + s;
            break;
        case TONOUN:
            s = charToLetter("M") + s;
            break;
        case TOPERSON:
            s = charToLetter("SH") + s;
            break;
        }
    return s;
}

QString Program::spell()
{
    QString r;
    bool ok;
    QString text = QInputDialog::getText(nullptr, "Add to Dictionary",
        "Characters:\nA B G D H V Z CH TS Y\nK L M N S AY P TZ Q R\nSH T _", QLineEdit::Normal,
        "", &ok);
    if (ok) {
        r = generateChars(text);
    }
    return r;
}

QList<QString> Program::getKeys()
{
    return dictionary.keys();
}

QString Program::getValue(QString key)
{
    return dictionary.value(key);
}

QString Program::getValue(int key)
{
    return dictionary.keys()[key];
}

QString Program::generateChars(QString shortChars) {
    QStringList chs = QStringList(shortChars.split(" "));
    QString w = "";
    for (QString str : chs) {
        w.append(charToLetter(str));
    }
    QChar c = w.back();
    if (c == "כ") w.replace(w.length()-1,1,"ך"); else
    if (c == "מ") w.replace(w.length()-1,1,"ם"); else
    if (c == "נ") w.replace(w.length()-1,1,"ן"); else
    if (c == "פ") w.replace(w.length()-1,1,"ף"); else
    if (c == "צ") w.replace(w.length()-1,1,"ץ");
    return w;

}

QString Program::charToLetter(QString ch)
{
    QString s = "-";
    if (ch == "A") return "א";
    if (ch == "B") return "ב";
    if (ch == "G") return "ג";
    if (ch == "D") return "ד";
    if (ch == "H") return "ה";
    if (ch == "V") return "ו";
    if (ch == "Z") return "ז";
    if (ch == "CH") return "ח";
    if (ch == "TS") return "ט";
    if (ch == "Y") return "י";
    if (ch == "K") return "כ";
    if (ch == "L") return "ל";
    if (ch == "M") return "מ";
    if (ch == "N") return "נ";
    if (ch == "S") return "ס";
    if (ch == "AY") return "ע";
    if (ch == "P") return "פ";
    if (ch == "TZ") return "צ";
    if (ch == "Q") return "ק";
    if (ch == "R") return "ר";
    if (ch == "SH") return "ש";
    if (ch == "T") return "ת";
    if (ch == "_") return " ";
    return s;
}

QString Program::numberToLetter(int number)
{
    QString s = "א";
    switch (number) {
        case 1: s = "א"; break;
        case 2: s = "ב"; break;
        case 3: s = "ג"; break;
        case 4: s = "ד"; break;
        case 5: s = "ה"; break;
        case 6: s = "ו"; break;
        case 7: s = "ז"; break;
        case 8: s = "ח"; break;
        case 9: s = "ט"; break;
        case 10: s = "י"; break;
        case 20: s = "כ"; break;
        case 30: s = "ל"; break;
        case 40: s = "מ"; break;
        case 50: s = "נ"; break;
        case 60: s = "ס"; break;
        case 70: s = "ע"; break;
        case 80: s = "פ"; break;
        case 90: s = "צ"; break;
        case 100: s = "ק"; break;
        case 200: s = "ר"; break;
        case 300: s = "ש"; break;
        case 400: s = "ת"; break;
    default: break;
    }
    return s;
}
