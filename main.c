#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//A struct cria login e senha para os usuários do sistema e armazena em uma lista
typedef struct Usuario{
   char login[15];
   char senha[9];
   struct Usuario *proximo;
} Usuario;

//Inicia a struct Usuario vazia
Usuario* iniciaUsuario(){
   return NULL;
};

//Insere um novo usuário
Usuario* insereUsuario(Usuario* listaUsuarios, char login[15], char senha[9]){
   Usuario* usuario = (Usuario*)malloc(sizeof(Usuario));
   strcpy(usuario->login, login);
   strcpy(usuario->senha, senha);
   usuario->proximo = listaUsuarios;
   return usuario;
};

//Exclui um usuário através do seu Login
Usuario* retiraUsuario(Usuario* listaUsuarios, char login[15]){
   Usuario* anterior = NULL;  //Ponteiro para o usuário anterior
   Usuario* aux = listaUsuarios;  //Ponteiro auxiliar para percorrer a lista de usuários

   //Procura o usuário na lista, guardando o usuário anterior
   while (aux != NULL && !(strcmp(aux->login, login) == 0)){
      anterior = aux;
      aux = aux->proximo;
   }

   //Verifica se encontrou o usuário
   if (aux == NULL){
      return listaUsuarios;  //Não encontrou, retorna a lista original
   }

   if (anterior == NULL){
       listaUsuarios = aux->proximo; //Retira o usuário do início da lista
   } else {
       anterior->proximo = aux->proximo; //Retira usuário do meio da lista
   }
   free(aux); //Libera espaço na memória usado para alocar a variável
   return listaUsuarios;
}

//Busca um usuário
Usuario* buscaUsuario(Usuario* listaUsuarios, char login[15]){
   Usuario* aux;

   for (aux = listaUsuarios; aux != NULL; aux = aux->proximo){
      if (strcmp(aux->login, login) == 0)
         return aux;
   }
   return NULL;
}

//Imprime a lista de usuários
void imprimeUsuarios(Usuario* listaUsuarios){
   Usuario* aux;
   for (aux = listaUsuarios; aux != NULL; aux = aux->proximo){
       printf("Login: %s\n", aux->login);
       printf("Senha: %s\n", aux->senha);
       printf("\n\n");
   }
   free(aux);
}

//A struct armazena os dados de cada paciente em uma lista
typedef struct Paciente{
   char nome[51];
   char cpf[12];
   char telefone[12];
   char rua[51];
   char numeroCasa[6];
   char bairro[31];
   char cidade[31];
   char estado[3];
   char cep[9];
   int diaNascimento;
   int mesNascimento;
   int anoNascimento;
   int idade;
   char email[61];
   int diaDiagnostico;
   int mesDiagnostico;
   int anoDiagnostico;
   int possuiComorbidade;
   char comorbidade[21];
   struct Paciente *proximo;
} Paciente;

//Inicia a struct Paciente vazia
Paciente* iniciaPaciente(){
   return NULL;
};

//Insere um novo paciente
Paciente* inserePaciente(Paciente* listaPacientes, char nome[51], char cpf[12], char telefone[12], char rua[51],
                 char numeroCasa[6], char bairro[31], char cidade[31], char estado[3], char cep[9],
                 int diaNascimento, int mesNascimento, int anoNascimento, char email[61],
                 int diaDiagnostico, int mesDiagnostico, int anoDiagnostico, int possuiComorbidade,
                 char comorbidade[21], int idade){
   Paciente* paciente = (Paciente*)malloc(sizeof(Paciente));
   strcpy(paciente->nome, nome);
   strcpy(paciente->cpf, cpf);
   strcpy(paciente->telefone, telefone);
   strcpy(paciente->rua, rua);
   strcpy(paciente->numeroCasa, numeroCasa);
   strcpy(paciente->bairro, bairro);
   strcpy(paciente->cidade, cidade);
   strcpy(paciente->estado, estado);
   strcpy(paciente->cep, cep);
   paciente->diaNascimento = diaNascimento;
   paciente->mesNascimento = mesNascimento;
   paciente->anoNascimento = anoNascimento;
   strcpy(paciente->email, email);
   paciente->diaDiagnostico = diaDiagnostico;
   paciente->mesDiagnostico = mesDiagnostico;
   paciente->anoDiagnostico = anoDiagnostico;
   paciente->possuiComorbidade = possuiComorbidade;
   strcpy(paciente->comorbidade, comorbidade);
   paciente->idade = idade;
   paciente->proximo = listaPacientes;
   return paciente;
};

