#include "editorSubject.hpp"
#include "emailAlertListener.hpp"
#include "loggingListenerhpp"

int main()
{
    EditorSubject editor;

    EmailAlertLisner emailAlertLisner("emailAlertLisner");
    LoggingLisner loggerLisner("loggerLisner");

    editor.attach(&emailAlertLisner);
    editor.attach(&loggerLisner);

    editor.notify();
    return 0;
}