#ifndef QTDEFOLHAS_ARVORE_BINARIA_H
#define QTDEFOLHAS_ARVORE_BINARIA_H

/* -------------------------------------------*/
int quantidadeFolhas(pNohArvore raiz){

   if (raiz == NULL)
    return 0;

   if (raiz->esquerda == NULL && raiz->direita == NULL)
      return 1; /*  é uma folha */

   return quantidadeFolhas(raiz->esquerda) +
          quantidadeFolhas(raiz->direita);

}

#endif







