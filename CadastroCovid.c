#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


typedef struct CadastroPacienteStruct{
    char nome[40];
    char cpf[11];
    char telefone[11];
    char email[40];
    int dia;
    int mes;
    int ano;
    char comorbidade[40];
    int anoDiag;
    char rua[40];
    char bairro[30];
    char numero[6];
    char cep[20];
    char cidade[20];
    char estado[20];
}Paciente;

typedef struct{
    char login[30];
    char senha[30];

}   pessoa; pessoa p1[1];

int escolha = 0;
Paciente *pac;
FILE *arquivo;
char paciente_dir[] = "Paciente.bin";

void menuPaciente();
Paciente receberPaciente();
void inserirPaciente();

int main()
{
    char login[30];
    char senha[30];
    int x;

    strcpy(p1[0].login, "Administrador");
    strcpy(p1[0].senha, "12345");
    do{
    printf("\n*************************************");
    printf("\n\tTELA LOGIN");
    printf("\n*************************************");
    printf("\n\tDigite o login: ");
    scanf("%s",login);
    printf("\n\tDigite a senha: ");
    scanf("%s",senha);
     x = 0;

    if ((strcmp(login,p1[0].login)==0) && (strcmp(senha,p1[0].senha)==0)){
        printf("\n\tUsuario logado");
        x=x+1;
        system("cls");
    }else{
          system("cls");
        printf("\n\tLogin e/ou senha incorretos tentar novamente");


    }
    }while (x<1);
    menuPaciente();
    return 0;
}
void menuPaciente(){
   do{
            int escolha;
    printf("\n********************************");
    printf("\n\tMENU PRINCIPAL");
    printf("\n********************************");
    printf("\n1-Cadastrar paciente");
    printf("\n2-Sair\n");
    scanf("\n%d",&escolha);
    switch(escolha)
    {
    case 1:
    fflush(stdin);
    system("cls");
    receberPaciente();
    break;
    case 2:
    printf("Encerado");
    default:
    printf("Op��o invalida");
    fflush(stdin);

    }
    }
    while(escolha != 0);

}
void removerQuebraLinha(char *string){
    if(string != NULL && strlen(string) > 0){
        short tamanho = strlen(string);
        if(string[tamanho-1]=='\n'){
            string[tamanho-1]='\0';
        }
    }
}
void receberString(char *string_destino, int quantidade_caracter){
    fgets(string_destino, quantidade_caracter, stdin);
    removerQuebraLinha(string_destino);
}
Paciente receberPaciente(){
    Paciente p;

    printf("\n********************************");
    printf("\n\tCADASTRAR PACIENTE");
    printf("\n********************************");
    printf("\nNome: ");
    receberString(p.nome,39);
    printf("\nCPF: ");
    receberString(p.cpf,11);
    fflush(stdin);
    printf("\nEmail: ");
    receberString(p.email,39);
    printf("\ndia de nascimento: ");
    scanf("\n%d",&p.dia);
    printf("\nmes de nascimento: ");
    scanf("\n%d",&p.mes);
    printf("\nano de nascimento: ");
    scanf("\n%d",&p.ano);
    printf("\nAno atual: ");
    scanf("\n%d",&p.anoDiag);
    fflush(stdin);
    system("cls");
    printf("\n********************************");
    printf("\n\fENDERECO DO PACIENTE");
    printf("\n********************************");
    printf("\nRua: ");
    receberString(p.rua,39);
    fflush(stdin);
    printf("\nBairro: ");
    receberString(p.bairro,30);
    printf("\nNumero: ");
    receberString(p.numero,6);
    fflush(stdin);
    printf("\nCep: ");
    receberString(p.cep,20);
    fflush(stdin);
    printf("\nCidade: ");
    receberString(p.cidade,20);
    printf("\nEstado: ");
    receberString(p.estado,20);
    system("cls");
    printf("\n********************************");
    printf("\n\fHISTORICO MEDICO");
    printf("\n********************************");
    printf("\nComorbidades: ");
    receberString(p.comorbidade,39);

    verificaIdade(p);
    return p;

}
verificaIdade(Paciente p){
    int idade = p.anoDiag-p.ano;
    if(idade<65){
        printf("O paciente tem menos de 65 anos n�o pertence ao grupo de risco.");
    }else{
            escreverArquivo(p.nome,p.cep,idade);
    }

}
escreverArquivo(char nome[40],char cep[40],int idade){
    FILE *f = fopen("C:\\Users\\Marcos\\OneDrive\\�rea de Trabalho\\Linguagem C\\dadospaciente.txt", "w");
if (f == NULL)
{
    printf("Error opening file!\n");
    exit(1);
}




fprintf(f,cep);





fclose(f);
}


