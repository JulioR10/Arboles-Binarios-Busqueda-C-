#ifndef ELEMENTOARBOLBINARIO_H
#define ELEMENTOARBOLBINARIO_H
#include "tipodato.h"
#include <memory>

class ElementoArbolBinario
{
public:
    // Members
    TipoDato dato;
    std::shared_ptr<ElementoArbolBinario> left = nullptr;
    std::shared_ptr<ElementoArbolBinario> right = nullptr;
public:
    // Constructor
    ElementoArbolBinario(const TipoDato& dato_) : dato{dato_} {};
};

#endif // ELEMENTOARBOLBINARIO_H
