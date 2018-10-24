#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ht.h"
}

TEST(ht_inserir, HashTableVaziaInserirUmElementoListaZero)
{
	const int tam = 8;

	struct ht h, h_esperado;
	int a_inserir = 0;
	int dados_esperado[1] = { 0 };

	aux_ht_preencher(&h, tam, intcmp, inthash, NULL, 0);
	aux_ht_preencher(&h_esperado, tam, intcmp, inthash, dados_esperado, sizeof(dados_esperado)/sizeof(int));

	ht_inserir(&h, &a_inserir);

	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_TRUE(HashTablesMatch(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}

TEST(ht_inserir, HashTableUmElementoListaZeroInserirSegundoElementoListaZero)
{
	const int tam = 8;

	struct ht h, h_esperado;
	int dados_inicio[1] = { 0 };
	int a_inserir = 8;
	int dados_esperado[2] = { 0, 8 };

	aux_ht_preencher(&h, tam, intcmp, inthash, dados_inicio, sizeof(dados_inicio)/sizeof(int));
	aux_ht_preencher(&h_esperado, tam, intcmp, inthash, dados_esperado, sizeof(dados_esperado)/sizeof(int));

	ht_inserir(&h, &a_inserir);

	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_TRUE(HashTablesMatch(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}

TEST(ht_inserir, HashTableDoisElementosListaZeroInserirTerceiroElementoListaZero)
{
	const int tam = 8;

	struct ht h, h_esperado;
	int dados_inicio[2] = { 0, 8 };
	int a_inserir = 16;
	int dados_esperado[3] = { 0, 8, 16 };

	aux_ht_preencher(&h, tam, intcmp, inthash, dados_inicio, sizeof(dados_inicio)/sizeof(int));
	aux_ht_preencher(&h_esperado, tam, intcmp, inthash, dados_esperado, sizeof(dados_esperado)/sizeof(int));

	ht_inserir(&h, &a_inserir);

	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_TRUE(HashTablesMatch(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}

TEST(ht_inserir, HashTableVaziaInserirUmElementoListaUm)
{
	const int tam = 8;

	struct ht h, h_esperado;
	int a_inserir = 1;
	int dados_esperado[1] = { 1 };

	aux_ht_preencher(&h, tam, intcmp, inthash, NULL, 0);
	aux_ht_preencher(&h_esperado, tam, intcmp, inthash, dados_esperado, sizeof(dados_esperado)/sizeof(int));

	ht_inserir(&h, &a_inserir);

	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_TRUE(HashTablesMatch(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}

TEST(ht_inserir, HashTableVaziaInserirUmElementoListaSete)
{
	const int tam = 8;

	struct ht h, h_esperado;
	int a_inserir = 7;
	int dados_esperado[1] = { 7 };

	aux_ht_preencher(&h, tam, intcmp, inthash, NULL, 0);
	aux_ht_preencher(&h_esperado, tam, intcmp, inthash, dados_esperado, sizeof(dados_esperado)/sizeof(int));

	ht_inserir(&h, &a_inserir);

	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_TRUE(HashTablesMatch(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}

TEST(ht_inserir, HashTableVaziaInserirDoisElementosListasUmESete)
{
	const int tam = 8;

	struct ht h, h_esperado;
	int dados_inicio[1] = { 1 };
	int a_inserir = 7;
	int dados_esperado[2] = { 1, 7 };

	aux_ht_preencher(&h, tam, intcmp, inthash, dados_inicio, sizeof(dados_inicio)/sizeof(int));
	aux_ht_preencher(&h_esperado, tam, intcmp, inthash, dados_esperado, sizeof(dados_esperado)/sizeof(int));

	ht_inserir(&h, &a_inserir);

	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_TRUE(HashTablesMatch(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}