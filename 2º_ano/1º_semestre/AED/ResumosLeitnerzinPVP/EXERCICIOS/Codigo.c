//Considere o TAD Arvore Binaria de Inteiros, em que cada nó armazena um numero
//inteiro. Considere que os elementos da arvore se encontram ordenados (in-order ) e que
// não existem elementos repetidos
//Desenvolva uma fun¸c˜ao recursiva eficiente — que n˜ao aceda a n´os desnecess´arios —
//que, dada a raiz da ´arvore, conte o n´umero de elementos pertencentes ao intervalo
//[a, b], b ≥ a


unsigned int CountValuesInRange(pointer root, int a, int b);


CountValuesInRange( Root* root, int a, int b) {
	if(root == NULL) return 0;
	

	if(root->value < a ) return CountValuesInRange(root->right, a, b);
	if (root->value > b) return CountValuesInRange(root->left, a, b); 

	return 1 + CountValuesInRange( root->left, a, b) + CountValuesInRange( root-> right, a,b);
} 
