#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ht.h"
}

TEST(ht_remover, HashTableVaziaRemoverNULL)
{
	const int tam = 8;

	struct ht h, h_esperado;

	aux_ht_preencher(&h, tam, intcmp, inthash, NULL, 0);
	aux_ht_preencher(&h_esperado, tam, intcmp, inthash, NULL, 0);

	ht_remover(&h, NULL);

	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_TRUE(HashTablesMatch(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}

TEST(ht_remover, HashTableVaziaRemoverElementoQueNaoExiste)
{
	const int tam = 8;

	struct ht h, h_esperado;
	int a_remover = 0;

	aux_ht_preencher(&h, tam, intcmp, inthash, NULL, 0);
	aux_ht_preencher(&h_esperado, tam, intcmp, inthash, NULL, 0);

	ht_remover(&h, &a_remover);

	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_TRUE(HashTablesMatch(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}

TEST(ht_remover, HashTableUmElementoRemoverElementoQueExiste)
{
	const int tam = 8;

	struct ht h, h_esperado;
	int dados[1] = { 0 };
	int a_remover = 0;

	aux_ht_preencher(&h, tam, intcmp, inthash, dados, sizeof(dados)/sizeof(int));
	aux_ht_preencher(&h_esperado, tam, intcmp, inthash, NULL, 0);

	ht_remover(&h, &a_remover);

	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_TRUE(HashTablesMatch(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}

TEST(ht_remover, HashTableUmElementoRemoverElementoQueNaoExisteColisao)
{
	const int tam = 8;

	struct ht h, h_esperado;
	int dados[1] = { 0 };
	int a_remover = 8;
	int dados_esperado[1] = { 0 };

	aux_ht_preencher(&h, tam, intcmp, inthash, dados, sizeof(dados)/sizeof(int));
	aux_ht_preencher(&h_esperado, tam, intcmp, inthash, dados_esperado, sizeof(dados_esperado)/sizeof(int));

	ht_remover(&h, &a_remover);

	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_TRUE(HashTablesMatch(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}

TEST(ht_remover, HashTableDoisElementosRemoverElementoQueExiste)
{
	const int tam = 8;

	struct ht h, h_esperado;
	int dados[2] = { 1, 7 };
	int a_remover = 7;
	int dados_esperado[1] = { 1 };

	aux_ht_preencher(&h, tam, intcmp, inthash, dados, sizeof(dados)/sizeof(int));
	aux_ht_preencher(&h_esperado, tam, intcmp, inthash, dados_esperado, sizeof(dados_esperado)/sizeof(int));

	ht_remover(&h, &a_remover);

	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_TRUE(HashTablesMatch(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}

TEST(ht_remover, HashTableDoisElementosRemoverElementoQueExisteColisao)
{
	const int tam = 8;

	struct ht h, h_esperado;
	int dados[2] = { 1, 9 };
	int a_remover = 1;
	int dados_esperado[1] = { 9 };

	aux_ht_preencher(&h, tam, intcmp, inthash, dados, sizeof(dados)/sizeof(int));
	aux_ht_preencher(&h_esperado, tam, intcmp, inthash, dados_esperado, sizeof(dados_esperado)/sizeof(int));

	ht_remover(&h, &a_remover);

	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_TRUE(HashTablesMatch(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}