#include <stdio.h>

int main(void)
{
	FILE *arquivo;
	char jnome[30], sobrenome[30], numero[30];
	int num;
		
	arquivo = fopen("contatos.vcf", "w+");
		
	printf("\n\nSistema de Cadastrar Pacote de Numeros para Celular\n");

	if(arquivo == NULL){
		printf("Erro! Nao foi possivel abrir o arquivo\n");
	} else{
			
		while(num != 1){
			
			fprintf(arquivo, "BEGIN:VCARD\n");
			fprintf(arquivo, "VERSION:2.1\n");
					
			fflush(stdin);
			printf("\n\nNome = ");
			scanf("%s", jnome);
				
			fflush(stdin);
			printf("SobreNome = ");
			scanf("%s", sobrenome);
				
			fflush(stdin);	
			printf("Numero = ");
			scanf("%s", &numero);
			fflush(stdin);	
				
			fprintf(arquivo, "N:%s;%s;;;\n", sobrenome, jnome);
			fprintf(arquivo, "FN:%s %s\n", jnome, sobrenome);
			fprintf(arquivo, "TEL;CELL:%s\n", numero);
			fprintf(arquivo, "END:VCARD\n");
			
			printf("\n\nNome: %s - Sobrenome: %s - Numero: %s ", jnome, sobrenome, numero);
			printf("\nContato adicionado com sucesso\n\n");
							
			printf("Finalizar? (sim = 1/nao = 0) ");
			scanf("%d", &num);
		}
		fclose(arquivo);
	}
	return 0;
}

