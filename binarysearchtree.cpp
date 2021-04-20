#include "binarysearchtree.h"

int _height(std::shared_ptr<ElementoArbolBinario> element) {
    if (element == nullptr) {
        return -1;
    }else{
        int height_left = _height(element->left);
        int height_right = _height(element->right);
        return 1 + std::max(height_left, height_right);
    }
}

int BinarySearchTree::heigh() const
{
    return _height(root);
}

int _size(std::shared_ptr<ElementoArbolBinario> element){
    if(element == nullptr){
        return 0;
    }else{
        int size_left = _size(element->left);
        int size_right = _size(element->right);
        return 1 + size_left + size_right;
    }
}

int BinarySearchTree::size() const
{
    return _size(root);
}

const TipoDato& _min(std::shared_ptr<ElementoArbolBinario> element){
    if(element->left != nullptr){
        return _min(element->left);
    }else{
        return element->dato;
    }
}

const TipoDato &BinarySearchTree::min() const
{
    return _min(root);
}

const TipoDato& _max(std::shared_ptr<ElementoArbolBinario> element){
    if(element->right != nullptr){
        return _max(element->right);
    }else{
        return element->dato;
    }
}

const TipoDato &BinarySearchTree::max() const
{
    return _max(root);
}

void inorder(std::shared_ptr<ElementoArbolBinario> element, std::function<void (TipoDato &)> action){
    if(element == nullptr){
        return;
    }

    inorder(element->right, action);
    action(element->dato);
    inorder(element->left, action);
}

void BinarySearchTree::dfs_inorder(std::function<void (/*const*/ TipoDato &)> action) /*const*/
{
    if(root == nullptr){
        return;
    }else{
        return inorder(root, action);
    }
}

void _for_each(std::shared_ptr<ElementoArbolBinario> element, std::function<void (TipoDato &)> action){
    if(element == nullptr){
        return;
    }

    action(element->dato);
    _for_each(element->left, action);
    _for_each(element->right, action);
}

void BinarySearchTree::for_each(std::function<void (TipoDato &)> action) const
{
    if (root == nullptr) {
        return;
    }else{
        return _for_each(root, action);
    }
}

const TipoDato &BinarySearchTree::find(int id) const
{
    auto elem = root;
    while(elem != nullptr){
        if(elem->dato.a == id){
            break;
        }else{
            elem = (id < elem->dato.a) ? elem->left : elem->right;
        }
    }
    return elem->dato;
}


bool _find(std::shared_ptr<ElementoArbolBinario> element, const TipoDato& dato) {
    // Handle corner case
    if (element == nullptr) {
        return false;
    }

    // Do actual work
    if (element->dato.a > dato.a) {
        return _find(element->left, dato);
    }else if (element->dato.a < dato.a) {
        return _find(element->right, dato);
    }else{
        return element->dato.a == dato.a;
    }
}

bool BinarySearchTree::find(const TipoDato &dato) const
{
    return _find(root, dato);
}

void BinarySearchTree::push(const TipoDato &dato)
{
    std::shared_ptr<ElementoArbolBinario> iterador = root;

    if(root == nullptr){
        root = std::make_shared<ElementoArbolBinario>(ElementoArbolBinario{dato});
    }

    BinarySearchTree notRoot;
    notRoot.root = std::make_shared<ElementoArbolBinario>(ElementoArbolBinario{dato});

    while(iterador != nullptr){
        if(dato.a > iterador->dato.a){
            if(iterador->right == nullptr){
                iterador->right = notRoot.root;
            }
            iterador = iterador->right;
        }else if(dato.a < iterador->dato.a){
            if(iterador->left == nullptr){
                iterador->left = notRoot.root;
            }
            iterador = iterador->left;
        }else{
            break;
        }
    }
}

void BinarySearchTree::remove(const TipoDato &dato){
    // Find the element (keep a reference to its parent)
    auto elem = root;
    std::shared_ptr<ElementoArbolBinario> parent = nullptr;
    while (elem != nullptr) {
        if (elem->dato.a == dato.a) {
            break;
        }
        parent = elem;
        elem = (dato.a < elem->dato.a) ? elem->left : elem->right;
    }
    // If not found, nothing to do
    if (elem == nullptr) {
        return;
    }
    // If it has two childs, replace with the max element in the subtree
    if (elem->left != nullptr && elem->right != nullptr) {
        elem->dato = _max(elem->left);
        // Now the element to remove is the one at that max position
        parent = elem;
        elem = elem->left;
        while (elem->right != nullptr) {
            parent = elem;
            elem = elem->right;
        }
    }

    // Now the node to remove only has 1 or 0 childs
    auto next = (elem->left != nullptr) ? elem->left : elem->right;
    if (parent == nullptr) {
        root = next;
    }else{
        if (parent->left == elem) {
            parent->left = next;
        }else{
            parent->right = next;
        }
    }
}

/*
void _push(std::shared_ptr<ElementoArbolBinario>& element, // Note the reference
           const TipoDato& dato) {
    // Handle corner case
    if (element == nullptr) {
        element = std::make_shared<ElementoArbolBinario>(dato);
        return;
    }

    // Do actual work
    if (element->dato > dato) {
        _push(element->left, dato);
    }
    else if (element->dato < dato) {
        _push(element->right, dato);
    }
    else {
        // It is a duplicated element! Do nothing, raise exception,...
    }
}

void BinarySearchTree::push(const TipoDato& dato) {
    return _push(root, dato);
}
*/
