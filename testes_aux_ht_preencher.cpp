#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ht.h"
}

TEST(aux_ht_preencher, HashTableVaziaArray8)
{
	struct ht h;
	const int tam = 8;
	int i;

	aux_ht_preencher(&h, tam, intcmp, inthash, NULL, 0);

	ASSERT_EQ(tam, h.tam_array);
	ASSERT_EQ(&inthash, h.hash);
	for (i = 0; i < tam; i++)
	{
		ASSERT_TRUE(LinkedListInitialized(&h.array_ll[i], intcmp));
	}

	aux_ht_limpar(&h);
}

TEST(aux_ht_preencher, HashTableVaziaArray4)
{
	struct ht h;
	const int tam = 4;
	int i;

	aux_ht_preencher(&h, tam, intcmp, inthash, NULL, 0);

	ASSERT_EQ(tam, h.tam_array);
	ASSERT_EQ(&inthash, h.hash);
	for (i = 0; i < tam; i++)
	{
		ASSERT_TRUE(LinkedListInitialized(&h.array_ll[i], intcmp));
	}

	aux_ht_limpar(&h);
}

TEST(aux_ht_preencher, HashTableArrayUmaListaUmElemento)
{
	struct ht h;
	const int tam = 1;
	int i;

	int dados[1] = { 1 };

	struct lld array_ll_res[1];
	int array_ll_dados0[1] = { 1 };
	int* array_ll_dados[1] = { array_ll_dados0 };
	int array_ll_tam_dados[1] = { sizeof(array_ll_dados0)/sizeof(int) };

	for (i = 0; i < tam; i++)
	{
		struct lld_el** elementos = (struct lld_el**)malloc(array_ll_tam_dados[i]*sizeof(struct lld_el*));
		aux_ll_preencher(&array_ll_res[i], intcmp, array_ll_dados[i], array_ll_tam_dados[i], elementos);
	}

	aux_ht_preencher(&h, tam, intcmp, inthash, dados, sizeof(dados)/sizeof(int));

	ASSERT_EQ(tam, h.tam_array);
	ASSERT_EQ(&inthash, h.hash);
	for (i = 0; i < tam; i++)
	{
		ASSERT_TRUE(LinkedListConsistent(&h.array_ll[i]));
		ASSERT_TRUE(LinkedListsMatch(&h.array_ll[i], &array_ll_res[i]));
	}

	aux_ht_limpar(&h);

	for (i = 0; i < tam; i++)
	{
		aux_ll_limpar(&array_ll_res[i]);
	}
}

TEST(aux_ht_preencher, HashTableArrayDuasListasUmElementoNaPrimeiraLista)
{
	struct ht h;
	const int tam = 2;
	int i;

	int dados[1] = { 0 };

	struct lld array_ll_res[2];
	int array_ll_dados0[1] = { 0 };
	int* array_ll_dados[2] = { array_ll_dados0, NULL };
	int array_ll_tam_dados[2] = { sizeof(array_ll_dados0)/sizeof(int), 0 };

	for (i = 0; i < tam; i++)
	{
		struct lld_el** elementos = (struct lld_el**)malloc(array_ll_tam_dados[i]*sizeof(struct lld_el*));
		aux_ll_preencher(&array_ll_res[i], intcmp, array_ll_dados[i], array_ll_tam_dados[i], elementos);
	}

	aux_ht_preencher(&h, tam, intcmp, inthash, dados, sizeof(dados)/sizeof(int));

	ASSERT_EQ(tam, h.tam_array);
	ASSERT_EQ(&inthash, h.hash);
	for (i = 0; i < tam; i++)
	{
		ASSERT_TRUE(LinkedListConsistent(&h.array_ll[i]));
		ASSERT_TRUE(LinkedListsMatch(&h.array_ll[i], &array_ll_res[i]));
	}

	aux_ht_limpar(&h);

	for (i = 0; i < tam; i++)
	{
		aux_ll_limpar(&array_ll_res[i]);
	}
}