//Exclui um paciente, pedindo como parâmetro seu CPF
Paciente* retiraPaciente(Paciente* listaPacientes, char cpf[12]){
   Paciente* anterior = NULL;  //Ponteiro para o paciente anterior
   Paciente* aux = listaPacientes;  //Ponteiro auxiliar para percorrer a lista de pacientes

   //Procura o paciente na lista, guardando o paciente anterior
   while (aux != NULL && !strcmp(aux->cpf, cpf) == 0){
      anterior = aux;
      aux = aux->proximo;
   }

   //Verifica se encontrou o paciente
   if (aux == NULL){
      return listaPacientes;  //Não encontrou, retorna a lista original
   }

   if (anterior == NULL){
       listaPacientes = aux->proximo; //Retira o paciente do início da lista
   } else {
       anterior->proximo = aux->proximo; //Retira paciente do meio da lista
   }
   free(aux); //Libera espaço na memória usado para alocar a variável
   return listaPacientes;
}

//Busca um paciente por seu CPF
Paciente* buscaPaciente(Paciente* listaPacientes, char cpf[12]){
   Paciente* aux;
   for (aux = listaPacientes; aux != NULL; aux = aux->proximo){
       if (strcmp(aux->cpf,cpf) == 0){
          return aux;
       }
   }
   return NULL;
}

//Imprime a lista de pacientes
void imprimePacientes(Paciente* listaPacientes){
   Paciente* aux;
   for (aux = listaPacientes; aux != NULL; aux = aux->proximo){
       //Dar printf nas informações dos pacientes
       printf("Nome: %s\n", aux->nome);
       printf("CPF: %s\n", aux->cpf);
       printf("Telefone: %s\n", aux->telefone);
       printf("Endereço: %s, %s\n", aux->rua, aux->numeroCasa);
       printf("Bairro: %s\n", aux->bairro);
       printf("Cidade: %s - %s\n", aux->cidade, aux->estado);
       printf("CEP: %s\n", aux->cep);
       printf("Data de nascimento: %d/%d/%d\n", aux->diaNascimento, aux->mesNascimento, aux->anoNascimento);
       printf("Idade: %d\n", aux->idade);
       printf("E-mail: %s\n", aux->email);
       printf("Data de diagnostico: %d/%d/%d\n", aux->diaDiagnostico, aux->mesDiagnostico, aux->anoDiagnostico);
       printf("Comorbidade: %s\n", aux->comorbidade);
       printf("\n\n");
   }
   free(aux);
}

//A struct armazena o CEP e idade dos pacientes que pertencem ao grupo de risco
typedef struct Risco{
   char cep[9];
   int idade;
   struct Risco *proximo;
} Risco;

//Inicia a struct Risco vazia
Risco* iniciaRisco(){
   return NULL;
}

//Insere um novo paciente que está no grupo de risco
Risco* insereRisco(Risco* listaRisco, char cep[9], int idade){
   Risco* risco = (Risco*)malloc(sizeof(Risco));
   strcpy(risco->cep, cep);
   risco->idade = idade;
   risco->proximo = listaRisco;
   return risco;
};

//Imprime a lista de pacientes em grupo de risco, contendo CEP e idade
void imprimeRisco(Risco* listaRisco){
   Risco* aux;
   for (aux = listaRisco; aux != NULL; aux = aux->proximo){
       printf("CEP: %s\n", aux->cep);
       printf("Idade: %d\n", aux->idade);
       printf("\n\n");
   }
}

//Função para salvar a lista de usuários em um arquivo txt
void salvarUsuarios(Usuario* listaUsuarios){
   Usuario* aux;
   FILE* arquivoUsuarios = fopen("usuarios.txt", "w");

   if (arquivoUsuarios){
      for (aux = listaUsuarios; aux != NULL; aux = aux->proximo){
         fprintf(arquivoUsuarios, "%s,%s;\n", aux->login, aux->senha);
      }
      fclose(arquivoUsuarios);
   } else {
      printf("\nERRO! Não foi possivel abrir o arquivo\n");
   }
}

