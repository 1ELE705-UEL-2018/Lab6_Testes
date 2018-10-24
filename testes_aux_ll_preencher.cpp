#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(aux_ll_preencher, ListaVazia)
{
	struct lld ll;

	aux_ll_preencher(&ll, intcmp, NULL, 0, NULL);

	ASSERT_EQ(NULL, ll.inicio);
	ASSERT_EQ(NULL, ll.fim);
	ASSERT_EQ(&intcmp, ll.compar);

	aux_ll_limpar(&ll);
}

TEST(aux_ll_preencher, ListaUmElemento)
{
	struct lld ll;
	int dados[1] = { 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(elementos[0], ll.inicio);
	ASSERT_EQ(elementos[0], ll.fim);
	ASSERT_EQ(&intcmp, ll.compar);

	ASSERT_EQ(NULL, elementos[0]->ant);
	ASSERT_EQ(&dados[0], elementos[0]->dado);
	ASSERT_EQ(NULL, elementos[0]->prox);

	aux_ll_limpar(&ll);
}

TEST(aux_ll_preencher, ListaDoisElementos)
{
	struct lld ll;
	int dados[2] = { 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(elementos[0], ll.inicio);
	ASSERT_EQ(elementos[1], ll.fim);
	ASSERT_EQ(&intcmp, ll.compar);

	ASSERT_EQ(NULL, elementos[0]->ant);
	ASSERT_EQ(&dados[0], elementos[0]->dado);
	ASSERT_EQ(elementos[1], elementos[0]->prox);

	ASSERT_EQ(elementos[0], elementos[1]->ant);
	ASSERT_EQ(&dados[1], elementos[1]->dado);
	ASSERT_EQ(NULL, elementos[1]->prox);

	aux_ll_limpar(&ll);
}

TEST(aux_ll_preencher, ListaTresElementos)
{
	struct lld ll;
	int dados[3] = { 1, 2, 3 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(elementos[0], ll.inicio);
	ASSERT_EQ(elementos[2], ll.fim);
	ASSERT_EQ(&intcmp, ll.compar);

	ASSERT_EQ(NULL, elementos[0]->ant);
	ASSERT_EQ(&dados[0], elementos[0]->dado);
	ASSERT_EQ(elementos[1], elementos[0]->prox);

	ASSERT_EQ(elementos[0], elementos[1]->ant);
	ASSERT_EQ(&dados[1], elementos[1]->dado);
	ASSERT_EQ(elementos[2], elementos[1]->prox);

	ASSERT_EQ(elementos[1], elementos[2]->ant);
	ASSERT_EQ(&dados[2], elementos[2]->dado);
	ASSERT_EQ(NULL, elementos[2]->prox);

	aux_ll_limpar(&ll);
}

TEST(aux_ll_preencher, ListaQuatroElementos)
{
	struct lld ll;
	int dados[4] = { 1, 2, 3, 4 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	ASSERT_EQ(elementos[0], ll.inicio);
	ASSERT_EQ(elementos[3], ll.fim);
	ASSERT_EQ(&intcmp, ll.compar);

	ASSERT_EQ(NULL, elementos[0]->ant);
	ASSERT_EQ(&dados[0], elementos[0]->dado);
	ASSERT_EQ(elementos[1], elementos[0]->prox);

	ASSERT_EQ(elementos[0], elementos[1]->ant);
	ASSERT_EQ(&dados[1], elementos[1]->dado);
	ASSERT_EQ(elementos[2], elementos[1]->prox);

	ASSERT_EQ(elementos[1], elementos[2]->ant);
	ASSERT_EQ(&dados[2], elementos[2]->dado);
	ASSERT_EQ(elementos[3], elementos[2]->prox);

	ASSERT_EQ(elementos[2], elementos[3]->ant);
	ASSERT_EQ(&dados[3], elementos[3]->dado);
	ASSERT_EQ(NULL, elementos[3]->prox);

	aux_ll_limpar(&ll);
}