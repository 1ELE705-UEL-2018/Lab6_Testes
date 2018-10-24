#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ht.h"
}

TEST(ht_buscar, HashTableVaziaBuscaNULL)
{
	const int tam = 8;

	struct ht h;
	int buscado = 0;

	aux_ht_preencher(&h, tam, intcmp, inthash, NULL, 0);

	ASSERT_EQ(NULL, ht_buscar(&h, NULL));

	aux_ht_limpar(&h);
}

TEST(ht_buscar, HashTableVaziaBuscaElementoQueNaoExiste)
{
	const int tam = 8;

	struct ht h;
	int buscado = 0;

	aux_ht_preencher(&h, tam, intcmp, inthash, NULL, 0);

	ASSERT_EQ(NULL, ht_buscar(&h, &buscado));

	aux_ht_limpar(&h);
}

TEST(ht_buscar, HashTableUmElementoBuscaElementoQueNaoExiste)
{
	const int tam = 8;

	struct ht h;
	int buscado = 1;
	int dados[1] = { 0 };

	aux_ht_preencher(&h, tam, intcmp, inthash, dados, sizeof(dados)/sizeof(int));

	ASSERT_EQ(NULL, ht_buscar(&h, &buscado));

	aux_ht_limpar(&h);
}

TEST(ht_buscar, HashTableUmElementoBuscaElementoQueExisteListaZero)
{
	const int tam = 8;

	struct ht h;
	int buscado = 0;
	int dados[1] = { 0 };
	struct ht_el* res;

	aux_ht_preencher(&h, tam, intcmp, inthash, dados, sizeof(dados)/sizeof(int));

	res = ht_buscar(&h, &buscado);

	ASSERT_NE((struct ht_el*)NULL, res);
	ASSERT_NE((void*)NULL, res->dado);
	ASSERT_EQ(buscado, *((int*)res->dado));

	aux_ht_limpar(&h);
}

TEST(ht_buscar, HashTableDoisElementosBuscaElementoQueExisteListaZeroColisao)
{
	const int tam = 8;

	struct ht h;
	int buscado = 8;
	int dados[2] = { 0, 8 };
	struct ht_el* res;

	aux_ht_preencher(&h, tam, intcmp, inthash, dados, sizeof(dados)/sizeof(int));

	res = ht_buscar(&h, &buscado);

	ASSERT_NE((struct ht_el*)NULL, res);
	ASSERT_NE((void*)NULL, res->dado);
	ASSERT_EQ(buscado, *((int*)res->dado));

	aux_ht_limpar(&h);
}

TEST(ht_buscar, HashTableUmElementoBuscaElementoQueExisteListaSete)
{
	const int tam = 8;

	struct ht h;
	int buscado = 7;
	int dados[1] = { 7 };
	struct ht_el* res;

	aux_ht_preencher(&h, tam, intcmp, inthash, dados, sizeof(dados)/sizeof(int));

	res = ht_buscar(&h, &buscado);

	ASSERT_NE((struct ht_el*)NULL, res);
	ASSERT_NE((void*)NULL, res->dado);
	ASSERT_EQ(buscado, *((int*)res->dado));

	aux_ht_limpar(&h);
}