#pragma once

#include "ll.h"

#define ht_el lld_el

struct ht
{
	struct lld* array_ll;
	int tam_array;
	int (*hash)(const void*, int);
};

void ht_inicializar(struct ht* h, int tam_array, int (*compar)(void*, void*), int(*hash)(const void*, int));
void ht_inserir(struct ht* h, void* eln);
struct ht_el* ht_buscar(struct ht* h, void* dado);
void ht_remover(struct ht* h, void* dado);
void ht_redimensionar(struct ht* h, int tam_array);
