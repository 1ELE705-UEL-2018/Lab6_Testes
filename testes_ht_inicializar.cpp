#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "ht.h"
}

TEST(ht_inicializar, InicializarTamArray0)
{
	int i;
	const int tam = 8;
	struct ht h = { NULL, 0, NULL };

	ht_inicializar(&h, 0, intcmp, inthash);

	ASSERT_NE((struct lld*)NULL, h.array_ll);
	ASSERT_EQ(tam*sizeof(struct lld), _msize(h.array_ll)) << "Quantidade de memoria alocada para o array de LLs esta' errada";
	ASSERT_EQ(tam, h.tam_array);
	ASSERT_EQ(&inthash, h.hash);

	for (i = 0; i < tam; i++)
	{
		ASSERT_TRUE(LinkedListInitialized(&h.array_ll[i], intcmp));
	}
}

TEST(ht_inicializar, InicializarTamArray16)
{
	int i;
	const int tam = 16;
	struct ht h = { NULL, 0, NULL };

	ht_inicializar(&h, tam, intcmp, inthash);

	ASSERT_NE((struct lld*)NULL, h.array_ll);
	ASSERT_EQ(tam*sizeof(struct lld), _msize(h.array_ll)) << "Quantidade de memoria alocada para o array de LLs esta' errada";
	ASSERT_EQ(tam, h.tam_array);
	ASSERT_EQ(&inthash, h.hash);

	for (i = 0; i < tam; i++)
	{
		ASSERT_TRUE(LinkedListInitialized(&h.array_ll[i], intcmp));
	}
}
