#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node* proximo;
};

int encontrarMeio(Node* inicio) {
    Node* lento = inicio;
    Node* rapido = inicio;

    while (rapido != NULL && rapido->proximo != NULL) {
        lento = lento->proximo;
        rapido = rapido->proximo->proximo;
    }

    return lento->valor;
}

bool procurar(Node* inicio, int valorProcurado) {
    Node* atual = inicio;

    while (atual != NULL) {
        if (atual->valor == valorProcurado) {
            return true;
        }

        atual = atual->proximo;
    }

    return false;
}

int main() {

    Node* n1 = new Node{1, NULL};
    Node* n2 = new Node{2, NULL};
    Node* n3 = new Node{3, NULL};
    Node* n4 = new Node{4, NULL};
    Node* n5 = new Node{5, NULL};
    Node* n6 = new Node{6, NULL};

    n1->proximo = n2;
    n2->proximo = n3;
    n3->proximo = n4;
    n4->proximo = n5;
    n5->proximo = n6;

    Node* inicio = n1;

    cout << "Valor do meio: " << encontrarMeio(inicio) << endl;

    cout << "Procurando o valor 4: ";

    if (procurar(inicio, 4)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    cout << "Procurando o valor 10: ";

    if (procurar(inicio, 10)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}