#include<stdio.h>
#include <time.h>
struct player{
    int no;
    char pname[100];
    int runs;
    int balls;
    int b_balls;
    int b_overs;
    int b_runs;
    int b_wickets;
};
char select_team[10];
char unselsect_team[10];
char toss_win_team[10];
char batball[10];
char wintoss[10];
char first_bat[10];
char first_ball[10];
char mychoice[10];
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
int i,m;
int ball=0;
char run[10];
int total=0;
int wicket=0;
int overs=0;
int baller=6;

int main(){

    team();
    selectteam();
    teamplayers();
    make_toss();
    //system("cls");
    batting();




}
void selectteam(){
    while(1){
        printf("\nSelect Your team(sl\\ind):");
        scanf("%s",select_team);
        if(!strcmp(select_team,team_name1) || !strcmp(select_team,team_name2) ){
            if(!strcmp(select_team,team_name1) ){
                strncpy(unselsect_team,team_name2,10);
                /*printf("ok1");
                printf("select:%s\n",select_team);
                printf("unselect:%s\n",unselsect_team);*/
            }else{
                strncpy(unselsect_team,team_name1,10);
                /*printf("ok1 else");
                printf("select:%s\n",select_team);
                printf("unselect:%s\n",unselsect_team);*/
            }
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
    /*printf("\nok2-teamplayers\n");
    printf("select:%s\n",select_team);
    printf("unselect:%s\n",unselsect_team);*/
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

                        for(i=0;i<11;i++){
                            while(1){
                                checking=1;
                                printf("\nEnter player %d:",i+1);
                                scanf("%d",&number);
                                size=sizeof(checkteam)/sizeof(checkteam[0]);
                                for(m=0;m<size;m++){
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
                        for(i=0;i<11;i++){
                            while(1){
                                checking=1;
                                printf("\nEnter player %d:",i+1);
                                scanf("%d",&number);
                                size=sizeof(checkteam)/sizeof(checkteam[0]);
                                for(m=0;m<size;m++){
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
    /*printf("\nok3-middleteamplayers\n");
    printf("select:%s\n",select_team);
    printf("unselect:%s\n",unselsect_team);*/
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
        /*printf("\nok4-middle 2\n");
        printf("select:%s\n",select_team);
        printf("unselect:%s\n",unselsect_team);*/

        if(!strcmp(select_team,team_name1) ){
                strncpy(unselsect_team,team_name2,10);
        }else{
                strncpy(unselsect_team,team_name1,10);
        }
        /*printf("\nok4-last\n");
        printf("select:%s\n",select_team);
        printf("unselect:%s\n",unselsect_team);*/

}
void make_toss(){
    /*printf("\nok5\n");
    printf("select:%s\n",select_team);
    printf("unselect:%s\n",unselsect_team);*/
    while(1){
        srand(time(0));
        printf("%s plese select head(h) or tail(t):",select_team);
        scanf("%s",mychoice);
        //printf("\n%s\n",mychoice);
        if(!strcmp(mychoice,"h") || !strcmp(mychoice,"t") ){
            const char *toss[]={"h","t"};

            int num = (rand() % (2 - 1 + 1)) ;
            //printf("\n%d\n",num);
            //char wintoss=toss[num];

            strncpy(wintoss,toss[num],10);
            //printf("ok1");
            if(!strcmp(wintoss,mychoice)){
                //printf("ok2if");
                strncpy(toss_win_team,select_team,10);
                printf("toss win team:%s",toss_win_team);
                printf("\n\t==============\n");
                printf("\tYou won the toss\n");
                printf("\t==============\n");
                while(1){
                    printf("\nChoose bat(bat) or ball(ball):");
                    scanf("%s",batball);
                    if(!strcmp(batball,"bat") || !strcmp(batball,"ball") ){
                        if(!strcmp(batball,"bat")){
                            strncpy(first_bat,select_team,10);
                            strncpy(first_ball,unselsect_team,10);
                        }else{
                            strncpy(first_bat,unselsect_team,10);
                            strncpy(first_ball,select_team,10);
                        }
                        break;


                    }else{
                        printf("\nPlease enter correct word(bat\\ball only)....\n");
                    }
                }

            }else{
                //printf("ok3else");
                printf("\n\t==============\n");
                printf("\tYou lose the toss\n");
                printf("\t==============\n");
                strncpy(toss_win_team,unselsect_team,10);
                //printf("toss win team:%s",toss_win_team);
                const char *myteams[]={select_team,unselsect_team};
                //printf("ok4");
                int num2 = (rand() % (2 - 1 + 1)) ;
                if(num2==0){
                    strncpy(first_bat,myteams[num2],10);
                    strncpy(first_ball,myteams[num2+1],10);
                }else{
                    strncpy(first_bat,myteams[num2],10);
                    strncpy(first_ball,myteams[num2-1],10);
                }



            }
            printf("\n\n\t=================================\n");
            printf("\t%s win the toss and %s will bat first.\n",toss_win_team,first_bat);
            printf("\t=================================\n");
            break;
        }else{
            printf("\nPlease enter correct letter(h\\t only)....\n\n");
        }
    }
}
void batting(){
    int no1=0;
    int no2=1;
    int no=0;
    int current_player=no1;
    srand(time(0));
    printf("\nOver 1: ");
    while(ball<30){

        const char *marks[]={"0","1","2","3","4","6","wide","w"};
        int num = (rand() % 8) ;
        strncpy(run,marks[num],10);
        printf("\t%s",run);
        if(!strcmp(marks[num],"0")){

            cteam1[current_player].balls+=1;

            cteam2[baller].b_balls+=1;
        }
        if(!strcmp(marks[num],"1")){
            total+=1;
            cteam1[current_player].runs+=1;
            cteam1[current_player].balls+=1;
            if(current_player==no1){
                current_player=no2;
            }else{
                current_player=no1;
            }

            cteam2[baller].b_runs+=1;
            cteam2[baller].b_balls+=1;
        }
        if(!strcmp(marks[num],"2")){
            total+=2;
            cteam1[current_player].runs+=2;
            cteam1[current_player].balls+=1;

            cteam2[baller].b_runs+=2;
            cteam2[baller].b_balls+=1;
        }
        if(!strcmp(marks[num],"3")){
            total+=3;
            cteam1[current_player].runs+=3;
            cteam1[current_player].balls+=1;
            if(current_player==no1){
                current_player=no2;
            }else{
                current_player=no1;
            }

            cteam2[baller].b_runs+=3;
            cteam2[baller].b_balls+=1;
        }
        if(!strcmp(marks[num],"4")){
            total+=4;
            cteam1[current_player].runs+=4;
            cteam1[current_player].balls+=1;

            cteam2[baller].b_runs+=4;
            cteam2[baller].b_balls+=1;
        }
        if(!strcmp(marks[num],"6")){
            total+=6;
            cteam1[current_player].runs+=6;
            cteam1[current_player].balls+=1;

            cteam2[baller].b_runs+=6;
            cteam2[baller].b_balls+=1;
        }
        if(!strcmp(marks[num],"w")){
            wicket+=1;
            cteam1[current_player].balls+=1;

            cteam2[baller].b_wickets+=1;
            cteam2[baller].b_balls+=1;

            if(wicket==10){
                break;
            }
            if(current_player==no1){
                while(1){
                    //printf("1 current palyer:%d no:%d\n",current_player,no);
                    no++;
                    //printf("2 current palyer:%d no:%d\n",current_player,no);
                    if(no!=no2){
                        current_player=no;
                        no1=no;
                        //printf("3 current palyer:%d no:%d\n",current_player,no);
                        break;
                    }
                }
            }
            if(current_player==no2){
                while(1){
                    //printf("1 current palyer:%d no:%d\n",current_player,no);
                    no++;
                    //printf("2 current palyer:%d no:%d\n",current_player,no);
                    if(no>no1){
                        current_player=no;
                        no2=no;
                        //printf("3 current palyer:%d no:%d\n",current_player,no);
                        break;
                    }
                }

            }
        }

        if(!strcmp(marks[num],"wide")){
            total+=1;

            cteam2[baller].b_runs+=1;
        }else{
            ball++;
            if(ball%6==0){
                overs++;
                cteam2[baller].b_overs+=1;
                printf("\n\n%s\t%d\t%d\n",cteam1[no1].pname,cteam1[no1].runs,cteam1[no1].balls);
                printf("%s\t%d\t%d\n",cteam1[no2].pname,cteam1[no2].runs,cteam1[no2].balls);
                printf("\n%s\t%d\t%d\t%d\n",cteam2[baller].pname,cteam2[baller].b_overs,cteam2[baller].b_runs,cteam2[baller].b_wickets);
                baller++;
                if(overs<5){

                    printf("\nOver %d: ",overs+1);

                }
            }
        }




    }
    printf("\n\n%Total\t:%d\nWickets\t:%d\nOvers\t:%d\n\n",total,wicket,overs);
    for(int z=0;z<=wicket+1;z++){
        printf("%s\t\t%d\t%d\n",cteam1[z].pname,cteam1[z].runs,cteam1[z].balls);
    }


}

