	BEFORE				AFTER
first  -> next = second  	first  -> next = NULL
second -> next = third		second -> next = first
third  -> next = NULL		third  -> next = second

pre = NULL;
current = *begin_list; (current = first now)

status 1: NULL    first -> second -> third -> NULL
           ↑        ↑
	  prev   current

status 2: NULL <- first  second -> third -> NULL
		    ↑      ↑
	           prev   current

status 3 : NULL <- first <- second  third -> NULL
	     		       ↑      ↑
	                      prev   current

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
