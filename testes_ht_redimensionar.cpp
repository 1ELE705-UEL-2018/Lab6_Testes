#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ht.h"
}

TEST(ht_redimensionar, HashTableVaziaRedimensionarUmParaDois)
{
	const int tam = 1, tam_depois = 2;

	struct ht h, h_esperado;

	aux_ht_preencher(&h, tam, intcmp, inthash, NULL, 0);
	aux_ht_preencher(&h_esperado, tam_depois, intcmp, inthash, NULL, 0);

	ht_redimensionar(&h, tam_depois);

	ASSERT_EQ(tam_depois, h.tam_array);
	ASSERT_EQ(tam_depois*sizeof(struct lld), _msize(h.array_ll)) << "Quantidade de memoria alocada para o array de LLs esta' errada";
	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_EQ(1, aux_ht_contem_mesmos_elementos(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}

TEST(ht_redimensionar, HashTableVaziaRedimensionarDoisParaQuatro)
{
	const int tam = 2, tam_depois = 4;

	struct ht h, h_esperado;

	aux_ht_preencher(&h, tam, intcmp, inthash, NULL, 0);
	aux_ht_preencher(&h_esperado, tam_depois, intcmp, inthash, NULL, 0);

	ht_redimensionar(&h, tam_depois);

	ASSERT_EQ(tam_depois, h.tam_array);
	ASSERT_EQ(tam_depois*sizeof(struct lld), _msize(h.array_ll)) << "Quantidade de memoria alocada para o array de LLs esta' errada";
	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_EQ(1, aux_ht_contem_mesmos_elementos(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}

TEST(ht_redimensionar, HashTableVaziaRedimensionarDoisParaUm)
{
	const int tam = 2, tam_depois = 1;

	struct ht h, h_esperado;

	aux_ht_preencher(&h, tam, intcmp, inthash, NULL, 0);
	aux_ht_preencher(&h_esperado, tam_depois, intcmp, inthash, NULL, 0);

	ht_redimensionar(&h, tam_depois);

	ASSERT_EQ(tam_depois, h.tam_array);
	ASSERT_EQ(tam_depois*sizeof(struct lld), _msize(h.array_ll)) << "Quantidade de memoria alocada para o array de LLs esta' errada";
	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_EQ(1, aux_ht_contem_mesmos_elementos(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}

TEST(ht_redimensionar, HashTableUmElementoNaListaZeroRedimensionarDoisParaUm)
{
	const int tam = 2, tam_depois = 1;

	struct ht h, h_esperado;
	int dados[1] = { 0 };
	int dados_esperado[1] = { 0 };

	aux_ht_preencher(&h, tam, intcmp, inthash, dados, sizeof(dados)/sizeof(int));
	aux_ht_preencher(&h_esperado, tam, intcmp, inthash, dados_esperado, sizeof(dados_esperado)/sizeof(int));

	ht_redimensionar(&h, tam_depois);

	ASSERT_EQ(tam_depois, h.tam_array);
	ASSERT_EQ(tam_depois*sizeof(struct lld), _msize(h.array_ll)) << "Quantidade de memoria alocada para o array de LLs esta' errada";
	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_EQ(1, aux_ht_contem_mesmos_elementos(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}

TEST(ht_redimensionar, HashTableUmElementoNaListaUmRedimensionarDoisParaUm)
{
	const int tam = 2, tam_depois = 1;

	struct ht h, h_esperado;
	int dados[1] = { 1 };
	int dados_esperado[1] = { 1 };

	aux_ht_preencher(&h, tam, intcmp, inthash, dados, sizeof(dados)/sizeof(int));
	aux_ht_preencher(&h_esperado, tam, intcmp, inthash, dados_esperado, sizeof(dados_esperado)/sizeof(int));

	ht_redimensionar(&h, tam_depois);

	ASSERT_EQ(tam_depois, h.tam_array);
	ASSERT_EQ(tam_depois*sizeof(struct lld), _msize(h.array_ll)) << "Quantidade de memoria alocada para o array de LLs esta' errada";
	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_EQ(1, aux_ht_contem_mesmos_elementos(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}

TEST(ht_redimensionar, HashTableDoisElementosUmPorListaRedimensionarDoisParaUm)
{
	const int tam = 2, tam_depois = 1;

	struct ht h, h_esperado;
	int dados[2] = { 0, 1 };
	int dados_esperado[2] = { 0, 1 };

	aux_ht_preencher(&h, tam, intcmp, inthash, dados, sizeof(dados)/sizeof(int));
	aux_ht_preencher(&h_esperado, tam, intcmp, inthash, dados_esperado, sizeof(dados_esperado)/sizeof(int));

	ht_redimensionar(&h, tam_depois);

	ASSERT_EQ(tam_depois, h.tam_array);
	ASSERT_EQ(tam_depois*sizeof(struct lld), _msize(h.array_ll)) << "Quantidade de memoria alocada para o array de LLs esta' errada";
	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_EQ(1, aux_ht_contem_mesmos_elementos(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}

TEST(ht_redimensionar, HashTableDoisElementosRedimensionarUmParaDoisResultadoEmListasDiferentes)
{
	const int tam = 1, tam_depois = 2;

	struct ht h, h_esperado;
	int dados[2] = { 0, 1 };
	int dados_esperado[2] = { 0, 1 };

	aux_ht_preencher(&h, tam, intcmp, inthash, dados, sizeof(dados)/sizeof(int));
	aux_ht_preencher(&h_esperado, tam, intcmp, inthash, dados_esperado, sizeof(dados_esperado)/sizeof(int));

	ht_redimensionar(&h, tam_depois);

	ASSERT_EQ(tam_depois, h.tam_array);
	ASSERT_EQ(tam_depois*sizeof(struct lld), _msize(h.array_ll)) << "Quantidade de memoria alocada para o array de LLs esta' errada";
	ASSERT_TRUE(HashTableConsistent(&h));
	ASSERT_EQ(1, aux_ht_contem_mesmos_elementos(&h_esperado, &h));

	aux_ht_limpar(&h);
	aux_ht_limpar(&h_esperado);
}