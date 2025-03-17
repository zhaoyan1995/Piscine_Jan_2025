search an item from a binary tree:
         a(7)
        /    \
       b(2)   c(3)
      / \      \
   d(4)  e(5)   f(9)


example like below in main function:

void *new;

new = atoi(argv[1]);
argv[1] = "5";
int result = btree_search_item(a, &new, cmp);

so we search number 5 in the binary tree.

void    *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));

Here the return value is void * type, so we only return the root->item once we find the result (not t_btree *root type !!!)


step 1: 
btree_search_item(7, 5, cmpf)
root != NULL || data_ref != NULL
cmpf(7, 5) != 0

step 2:
result = btree_search_item(root->left, 5, cmpf)
result = btree_search_item(2, 5, cmpf)
root != NULL || data_ref != NULL
cmpf(2, 5) != 0

step 3:
result = btree_search_item(root->left, 5, cmpf)
result = btree_search_item(4, 5, cmpf)
root != NULL || data_ref != NULL
cmpf(4, 5) != 0

step 4:
result = btree_search_item(root->left, 5, cmpf) 
result = btree_search_item(NULL, 5, cmpf)
root == NULL || data_ref == NULL

step 5:
root == NULL || data_ref != NULL =>return(0)
backtracking to btree_search_item(4, 5, cmpf)
result == btree_search_item(root->left, 5, cmpf) = NULL;
so 
    return (btree_search_item(root->right, data_ref, cmpf));

step 6:
btree_search_item(root->right, 5, cmpf)
result = btree_search_item(NULL, 5, cmpf)
root == NULL || data_ref != NULL

step 7:
root == NULL || data_ref != NULL =>return(0)
backtracking to btree_search_item(4, 5, cmpf)
backtracking to btree_search_item(2, 5, cmpf)

step 8:
root == NULL || data_ref != NULL =>return(0)
result == NULL
so 
    return (btree_search_item(root->right, data_ref, cmpf));
if (cmpf(5, 5) == 0)
        return (5);

step 9:
result = 5 from the step 8 so 
if (result) is correct then return (result)
then we return 5 at the end, the program finished

The result will be affected by a value ONLY IF the recusive program attain the end of the branch (so result == NULL in this case) OR cmpf(x, x) == 0 (then result == x)
