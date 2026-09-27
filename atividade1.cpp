#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node* proximo;
};

int tamanho(Node* inicio) {
    int contador = 0;

    while (inicio != null) {
        contador++;
        inicio = inicio->proximo;
    }

    return contador;
}

void remover(Node*& inicio, int posicao) {

    if (inicio == null) {
        return;
    }

    if (posicao == 0) {
        Node* temp = inicio;
        inicio = inicio->proximo;
        delete temp;
        return;
    }

    Node* atual = inicio;

    for (int i = 0; i < posicao - 1; i++) {
        if (atual->proximo == null) {
            return;
        }

        atual = atual->proximo;
    }

    if (atual->proximo == null) {
        return;
    }

    Node* temp = atual->proximo;
    atual->proximo = temp->proximo;

    delete temp;
}

int main() {

    Node* n1 = new Node{10, null};
    Node* n2 = new Node{20, null};
    Node* n3 = new Node{30, null};
    Node* n4 = new Node{40, null};

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