//Função para ler os usuários de um arquivo txt
Usuario* lerUsuarios(Usuario* listaUsuarios){
   char login[15];
   char senha[9];
   FILE* arquivoUsuarios = fopen("usuarios.txt", "r");

   if (arquivoUsuarios){
      while (fscanf(arquivoUsuarios, "%14[^,],%8[^\;];\n", login, senha) != -1){
         listaUsuarios = insereUsuario(listaUsuarios, login, senha);
      }
      fclose(arquivoUsuarios);
   } else {
      printf("\nERRO! Não foi possivel abrir o arquivo\n");
   }

   return listaUsuarios;
}

//Função para salvar os pacientes em um arquivo txt
void salvarPacientes(Paciente* listaPacientes){
   Paciente* aux;
   FILE* arquivoPacientes = fopen("pacientes.txt", "w");

   if (arquivoPacientes){
      for (aux = listaPacientes; aux != NULL; aux = aux->proximo){
         fprintf(arquivoPacientes, "Nome: %s,\nCPF: %s,\nTelefone: %s,\nEndereço: %s, %s,\nBairro: %s,\nCidade:%s-%s,\nCEP: %s,\nData de nascimento: %d/%d/%d,\nE-mail: %s,\nData de diagnóstico: %d/%d/%d,\nPossui comorbidade: %d,\nComorbidade: %s,\nIdade: %d;\n\n",
                 aux->nome, aux->cpf, aux->telefone, aux->rua, aux->numeroCasa, aux->bairro, aux->cidade, aux->estado,
                 aux->cep,  aux->diaNascimento, aux->mesNascimento, aux->anoNascimento, aux->email, aux->diaDiagnostico,
                 aux->mesDiagnostico, aux->anoDiagnostico, aux->possuiComorbidade, aux->comorbidade, aux->idade);
      }
      fclose(arquivoPacientes);
   } else {
      printf("\nERRO! Não foi possivel abrir o arquivo\n");
   }
}

//Função para ler os pacientes de um arquivo txt
Paciente* lerPacientes(Paciente* listaPacientes){
   Paciente* aux;
   char nome[51];
   char cpf[12];
   char telefone[12];
   char rua[51];
   char numeroCasa[6];
   char bairro[31];
   char cidade[31];
   char estado[3];
   char cep[9];
   int diaNascimento;
   int mesNascimento;
   int anoNascimento;
   int idade;
   char email[61];
   int diaDiagnostico;
   int mesDiagnostico;
   int anoDiagnostico;
   int possuiComorbidade;
   char comorbidade[21];
   FILE* arquivoPacientes = fopen("pacientes.txt", "r");

   if (arquivoPacientes){
      while (fscanf(arquivoPacientes, "Nome: %50[^,],\nCPF: %11[^,],\nTelefone: %11[^,],\nEndereço: %50[^,], %5[^,],\nBairro: %30[^,],\nCidade: %30[^-]-%2[^,],\nCEP: %8[^,],\nData de nascimento: %d/%d/%d,\nE-mail: %60[^,],\nData de diagnóstico: %d/%d/%d,\nPossui comorbidade: %d,\nComorbidade: %20[^,],\nIdade: %d;\n\n",
                    nome, cpf, telefone, rua, numeroCasa, bairro, cidade, estado, cep, &diaNascimento, &mesNascimento,
                    &anoNascimento, email, &diaDiagnostico, &mesDiagnostico, &anoDiagnostico,
                    &possuiComorbidade, comorbidade, &idade) != -1){
         listaPacientes = inserePaciente(listaPacientes, nome, cpf, telefone, rua, numeroCasa, bairro, cidade,
                                         estado, cep, diaNascimento, mesNascimento, anoNascimento, email,
                                         diaDiagnostico, mesDiagnostico, anoDiagnostico, possuiComorbidade,
                                         comorbidade, idade);
      }
      fclose(arquivoPacientes);
   } else {
      printf("\nERRO! Não foi possivel abrir o arquivo\n");
   }

   return listaPacientes;
}

//Função para salvar idade e CEP dos pacientes do grupo de risco em um arquivo txt
void salvarRisco(Risco* listaGruposRisco){
   Risco* aux;
   FILE* arquivoRisco = fopen("gruposderisco.txt", "w");

   if (arquivoRisco){
      for (aux = listaGruposRisco; aux != NULL; aux = aux->proximo){
         fprintf(arquivoRisco, "CEP: %s,\nIdade: %d;\n\n", aux->cep, aux->idade);
      }
      fclose(arquivoRisco);
   } else {
      printf("\nERRO! Não foi possivel abrir o arquivo\n");
   }
}

