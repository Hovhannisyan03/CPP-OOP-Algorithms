#include "text_editor.h"

int main()
{
    text_editor editor;

    editor.type("Text1");
    editor.view();

    editor.type(" Text2");
    editor.view();

    editor.type(" Text3 Text4 Text5");
    editor.view();

    editor.undo();
    editor.view();

    editor.undo();
    editor.view();

    editor.redo();
    editor.view();

    editor.redo();
    editor.view();
}