// struct header_pointer {
// 	node* first 
//	int num_elems
//}



header_pointer* Merge(header_pointer* seq_1, header_pointer* seq_2) {
	node* node_A = seq_1 ? seq_1->first : NULL;
  node* node_B = seq_2 ? seq_2->first : NULL; 
	
	header_pointer* merged_list = malloc(sizeof(header_pointer));
	merged_list->num_elems = 0; merged_list->first =NULL;
	node* cursor = NULL;
	while(node_A && node_B){
		node* newNode = malloc(sizeof(node));
		newNode->next = NULL;
		if(node_A->value <= node_B->value) {
			newNode->value = node_A->value;
			node_A = node_A ->next;
		}	else {
			newNode->value = node_B->value;
			node_B = node_B ->next;
		}
		
	 if(merged_list->first == NULL) {
		merged_list->first = newNode;
			
	 } else {
		cursor->next = newNode; 	
		}
		cursor = newNode;
	 	merged_list->num_elems++;
	}  
	
	while(node_A) {
		node* newNode = malloc(sizeof(node));
		newNode->next= NULL;
		newNode->value = node_A->value;
		if(merged_list->first == NULL) {
    merged_list->first = newNode;
   } else {
    cursor->next = newNode;
    }
    cursor = newNode;
    merged_list->num_elems++;
		node_A = node_A->next; 
	 }

	while(node_B) {
    node* newNode = malloc(sizeof(node));
		newNode->next = NULL;
    newNode->value = node_B->value;
    if(merged_list->first == NULL) {
    merged_list->first = newNode;

   } else {
    cursor->next = newNode;
    }
    cursor = newNode;
    merged_list->num_elems++;
		node_B = node_B->next;
   }
	
	return merged_list;
}
