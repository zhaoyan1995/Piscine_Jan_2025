Using Bubble sort when we want to sort a serie of linked lists
Firstly, we need to measure the size of this linked list

Then, we need to use two while loops, the number of comparaison should be size - 1, because if we have 4 linked lists, we need to compare three times to finish up the sort process.
So the first while loop should control in which number of comparaison we are. (the first one, the second one, the third one, the size - 1 th one
the second while loop is to compare two elements side by side, if the first one is bigger than the second one, then we use the ft_swap function to swap the value of the two linked lists. We continue the second loop until the end of the linked lists.

Every time before we start the second while loop to proceed the bubble sort, we need to reset the head of the linked list at the beginning of the linked lists. 

We create a tempo variable to proceed the swap process, but we need to be careful when we want to clarify the nature of the variable tempo, we should not declare the tempo as t_list variable, because we are not allowed to use ft_create_elem here, so we only have to declare void *tempo, then we can swap the value of current->data and the value of current->next->data sucessfully.

In ft_swap we use void **data1 void **data2 so that we could transfer the exchanged value correctly to the ft_list_sort function , otherwise we can not change the value of the begin_list.
