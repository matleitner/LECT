/*
 * UxTXREG registo que irá transmitir a informação 
 * para ativar modo de transmissão: UxSTAbits.UTXEN; após desligar ou reset todas as UART são desligadas.
 *
 * Configuração dos parametros da trama UxMODE, a dimensão da palavra a transmitir tipo de paridad, definidos pelo campo PDSEL (2 bits), 
 * nº de bits de stop, configurado através do bit STSEL do mesmo registo 
 *
 * O relógio que determina a taxa de transmissão e receção é obtido através de uma divisão por 4 ou por 16 (bit BRGH de UxMODE) do relógio gerado pelo módulo BRG.
 *
 * Gestão do "RX FIFO" através do registo UxRXREG
*/
// ################ substitui x pelo número da UART ##################
int main(void){
	// Configuração do UART
	
	// Configurar o gerador de baudrate	
	UxBRG = ;
	UxMODEbits.BRGH = ;
	
	// 2- Configurar parâmetros da trama: dimensão da palavra e tipo de paridade
	UxMODEbits.PDSEL = ;
	UxMODEbits.STSEL = ;	// Configurar o número de stop bits
		
	// 3- Ativar os módulos de transmissão e receção 
	UxSTAbits.UTKEN = ;
	UxSTAbits.URXEN = ;

	// 4- Ativar a UART
	
	UxMODE.ON = ;
	

}