//Função para ler os pacientes de grupo de risco de um arquivo txt
Risco* lerRisco(Risco* listaGruposRisco){
   char cep[9];
   int idade;
   FILE* arquivoRisco = fopen("gruposderisco.txt", "r");

   if (arquivoRisco){
      while (fscanf(arquivoRisco, "CEP: %8[^,],\nIdade: %d;\n\n", cep, &idade) != -1){
         listaGruposRisco = insereRisco(listaGruposRisco, cep, idade);
      }
      fclose(arquivoRisco);
   } else {
      printf("\nERRO! Não foi possivel abrir o arquivo\n");
   }

   return listaGruposRisco;
}

//Função para cadastrar um usuário no sistema
Usuario* cadastrarUsuario(Usuario* listaUsuarios){
   //Criando as variáveis de login e senha
   Usuario* conferirLogin;
   char login[15];
   char senha[9];

   //Tela de cadastro de usuário
   printf("******************************************\n");
   printf("**********CADASTRO DE USUARIO*************\n");
   printf("******************************************\n\n");

   //Solicita que o usuário informe o login de até 14 caracteres
   do{
   fflush(stdin);
   printf("Informe seu login de 10 ate 14 caracteres:\n");
   gets(login);
   conferirLogin = buscaUsuario(listaUsuarios, login);
   if (conferirLogin != NULL)
      printf("ERRO! Login ja foi cadastrado\n\n");
   if (strlen(login) < 10 || strlen(login) > 14)
       //Apresenta um erro se o usuário digitar um login com mais de 14 caracteres
       printf("ERRO! O login deve conter entre 10 e 14 caracteres\n\n");
   } while (strlen(login) < 10 || strlen(login) > 14 || conferirLogin != NULL); //Repete até que o login esteja correto
   //Solicita que o usuário informe uma senha de até 8 caracteres
   do{
   fflush(stdin);
   printf("Informe uma senha de 6 ate 8 caracteres:\n");
   gets(senha);
   if (strlen(senha) < 6 || strlen(senha) > 8)
      //Apresenta um erro se o usuário digitar uma senha com mais de 8 caracteres
      printf("ERRO! A senha deve conter de 6 ate 8 caracteres\n\n");
   } while (strlen(senha) < 6 || strlen(senha) > 8);  //Repete até que a senha esteja correta
   printf("\n");

   //Insere o usuário cadastrado na lista de usuários e retorna a lista
   listaUsuarios = insereUsuario(listaUsuarios, login, senha);
   return listaUsuarios;
};

//Função para fazer login no sistema
int login(Usuario* listaUsuarios){
   char loginUsuario[15];
   char senhaUsuario[9];
   int sucessoLogin = 0;
   Usuario* usuario; //Usuário encontrado pela busca

   //Pedindo login e senha para o usuário
   printf("*****************************************\n");
   printf("*************TELA DE LOGIN***************\n");
   printf("*****************************************\n\n");
   do{
      printf("Login: ");
      fflush(stdin);
      gets(loginUsuario);
      if (strlen(loginUsuario) < 10 || strlen(loginUsuario) > 14)
         printf("ERRO! Comprimento invalido do login\n");
   } while (strlen(loginUsuario) < 10 || strlen(loginUsuario) > 14);
   do{
      printf("Senha: ");
      gets(senhaUsuario);
      if (strlen(senhaUsuario) < 6 || strlen(senhaUsuario) > 8)
         printf("ERRO! Comprimento invalido da senha\n");
   } while (strlen(senhaUsuario) < 6 || strlen(senhaUsuario) > 8);
   usuario = buscaUsuario(listaUsuarios, loginUsuario);
   if (usuario == NULL){
      sucessoLogin = 0;
      printf("Usuario invalido!\n");
      system("pause");
      return sucessoLogin;
   }
   if (strcmp(senhaUsuario, usuario->senha) == 1 || strcmp(loginUsuario, usuario->login) == 1){
      sucessoLogin = 0;
      printf("Senha invalida!\n");
      system("pause");
      return sucessoLogin;
   }
   if (strcmp(senhaUsuario, usuario->senha) == 0){
      sucessoLogin = 1;
      printf("Bem vindo %s. Login realizado com sucesso!\n", usuario->login);
      system("pause");
      return sucessoLogin;
   }
   return sucessoLogin;
}

