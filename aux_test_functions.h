#pragma once

extern "C"
{
#include "ll.h"
#include "ht.h"

	int intcmp(void* arg1, void* arg2);
	int inthash(const void* dado, int n);
}

void aux_ll_preencher(struct lld* ll, int(*compar)(void*, void*), int dados[], int tam_lista, struct lld_el* elementos[]);
int aux_ll_consistente(const struct lld* ll);
int aux_ll_iguais(const struct lld* ll1, const struct lld* ll2);
void aux_ll_limpar(struct lld* ll);

void aux_ht_preencher(struct ht* h, int tam_array, int(*compar)(void*, void*), int(*hash)(const void*, int), int dados[], int tam_dados);
int aux_ht_consistente(const struct ht* h);
int aux_ht_iguais(const struct ht* h1, const struct ht* h2);
int aux_ht_contem_mesmos_elementos(const struct ht* h1, const struct ht* h2);
void aux_ht_limpar(struct ht* h);

int memoria_foi_liberada(void* arg, int tam);

::testing::AssertionResult LinkedListInitialized(const struct lld* ll, int (*compar)(void*, void*));
::testing::AssertionResult LinkedListConsistent(const struct lld* ll);
::testing::AssertionResult LinkedListsMatch(const struct lld* ll1, const struct lld* ll2);
::testing::AssertionResult HashTableConsistent(const struct ht* h);
::testing::AssertionResult HashTablesMatch(const struct ht* h1, const struct ht* h2);
