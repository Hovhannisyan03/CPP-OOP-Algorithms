#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include "../stack.h"
class text_editor
{
    public:
        text_editor();
        void type(std::string text);
        void undo();
        void redo();
        void view() const;
    private:
        my_std::stack<std::string> m_undo;
        my_std::stack<std::string> m_redo;
        std::string m_text;
};

#endif