//Função para mudar a senha do usuario
Usuario* alterarSenha(Usuario* listaUsuarios){
   Usuario* usuario = usuario;
   char login[15];
   char senha[9];

   printf("*********************************************\n");
   printf("***********ALTERACAO DE SENHA****************\n");
   printf("*********************************************\n\n");
   printf("Login: ");
   fflush(stdin);
   gets(login);
   do {
      printf("Nova senha: ");
      gets(senha);
      if (strlen(senha) < 6 || strlen(senha) > 8)
         printf("ERRO! A senha deve conter de 6 ate 8 caracteres\n\n");
   } while (strlen(senha) < 6 || strlen(senha) > 8);
   usuario = buscaUsuario(listaUsuarios, login);
   if (usuario == NULL){
      printf("Usuario invalido!\n");
   } else {
      listaUsuarios = retiraUsuario(listaUsuarios, login);
      listaUsuarios = insereUsuario(listaUsuarios, login, senha);
      printf("Senha alterada com sucesso!\n");
      system("pause");
   }
   printf("\n");

   return listaUsuarios;
}

//Função para validar informações que não permitem números e caracteres especiais
int validarInformacoesAlfabeticasPaciente(char informacao[51]){
   int infoValida;
   int i;
   for (i=0; i < strlen(informacao); i++){
      if (!isalpha(informacao[i]) && !isblank(informacao[i]) && !isspace(informacao[i])){
         infoValida = 0;
      } else {
         infoValida = 1;
      }
   }
   return infoValida;
}

//Função para validar informações que só permitem números, como CPF e telefone
int validarInformacoesNumericasPaciente(char informacaoNum[12]){
   int infoValida;
   int i;
   for (i=0; i < strlen(informacaoNum); i++){
      if (!isdigit(informacaoNum[i])){
         infoValida = 0;
      } else {
         infoValida = 1;
      }
   }
   return infoValida;
}

//Função para validar o estado
int validarEstado(char estadoSigla[3]){
   int estadoValido;
   int i;
   for (i=0; i < strlen(estadoSigla); i++){
      if (!isalpha(estadoSigla[i])){
         estadoValido = 0;
      } else {
         estadoValido = 1;
      }
   }
   return estadoValido;
}

//Função para verificar se ano é bissexto
int verificaAnoBissexto(int ano){
   int validarBissexto;
   int anoAmostra;
   anoAmostra = ano;

   //Se o ano for divisível por 4 e não for divisível por 100, então ele é bissexto
   //Se o ano não for divisível por 4, porém for divisível por 400, então ele é bissexto
   if (anoAmostra % 4 == 0 && anoAmostra % 100 != 0){
      validarBissexto = 1;
      return validarBissexto;
   } else {
      if (anoAmostra % 400 == 0){
         validarBissexto = 1;
         return validarBissexto;
      } else {
         validarBissexto = 0;
      }
   }
   return validarBissexto;
}

//Função para validar data
int validarData(int diaVerificar, int mesVerificar, int anoVerificar){
   int dia = diaVerificar;
   int mes = mesVerificar;
   int ano = anoVerificar;
   int validarData = 1;

   if (mes < 1 || mes > 12){
      validarData = 0;
      return validarData;
   }
   if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia < 1 || dia > 31)){
      validarData = 0;
      return validarData;
   }
   if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia < 1 || dia > 30)){
      validarData = 0;
      return validarData;
   }
   if (mes == 2 && verificaAnoBissexto(ano) == 0 && (dia < 1 || dia > 28)){   //Se não for bissexto
      validarData = 0;
      return validarData;
   }
   if (mes == 2 && verificaAnoBissexto(ano) == 1 && (dia < 1 || dia > 29)){   //Se for bissexto
      validarData = 0;
      return validarData;
   }

   return validarData;
}

