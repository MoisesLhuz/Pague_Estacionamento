#include <stdio.h>
#include <stdlib.h>

//* Membros da Equipe: Moises Santos da Luz(fodao), Carlos Emanuel, Gustavo Rocha, Gabriel Matias, Anderson Santana

int main() {

    float valorResto = 0, valor, Total = 0, acrescimos = 0, valorPago = 0, prejuizo, somaPago, somaTotal, somaPrejuizo, mediaIndividual = 0, mediaGeral = 0, nTotalSoma = 0, nTotalPago = 0, PercDeCobranca = 0, qtdCliente = 0, qtdClientePagoCorretamente = 0, menorValorPago, TotalMoto = 0, TotalCarroPequeno = 0, TotalCarroGrande = 0;
    int hInicial, mInicial, sInicial, hFinal, mFinal, sFinal, h, m, s, sT, opc, codigoVeiculo = 0, dia, resto, menor = 0;

   	do{
        printf("\n\nMenu Inicial************************\n\n");
        printf("1-Registrar Movimento\n")	;
        printf("2-Gerar Relatorio\n")	;
        printf("3-Encerrar\n\n")	;
        printf("****************************\n");
        printf("\nDigite uma opcao: ");
		scanf("%d", &opc);

        switch (opc)
		{

			case 1 :

            for (dia=1; dia<=30; dia++){
                somaPago = 0;
                somaTotal = 0;
                somaPrejuizo = 0;
                prejuizo = 0;



                do{
                    do{
					printf("***************************\n");
                    printf("\nSelecione o Tipo de Veiculo\n[1]p/Moto\n[2]p/CarroPequeno\n[3]CarroGrande\n\n");
                    printf("*****\n");
                    scanf("%d", &opc);
                    if(opc>3){
                        printf("OPCAO INVALIDA!! Digite uma opcao valida!!\n\n");
               		}
                	}while(opc>3);

					printf("Informe o codigo do veiculo: ");
                    scanf("%d", &codigoVeiculo);

					do{

	                    do{
							printf("Informe o Horario de ENTRADA no formato 00:00:00: ");
								scanf("%d:%d:%d", &hInicial, &mInicial, &sInicial);
							if(hInicial>23 || mInicial>59 || sInicial>59){
			                	printf("Horario Invalido!! Digite um horario valido!!\n");
							}
						}while (hInicial>23 || mInicial>59 || sInicial>59);

						do{
							printf("Informe o Horario de SAIDA no formato 00:00:00: ");
	                        scanf("%d:%d:%d", &hFinal,&mFinal,&sFinal);
	                        if(hFinal>23 || mFinal>59 || sFinal>59){
							printf("Horario Invalido!! Digite um horario valido!!\n");
							}
						}while(hFinal>23 || mFinal>59 || sFinal>59);

					h= (hFinal - hInicial);
                    m= (mFinal - mInicial);
                    s= (sFinal - sInicial);

					if(s < 0){
                        s = s + 60;
                        m = m - 1;
                    }
                    if(m < 0){
                        m = m + 60;
                        h = h - 1;
                    }

					sT = (h*3600) + (m*60) + (s);

					if(sT<0){
						printf("\n\nHorario Inicial e maior que o horario final!!\n\n");
					}

					}while(sT<0);



                    if(opc==1){
                        valor = 3.50;
                        acrescimos = 2,00;
                            if(sT<=900){
                                Total = 0;
                                    }else{
                                        if(sT>900 && sT<=3600){
                                        Total = valor;
                                            }else{
                                                if(sT>3600){
                                                    Total = valor + (acrescimos * ((sT - 3600)/3600));
                                                    resto = sT % 3600;
													if(resto>0){
                                                        Total = Total + acrescimos;
                                                }
                                                }
                                            }
                                    }
                    }


                    if(opc==2){
                        valor = 5.00;
                        acrescimos = 3,50;
                            if(sT<=900){
                                Total = 0;
                                    }else{
                                        if(sT>900 && sT<=3600){
                                        Total = valor;
                                            }else{
                                                if(sT>3600){
                                                    Total = valor + (acrescimos * ((sT - 3600)/3600));
                                                    resto = sT % 3600;
													if(resto>0){
                                                        Total = Total + acrescimos;
                                                }
                                                }
                                            }
                                    }
                    }

                     if(opc==3){
                        valor = 6.50;
                        acrescimos = 4,50;
                            if(sT<=900){
                                Total = 0;
                                    }else{
                                        if(sT>900 && sT<=3600){
                                        Total = valor;
                                            }else{
                                                if(sT>3600){
                                                    Total = valor + (acrescimos * ((sT - 3600)/3600));
                                                    resto = sT % 3600;
													if(resto>0){
                                                        Total = Total + acrescimos;
                                                }
                                                }
                                            }
                                    }
                    }

                    printf("Tempo de permanencia: %d:%d:%d\n\n", h, m, s);
                    printf("VALOR CORRETO a ser pago: %.2f\n", Total);
                    printf("Digite o VALOR PAGO pelo cliente: ");
                    scanf("%f", &valorPago);

                    qtdCliente++;
                    prejuizo = Total - valorPago;

                    if(opc == 1){
                        TotalMoto = TotalMoto + valorPago;
                        }else
                            if(opc == 2){
                            TotalCarroPequeno = TotalCarroPequeno + valorPago;
                            }else{
                                TotalCarroGrande = TotalCarroGrande + valorPago;
                            }


                    if(prejuizo<0){
                        prejuizo = prejuizo* -1;
                    }

                    if(valorPago == Total){
                        qtdClientePagoCorretamente++;
                    }
                    if(dia == 1 && qtdCliente == 1){
                        menor = codigoVeiculo;
                        menorValorPago = valorPago;
                    }
                    if(valorPago<menorValorPago){
                        menor = codigoVeiculo;
                        menorValorPago = valorPago;
                    }

                    if(valorPago!=Total){
                        printf("Valor cobrado foi o VALOR PAGO: %.2f\n", valorPago);
                            }else{
                                printf("Valor cobrado foi o VALOR CORRETO: %.2f\n", Total);
                            }
                    printf("Diferenca de %.2f do VALOR CORRETO para o VALOR PAGO\n", prejuizo);
                    printf("Dados do veiculo: %d\n\n", codigoVeiculo);


                    somaPago = somaPago + valorPago;
                    somaTotal = somaTotal + Total;
                    somaPrejuizo = somaPrejuizo + prejuizo;


                    printf("Digite\n[1]p/Continuar\n[0]p/Sair ou Lancar proximo dia\n");
                    scanf("%d", &opc);

                }while (opc == 1);
                    printf ("Operacao Finalizada\n");
                    printf("*****\n");
                    printf("\n\nTotal do Dia: %d\n", dia);
                    printf("Valor total arrecadado: %.2f\n", somaPago);
                    printf("Valor total que deveria ser arrecadado: %.2f\n", somaTotal);
                    printf("A Diferenca entre valor arrecadado e o valor correto: %.2f\n", somaPrejuizo);
                    if(somaPago>somaTotal){
                        printf("Lucro de: %.2f Para o dia: %d\n", somaPrejuizo, dia);
                        }else
                        	if(somaPago == somaTotal){
                        		printf("Dia: %d todas as cobranças feitas corretamente\n", dia);
								}else{
	                                printf("Prejuizo de: %.2f Para o dia: %d\n", somaPrejuizo, dia);
	                            }

            mediaIndividual = mediaIndividual + somaPago;
            mediaGeral = mediaIndividual / 30;
            nTotalSoma = nTotalSoma + somaTotal;
            nTotalPago = nTotalPago + somaPago;

            }

            break;
            case 2 :
                printf("RELATORIO GERAL******************\n\n");
                PercDeCobranca = (qtdClientePagoCorretamente / qtdCliente * 100);
                printf("Media do valor arrecadado no mes: %.2f\n", mediaGeral);
                printf("Diferenca entre os valores das cobrancas realizadas. VALOR CORRETO: %.2f VALOR PAGO: %.2f\n", nTotalSoma, nTotalPago);
                printf("Codigo do cliente que pagou o menor VALOR: %d\n", menor);
                printf("Percentual de cobrancas feitas corretamente: %.2f% \n", PercDeCobranca);
                printf("Valor total arrecadado por tipo de veiculo. Moto: %.2f Carro Pequeno: %.2f Carro Grande: %.2f\n\n", TotalMoto, TotalCarroPequeno, TotalCarroGrande);
                printf("**********************\n");
			break;

			case 3 :
                printf("Encerrar\n\n");

			break;
            default :
			printf("OPCAO INVALIDA!! Digite uma opcao valida!");
			break;
            }
	}while(opc!=3);
		printf("Programa Encerrado!");
    return 0;
}
