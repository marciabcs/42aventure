#include "ft_btree.h"
#include <stdio.h>
#include <unistd.h>

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));

void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));

void btree_apply_suffix(t_btree *root, void (*applyf)(void *));

void btree_apply_prefix(t_btree *root, void (*applyf)(void *));

void btree_apply_infix(t_btree *root, void (*applyf)(void *));

int btree_level_count(t_btree *root);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	char	*str;

	str = s;
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*(s1 + i))
	{
		if (*(s2 + i) != *(s1 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	if (*(s2 + i))
		return (*(s1 + i) - *(s2 + i));
	return (0);
}

int main(void)//(int c, char **v)
{
//	t_btree	*root;
//	t_btree	*aux;
	t_btree	*pnode;
//	int		i;
	char	*str[20];

	str[0] = "[---][0]fruit";
	str[1] = "[L--][01]pomme";
	str[2] = "[LL-][011]cerise";
	str[3] = "[LR-][012]banane";
	str[4] = "[LLL][0111]fraise";
	str[5] = "[LRL][0121]abricot";
	str[6] = "[LRR][0122]datte";
	str[7] = "[R--][02]noisette";
	str[8] = "[RL-][021]framboise";
	str[9] = "[RR-][022]peche";
	str[10] = "[RRR][0222]poire";
	str[11] = "[RRRR][02222]mangue";
	pnode = btree_create_node(str[0]);
	pnode->left = btree_create_node(str[1]);
	pnode->left->left = btree_create_node(str[2]);
	pnode->left->right = btree_create_node(str[3]);
	pnode->left->left->left = btree_create_node(str[4]);
	pnode->left->right->left = btree_create_node(str[5]);
	pnode->left->right->right = btree_create_node(str[6]);
	pnode->right = btree_create_node(str[7]);
	pnode->right->left = btree_create_node(str[8]);
	pnode->right->right = btree_create_node(str[9]);
	pnode->right->right->right = btree_create_node(str[10]);
	pnode->right->right->right->right = btree_create_node(str[11]);
	printf("%s\n", (char *)pnode->item);
	printf("%s\n", (char *)pnode->left->item);
	printf("%s\n", (char *)pnode->left->left->item);
	printf("%s\n", (char *)pnode->left->right->item);
	printf("%s\n", (char *)pnode->left->left->left->item);
	printf("%s\n", (char *)pnode->left->right->left->item);
	printf("%s\n", (char *)pnode->left->right->right->item);
	printf("%s\n", (char *)pnode->right->item);
	printf("%s\n", (char *)pnode->right->left->item);
	printf("%s\n", (char *)pnode->right->right->item);
	printf("%s\n", (char *)pnode->right->right->right->item);
	printf("%s\n", (char *)pnode->right->right->right->right->item);
/*	if (c == 1)
		printf("please enter words to create a tree\n");
	else
{
	i = 1;
	while (i < c)
	{
		btree_insert_data(&root, v[i], (int (*)(void *, void *))&ft_strcmp);
		i++;
	}
	aux = root;*/
	printf("\nex05 = %s\n", btree_search_item(pnode, str[6], (int (*)(void *, void *))&ft_strcmp));
	printf("\nimpression suffix de l'arbre cree\n");
	btree_apply_suffix(pnode, (void (*)(void *))&ft_putstr);
//	root = aux;
	printf("\nimpression prefix de l'arbre cree\n");
	btree_apply_prefix(pnode, (void (*)(void *))&ft_putstr);
//	root = aux;
	printf("\nimpression infix de l'arbre cree\n");
	btree_apply_infix(pnode, (void (*)(void *))&ft_putstr);
	printf("\nfonction level count = %d\n", btree_level_count(pnode));
	return (0);
}
