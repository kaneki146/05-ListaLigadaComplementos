#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	ultimo = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	NO* atual = primeiro;
	NO* anterior = NULL;
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	while (atual != NULL && atual->valor < novo->valor) {
		anterior = atual;
		atual = atual->prox;
	}

	if (atual != NULL && atual->valor == novo->valor) {
		cout << "O valor ja existe" << endl;
		free(novo);
		return;
	}

	novo->prox = atual;

	if (anterior == NULL) {
		primeiro = novo;
	}
	else {
		anterior->prox = novo;
	}
	if (atual == NULL) {
		ultimo = novo;
	}
}

void excluirElemento()
{
	NO* atual = primeiro;
	NO* anterior = NULL;
	int valor;
	cout << "Digite o valor que deseja excluir" << endl;
	cin >> valor;
	while (atual != NULL && atual->valor < valor) {
		anterior = atual;
		atual = atual->prox;
	}
	if (atual == NULL) {
		cout << "Valor nao encontrado" << endl;
		return;
	}
	if (atual->valor > valor) {
		cout << "Valor nao encontrado" << endl;
		return;
	}
	if (anterior == NULL) {
		primeiro = atual->prox;
	}
	else {
		anterior->prox = atual->prox;
	}
	if (atual == ultimo) {
		ultimo = anterior;
	}
	free(atual);
}

void buscarElemento()
{
	NO* aux = primeiro;
	int valor = 0;
	cout << "Digite o numero que deseja encontrar" << endl;
	cin >> valor;

	while (aux != NULL) {
		if (aux->valor == valor) {
			cout << "Numero encontrado" << endl;
			return;
		}
		if (aux->valor > valor) {
			cout << "Numero nao encontrado" << endl;
			return;
		}
		aux = aux->prox;
	}

	cout << "Numero nao encontrado" << endl;
}


