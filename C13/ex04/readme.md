the infix order to traversal the binary tree is :
Left -> Root -> Right

In the function btree_insert_data

we start with a btree that the root == NULL then we insert the datas one by one.

In the main function, we call the btree_insert_data in the following order:
d -> b -> f -> a -> c -> e -> g

By using these functions in main function, we could have the following binary tree:
Example:
        d 
       / \
      b   f
     /\   /\
    a  c e  g

Since that we use infix to print the binary tree, so the output in the command line would be like this :

a -> b -> c -> d -> e -> f -> g

Below is the detailed process:

d -> b -> f -> a -> c -> e -> g

initial : t_btree *root = NULL

Step 0 :  btree_insert_data(&root, "d", ft_strcmp_void_data)
     d

Step 1 :  btree_insert_data(&root, "b", ft_strcmp_void_data)
     d
    /
   b 

Step 2 : btree_insert_data(&root, "f", ft_strcmp_void_data)

     d 
    / \ 
   b   f
 

Step 3 : btree_insert_data(&root, "a", ft_strcmp_void_data)

     d 
    / \ 
   b   f
  / 
 a

Step 4 : btree_insert_data(&root, "c", ft_strcmp_void_data)

     d 
    / \ 
   b   f
  / \  
 a   c

Step 5 : btree_insert_data(&root, "e", ft_strcmp_void_data)

     d 
    / \ 
   b   f
  /\   / 
 a  c e

Step 6 : btree_insert_data(&root, "g", ft_strcmp_void_data)

     d 
    / \ 
   b   f
  /\   /\ 
 a  c e  g


