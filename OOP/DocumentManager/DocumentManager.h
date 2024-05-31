#ifndef DocumentManager_H
#define DocumentManager_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class DocumentManager
{
    public:
        void menu();
        void createDocument();
        void editDocument();
        void viewDocument();
        void showDocuments();
    private:
        std::vector<std::string> allFiles;
};

#endif