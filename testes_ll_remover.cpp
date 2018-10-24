#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ll.h"
}

TEST(ll_remover, ListaUmElementoNaoLiberaMemoria)
{
	struct lld ll, ll_depois;
	int dados[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, NULL, 0, NULL);

	ll_remover(&ll, ll.inicio, 0);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_EQ(0, memoria_foi_liberada(elementos[0], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_remover, ListaUmElementoLiberaMemoria)
{
	struct lld ll, ll_depois;
	int dados[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, NULL, 0, NULL);

	ll_remover(&ll, ll.inicio, 1);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[0], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
	aux_ll_limpar(&ll_depois);
}

TEST(ll_remover, ListaDoisElementosRemovePrimeiroNaoLiberaMemoria)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 1 }, dados_depois[1] = { 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.inicio, 0);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_EQ(0, memoria_foi_liberada(elementos[0], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
}

TEST(ll_remover, ListaDoisElementosRemovePrimeiroLiberaMemoria)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 1 }, dados_depois[1] = { 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.inicio, 1);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[0], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
}

TEST(ll_remover, ListaDoisElementosRemoveUltimoNaoLiberaMemoria)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 1 }, dados_depois[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.fim, 0);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_EQ(0, memoria_foi_liberada(elementos[1], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
}

TEST(ll_remover, ListaDoisElementosRemoveUltimoLiberaMemoria)
{
	struct lld ll, ll_depois;
	int dados[2] = { 0, 1 }, dados_depois[1] = { 0 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.fim, 1);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[1], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
}

TEST(ll_remover, ListaTresElementosRemovePrimeiroNaoLiberaMemoria)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[2] = { 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.inicio, 0);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_EQ(0, memoria_foi_liberada(elementos[0], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
}

TEST(ll_remover, ListaTresElementosRemovePrimeiroLiberaMemoria)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[2] = { 1, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.inicio, 1);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[0], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
}

TEST(ll_remover, ListaTresElementosRemoveUltimoNaoLiberaMemoria)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.fim, 0);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_EQ(0, memoria_foi_liberada(elementos[2], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
}

TEST(ll_remover, ListaTresElementosRemoveUltimoLiberaMemoria)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[2] = { 0, 1 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.fim, 1);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[2], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
}

TEST(ll_remover, ListaTresElementosRemoveMeioNaoLiberaMemoria)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[2] = { 0, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.inicio->prox, 0);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_EQ(0, memoria_foi_liberada(elementos[1], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
}

TEST(ll_remover, ListaTresElementosRemoveMeioLiberaMemoria)
{
	struct lld ll, ll_depois;
	int dados[3] = { 0, 1, 2 }, dados_depois[2] = { 0, 2 };
	struct lld_el* elementos[sizeof(dados)/sizeof(int)];
	struct lld_el* elementos_depois[sizeof(dados)/sizeof(int)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_ll_preencher(&ll, intcmp, dados, sizeof(dados)/sizeof(int), elementos);
	aux_ll_preencher(&ll_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int), elementos_depois);

	ll_remover(&ll, ll.inicio->prox, 1);

	ASSERT_TRUE(LinkedListConsistent(&ll));
	ASSERT_TRUE(LinkedListsMatch(&ll, &ll_depois));
	ASSERT_NE(0, memoria_foi_liberada(elementos[1], sizeof(struct lld_el))) << "Erro: voce esqueceu de liberar a memoria do elemento removido";

	_CrtSetDbgFlag(tmpFlagOld);

	aux_ll_limpar(&ll);
}
