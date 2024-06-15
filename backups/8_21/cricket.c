#include<stdio.h>
struct player{
    int no;
    char pname[100];
    int runs;
    int balls;
};
char select_team[10];
char xi[100];
struct player team1[16];
struct player team2[16];
struct player cteam1[11];
struct player cteam2[11];
char team_name1[10]="sl";
char team_name2[10]="ind";
int checkteam[11];
int size;
int checking=1;
int number;
int main(){
    team();
    selectteam();
    teamplayers();




}
void selectteam(){
    while(1){
        printf("\nSelect Your team(sl\\ind):");
        scanf("%s",select_team);
        if(!strcmp(select_team,team_name1) || !strcmp(select_team,team_name2) ){
            break;
        }else{
            printf("\nPlease enter correct word(sl\\ind only)\n");
        }
    }


}
void team(){
    FILE *file1;
    FILE *file2;
    char name[100];

    int playerno=0;

    printf("\t==================\n");
    printf("\tSuper Over Cricket\n");
    printf("\t==================\n");



    char teamname1[20]="sl.txt";
    char teamname2[20]="ind.txt";

    file1=fopen(teamname1,"r");
    file2=fopen(teamname2,"r");
    if(file1==NULL && file2==NULL){
        printf("File cannot open.");
    }else{

        playerno=0;
        fscanf(file1,"\n%s",name);
       // printf("\n\n\t\t%s\n",name);
        //printf("\t\t===========\n\n");
        while(!feof(file1)){
            fscanf(file1,"\n%s",name);
            //printf("\n%s",name);
            team1[playerno].no=playerno+1;
            strncpy(team1[playerno].pname,name,100);
            playerno++;

        }
        //printf("\n\n");
        fclose(file1);

        playerno=0;
        fscanf(file2,"\n%s",name);
        //printf("\n\n\t\t%s\n",name);
        //printf("\t\t===========\n\n");
        while(!feof(file2)){
            fscanf(file2,"\n%s",name);
            //printf("\n%s",name);
            team2[playerno].no=playerno+1;
            strncpy(team2[playerno].pname,name,100);
            playerno++;

        }
        fclose(file2);
        printf("\n\n");


        printf("\t\tSri Lanka\n");
        printf("\t\t=========\n\n");
        for(int i=0;i<16;i++){
            printf("%d %s \n",team1[i].no,team1[i].pname);
        }
        printf("\n\n");

        printf("\t\tIndia\n");
        printf("\t\t=====\n\n");
        for(int i=0;i<16;i++){
            printf("%d %s \n",team2[i].no,team2[i].pname);
        }


    }
}
void teamplayers(){
    while(1){
        printf("\n\nDefault xi\t:press 'd'\n");
        printf("Customize xi\t:press 'c'\n");
        printf("Enter letter\t:");
        scanf("%s",xi);
            if(!strcmp(xi,"d") || !strcmp(xi,"c") ){
                if(!strcmp(xi,"d")){
                    //strncpy(team1,cteam1,11);
                    //strncpy(team2,cteam2,11);
                    memcpy(&cteam1, &team1, sizeof(team1));
                    memcpy(&cteam2, &team2, sizeof(team2));
                    /*for (int i=0; i<11; i++) {
                        team1[i] = cteam1[i];
                    }*/
                    //printf("\nok\n");
                }else{
                    printf("Enter only player no..\n");
                    if(!strcmp(select_team,team_name1)){

                        for(int i=0;i<11;i++){
                            while(1){
                                checking=1;
                                printf("\nEnter player %d:",i+1);
                                scanf("%d",&number);
                                size=sizeof(checkteam)/sizeof(checkteam[0]);
                                for(int m=0;m<size;m++){
                                    if(checkteam[m]==number){
                                        checking=0;
                                    }
                                }
                                if(number>0 && number<17 && checking==1){
                                    memcpy(&cteam1[i], &team1[number-1], sizeof(team1));
                                    checkteam[i]=number;
                                    size++;
                                    printf("\n\t%s\n",team1[number-1].pname);
                                    break;
                                }else{
                                    printf("\nPlease enter 1-17 only and don't repeat player no..\n");
                                }

                            }

                        }
                        memcpy(&cteam2, &team2, sizeof(team2));
                    }else{
                        for(int i=0;i<11;i++){
                            while(1){
                                checking=1;
                                printf("\nEnter player %d:",i+1);
                                scanf("%d",&number);
                                size=sizeof(checkteam)/sizeof(checkteam[0]);
                                for(int m=0;m<size;m++){
                                    if(checkteam[m]==number){
                                        checking=0;
                                    }
                                }
                                if(number>0 && number<17 && checking==1){
                                    printf("\ni:%d number:%d\n",i,number);
                                    //error line//memcpy(&cteam3[i], &team2[number-1], sizeof(team2));
                                    cteam2[i]=team2[number-1];
                                    checkteam[i]=number;
                                    size++;
                                    printf("\n\t%s\n",team2[number-1].pname);
                                    break;
                                }else{
                                    printf("\nPlease enter 1-17 only and don't repeat player no..\n");
                                }

                            }

                        }

                        memcpy(&cteam1, &team1, sizeof(team1));
                    }

                }
                break;
            }else{
                printf("\nPlease enter correct letter(d\\c only)\n");
            }
    }
    printf("\n\t\tSri Lanka\n");
        printf("\t\t=========\n\n");
        for(int i=0;i<11;i++){
            printf("|---------------|\n");
            printf("|   .-\"\"\"-.     |\n");
            printf("|  / .===. \\    |\n");
            printf("|  \\/ 6 6 \\/    |\n");
            printf("|  ( \\___/ )    |\n");
            printf("|   \\_____/     |\n");
            printf("|---------------|\n");
            printf("%d %s \n",i+1,cteam1[i].pname);
            if(i==3 || i==6 || i==9){
                printf("\n");
            }
        }
        printf("\n\n");

        printf("\t\tIndia\n");
        printf("\t\t=====\n\n");
        for(int i=0;i<11;i++){
            printf("|---------------|\n");
            printf("|   .-\"\"\"-.     |\n");
            printf("|  / .===. \\    |\n");
            printf("|  \\/ 6 6 \\/    |\n");
            printf("|  ( \\___/ )    |\n");
            printf("|   \\_____/     |\n");
            printf("|---------------|\n");
            printf("%d %s \n\n",i+1,cteam2[i].pname);
        }

}
