#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

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
	// se a lista j� possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
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
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
		return;
	}

	if (novo->valor < primeiro->valor)
	{
		if (novo->valor == primeiro->valor)
		{
			free(novo);
			return;
		}
		novo->prox = primeiro;
		primeiro = novo;
		return;
	}

	NO* aux = primeiro;
	NO* anteriror = NULL;

	while (aux != NULL)
	{
		if (aux->valor == novo->valor)
		{
			free(novo);
			return;
		}
		if (aux->valor > novo->valor)
		{
			anterior = aux;
			aux = aux->prox;
		}
	}

	novo->prox = aux;
	if (anterior != NULL)
	{
		anterior->prox = novo;
	}
}

void excluirElemento()
{
	int valor;
	cout << "Digite o elemnto a ser excluido: ";
	cin >> valor;

	NO* aux = primeiro;
	NO* anterior = NULL;

	while (aux != NULL)
	{
		if (aux->valor == valor)
		{
			break;

		}
		anterior = aux;
		aux = aux->prox;
	}

	if (aux != NULL)
	{
		if (anterior == NULL)
		{
			primeiro = aux->prox;
		}
		else {
			anterior->prox = aux->prox;
		}
		free(aux);
	}
}

void buscarElemento()
{
	int valor;
	cout << "Digite o elemento a ser buscado: ";
	cin >> valor;

	NO* aux = primeiro;

	while (aux != NULL)
	{
		if (aux->valor == valor)
		{
			cout << "Elemento encontrado: " << valor << endl;
			return;
		}
		if (aux->valor > valor)
		{
			break;
		}
		aux = aux->prox;
	}

	cout << "Elemento n�o encontrado " << valor << endl;

