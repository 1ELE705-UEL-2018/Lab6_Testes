#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(aux_ll_iguais, ListasVaziasComparIgual)
{
	struct lld ll1, ll2;

	aux_ll_preencher(&ll1, intcmp, NULL, 0, NULL);
	aux_ll_preencher(&ll2, intcmp, NULL, 0, NULL);

	ASSERT_EQ(-1, aux_ll_iguais(&ll1, &ll2));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll2);
}

TEST(aux_ll_iguais, ListasVaziasComparDiferente)
{
	struct lld ll1, ll2;

	aux_ll_preencher(&ll1, intcmp, NULL, 0, NULL);
	aux_ll_preencher(&ll2, NULL, NULL, 0, NULL);

	ASSERT_EQ(-2, aux_ll_iguais(&ll1, &ll2));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll2);
}

TEST(aux_ll_iguais, ListasUmElementoIguais)
{
	struct lld ll1, ll2;
	int dados1[1] = { 1 }, dados2[1] = { 1 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_EQ(-1, aux_ll_iguais(&ll1, &ll2));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll2);
}

TEST(aux_ll_iguais, ListasUmElementoDiferentes)
{
	struct lld ll1, ll2;
	int dados1[1] = { 0 }, dados2[1] = { 1 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_EQ(0, aux_ll_iguais(&ll1, &ll2));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll2);
}

TEST(aux_ll_iguais, ListasDoisElementosIguais)
{
	struct lld ll1, ll2;
	int dados1[2] = { 0, 1 }, dados2[2] = { 0, 1 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_EQ(-1, aux_ll_iguais(&ll1, &ll2));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll2);
}

TEST(aux_ll_iguais, ListasDoisElementosDiferentesPrimeiro)
{
	struct lld ll1, ll2;
	int dados1[2] = { 1, 1 }, dados2[2] = { 0, 1 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_EQ(0, aux_ll_iguais(&ll1, &ll2));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll2);
}

TEST(aux_ll_iguais, ListasDoisElementosDiferentesSegundo)
{
	struct lld ll1, ll2;
	int dados1[2] = { 0, 0 }, dados2[2] = { 0, 1 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_EQ(1, aux_ll_iguais(&ll1, &ll2));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll2);
}

TEST(aux_ll_iguais, ListasTresElementosIguais)
{
	struct lld ll1, ll2;
	int dados1[3] = { 0, 1, 2 }, dados2[3] = { 0, 1, 2 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_EQ(-1, aux_ll_iguais(&ll1, &ll2));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll2);
}

TEST(aux_ll_iguais, ListasTresElementosDiferentesPrimeiro)
{
	struct lld ll1, ll2;
	int dados1[3] = { 1, 1, 2 }, dados2[3] = { 0, 1, 2 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_EQ(0, aux_ll_iguais(&ll1, &ll2));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll2);
}

TEST(aux_ll_iguais, ListasTresElementosDiferentesSegundo)
{
	struct lld ll1, ll2;
	int dados1[3] = { 0, 2, 2 }, dados2[3] = { 0, 1, 2 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_EQ(1, aux_ll_iguais(&ll1, &ll2));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll2);
}

TEST(aux_ll_iguais, ListasTresElementosDiferentesTerceiro)
{
	struct lld ll1, ll2;
	int dados1[3] = { 0, 1, 0 }, dados2[3] = { 0, 1, 2 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_EQ(2, aux_ll_iguais(&ll1, &ll2));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll2);
}

TEST(aux_ll_iguais, ListasVaziaUmElemento)
{
	struct lld ll1, ll2;
	int dados2[3] = { 0, 1, 2 };
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, NULL, 0, NULL);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_EQ(-3, aux_ll_iguais(&ll1, &ll2));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll2);
}

TEST(aux_ll_iguais, ListasUmElementoDoisElementos)
{
	struct lld ll1, ll2;
	int dados1[1] = { 0 }, dados2[2] = { 0, 0 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_EQ(-3, aux_ll_iguais(&ll1, &ll2));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll2);
}

TEST(aux_ll_iguais, ListasUmElementoTresElementos)
{
	struct lld ll1, ll2;
	int dados1[1] = { 0 }, dados2[3] = { 0, 0, 0 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_EQ(-3, aux_ll_iguais(&ll1, &ll2));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll2);
}

TEST(aux_ll_iguais, ListasDoisElementosTresElementos)
{
	struct lld ll1, ll2;
	int dados1[2] = { 0, 0 }, dados2[3] = { 0, 0, 0 };
	struct lld_el* elementos1[sizeof(dados1)/sizeof(int)];
	struct lld_el* elementos2[sizeof(dados2)/sizeof(int)];

	aux_ll_preencher(&ll1, intcmp, dados1, sizeof(dados1)/sizeof(int), elementos1);
	aux_ll_preencher(&ll2, intcmp, dados2, sizeof(dados2)/sizeof(int), elementos2);

	ASSERT_EQ(-3, aux_ll_iguais(&ll1, &ll2));

	aux_ll_limpar(&ll1);
	aux_ll_limpar(&ll2);
}
