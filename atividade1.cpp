#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node* proximo;
};

// Tamanho da lista
int tamanho(Node* inicio) {
    int contador = 0;

    while (inicio != NULL) {
        contador++;
        inicio = inicio->proximo;
    }

    return contador;
}

// Remover em qualquer posição
void remover(Node*& inicio, int posicao) {

    if (inicio == NULL) {
        return;
    }

    // Remover o primeiro elemento
    if (posicao == 0) {
        Node* temp = inicio;
        inicio = inicio->proximo;
        delete temp;
        return;
    }

    Node* atual = inicio;

    // Encontrar o elemento anterior
    for (int i = 0; i < posicao - 1; i++) {
        if (atual->proximo == NULL) {
            return;
        }

        atual = atual->proximo;
    }

    if (atual->proximo == NULL) {
        return;
    }

    Node* temp = atual->proximo;
    atual->proximo = temp->proximo;

    delete temp;
}

int main() {

    Node* n1 = new Node{10, NULL};
    Node* n2 = new Node{20, NULL};
    Node* n3 = new Node{30, NULL};
    Node* n4 = new Node{40, NULL};

    n1->proximo = n2;
    n2->proximo = n3;
    n3->proximo = n4;

    Node* inicio = n1;

    cout << "Tamanho: " << tamanho(inicio) << endl;

    remover(inicio, 2);

    cout << "Tamanho depois da remocao: "
         << tamanho(inicio) << endl;

    return 0;
}