//Função para calcular idade do paciente
int idadePaciente(int diaNascimento, int mesNascimento, int anoNascimento){
   int diaAtual, mesAtual, anoAtual, idade;

   //Ponteiro para struct da biblioteca time.h que armazena data e hora
   struct tm *dataAtual;

   //Obtendo o tempo atual em segundos
   time_t segundos;
   time(&segundos);

   //Utilizando a função localtime para converter de segundos para o tempo atual
   dataAtual = localtime(&segundos);

   //Utilizando a struct para obter dia, mês e ano atuais
   diaAtual = dataAtual->tm_mday;
   mesAtual = dataAtual->tm_mon+1;     //É necessário somar 1 para obter o mês correto
   anoAtual = dataAtual->tm_year+1900;     //Para obter o ano atual, é necessário somar 1900

   //Cálculo da idade do paciente
   idade = anoAtual - anoNascimento;
   if (mesAtual < mesNascimento){
      idade = idade - 1;
      return idade;
   }
   if (mesAtual == mesNascimento && diaAtual < diaNascimento){
      idade = idade - 1;
      return idade;
   }
   return idade;
}

//Função que insere em uma lista o CEP e idade dos pacientes que possuem comorbidades ou tenham acima de 65 anos
Risco* adicionarGruposRisco(Risco* listaGruposRisco, Paciente* listaPacientes){
   Paciente* aux = (Paciente*)malloc(sizeof(Paciente));

   for (aux = listaPacientes; aux != NULL; aux = aux->proximo){
      if (aux->idade >= 65 || aux->possuiComorbidade == 1)
         listaGruposRisco = insereRisco(listaGruposRisco, aux->cep, aux->idade);
   }

   return listaGruposRisco;
}

