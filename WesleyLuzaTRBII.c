#include <stdio.h>
#include <string.h>

void limparBuffer() { 
    int c; while ((c = getchar()) != '\n'); 
}

int main() {
int opcao1, adicional;
float salarioBruto, salarioBase, horasTrabalhadas, horaExtra, valorHora, valorExtra, descontoInss, porcentagemInss, numeroDependentes, porcentagemIrpf, descontoIrpf, deducaoDependentes;
float baseIrpf, totalIrpf;
char razao_social[100], cnpj[20], endereco[150], nomefunc[50], cargofunc[50], dataNascimento[11], mesReferente[20], novaOp = 'S';

do {
printf("\n\nPrograma FOLHA DE PAGAMENTO \n");
printf("1 - Configurar dados da empresa. \n");
printf("2 - Calcular salário mensal. \n");
printf("3 - Sair. \n");
printf("Escolha uma das opcoes acima: \n");
scanf("%d", &opcao1);

while(opcao1 < 0 || opcao1 > 3) {
    printf("Valor informado esta errado. Tente novamente. \n");
    scanf("%i", &opcao1);
}

switch(opcao1) {
case 1:
limparBuffer();
printf("Informe os dados: \n");
printf("1 - Digite a razao social: \n");
fgets(razao_social, sizeof(razao_social), stdin);
razao_social[strcspn(razao_social, "\n")] = 0;

printf("2 - Digite o CNPJ: \n");
fgets(cnpj, sizeof(cnpj), stdin);
cnpj[strcspn(cnpj, "\n")] = 0;

printf("3 - Informe o endereco: \n");
fgets(endereco, sizeof(endereco), stdin);
endereco[strcspn(endereco, "\n")] = 0;
break;

case 2:
limparBuffer();
printf("Informe os dados a seguir: \n");
printf("1 - Digite o mês referente: \n");
fgets(mesReferente, sizeof(mesReferente), stdin);
mesReferente[strcspn(mesReferente, "\n")] = 0;
printf("2 - Informe o nome completo do funcionario: \n");
fgets(nomefunc, sizeof(nomefunc), stdin);
nomefunc[strcspn(nomefunc, "\n")] = 0;
printf("3 - Digite sua data de nascimento: \n");
fgets(dataNascimento, sizeof(dataNascimento), stdin);
dataNascimento[strcspn(dataNascimento, "\n")] = 0;
limparBuffer();
printf("4 - Informe o cargo do funcionario: \n");
fgets(cargofunc, sizeof(cargofunc), stdin);
cargofunc[strcspn(cargofunc, "\n")] = 0;
printf("5 - Informe o numero de horas trabalhadas no mes: \n");
scanf("%f", &horasTrabalhadas);
printf("6 - Informe o valor de cada hora: \n");
scanf("%f", &valorHora);
printf("7 - Informe o numero de dependentes (Se o funcionario nao tiver, informar 0): \n");
scanf("%f", &numeroDependentes);

// Calculo do salario mensal
if(horasTrabalhadas > 220 && horasTrabalhadas <= 240) {
horaExtra = (horasTrabalhadas-220);
valorExtra = (horaExtra*valorHora)*1.25;
salarioBase = (horasTrabalhadas - horaExtra) * valorHora;
} else if(horasTrabalhadas > 240) {
horaExtra = (horasTrabalhadas-240);
valorExtra = (horaExtra*valorHora)*1.5;
salarioBase = (horasTrabalhadas - horaExtra) * valorHora;
} else {
valorExtra = 0;
salarioBase = horasTrabalhadas * valorHora;
}

salarioBruto = salarioBase + valorExtra;

// calculo do inss;
if (salarioBruto <= 1412.00) {
    descontoInss = salarioBruto * 0.075;
    porcentagemInss = 7.5;
} else if (salarioBruto > 1412.01 && salarioBruto <= 2666.68) {
    descontoInss = salarioBruto * 0.09;
    porcentagemInss = 9;
} else if (salarioBruto > 2666.69 && salarioBruto <= 4000.03) {
    descontoInss = salarioBruto * 0.12;
    porcentagemInss = 12;
} else if (salarioBruto > 4000.04 && salarioBruto <= 7786.02) {
    descontoInss = salarioBruto * 0.14;
    porcentagemInss = 14;
} else if (salarioBruto > 7786.03) {
    descontoInss = 908.94;
}

// calculo do irpf;
deducaoDependentes = numeroDependentes * 189.59;
baseIrpf = salarioBruto - descontoInss - deducaoDependentes;

if(baseIrpf <= 2112.00) {
    descontoIrpf = 0;
} else if (baseIrpf > 2112.01 && baseIrpf <= 2826.65) {
    descontoIrpf = baseIrpf * 0.075 - 158.40;
    porcentagemIrpf = 7.5;
} else if (baseIrpf > 2826.66 && baseIrpf <= 3751.05) {
    descontoIrpf = baseIrpf * 0.15 - 370.40;
    porcentagemIrpf = 15;
} else if (baseIrpf > 3751.06 && baseIrpf <= 4664.68) {
    descontoIrpf = baseIrpf * 0.225 - 651.73;
    porcentagemIrpf = 22.5;
} else if (baseIrpf > 4664.68) {
    descontoIrpf = baseIrpf * 0.275 - 884.96;
    porcentagemIrpf = 27.5;
}
if(descontoIrpf < 0) {
    descontoIrpf = 0;
    porcentagemIrpf = 0;
}

printf("\n---------------------------------------------------------------\n");
printf("\t\tCONTRACHEQUE MENSAL\n");
printf("---------------------------------------------------------------\n");
printf("EMPRESA: %s\t", razao_social);
printf("CNPJ: %s\n", cnpj);
printf("ENDEREÇO: %s\n", endereco);
printf("---------------------------------------------------------------\n");
printf("FUNCIONARIO: %s\t", nomefunc);
printf("CARGO: %s\n", cargofunc);
printf("DATA DE NASCIMENTO: %s\n", dataNascimento);
printf("MÊS REFERENTE: %s\n", mesReferente);
printf("---------------------------------------------------------------\n");
printf("HORAS TRABALHADAS: %.2f\t", horasTrabalhadas);
printf("VALOR DA HORA: R$%.2f\n", valorHora);
if(horasTrabalhadas > 220 && horasTrabalhadas <= 240) {
printf("HORAS EXTRAS: %.2fh com adicional de 25 por cento.\n\n", horaExtra);
} else if(horasTrabalhadas > 240){
printf("HORAS EXTRAS: %.2fh com adicional de 50 por cento.\n\n", horaExtra);
} else {
    printf("HORAS EXTRAS: Voce nao trabalhou horas extras. \n\n");
}
printf("SALARIO BASE: R$%.2f\n", salarioBase);
printf("VALOR HORAS EXTRAS: R$%.2f\n", valorExtra);
printf("TOTAL VENCIMENTOS: R$%.2f\n\n", salarioBruto);
if (salarioBruto > 7786.03) {
    printf("DESCONTO INSS(Teto): R$%.2f\n", descontoInss);
} else {
printf("DESCONTO INSS(%.1f%%): R$%.2f\n", porcentagemInss, descontoInss);
}
printf("DESCONTO IRPF(%.1f%%): R$%.2f\n", porcentagemIrpf, descontoIrpf);
printf("TOTAL DESCONTOS: R$%.2f\n\n", descontoInss + descontoIrpf);
printf("SALARIO LÍQUIDO: R$%.2f\n", salarioBruto - (descontoInss + descontoIrpf));
printf("---------------------------------------------------------------\n");

do {
    printf("\nDeseja realizar uma nova operação? (S para voltar ao menu 2 / N para voltar ao menu 1): ");
    limparBuffer();
    scanf(" %c", &novaOp);
    if(novaOp != 'S' && novaOp != 's' && novaOp != 'N' && novaOp != 'n') {
        printf("Opção inválida. Digite apenas S ou N.\n");
    }
} while(novaOp != 'S' && novaOp != 's' && novaOp != 'N' && novaOp != 'n');

if(novaOp == 'S' || novaOp == 's') {
    opcao1 = 2;
} else {
    opcao1 = 0; 
}
break;

case 3:
printf("Encerrando programa... \n");
break;
default: {
    printf("Opcao invalida, tente novamente. \n");
    break;
}
}
} while (opcao1 != 3);
}

