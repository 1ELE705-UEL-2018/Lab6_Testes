#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ht.h"
}

TEST(aux_ht_contem_mesmos_elementos, HashTableVaziaIguais)
{
	struct ht h1, h2;
	const int tam = 8;

	aux_ht_preencher(&h1, tam, intcmp, inthash, NULL, 0);
	aux_ht_preencher(&h2, tam, intcmp, inthash, NULL, 0);

	ASSERT_EQ(1, aux_ht_contem_mesmos_elementos(&h1, &h2));

	aux_ht_limpar(&h1);
	aux_ht_limpar(&h2);
}

TEST(aux_ht_contem_mesmos_elementos, HashTableVaziaNumeroDeListasDiferentes)
{
	struct ht h1, h2;

	aux_ht_preencher(&h1, 8, intcmp, inthash, NULL, 0);
	aux_ht_preencher(&h2, 4, intcmp, inthash, NULL, 0);

	ASSERT_EQ(1, aux_ht_contem_mesmos_elementos(&h1, &h2));

	aux_ht_limpar(&h1);
	aux_ht_limpar(&h2);
}

TEST(aux_ht_contem_mesmos_elementos, HashTableVaziaFuncoesHashDiferentes)
{
	struct ht h1, h2;
	const int tam = 8;

	aux_ht_preencher(&h1, tam, intcmp, inthash, NULL, 0);
	aux_ht_preencher(&h2, tam, intcmp, NULL, NULL, 0);

	ASSERT_EQ(1, aux_ht_contem_mesmos_elementos(&h1, &h2));

	aux_ht_limpar(&h1);
	aux_ht_limpar(&h2);
}

TEST(aux_ht_contem_mesmos_elementos, HashTableVaziaFuncoesComparacaoDiferentes)
{
	struct ht h1, h2;
	const int tam = 8;

	aux_ht_preencher(&h1, tam, intcmp, inthash, NULL, 0);
	aux_ht_preencher(&h2, tam, NULL, inthash, NULL, 0);

	ASSERT_EQ(1, aux_ht_contem_mesmos_elementos(&h1, &h2));

	aux_ht_limpar(&h1);
	aux_ht_limpar(&h2);
}

TEST(aux_ht_contem_mesmos_elementos, HashTableUmaListaUmElementoIguais)
{
	struct ht h1, h2;
	const int tam = 1;

	int dados1[1] = { 1 };
	int dados2[1] = { 1 };

	aux_ht_preencher(&h1, tam, intcmp, inthash, dados1, sizeof(dados1)/sizeof(int));
	aux_ht_preencher(&h2, tam, intcmp, inthash, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(1, aux_ht_contem_mesmos_elementos(&h1, &h2));

	aux_ht_limpar(&h1);
	aux_ht_limpar(&h2);
}

TEST(aux_ht_contem_mesmos_elementos, HashTableUmaListaUmElementoDiferentes)
{
	struct ht h1, h2;
	const int tam = 1;

	int dados1[1] = { 0 };
	int dados2[1] = { 1 };

	aux_ht_preencher(&h1, tam, intcmp, inthash, dados1, sizeof(dados1)/sizeof(int));
	aux_ht_preencher(&h2, tam, intcmp, inthash, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(0, aux_ht_contem_mesmos_elementos(&h1, &h2));

	aux_ht_limpar(&h1);
	aux_ht_limpar(&h2);
}

TEST(aux_ht_contem_mesmos_elementos, HashTableUmaListaNumeroDeElementosDiferente)
{
	struct ht h1, h2;
	const int tam = 1;

	int dados1[1] = { 0 };
	int dados2[2] = { 0, 1 };

	aux_ht_preencher(&h1, tam, intcmp, inthash, dados1, sizeof(dados1)/sizeof(int));
	aux_ht_preencher(&h2, tam, intcmp, inthash, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(0, aux_ht_contem_mesmos_elementos(&h1, &h2));

	aux_ht_limpar(&h1);
	aux_ht_limpar(&h2);
}

TEST(aux_ht_contem_mesmos_elementos, HashTableDuasListasUmElementoCadaIguais)
{
	struct ht h1, h2;
	const int tam = 2;

	int dados1[1] = { 0 };
	int dados2[1] = { 0 };

	aux_ht_preencher(&h1, tam, intcmp, inthash, dados1, sizeof(dados1)/sizeof(int));
	aux_ht_preencher(&h2, tam, intcmp, inthash, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(1, aux_ht_contem_mesmos_elementos(&h1, &h2));

	aux_ht_limpar(&h1);
	aux_ht_limpar(&h2);
}

TEST(aux_ht_contem_mesmos_elementos, HashTableDuasListasNumeroDeElementosDiferenteMaisNaSegunda)
{
	struct ht h1, h2;
	const int tam = 2;

	int dados1[1] = { 0 };
	int dados2[2] = { 0, 1 };

	aux_ht_preencher(&h1, tam, intcmp, inthash, dados1, sizeof(dados1)/sizeof(int));
	aux_ht_preencher(&h2, tam, intcmp, inthash, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(0, aux_ht_contem_mesmos_elementos(&h1, &h2));

	aux_ht_limpar(&h1);
	aux_ht_limpar(&h2);
}


TEST(aux_ht_contem_mesmos_elementos, HashTableDuasListasNumeroDeElementosDiferenteMaisNaPrimeira)
{
	struct ht h1, h2;
	const int tam = 2;

	int dados1[2] = { 0, 1 };
	int dados2[1] = { 0 };

	aux_ht_preencher(&h1, tam, intcmp, inthash, dados1, sizeof(dados1)/sizeof(int));
	aux_ht_preencher(&h2, tam, intcmp, inthash, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(0, aux_ht_contem_mesmos_elementos(&h1, &h2));

	aux_ht_limpar(&h1);
	aux_ht_limpar(&h2);
}

TEST(aux_ht_contem_mesmos_elementos, HashTableUmaListaOrdemDosElementosDiferente)
{
	struct ht h1, h2;
	const int tam = 1;

	int dados1[2] = { 0, 1 };
	int dados2[2] = { 1, 0 };

	aux_ht_preencher(&h1, tam, intcmp, inthash, dados1, sizeof(dados1)/sizeof(int));
	aux_ht_preencher(&h2, tam, intcmp, inthash, dados2, sizeof(dados2)/sizeof(int));

	ASSERT_EQ(1, aux_ht_contem_mesmos_elementos(&h1, &h2));

	aux_ht_limpar(&h1);
	aux_ht_limpar(&h2);
}
