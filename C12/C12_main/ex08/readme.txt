ft_list_reverse(t_list **begin_list);

By using the ft_list_reverse, the new linked list is:

third -> second -> first -> NULL

*next : in order to save the next element in the orignal order

*current : the element we want to use as input to traversal all the t_list element in begin_list

*prev : the element which represent the last element compared to the current one 

Example in main.c
the original linked list is :

first -> second -> third -> NULL

first  -> next = second
second -> next = third
third  -> next = NULL

By using the ft_list_reverse, the new linked list is:

third -> second -> first -> NULL

first  -> next = NULL
second -> next = first
third  -> next = second


	BEFORE				AFTER
first  -> next = second  	first  -> next = NULL
second -> next = third		second -> next = first
third  -> next = NULL		third  -> next = second

pre = NULL;
current = *begin_list; (current = first now)
		
status 1: NULL    first -> second -> third -> NULL
           ↑        ↑
	  prev   current

when current == first (in WHILE loop)
next = current->next  (next = first->next , next = second)
current->next = prev  (first->next = NULL, we linked the first with NULL, this is the end of the new linked list)
prev = current (prev = first, reset the value of prev, in order to prepare for the next loop)
current = next (current = second, reset the value of current, in order to preapre for the next loop)

status 2: NULL <- first  second -> third -> NULL
		    ↑      ↑
	           prev   current

when current == second (in WHILE loop)
next = current->next  (next = second->next , next = third)
current->next = prev  (second->next = first, we linked the second with first, the next element of second is first)
prev = current (prev = second, reset the value of prev, in order to prepare for the next loop)
current = next (current = third, reset the value of current, in order to preapre for the next loop)

status 3 : NULL <- first <- second  third -> NULL
	     		       ↑      ↑
	                      prev   current

when current == third (in WHILE loop)
next = current->next  (next = third->next , next = NULL)
current->next = prev  (third->next = second, we linked the third with second, the next element of third is second)
prev = current (prev = third, reset the value of prev, in order to prepare for the next loop)
current = next (current = NULL, reset the value of current, in order to preapre for the next loop)

status 4 : NULL <- first <- second <- third  NULL
			       ↑        ↑
	                      prev   current

when current == NULL, CAN NOT continue the while loop, so the program stops. 

final step :
	*begin_list = prev

status 5 : NULL <- first <- second <- third  NULL
			                ↑      ↑
	                               prev   current	
			       		↑ 
				    *begin_list
				        ↑	
				     begin_list
