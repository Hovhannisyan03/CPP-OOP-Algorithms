#include "text_editor.h"

text_editor::text_editor() : m_undo(),m_redo(),m_text(""){}

void text_editor::type(std::string text)
{
    m_undo.push(m_text);
    m_text += text;
    while (!m_redo.empty()) 
    {
        m_redo.pop();
    }
}

void text_editor::undo()
{
    if(m_undo.empty())
    {
        return;
    }
    m_redo.push(m_text);
    m_text = m_undo.top();
    m_undo.pop();
}

void text_editor::redo()
{
    if(m_redo.empty())
    {
        return;
    }
    m_undo.push(m_text);
    m_text = m_redo.top();
    m_redo.pop();
}

void text_editor::view() const
{
    std::cout << m_text << std::endl;
}