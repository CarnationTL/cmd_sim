#include "completer.h"
#define EXE_SUCCESS 0
#define EXE_FAIL -1
/**
  completer the signal select...
*/
Completer::Completer(QObject *parent) :
    QObject(parent) {
}

//QStringList wordList;
// wordList << "alpha" << "omega" << "omicron" << "zeta";
//
// QLineEdit *lineEdit = new QLineEdit(this);
//
// QCompleter *completer = new QCompleter(wordList, this);
// completer->setCaseSensitivity(Qt::CaseInsensitive);
// lineEdit->setCompleter(completer);
//
int Completer::addWordList(QString word) {
    _wordlist << word;
    return EXE_SUCCESS;
}

int Completer::delWordList(QString word) {
    if(word.length() <= 0)
        return -1;

    return 0;
}

int Completer::clearWordList() {
    if(_wordlist.size() > 0) {
        _wordlist.clear();
    }

}

int Completer::updateCompeleter() {
    return 0;
}

/**
  addch string
*/
int Completer::attchCompeleter(QStringList &_wStringlist) {

}