TEST(aux_ht_preencher, HashTableArrayDuasListasUmElementoNaSegundaLista)
{
	struct ht h;
	const int tam = 2;
	int i;

	int dados[1] = { 1 };

	struct lld array_ll_res[2];
	int array_ll_dados1[1] = { 1 };
	int* array_ll_dados[2] = { NULL, array_ll_dados1 };
	int array_ll_tam_dados[2] = { 0, sizeof(array_ll_dados1)/sizeof(int) };

	for (i = 0; i < tam; i++)
	{
		struct lld_el** elementos = (struct lld_el**)malloc(array_ll_tam_dados[i]*sizeof(struct lld_el*));
		aux_ll_preencher(&array_ll_res[i], intcmp, array_ll_dados[i], array_ll_tam_dados[i], elementos);
	}

	aux_ht_preencher(&h, tam, intcmp, inthash, dados, sizeof(dados)/sizeof(int));

	ASSERT_EQ(tam, h.tam_array);
	ASSERT_EQ(&inthash, h.hash);
	for (i = 0; i < tam; i++)
	{
		ASSERT_TRUE(LinkedListConsistent(&h.array_ll[i]));
		ASSERT_TRUE(LinkedListsMatch(&h.array_ll[i], &array_ll_res[i]));
	}

	aux_ht_limpar(&h);

	for (i = 0; i < tam; i++)
	{
		aux_ll_limpar(&array_ll_res[i]);
	}
}

TEST(aux_ht_preencher, HashTableArrayDuasListasDoisElementosUmPorLista)
{
	struct ht h;
	const int tam = 2;
	int i;

	int dados[2] = { 10, 7 };

	struct lld array_ll_res[2];
	int array_ll_dados0[1] = { 10 };
	int array_ll_dados1[1] = { 7 };
	int* array_ll_dados[2] = { array_ll_dados0, array_ll_dados1 };
	int array_ll_tam_dados[2] = { sizeof(array_ll_dados0)/sizeof(int), sizeof(array_ll_dados1)/sizeof(int) };

	for (i = 0; i < tam; i++)
	{
		struct lld_el** elementos = (struct lld_el**)malloc(array_ll_tam_dados[i]*sizeof(struct lld_el*));
		aux_ll_preencher(&array_ll_res[i], intcmp, array_ll_dados[i], array_ll_tam_dados[i], elementos);
	}

	aux_ht_preencher(&h, tam, intcmp, inthash, dados, sizeof(dados)/sizeof(int));

	ASSERT_EQ(tam, h.tam_array);
	ASSERT_EQ(&inthash, h.hash);
	for (i = 0; i < tam; i++)
	{
		ASSERT_TRUE(LinkedListConsistent(&h.array_ll[i]));
		ASSERT_TRUE(LinkedListsMatch(&h.array_ll[i], &array_ll_res[i]));
	}

	aux_ht_limpar(&h);

	for (i = 0; i < tam; i++)
	{
		aux_ll_limpar(&array_ll_res[i]);
	}
}

TEST(aux_ht_preencher, HashTableArrayUmaListaDoisElementos)
{
	struct ht h;
	const int tam = 1;
	int i;

	int dados[2] = { 10, 7 };

	struct lld array_ll_res[1];
	int array_ll_dados0[2] = { 10, 7 };
	int* array_ll_dados[1] = { array_ll_dados0 };
	int array_ll_tam_dados[1] = { sizeof(array_ll_dados0)/sizeof(int) };

	for (i = 0; i < tam; i++)
	{
		struct lld_el** elementos = (struct lld_el**)malloc(array_ll_tam_dados[i]*sizeof(struct lld_el*));
		aux_ll_preencher(&array_ll_res[i], intcmp, array_ll_dados[i], array_ll_tam_dados[i], elementos);
	}

	aux_ht_preencher(&h, tam, intcmp, inthash, dados, sizeof(dados)/sizeof(int));

	ASSERT_EQ(tam, h.tam_array);
	ASSERT_EQ(&inthash, h.hash);
	for (i = 0; i < tam; i++)
	{
		ASSERT_TRUE(LinkedListConsistent(&h.array_ll[i]));
		ASSERT_TRUE(LinkedListsMatch(&h.array_ll[i], &array_ll_res[i]));
	}

	aux_ht_limpar(&h);

	for (i = 0; i < tam; i++)
	{
		aux_ll_limpar(&array_ll_res[i]);
	}
}