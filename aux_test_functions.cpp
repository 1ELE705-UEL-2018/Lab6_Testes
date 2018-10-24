#include "gtest/gtest.h"
#include "aux_test_functions.h"

int intcmp(void* arg1, void* arg2)
{
	int* a1 = (int*)arg1;
	int* a2 = (int*)arg2;

	return *a1 - *a2;
}

int inthash(const void* dado, int n)
{
	int* d = (int*)dado;

	return *d % n;
}

void aux_ll_preencher(struct lld* ll, int(*compar)(void*, void*), int dados[], int tam_lista, struct lld_el* elementos[])
{
	int i;

	ll->compar = compar;

	for (i = 0; i < tam_lista; i++)
	{
		elementos[i] = NULL;
	}

	if (tam_lista == 0)
	{
		ll->inicio = ll->fim = NULL;
		return;
	}
	else
	{
		elementos[0] = (struct lld_el*)malloc(sizeof(struct lld_el));
		elementos[tam_lista - 1] = (struct lld_el*)malloc(sizeof(struct lld_el));
		ll->inicio = elementos[0];
		ll->fim = elementos[tam_lista - 1];
	}

	if (tam_lista > 1)
	{
		if (elementos[1] == NULL)
		{
			elementos[1] = (struct lld_el*)malloc(sizeof(struct lld_el));
		}
		elementos[0]->prox = elementos[1];

		for (i = 1; i < tam_lista - 1; i++)
		{
			elementos[i]->ant = elementos[i - 1];
			elementos[i]->dado = &dados[i];
			if (elementos[i + 1] == NULL)
			{
				elementos[i + 1] = (struct lld_el*)malloc(sizeof(struct lld_el));
			}
			elementos[i]->prox = elementos[i + 1];
		}

		elementos[tam_lista - 1]->ant = elementos[tam_lista - 2];
	}

	elementos[0]->ant = NULL;
	elementos[0]->dado = &dados[0];
	elementos[tam_lista - 1]->dado = &dados[tam_lista - 1];
	elementos[tam_lista - 1]->prox = NULL;
}

int aux_ll_consistente(const struct lld* ll)
{
	struct lld_el* el;
	struct lld_el* el_ant = NULL;
	struct lld_el* el_prox = NULL;

	int i;

	if (ll->inicio && ll->inicio->ant != NULL)
	{
		return -2;
	}

	if (ll->fim && ll->fim->prox != NULL)
	{
		return -3;
	}

	for (i = 0, el = ll->inicio; el != NULL; el = el->prox)
	{
		if (el->prox && el->prox->ant != el)
		{
			return i;
		}

		i++;

		el_ant = el;
	}

	if (el_ant != ll->fim)
	{
		return -4;
	}

	return -1;
}

int aux_ll_iguais(const struct lld* ll1, const struct lld* ll2)
{
	int i = 0;

	struct lld_el *el1, *el2;

	if (ll1->compar != ll2->compar)
	{
		return -2;
	}

	el1 = ll1->inicio;
	el2 = ll2->inicio;

	while (el1 != NULL && el2 != NULL)
	{
		if (ll1->compar(el1->dado, el2->dado) != 0)
		{
			return i;
		}

		el1 = el1->prox;
		el2 = el2->prox;
		i++;
	}

	if (el1 != el2)
	{
		return -3;
	}

	return -1;
}

void aux_ll_limpar(struct lld* ll)
{
	struct lld_el* el = ll->inicio;

	while (el != NULL)
	{
		struct lld_el* aux = el->prox;
		free(el);
		el = aux;
	}
}

void aux_ht_preencher(struct ht* h, int tam_array, int(*compar)(void*, void*), int(*hash)(const void*, int), int dados[], int tam_dados)
{
	int i, j;

	if (tam_array == 0)
	{
		h->tam_array = 8;
	}
	else
	{
		h->tam_array = tam_array;
	}

	h->hash = hash;
	h->array_ll = (struct lld*)malloc(h->tam_array*sizeof(struct lld));

	for (i = 0; i < h->tam_array; i++)
	{
		int* ll_dados = NULL;
		int tam_lista = 0;
		struct lld_el** elementos = NULL;

		for (j = 0; j < tam_dados; j++)
		{
			if (h->hash(&dados[j], h->tam_array) == i)
			{
				tam_lista++;
			}
		}

		if (tam_lista > 0)
		{
			int k = 0;

			ll_dados = (int*)malloc(tam_lista*sizeof(int));
			elementos = (struct lld_el**)malloc(tam_lista*sizeof(struct lld_el*));

			for (j = 0; j < tam_dados; j++)
			{
				if (h->hash(&dados[j], h->tam_array) == i)
				{
					ll_dados[k++] = dados[j];
				}
			}
		}

		aux_ll_preencher(&h->array_ll[i], compar, ll_dados, tam_lista, elementos);
	}
}

int aux_ht_consistente(const struct ht* h)
{
	int i;
	struct lld_el* el;

	for (i = 0; i < h->tam_array; i++)
	{
		switch (aux_ll_consistente(&h->array_ll[i]))
		{
			case -1:
				break;

			default:
				return i;
		}
	}

	for (i = 0; i < h->tam_array; i++)
	{
		el = h->array_ll[i].inicio;
		while (el)
		{
			if (h->hash(el->dado, h->tam_array) != i)
			{
				return i;
			}

			el = el->prox;
		}
	}

	return -1;
}

