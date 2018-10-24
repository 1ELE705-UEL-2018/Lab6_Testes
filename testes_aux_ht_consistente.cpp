#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ht.h"
}

TEST(aux_ht_consistente, HashTableVaziaConsistente)
{
	struct ht h;
	const int tam = 8;

	aux_ht_preencher(&h, tam, intcmp, inthash, NULL, 0);

	ASSERT_EQ(-1, aux_ht_consistente(&h));

	aux_ht_limpar(&h);
}

TEST(aux_ht_consistente, HashTableUmaListaUmElementoInconsistenteListaInicioNaoNULL)
{
	struct ht h;
	int dados[1] = { 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	h.tam_array = 1;
	h.hash = inthash;
	h.array_ll = (struct lld*)malloc(1*sizeof(struct lld));
	aux_ll_preencher(&h.array_ll[0], intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	h.array_ll[0].inicio->ant = h.array_ll[0].inicio;

	ASSERT_EQ(0, aux_ht_consistente(&h));

	h.array_ll[0].inicio->ant = NULL;

	aux_ht_limpar(&h);
}

TEST(aux_ht_consistente, HashTableUmaListaUmElementoInconsistenteListaFimNaoNULL)
{
	struct ht h;
	int dados[1] = { 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	h.tam_array = 1;
	h.hash = inthash;
	h.array_ll = (struct lld*)malloc(1*sizeof(struct lld));
	aux_ll_preencher(&h.array_ll[0], intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	h.array_ll[0].fim->prox = h.array_ll[0].inicio;

	ASSERT_EQ(0, aux_ht_consistente(&h));

	h.array_ll[0].fim->prox = NULL;

	aux_ht_limpar(&h);
}

TEST(aux_ht_consistente, HashTableUmaListaDoisElementosInconsistenteListaFimIncorreto)
{
	struct ht h;
	int dados[2] = { 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	h.tam_array = 1;
	h.hash = inthash;
	h.array_ll = (struct lld*)malloc(1*sizeof(struct lld));
	aux_ll_preencher(&h.array_ll[0], intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	elementos[0]->prox = NULL;

	ASSERT_EQ(0, aux_ht_consistente(&h));

	elementos[0]->prox = elementos[1];

	aux_ht_limpar(&h);
}

TEST(aux_ht_consistente, HashTableUmaListaDoisElementosInconsistenteListaPrimeiroElemento)
{
	struct ht h;
	int dados[2] = { 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	h.tam_array = 1;
	h.hash = inthash;
	h.array_ll = (struct lld*)malloc(1*sizeof(struct lld));
	aux_ll_preencher(&h.array_ll[0], intcmp, dados, sizeof(dados)/sizeof(int), elementos);

	elementos[1]->ant = NULL;

	ASSERT_EQ(0, aux_ht_consistente(&h));

	elementos[1]->ant = elementos[0];

	aux_ht_limpar(&h);
}

TEST(aux_ht_consistente, HashTableDuasListasDoisElementosInconsistenteSomenteNaSegundaLista)
{
	struct ht h;
	int dados1[2] = { 1, 7 };
	struct lld_el* elementos[sizeof(dados1)/sizeof(int)];

	h.tam_array = 2;
	h.hash = inthash;
	h.array_ll = (struct lld*)malloc(2*sizeof(struct lld));
	aux_ll_preencher(&h.array_ll[0], intcmp, NULL, 0, NULL);
	aux_ll_preencher(&h.array_ll[1], intcmp, dados1, sizeof(dados1)/sizeof(int), elementos);

	elementos[1]->ant = NULL;

	ASSERT_EQ(1, aux_ht_consistente(&h));

	elementos[1]->ant = elementos[0];

	aux_ht_limpar(&h);
}

TEST(aux_ht_consistente, HashTableDuasListasUmElementoInconsistenteErroHashElementoPrimeiraLista)
{
	struct ht h;
	int dados0[1] = { 1 };
	struct lld_el* elementos[sizeof(dados0)/sizeof(int)];

	h.tam_array = 2;
	h.hash = inthash;
	h.array_ll = (struct lld*)malloc(2*sizeof(struct lld));
	aux_ll_preencher(&h.array_ll[0], intcmp, dados0, sizeof(dados0)/sizeof(int), elementos);
	aux_ll_preencher(&h.array_ll[1], intcmp, NULL, 0, NULL);

	ASSERT_EQ(0, aux_ht_consistente(&h));

	aux_ht_limpar(&h);
}

TEST(aux_ht_consistente, HashTableDuasListasDoisElementoInconsistenteErroHashSegundoElementoPrimeiraLista)
{
	struct ht h;
	int dados0[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados0)/sizeof(int)];

	h.tam_array = 2;
	h.hash = inthash;
	h.array_ll = (struct lld*)malloc(2*sizeof(struct lld));
	aux_ll_preencher(&h.array_ll[0], intcmp, dados0, sizeof(dados0)/sizeof(int), elementos);
	aux_ll_preencher(&h.array_ll[1], intcmp, NULL, 0, NULL);

	ASSERT_EQ(0, aux_ht_consistente(&h));

	aux_ht_limpar(&h);
}

TEST(aux_ht_consistente, HashTableDuasListasDoisElementoInconsistenteErroHashPrimeiroElementoSegundaLista)
{
	struct ht h;
	int dados0[1] = { 0 };
	int dados1[1] = { 2 };
	struct lld_el* elementos0[sizeof(dados0)/sizeof(int)];
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];

	h.tam_array = 2;
	h.hash = inthash;
	h.array_ll = (struct lld*)malloc(2*sizeof(struct lld));
	aux_ll_preencher(&h.array_ll[0], intcmp, dados0, sizeof(dados0)/sizeof(int), elementos0);
	aux_ll_preencher(&h.array_ll[1], intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);

	ASSERT_EQ(1, aux_ht_consistente(&h));

	aux_ht_limpar(&h);
}
