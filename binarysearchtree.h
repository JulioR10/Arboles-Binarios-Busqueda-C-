#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "elementoarbolbinario.h"
#include <functional>

class BinarySearchTree
{
private:
    std::shared_ptr<ElementoArbolBinario> root = nullptr;

public:
    BinarySearchTree():root{nullptr}{};  // Creates empty tree
    BinarySearchTree(const TipoDato& dato):root{std::make_shared<ElementoArbolBinario>(ElementoArbolBinario{dato})}{};

    int heigh() const;
    int size() const; // Number of nodes

    const TipoDato& min() const;
    const TipoDato& max() const;

    void dfs_inorder(std::function<void(/*const*/ TipoDato&)> action) /*const*/;
    void for_each(std::function<void (TipoDato&)> action) const;  // Visit all the nodes

    const TipoDato& find(int id) const; // Return the employee with the given id
    bool find(const TipoDato&) const;
    void push(const TipoDato&);
    void remove(const TipoDato&);
};

#endif // BINARYSEARCHTREE_H
