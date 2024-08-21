#include "AVL.h"
#include <iostream>

void add(int &x)
{
    x += 5;
    std::cout << x << " ";    
}

void sub(int &x)
{
    x -= 3;
    std::cout << x << " ";    
}

void mul(int &x)
{
    x *= 2;
    std::cout << x << " ";    
}

int main()
{
    my_std::AVL<int> obj;
    obj.insert(60);
    obj.insert(40);
    obj.insert(80);
                                
    std::cout << obj.get_height() << std::endl;
    obj.insert(30);
    obj.insert(50);
    obj.insert(70);
    obj.insert(90);

    obj.inorder(&add);
    obj.postorder();
    obj.preorder();

    obj.preorder(&mul);
    obj.postorder();
    obj.preorder();

    obj.postorder(&sub);
    obj.postorder();
    obj.preorder();

    obj.level_order(&sub);
    obj.postorder();
    obj.preorder();
    std::cout << "Size of obj: " << obj.get_number_of_nodes() << std::endl;

    my_std::AVL<int> obj2(obj);
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

    obj.preorder(&mul);

    obj2.inorder();

    obj2 = obj;

    obj.preorder(&sub);

    obj2.inorder();

    my_std::AVL<int> obj3 = std::move(obj);
    obj3.insert(412);

    obj3.postorder();

    obj3 = {15,25,3,4,9,7,5,8};
    obj3.level_order();

}