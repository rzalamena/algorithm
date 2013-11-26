#include <sys/queue.h>

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

struct number {
	int			n_number;
	SLIST_ENTRY(number)	n_entry;
};
static SLIST_HEAD(NHEAD, number) nhead = SLIST_HEAD_INITIALIZER(&nhead);

static int
number_cmp(struct number *n, struct number *nn)
{
	if (n->n_number > nn->n_number)
		return (1);
	else if (n->n_number < nn->n_number)
		return (-1);
	return (0);
}

SLIST_MERGESORT_PROTOTYPE_STATIC(NHEAD, number, n_entry)
SLIST_MERGESORT_GENERATE_STATIC(NHEAD, number, n_entry, number_cmp)

int
main(int argc, char *argv[])
{
	struct	 number *n;
	int	 i;

	for (i = 1; i < 500; i++) {
		n = calloc(1, sizeof(*n));
		if (n == NULL)
			err(1, "calloc");

		n->n_number = i;
		SLIST_INSERT_HEAD(&nhead, n, n_entry);
	}

	printf("List:\n");
	SLIST_FOREACH(n, &nhead, n_entry)
		printf(" %d", n->n_number);
	printf("\n");

	SLIST_MERGESORT(NHEAD, &nhead);

	printf("List sorted:\n");
	SLIST_FOREACH(n, &nhead, n_entry)
		printf(" %d", n->n_number);
	printf("\n");

	exit(EXIT_SUCCESS);
}