int aux_ht_iguais(const struct ht* h1, const struct ht* h2)
{
	int i;

	if (h1->tam_array != h2->tam_array)
	{
		return -2;
	}

	if (h1->hash != h2->hash)
	{
		return -3;
	}

	for (i = 0; i < h1->tam_array; i++)
	{
		switch (aux_ll_iguais(&h1->array_ll[i], &h2->array_ll[i]))
		{
			case -1:
				break;

			case -2:
				return -4;

			default:
				return i;
		}
	}

	return -1;
}

int aux_ht_contem_mesmos_elementos(const struct ht* h1, const struct ht* h2)
{
	int i;

	for (i = 0; i < h1->tam_array; i++)
	{
		struct lld_el* el = h1->array_ll[i].inicio;

		while (el != NULL)
		{
			struct lld_el* el2 = ll_buscar(&h2->array_ll[h2->hash(el->dado, h2->tam_array)], el->dado);

			if (el2 == NULL || h1->array_ll[0].compar(el->dado, el2->dado) != 0)
			{
				return 0;
			}

			el = el->prox;
		}
	}

	for (i = 0; i < h2->tam_array; i++)
	{
		struct lld_el* el = h2->array_ll[i].inicio;

		while (el != NULL)
		{
			struct lld_el* el2 = ll_buscar(&h1->array_ll[h1->hash(el->dado, h1->tam_array)], el->dado);

			if (el2 == NULL || h2->array_ll[0].compar(el->dado, el2->dado) != 0)
			{
				return 0;
			}

			el = el->prox;
		}
	}
	return 1;
}

void aux_ht_limpar(struct ht* h)
{
	int i;

	for (i = 0; i < h->tam_array; i++)
	{
		aux_ll_limpar(&h->array_ll[i]);
	}

	free(h->array_ll);
}

int memoria_foi_liberada(void* arg, int tam)
{
	int i;
	unsigned char* arg_char = (unsigned char*)arg;
	for (i = 0; i < tam; i++)
	{
		if (arg_char[i] != 0xDD)
		{
			return 0;
		}
	}

	return 1;
}

::testing::AssertionResult LinkedListInitialized(const struct lld* ll, int (*compar)(void*, void*))
{
	if (ll == NULL)
	{
		return ::testing::AssertionFailure() << "ll == NULL";
	}

	if (ll->inicio != NULL)
	{
		return ::testing::AssertionFailure() << "ll->inicio != NULL";
	}

	if (ll->fim != NULL)
	{
		return ::testing::AssertionFailure() << "ll->fim != NULL";
	}

	if (ll->compar != compar)
	{
		return ::testing::AssertionFailure() << "ll->compar != compar";
	}

	return ::testing::AssertionSuccess();
}

::testing::AssertionResult LinkedListConsistent(const struct lld* ll)
{
	int res = aux_ll_consistente(ll);

	switch (res)
	{
		case -1:
			return ::testing::AssertionSuccess();
		case -2:
			return ::testing::AssertionFailure() << "ll->inicio->ant != NULL";
		case -3:
			return ::testing::AssertionFailure() << "ll->fim->prox != NULL";
		case -4:
			return ::testing::AssertionFailure() << "Ultimo elemento da lista != ll->fim";
		default:
			return ::testing::AssertionFailure() << "Inconsistencia na posicao " << res << " da lista: el->prox->ant != el ou el->ant->prox != e";
	}
}

::testing::AssertionResult LinkedListsMatch(const struct lld* ll1, const struct lld* ll2)
{
	int res = aux_ll_iguais(ll1, ll2);

	switch (res)
	{
		case -1:
			return ::testing::AssertionSuccess();
		case -2:
			return ::testing::AssertionFailure() << "Funcoes de comparacao diferentes";
		case -3:
			return ::testing::AssertionFailure() << "Tamanho das listas diferente";
		default:
			return ::testing::AssertionFailure() << "Elemento na posicao " << res << " diferente entre as duas listas";
	}
}

::testing::AssertionResult HashTableConsistent(const struct ht* h)
{
	int res = aux_ht_consistente(h);

	switch (res)
	{
		case -1:
			return ::testing::AssertionSuccess();
		default:
			return ::testing::AssertionFailure() << "Inconsistencia na lista de indice " << res << "; por exemplo, elemento armazenado em lista diferente do valor da funcao de hash";
	}
}

::testing::AssertionResult HashTablesMatch(const struct ht* h1, const struct ht* h2)
{
	int res = aux_ht_iguais(h1, h2);

	switch (res)
	{
		case -1:
			return ::testing::AssertionSuccess();
		case -2:
			return ::testing::AssertionFailure() << "Tamanho do array de listas ligadas diferente";
		case -3:
			return ::testing::AssertionFailure() << "Funcao de hash diferente";
		case -4:
			return ::testing::AssertionFailure() << "Funcao de comparacao diferente";
		default:
			return ::testing::AssertionFailure() << "Diferenca nas listas de indice " << res;
	}
}