//Função para cadastrar um paciente
Paciente* cadastrarPaciente(Paciente* listaPacientes){
   //Criando as variáveis de atributos do paciente
   char nome[51];
   char cpf[12];
   char telefone[12];
   char rua[51];
   char numeroCasa[6];
   char bairro[31];
   char cidade[31];
   char estado[3];
   char cep[9];
   int diaNascimento;
   int mesNascimento;
   int anoNascimento;
   char email[61];
   int diaDiagnostico;
   int mesDiagnostico;
   int anoDiagnostico;
   int possuiComorbidade;
   char comorbidade[21];
   int idade;

   Paciente* conferirCadastro;

   //Tela de cadastro de pacientes
   printf("***********************************************************\n");
   printf("*************CADASTRO DO PACIENTE COM COVID-19*************\n");
   printf("***********************************************************\n\n");
   //Nome do paciente
   do{
      fflush(stdin);
      printf("Nome: ");
      gets(nome);
      if (validarInformacoesAlfabeticasPaciente(nome) == 0 || strlen(nome) > 50)
         printf("ERRO! Utilizar no maximo 50 caracteres, sem incluir numeros ou caracteres especiais\n");
   } while (strlen(nome) > 50 || validarInformacoesAlfabeticasPaciente(nome) == 0);

   //CPF do paciente
   do{
      printf("\nCPF: ");
      gets(cpf);
      conferirCadastro = buscaPaciente(listaPacientes, cpf);
      if (conferirCadastro != NULL)
         printf("ERRO! CPF ja consta no sistema\n");
      if (validarInformacoesNumericasPaciente(cpf) == 0 || strlen(cpf) != 11)
         printf("ERRO! CPF deve conter apenas 11 caracteres numericos\n");
   } while (strlen(cpf) != 11 || validarInformacoesNumericasPaciente(cpf) == 0 || conferirCadastro != NULL);

   //Telefone do paciente
   do{
      printf("\nTelefone: ");
      gets(telefone);
      if (validarInformacoesNumericasPaciente(telefone) == 0 || strlen(telefone) < 10 || strlen(telefone) > 11)
         printf("ERRO! Telefone deve conter apenas valores numericos, sendo 10 numeros para fixo ou 11 para celular\n");
   } while (strlen(telefone) < 10 || strlen(telefone) > 11 || validarInformacoesNumericasPaciente(telefone) == 0);

   //Endereço do paciente
   do{
      printf("\nRua: ");
      gets(rua);
      if (strlen(rua) > 60)
         printf("ERRO! Endereco deve conter no maximo 60 caracteres\n");
   } while (strlen(rua) > 60);
   do{
      printf("\nNumero da casa: ");
      gets(numeroCasa);
      if (strlen(numeroCasa) > 6 || validarInformacoesNumericasPaciente(numeroCasa) == 0)
         printf("ERRO! Utilizar ate 6 caracteres numericos no preenchimento\n");
   } while (strlen(numeroCasa) > 6 || validarInformacoesNumericasPaciente(numeroCasa) == 0);
   do{
      printf("\nBairro: ");
      gets(bairro);
      if (strlen(bairro) > 30 || validarInformacoesAlfabeticasPaciente(bairro) == 0)
         printf("ERRO! Bairro deve conter no maximo 30 caracteres, sem incluir numeros ou caracteres especiais\n");
   } while (strlen(bairro) > 30 || validarInformacoesAlfabeticasPaciente(bairro) == 0);
   do{
      printf("\nCidade: ");
      gets(cidade);
      if (strlen(cidade) > 30 || validarInformacoesAlfabeticasPaciente(cidade) == 0)
         printf("ERRO! Cidade deve conter no maximo 30 caracteres, sem incluir numeros ou caracteres especiais\n");
   } while (strlen(cidade) > 30 || validarInformacoesAlfabeticasPaciente(cidade) == 0);
   do{
      printf("\nEstado (Sigla): ");
      gets(estado);
      if (strlen(estado) != 2 || validarEstado(estado) == 0)
         printf("ERRO! Preencher o estado com sua sigla contendo 2 caracteres alfabeticos\n");
   } while (strlen(estado) != 2 || validarEstado(estado) == 0);
   do{
      printf("\nCEP: ");
      gets(cep);
      if (strlen(cep) != 8 || validarInformacoesNumericasPaciente(cep) == 0)
         printf("ERRO! Formato invalido, favor digitar um CEP com 8 numeros\n");
   } while (strlen(cep) != 8 || validarInformacoesNumericasPaciente(cep) == 0);

   //E-mail do paciente
   do{
   printf("\nE-mail: ");
   gets(email);
   if (strlen(email) > 60)
      printf("ERRO! E-mail não pode conter mais de 60 caracteres\n");
   } while (strlen(email) > 60);

   //Data de nascimento do paciente
   do{
      printf("\nData de nascimento:\n");
      fflush(stdin);
      printf("Dia: ");
      scanf("%d", &diaNascimento);
      printf("Mes: ");
      scanf("%d", &mesNascimento);
      printf("Ano: ");
      scanf("%d", &anoNascimento);
      if (validarData(diaNascimento, mesNascimento, anoNascimento) == 0)
         printf("ERRO! Data inválida\n");
   } while (validarData(diaNascimento, mesNascimento, anoNascimento) == 0);

   //Data de diagnóstico
   do{
      printf("\nData de diagnostico:\n");
      fflush(stdin);
      printf("Dia: ");
      scanf("%d", &diaDiagnostico);
      printf("Mes: ");
      scanf("%d", &mesDiagnostico);
      printf("Ano: ");
      scanf("%d", &anoDiagnostico);
      if (validarData(diaDiagnostico, mesDiagnostico, anoDiagnostico) == 0)
         printf("ERRO! Data inválida\n");
   } while (validarData(diaDiagnostico, mesDiagnostico, anoDiagnostico) == 0);

   //Paciente possui comorbidade ou não
   do{
      printf("\nPossui alguma comorbidade? (0-Nao, 1-Sim): ");
      fflush(stdin);
      scanf("%d", &possuiComorbidade);
      if (possuiComorbidade < 0 || possuiComorbidade > 1)
         printf("ERRO! Digite 0 se não possui comorbidade ou 1 se possui comorbidade\n");
   } while (possuiComorbidade < 0 || possuiComorbidade > 1);
      //Tipo de comorbidade
   if (possuiComorbidade == 1){
      do{
         printf("\nTipo de comorbidade: ");
         fflush(stdin);
         gets(comorbidade);
         if (strlen(comorbidade) > 20 || validarInformacoesAlfabeticasPaciente(comorbidade) == 0)
            printf("ERRO! Utilizar no maximo 20 caracteres, sem incluir numeros ou caracteres especiais\n");
      } while (strlen(comorbidade) > 20 || validarInformacoesAlfabeticasPaciente(comorbidade) == 0);
   }
   if (possuiComorbidade == 0){
      strcpy(comorbidade, "Nao possui");
      printf("\n");
    printf("\n");
   }

   //Calculando a idade do paciente
   idade = idadePaciente(diaNascimento, mesNascimento, anoNascimento);

   //Insere o paciente cadastrado na lista de pacientes e retorna a lista
   listaPacientes = inserePaciente(listaPacientes, nome, cpf, telefone, rua, numeroCasa, bairro, cidade, estado,
                              cep, diaNascimento, mesNascimento, anoNascimento, email, diaDiagnostico,
                              mesDiagnostico, anoDiagnostico, possuiComorbidade, comorbidade, idade);

   return listaPacientes;
}

