#include "DocumentManager.h"

void DocumentManager::menu()
{
    std::cout << "-------------------------" << std::endl;
    std::cout << "| DOCUMENT MANAGMENT SYSTEM |" << std::endl;
    std::cout << "-------------------------" << std::endl;
    while(1)
    {
        std::cout << "----------------------" << std::endl;     
        std::cout << "| 1. Create Document |" << std::endl;
        std::cout << "| 2. Edit Document   |" << std::endl;
        std::cout << "| 3. View Document   |" << std::endl;
        std::cout << "| 4. Show Document   |" << std::endl;
        std::cout << "| 5. Exit            |" << std::endl;
        std::cout << "----------------------" << std::endl;     

        char choose;
        std::cout << "=== Enter your choose: ";
        std::cin >> choose;
        switch(choose)
            {
            case '1':
            {   
                createDocument();
                break;
            }
            case '2':
            {
                editDocument();
                break;
            }
            case '3':
            {
                viewDocument();
                break;
            }
            case '4':
            {
                showDocuments();
                break;
            }
            case '5':
            {
                std::cout << "-----------------------" << std::endl;
                std::cout << "| The program is over |" << std::endl;
                std::cout << "-----------------------" << std::endl;
                return;
            }
            default:
            {
                std::cout << "=== Invalid input ===" << std::endl;
            }
        }
    }
    return;
}

void DocumentManager::createDocument()
{
    std::string fileName;    
    std::cout << "=== Enter document name: ";
    std::cin >> fileName;

    if(0 == allFiles.size())
    {
        allFiles.push_back(fileName);
        std::ofstream file(fileName);
        std::cout << "=== Document " << fileName << " created successfully ===" << std::endl;
        return;
    }
    
    for(auto elem : allFiles)
    {
        if(elem == fileName)
        {
            std::cout << "=== A document with that name already exists ===" << std::endl;
            std::cout << "=== View document list ? (Y/N): ";
            std::string ch;
            std::cin >> ch;
            if(ch == "Y" || ch == "y" || ch == "Yes" || ch == "YES" || ch == "yes")
            {
                showDocuments();
            }
            return;
        }
    }

    allFiles.push_back(fileName);
    std::ofstream file(fileName);
    std::cout << "=== Document " << fileName << " created successfully ===" << std::endl;
    return;
}

void DocumentManager::editDocument()
{
    if(0 == allFiles.size())
    {
        std::cout << "=== Document list is empty ===" << std::endl;
        return;
    }

    std::string ch = "Yes";
    std::string fileName;
    std::fstream file;
    while(ch == "Y" || ch == "y" || ch == "Yes" || ch == "YES" || ch == "yes")
    {
        std::cout << "=== Enter document name: ";
        std::cin >> fileName;
        int count = 0;
        for(auto elem : allFiles)
        {
            if(elem == fileName)
            {
                ++count;
                std::string ch1 = "Yes";
                while(ch1 == "Y" || ch1 == "y" || ch1 == "Yes" || ch1 == "YES" || ch1 == "yes")
                {
                    std::cout << "------------------------" << std::endl;
                    std::cout << "| 1. Write new contents|" << std::endl;
                    std::cout << "| 2. Append contents   |" << std::endl;
                    std::cout << "------------------------" << std::endl;
                    char choose;
                    std::cout << "=== Enter your choose: ";
                    std::cin >> choose;
                    switch(choose)
                    {
                        case '1':
                        {   
                            std::string contents = "";
                            std::cout << "=== Enter contents: ";
                            std::cin.get();
                            std::getline(std::cin,contents);
                            file.open(fileName, std::ios::out);
                            file << contents << std::endl;
                            file.close();
                            std::cout << "=== Content added to " << fileName << " ===" << std::endl;
                            break;
                        }
                        case '2':
                        {
                            std::string contents = "";
                            std::cout << "=== Enter contents: ";
                            std::cin.get();
                            std::getline(std::cin,contents);
                            file.open(fileName, std::ios::app);
                            file << contents << std::endl;
                            file.close();
                            std::cout << "=== Content added to " << fileName << " ===" << std::endl;
                            break;
                        }
                        default:
                        {
                            std::cout << "=== Invalid input ===" << std::endl;
                        }
                    }
                    std::cout << "=== Continue editing " << fileName << " document ? (Y/N): ";
                    std::cin >> ch1;    
                }
            }
        }
        if(count == 0)
        {
            std::cout << "=== Invalid document name ===" << std::endl;
            std::cout << "=== View document list ? (Y/N): ";
            std::string ch2;
            std::cin >> ch2;
            if(ch2 == "Y" || ch2 == "y" || ch2 == "Yes" || ch2 == "YES" || ch2 == "yes")
            {
                showDocuments();
            }
        }
        std::cout << "=== Continue edit documents ? (Y/N): ";
        std::cin >> ch;
    }
    return;
}

void DocumentManager::viewDocument()
{
    if(0 == allFiles.size())
    {
        std::cout << "=== Document list is empty ===" << std::endl;
        return;
    }

    std::string ch = "Yes";
    while(ch == "Y" || ch == "y" || ch == "Yes" || ch == "YES" || ch == "yes")
    {
        int count = 0;
        std::string fileName;
        std::cout << "=== Enter document name: ";
        std::cin >> fileName;
        std::fstream file;
        for(auto elem : allFiles)
        {
            if(elem == fileName)
            {   
                ++count;
                file.open(fileName, std::ios::in);
                std::string line;
                std::cout << "=== Document contents ===" << std::endl;
                while(getline(file, line))
                {
                    std::cout << line;
                }
                file.close();
                std::cout << std::endl;
            }
        }
        if(count == 0)
        {
            std::cout << "=== Invalid document name ===" << std::endl;
            std::cout << "=== View document lists ? (Y/N): ";
            std::string ch1;
            std::cin >> ch1;
            if(ch1 == "Y" || ch1 == "y" || ch1 == "Yes" || ch1 == "YES" || ch1 == "yes")
            {
                showDocuments();
            }
        }
        std::cout << "=== Continue view documents ? (Y/N): ";
        std::cin >> ch;
    }

    return;
}

void DocumentManager::showDocuments()
{
    if(0 == allFiles.size())
    {
        std::cout << "=== Document list is empty ===" << std::endl;
        return;
    }
    std::cout << "=== All Documents ===" << std::endl;
    for(auto elem : allFiles)
    {
        std::cout << elem << std::endl;
    }
    return;
}