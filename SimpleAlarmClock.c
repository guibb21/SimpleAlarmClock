#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

time_t converter (int hora, int minutos, time_t tempo_atual);
void teste (void);

int main() 
{
    srand(time(NULL));

    int hora, minutos;
    char entrada[50];

    time_t tempo_atual;
    time(&tempo_atual);


    while (1)
    {
        printf("Defina o horario do alarme:\n");
        printf("(Hora:Minutos)\n");
        if (fgets(entrada, sizeof(entrada), stdin) != NULL)
        {
            if (sscanf(entrada, "%d:%d", &hora, &minutos) == 2)
            {
                if (hora < 24 && hora >= 0 && minutos >= 0 && minutos < 60)
                {
                    break;
                }
            }
        }
        system("clear");
        printf("\nDigite novamente '(Hora:Minutos)'\n\n");
    }

    time_t tempo_alarme = converter(hora, minutos, tempo_atual);

    printf("Horario atual: %s", ctime(&tempo_atual));
    printf("Horario alarme: %s", ctime(&tempo_alarme));

    long segundos_restantes = (long)(tempo_alarme - tempo_atual);
    sleep(segundos_restantes);


    teste();

    return 0;
}

time_t converter (int hora, int minutos, time_t tempo_atual)
{
    struct tm *info_tempo_ptr = localtime(&tempo_atual);
    struct tm info_tempo = *info_tempo_ptr;


    info_tempo.tm_hour = hora;
    info_tempo.tm_min = minutos;
    info_tempo.tm_sec = 0; 


    time_t tempo_alarme = mktime(&info_tempo);

    if (tempo_alarme < tempo_atual) {
        tempo_alarme += 86400; 
    }

    return tempo_alarme;
}

void teste (void)
{
    system("clear");

    int num1 = (rand() % 30) + 1;
    int num2 = (rand() % 30) + 1;
    int oper = (rand() % 3) + 1;
    int resposta, condicao = 0;
    char entrada[25];

    while (!condicao)
    {
        printf("ACORDE\n\n\n");
        printf("resolva a seguinte equacao\n");
        switch (oper)
        {
        case 1:
            printf("%d + %d\n", num1, num2);
            if (fgets(entrada, sizeof(entrada), stdin) != NULL)
            {
                if (sscanf(entrada, "%d", &resposta) == 1)
                {
                    if (resposta == num1 + num2)
                    {
                        condicao = 1;
                    }
                }
            }
            break;
        
        case 2:
            printf("%d - %d\n", num1, num2);
            if (fgets(entrada, sizeof(entrada), stdin) != NULL)
            {
                if (sscanf(entrada, "%d", &resposta) == 1)
                {
                    if (resposta == num1 - num2)
                    {
                        condicao = 1;
                    }
                }
            }
            break;
        case 3:
            printf("%d * %d\n", num1, num2);
            if (fgets(entrada, sizeof(entrada), stdin) != NULL)
            {
                if (sscanf(entrada, "%d", &resposta) == 1)
                {
                    if (resposta == num1 * num2)
                    {
                        condicao = 1;
                    }
                }
            }
            break;
        }
        if (!condicao)
        {
            system("clear");
            printf("Tente novamente\n\n");
        }
    }
    system("clear");
    printf("Alarme desarmado");

}