//Tela de cadastro de pacientes
void telaCadastroPacientes(Paciente* listaPacientes, Risco* listaGruposRisco){
   int opcaoSelecionada;
   char cpf[12];

   system("cls");
   printf("********************************************************\n");
   printf("**********CADASTRO DE PACIENTES COM COVID-19************\n");
   printf("********************************************************\n\n");
   printf("Selecione a opcao desejada:\n");
   printf("1 - Cadastrar novo paciente\n");
   printf("2 - Remover paciente\n");
   printf("3 - Sair e salvar pacientes de grupo de risco\n");
   scanf("%d", &opcaoSelecionada);
   do{
      switch (opcaoSelecionada){
         case 1:
         system("cls");
         listaPacientes = cadastrarPaciente(listaPacientes);
         salvarPacientes(listaPacientes);
         telaCadastroPacientes(listaPacientes, listaGruposRisco);
         case 2:
         system("cls");
         printf("*******************************************\n");
         printf("************EXCLUIR PACIENTE***************\n");
         printf("*******************************************\n\n");
         do{
            fflush(stdin);
            printf("Digite o CPF do paciente que deseja remover: ");
            gets(cpf);
            if (strlen(cpf) != 11)
               printf("ERRO! Digite o CPF com 11 caracteres numericos\n");
         } while (strlen(cpf) != 11);
         listaPacientes = retiraPaciente(listaPacientes, cpf);
         salvarPacientes(listaPacientes);
         telaCadastroPacientes(listaPacientes, listaGruposRisco);
         case 3:
         listaGruposRisco = adicionarGruposRisco(listaGruposRisco, listaPacientes);
         salvarRisco(listaGruposRisco);
         exit(0);
         default:
         printf("Opcao invalida! Selecione uma das opcoes disponiveis\n");
         scanf("%d", &opcaoSelecionada);
      }
   } while (opcaoSelecionada < 1 || opcaoSelecionada > 3);
}

//Tela de login do software
void telaLogin(Usuario* listaUsuarios, Paciente* listaPacientes, Risco* listaGruposRisco){
   int opcaoSelecionada;
   int loginRealizado;

   system("cls");
   printf("****************************************************************\n");
   printf("********PROGRAMA DE MONITORAMENTO DE CASOS DE COVID-19**********\n");
   printf("****************************************************************\n\n");
   printf("Selecione a opcao desejada:\n");
   printf("1 - Cadastrar novo usuario\n");
   printf("2 - Fazer login no sistema\n");
   printf("3 - Alterar senha do usuario\n");
   printf("4 - Sair\n");
   do{
      scanf("%d", &opcaoSelecionada);
      switch (opcaoSelecionada){
         case 1:
         system("cls");
         listaUsuarios = cadastrarUsuario(listaUsuarios);
         salvarUsuarios(listaUsuarios);
         telaLogin(listaUsuarios, listaPacientes, listaGruposRisco);
         case 2:
         system("cls");
         loginRealizado = login(listaUsuarios);
         if (loginRealizado == 0){
            telaLogin(listaUsuarios, listaPacientes, listaGruposRisco);
         } else {
            telaCadastroPacientes(listaPacientes, listaGruposRisco);
         }
         case 3:
         system("cls");
         listaUsuarios = alterarSenha(listaUsuarios);
         salvarUsuarios(listaUsuarios);
         telaLogin(listaUsuarios, listaPacientes, listaGruposRisco);
         case 4:
         exit(0);
         default:
         printf("Opcao invalida! Selecione uma das 4 opcoes disponiveis\n");
         break;
      }
   } while (opcaoSelecionada < 1 || opcaoSelecionada > 4);
}

int main(){

   //Declarando as variáveis
   Paciente* listaPacientes;
   Usuario* listaUsuarios;
   Risco* listaGruposRisco;

   //Iniciando as structs
   listaPacientes = iniciaPaciente();
   listaUsuarios = iniciaUsuario();
   listaGruposRisco = iniciaRisco();

   //Carregando os arquivos txt nas structs
   listaUsuarios = lerUsuarios(listaUsuarios);
   listaPacientes = lerPacientes(listaPacientes);

   //Executando a tela de login
   telaLogin(listaUsuarios, listaPacientes, listaGruposRisco);

   return 0;
}

