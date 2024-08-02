#include "BST.h"
#include <iostream>

int main()
{
    my_std::binary_search_tree<int> obj;
    std::cout << obj.get_height() << std::endl;
    obj.insert(60);
    obj.insert(40);
    obj.insert(80);

    std::cout << obj.get_height() << std::endl;
    obj.insert(30);
    obj.insert(50);
    obj.insert(70);
    obj.insert(90);
    std::cout << "Size of obj: " << obj.get_number_of_nodes() << std::endl;

    my_std::binary_search_tree<int> obj2(obj);
    obj2.remove(90);
    obj2.insert(156);

    std::cout << obj.get_height() << std::endl;
    std::cout << obj2.get_height() << std::endl;

    obj.insert(51);
    obj.insert(52);
    obj.insert(53);
    obj.insert(54);
    obj.insert(55);
    std::cout << obj.get_height() << std::endl;

    obj.inorder(0);

    obj.preorder();
    obj.postorder();

    obj2.inorder();

    obj2.preorder(0);

    obj2.postorder(0);

    obj2 = obj;

    obj.inorder(0);
    obj.preorder();
    obj.postorder();

    obj2.inorder();
    obj2.preorder(0);
    obj2.postorder(0);

    my_std::binary_search_tree<int> obj3 = std::move(obj);
    obj3.insert(412);

    obj.inorder(0);
    obj.preorder(0);
    obj.postorder(0);

    obj2.inorder(0);
    obj2.preorder(0);
    obj2.postorder(1);

    obj3.inorder(0);
    obj3.preorder(1);
    obj3.postorder(0);

    obj3 = {15,25,3,4,9,7,5,8};
    obj3.inorder(0);
    obj3.preorder(1);
    obj3.postorder(1);

}