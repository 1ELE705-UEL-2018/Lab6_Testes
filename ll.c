#include <stddef.h>
#include <stdlib.h>
#include "ll.h"

void ll_inicializar(struct lld* ll, int(*compar)(void*, void*))
{
	ll->inicio = ll->fim = NULL;
	ll->compar = compar;
}

void ll_inserir_elemento_apos(struct lld* ll, struct lld_el* el, struct lld_el* eln)
{
	if (ll->inicio == NULL && ll->fim == NULL)
	{
		ll->inicio = ll->fim = eln;
		eln->ant = eln->prox = NULL;
	}
	else if (el == NULL)
	{
		eln->ant = NULL;
		eln->prox = ll->inicio;
		ll->inicio->ant = eln;
		ll->inicio = eln;
	}
	else if (el == ll->fim)
	{
		eln->ant = ll->fim;
		eln->prox = NULL;
		ll->fim->prox = eln;
		ll->fim = eln;
	}
	else
	{
		eln->ant = el;
		eln->prox = el->prox;
		el->prox->ant = eln;
		el->prox = eln;
	}
}

void ll_inserir_apos(struct lld* ll, struct lld_el* el, void* eln)
{
	struct lld_el* novo_el = malloc(sizeof(struct lld_el));
	novo_el->dado = eln;
	ll_inserir_elemento_apos(ll, el, novo_el);
}

void ll_remover(struct lld* ll, struct lld_el* el, int liberar_memoria)
{
	if (ll->inicio == ll->fim)
	{
		ll->inicio = ll->fim = NULL;
	}
	else if (el == ll->inicio)
	{
		ll->inicio->prox->ant = NULL;
		ll->inicio = ll->inicio->prox;
	}
	else if (el == ll->fim)
	{
		ll->fim->ant->prox = NULL;
		ll->fim = ll->fim->ant;
	}
	else
	{
		el->ant->prox = el->prox;
		el->prox->ant = el->ant;
	}

	if (liberar_memoria != 0)
	{
		free(el);
	}
}

struct lld_el* ll_buscar(struct lld* ll, void* eln)
{
	struct lld_el* atual = ll->inicio;
	while (atual != NULL && ll->compar(atual->dado, eln) != 0)
	{
		atual = atual->prox;
	}

	return atual;
}
