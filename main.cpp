#include <iostream>
#include "binarysearchtree.h"

using namespace std;

int main()
{
    TipoDato uno{1};
    TipoDato dos{2};
    TipoDato tres{3};
    TipoDato cuatro{4};
    TipoDato cinco{5};

    BinarySearchTree arbol;

    arbol.push(tres);
    arbol.push(dos);
    arbol.push(cuatro);
    arbol.push(uno);
    arbol.push(cinco);

    cout << "Max: " << arbol.max().a << " Min: " << arbol.min().a << endl;

    arbol.dfs_inorder([] (TipoDato& dato){
        cout << dato.a << " ";
    });

    cout << endl;

    arbol.for_each([] (TipoDato& dato){
        cout << dato.a << " ";
    });

    cout << endl << arbol.heigh() << " " << arbol.size() << endl;

    cout << "Find: " << arbol.find(2).a << endl;

    if(arbol.find(tres) == true){
        cout << "Tres si" << endl;
    }else{
        cout << "Tres no" << endl;
    }

    return 0;
}
