#include <stdio.h>
#include <stdbool.h>

int main(){
    int hour;
    int day;
    int month;
    const char* hour_fact;
    const char* month_fact;
    const char* day_fact;
    bool weekly = false;

    printf("Entrez l'heure : ");
    scanf("%d", &hour);

    printf("Entrez le jour de la semaine en chiffre (0 étant lundi) : ");
    scanf("%d", &day);

    printf("Entrez le mois en chiffre (0 étant janvier) : ");
    scanf("%d", &month);

    if (6 <= hour && hour <= 12){
           hour_fact = "matin";
    } else if (13 <= hour && hour <= 19){
        hour_fact = "après-midi";
    } else if (20 <= hour || hour <= 5){
        hour_fact = "soir";
    }

    if ( 11<= month || month <= 2){
        month_fact = "d'hiver" ;
    } else if ( 3<= month || month <= 4){
        month_fact = "de printemps" ;
    } else if ( 5<= month || month <= 7){
        month_fact = "d'été" ;
    } else if ( 8<= month || month <= 10){
        month_fact = "d'automne" ;
    }

    if ( day == 5 || day == 6 ){
        weekly = true;
        day_fact = "le week-end";
    }

    if ( weekly == true ) {
        printf("C'est un %s %s %s",hour_fact, month_fact, day_fact);
    } else if ( weekly == false ) {
        printf("C'est un %s %s ",hour_fact, month_fact);
    }
    
}