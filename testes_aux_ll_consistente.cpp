#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(aux_ll_consistente, ListaVaziaConsistente)
{
	struct lld ll;

	aux_ll_preencher(&ll, intcmp, NULL, 0, NULL);

	ASSERT_EQ(-1, aux_ll_consistente(&ll));

	aux_ll_limpar(&ll);
}

TEST(aux_ll_consistente, ListaUmElementoConsistente)
{
	struct lld ll;
	int dados[1] = { 1 };
	struct lld_el* elementos[sizeof(dados) / sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados) / sizeof(int), elementos);

	ASSERT_EQ(-1, aux_ll_consistente(&ll));

	aux_ll_limpar(&ll);
}

TEST(aux_ll_consistente, ListaUmElementoInconsistenteInicioNaoNULL)
{
	struct lld ll;
	int dados[1] = { 1 };
	struct lld_el* elementos[sizeof(dados) / sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados) / sizeof(int), elementos);

	ll.inicio->ant = ll.inicio;

	ASSERT_EQ(-2, aux_ll_consistente(&ll));

	ll.inicio->ant = NULL;

	aux_ll_limpar(&ll);
}

TEST(aux_ll_consistente, ListaUmElementoInconsistenteFimNaoNULL)
{
	struct lld ll;
	int dados[1] = { 1 };
	struct lld_el* elementos[sizeof(dados) / sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados) / sizeof(int), elementos);

	ll.fim->prox = ll.inicio;

	ASSERT_EQ(-3, aux_ll_consistente(&ll));

	ll.fim->prox = NULL;

	aux_ll_limpar(&ll);
}

TEST(aux_ll_consistente, ListaDoisElementosConsistente)
{
	struct lld ll;
	int dados[2] = { 1, 2 };
	struct lld_el* elementos[sizeof(dados) / sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados) / sizeof(int), elementos);

	ASSERT_EQ(-1, aux_ll_consistente(&ll));

	aux_ll_limpar(&ll);
}

TEST(aux_ll_consistente, ListaDoisElementosInconsistenteFimIncorreto)
{
	struct lld ll;
	int dados[2] = { 1, 2 };
	struct lld_el* elementos[sizeof(dados) / sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados) / sizeof(int), elementos);

	elementos[0]->prox = NULL;

	ASSERT_EQ(-4, aux_ll_consistente(&ll));

	elementos[0]->prox = elementos[1];

	aux_ll_limpar(&ll);
}

TEST(aux_ll_consistente, ListaDoisElementosInconsistentePrimeiroElemento)
{
	struct lld ll;
	int dados[2] = { 1, 2 };
	struct lld_el* elementos[sizeof(dados) / sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados) / sizeof(int), elementos);

	elementos[1]->ant = NULL;

	ASSERT_EQ(0, aux_ll_consistente(&ll));

	elementos[1]->ant = elementos[0];

	aux_ll_limpar(&ll);
}

TEST(aux_ll_consistente, ListaTresElementosConsistente)
{
	struct lld ll;
	int dados[3] = { 1, 2, 3 };
	struct lld_el* elementos[sizeof(dados) / sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados) / sizeof(int), elementos);

	ASSERT_EQ(-1, aux_ll_consistente(&ll));

	aux_ll_limpar(&ll);
}

TEST(aux_ll_consistente, ListaTresElementosInconsistentePrimeiroElementoCaso1)
{
	struct lld ll;
	int dados[3] = { 1, 2, 3 };
	struct lld_el* elementos[sizeof(dados) / sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados) / sizeof(int), elementos);

	elementos[0]->prox = elementos[2];

	ASSERT_EQ(0, aux_ll_consistente(&ll));

	elementos[0]->prox = elementos[1];

	aux_ll_limpar(&ll);
}

TEST(aux_ll_consistente, ListaTresElementosInconsistentePrimeiroElementoCaso2)
{
	struct lld ll;
	int dados[3] = { 1, 2, 3 };
	struct lld_el* elementos[sizeof(dados) / sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados) / sizeof(int), elementos);

	elementos[1]->ant = NULL;

	ASSERT_EQ(0, aux_ll_consistente(&ll));

	elementos[1]->ant = elementos[0];

	aux_ll_limpar(&ll);
}

TEST(aux_ll_consistente, ListaTresElementosInconsistenteSegundoElementoCaso1)
{
	struct lld ll;
	int dados[3] = { 1, 2, 3 };
	struct lld_el* elementos[sizeof(dados) / sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados) / sizeof(int), elementos);

	elementos[1]->prox = elementos[0];

	ASSERT_EQ(1, aux_ll_consistente(&ll));

	elementos[1]->prox = elementos[2];

	aux_ll_limpar(&ll);
}

TEST(aux_ll_consistente, ListaTresElementosInconsistenteSegundoElementoCaso2)
{
	struct lld ll;
	int dados[3] = { 1, 2, 3 };
	struct lld_el* elementos[sizeof(dados) / sizeof(int)];

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados) / sizeof(int), elementos);

	elementos[2]->ant = elementos[0];

	ASSERT_EQ(1, aux_ll_consistente(&ll));

	elementos[2]->ant = elementos[1];

	aux_ll_limpar(&ll);
}