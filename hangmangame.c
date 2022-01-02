#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* necessary header file */

void hangman(int i)    /* hangman drawing funtion */
{
    if (i==8)
    {
        printf("********The Game Of Hangman********\n");
        printf("\n");
        printf("         ****************\n");
        printf("         #  __________  #\n");
        printf("         #   |    |     #\n");
        printf("         #   |    O     #\n");
        printf("         #   |    |     #\n");
        printf("         #   |   / \\    #\n");
        printf("         #   |________  #\n");
        printf("         #              #\n");
        printf("         ****************\n");
        printf("\n");
        printf("***********************************\n");
        printf("\n");
    }
        if (i==7)
    {
        printf("********The Game Of Hangman********\n");
        printf("\n");
        printf("          ****************\n");
        printf("          #  __________  #\n");
        printf("          #   |    |     #\n");
        printf("          #   |    O     #\n");
        printf("          #   |    |     #\n");
        printf("          #   |   /      #\n");
        printf("          #   |________  #\n");
        printf("          #              #\n");
        printf("          ****************\n");
        printf("\n");
        printf("***********************************\n");
        printf("\n");
    }
        if (i==6)
    {
        printf("********The Game Of Hangman********\n");
        printf("\n");
        printf("          ****************\n");
        printf("          #  __________  #\n");
        printf("          #   |    |     #\n");
        printf("          #   |    O     #\n");
        printf("          #   |    |     #\n");
        printf("          #   |          #\n");
        printf("          #   |________  #\n");
        printf("          #              #\n");
        printf("          ****************\n");
        printf("\n");
        printf("***********************************\n");
        printf("\n");
    }
        if (i==5)
    {
        printf("********The Game Of Hangman********\n");
        printf("\n");
        printf("          ****************\n");
        printf("          #  __________  #\n");
        printf("          #   |    |     #\n");
        printf("          #   |    O     #\n");
        printf("          #   |          #\n");
        printf("          #   |          #\n");
        printf("          #   |________  #\n");
        printf("          #              #\n");
        printf("          ****************\n");
        printf("\n");
        printf("***********************************\n");
        printf("\n");
    }
        if (i==4)
    {
        printf("********The Game Of Hangman********\n");
        printf("\n");
        printf("          ****************\n");
        printf("          #  __________  #\n");
        printf("          #   |    |     #\n");
        printf("          #   |          #\n");
        printf("          #   |          #\n");
        printf("          #   |          #\n");
        printf("          #   |________  #\n");
        printf("          #              #\n");
        printf("          ****************\n");
        printf("\n");
        printf("***********************************\n");
        printf("\n");
    }
        if (i==3)
    {
        printf("********The Game Of Hangman********\n");
        printf("\n");
        printf("          ****************\n");
        printf("          #  __________  #\n");
        printf("          #   |          #\n");
        printf("          #   |          #\n");
        printf("          #   |          #\n");
        printf("          #   |          #\n");
        printf("          #   |________  #\n");
        printf("          #              #\n");
        printf("          ****************\n");
        printf("\n");
        printf("***********************************\n");
        printf("\n");
    }
        if (i==2)
    {
        printf("********The Game Of Hangman********\n");
        printf("\n");
        printf("          ****************\n");
        printf("          #              #\n");
        printf("          #   |          #\n");
        printf("          #   |          #\n");
        printf("          #   |          #\n");
        printf("          #   |          #\n");
        printf("          #   |________  #\n");
        printf("          #              #\n");
        printf("          ****************\n");
        printf("\n");
        printf("***********************************\n");
        printf("\n");
    }
        if (i==1)
    {
        printf("********The Game Of Hangman********\n");
        printf("\n");
        printf("          ****************\n");
        printf("          #              #\n");
        printf("          #              #\n");
        printf("          #              #\n");
        printf("          #              #\n");
        printf("          #              #\n");
        printf("          #    ________  #\n");
        printf("          #              #\n");
        printf("          ****************\n");
        printf("\n");
        printf("***********************************\n");
        printf("\n");
    }
        if (i==0)
    {
        printf("********The Game Of Hangman********\n");  /* empty UI */
        printf("\n");
        printf("          ****************\n");
        printf("          #              #\n");
        printf("          #              #\n");
        printf("          #              #\n");
        printf("          #              #\n");
        printf("          #              #\n");
        printf("          #              #\n");
        printf("          #              #\n");
        printf("          ****************\n");
        printf("\n");
        printf("***********************************\n");
        printf("\n");
    }
}

struct usr  /* a struct works in the entire programme */
{
    char name[17];
    char pw[17];
    int play_time;
};

int fexists(const char *fname)  /* funcion for judging whether a file exists */
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

int play(char *word)  /* the main boay of the game */
{
	int len,i,wrongt,win,corr,fer,aga;
	char tmp;
    char *show;
	char wrongr[9];
	for (i=0;i<9;i++)
		wrongr[i]='\0';
	wrongt=0;
	fer=0;
	aga=0;
	corr=-1;
	len=strlen(word);
    win=len;
    show=(char*)malloc(sizeof(char)*(len+1));  /* show string that will display in the cmd*/
    show[len]='\0';
	for (i=0;i<len;i++)
    {
        show[i]='?';
        if (word[i]==32)
        {
            win--;
            show[i]=32;
        }
    }

	charget:  /* input letter part */

	while(1)
	{
		system("cls");
		hangman(wrongt);
		printf("%s\n\n",show);
		printf("Wrong letters you have entered: %s\n\n", wrongr);

		if (wrongt==8)   /* judging whether you are win or lose */
		{
            printf("You lose. The word is %s\n\n", word);
            printf("Press Enter to return to the menu...");
			getchar();
			fflush(stdin);
			return 0;
		}
		if (!win)
		{
			printf("Congrats!\n\nYou win. Press Enter to return to the menu...");
			getchar();
			fflush(stdin);
			return 1;
		}
		if (corr==1)
			printf("You are right! Next letter please.\n\n");
		if (corr==0)
			printf("You are wrong. Try another one.\n\n");  
		if (fer)
			printf("Invalid input! Try again.\n\n");  /* for the corresponding error */
		if (aga)
			printf("You have entered this letter! Try another one.\n\n");  /* for the corresponding error */
		aga=0;
		fer=0;
		corr=-1;
		printf("Please enter a letter: ");
		tmp=getchar();
		if (!((tmp>64) && (tmp<91)|(tmp>96) && (tmp<123)))
		{
			fflush(stdin);
			fer=1;
			goto charget;
		}
				for (i=0;i<len;i++)
		{
		if ((tmp==show[i]) |(tmp+32==show[i])|(tmp-32==show[i]))
		{
			fflush(stdin);
			aga=1;
			goto charget;
		}
		}
		while(1)
		{
			if (getchar()!=10)
			{
				fflush(stdin);
				fer=1;
				goto charget;
			}
			else
				break;
		}
		corr=0;
		for (i=0;i<len;i++)
		{
			if ((tmp==word[i])|(tmp+32==word[i])|(tmp-32==word[i]))
			{
				show[i]=word[i];
				win--;
				corr=1;
			}

		}
		if (corr==0)
		{
			printf("%d",wrongt);
			wrongr[wrongt]=tmp;
			wrongt++;
		}

	}
}


int login(struct usr *tusr)  /* login function */
{
	char *iword;
    char buf;
    double perc;
	FILE *file;
	int tmp,er,win,i;
	tmp=0;
	er=0;
	logmenu:
	system("cls");
    hangman(8);
    if (er)
    	printf("Invalid input! Please Retry...\n\n");  /* for the corresponding error */

    er=0;
    printf("Choose from the following options:\n");  /* login menu */
    printf("\n");
    printf("        1.Start a new game \n");
    printf("        2.Game History\n");
    printf("        3.Clear Game History\n");
    printf("        4.Logout\n");
    printf("\n");
    printf("Input your choice and press Enter: ");
    if (!scanf("%d",&tmp) | ((tmp!=1) && (tmp!=2) && (tmp!=3) && (tmp!=4)))
    {
    	fflush(stdin);
    	er=1;
    	goto logmenu;
    }
    fflush(stdin);

 	if (tmp==1)
 	{	
        modemenu:
        system("cls");
        hangman(8);
        if (er)
            printf("Invalid input! Please Retry...\n\n");  /* for the corresponding error */

        er=0;
        printf("Do you want to play against the computer or against your friends?\n\n");  /* mode choosing */
        printf("Choose from the following options:\n");
        printf("\n");
        printf("        1.Computer\n");
        printf("        2.Player\n");
        printf("\n");
        printf("Input your choice and press Enter: ");

        if (!scanf("%d",&tmp) | ((tmp!=1) && (tmp!=2)))
            {
                fflush(stdin);
                er=1;
                goto modemenu;
            }
        fflush(stdin);
        iword=(char*)malloc(sizeof(char)*50);
        if (tmp==1)
        {
            topicmenu:
            
            file=fopen("data.txt","r");
            system("cls");
            hangman(8);
            if (er)
                printf("Invalid input! Please Retry...\n\n");  /* for the corresponding error */

            er=0;
            printf("Please choose a word topic!\n\n");  /* topic choosing */
            printf("Choose from the following options:\n");
            printf("\n");
            printf("        1.Animals\n");
            printf("        2.Countries\n");
            printf("        3.Movies\n");
            printf("\n");
            printf("Input your choice and press Enter: ");

            if (!scanf("%d",&tmp) | ((tmp!=1) && (tmp!=2) && (tmp!=3)))
                {
                    fflush(stdin);
                    er=1;
                    goto topicmenu;
                }
            fflush(stdin);

            if (tmp==1)    /* random words selecting */
            {
                tmp=210+rand()%210;
                for (i=0;i<tmp;i++)
                    fgets(iword, 50, file);
            }
            if (tmp==2)
            {
                tmp=422+rand()%195;
                for (i=0;i<tmp;i++)
                    fgets(iword, 50, file);
            }
            if (tmp==3)
            {
                tmp=2+rand()%196;
                for (i=0;i<tmp;i++)
                    fgets(iword, 50, file);
            }
            fclose(file);
            tmp=strlen(iword);
            iword[tmp-1]='\0';


            tmp=1;


        }

        if (tmp==2)
        {
            er=0;
            i=0;

            
            system("cls");
            hangman(8);

            wordget:
            printf("(Less than 50 letters, including spaces)\n");  /* for input of the word by player */
            printf("Please input your word: ");
            er=0;
            

            while(1)
            {
                buf=getchar();
                if (buf==10)
                {
                    if (er | !i)
                    {   
                        system("cls");
                        hangman(8);

                        printf("Invalid input! Retry.\n\n");  /* for the corresponding error */
                        goto wordget;
                    }
                    break;

                }
                if ((((buf>64) && (buf<91))|((buf>96) && (buf<123)) | (buf==32)) && !er && i<49)
                {
                    iword[i]=buf;
                    i++;
                    iword[i]='\0';
                }
                else
                {
                    er=1;
                }
                
            }
        }    
        

        win=play(iword);
 		tusr->play_time++;
 		file=fopen(tusr->name, "r+b");     /* this part store win lose data into file */
 		fwrite(tusr,sizeof(struct usr),1,file);
       
        fseek(file, sizeof(int)*(tusr->play_time-1), SEEK_CUR);
 		fwrite(&win,sizeof(int),1,file);
 		fclose(file);
 		goto logmenu;
 	}

 	
 	if (tmp==2)  /* the play history showing part */
 	{
        win=0;
 		system("cls");
 		hangman(8);
 		file=fopen(tusr->name, "rb");
 		fread(tusr, sizeof(struct usr),1,file);
 		if (!tusr->play_time)
 		{
 			printf("        Empty!\n");
 			printf("\nPress Enter to return to the menu...");
 			getchar();
 			fflush(stdin);
 			goto logmenu;

 		}
 		else
 		{
 			for (i=0;i<tusr->play_time;i++)
 			{
 				fread(&tmp, sizeof(int), 1, file);
 				if (tmp)
                {
 					printf("        %d...............win\n",i+1);
                    win++;
                }
 				else
                    printf("        %d...............lose\n",i+1);
            }
            fclose(file);
            perc=((double) win/tusr->play_time)*100;
            printf("Total Win: %d        Win Rate: %.1f%%\n",win,perc);  /* calculate the win rate */
 			printf("\nPress Enter to return to the menu...");
 			getchar();
 			fflush(stdin);
 			goto logmenu;
 			
 		}
 	}

    if (tmp==3)
    {
        delete:


        system("cls");
        hangman(8);
        if (er)
        printf("Invalid input! Please Retry...\n\n");  /* for the corresponding error */

        er=0;
        printf("Are you sure you want to delete all game records (unrecoverable)?\n");  /* erase all user data */
        printf("Choose from the following options:\n\n");
        printf("        1.Yes\n");
        printf("        2.No\n\n");
        printf("Input your choice and press Enter: ");
        if (!scanf("%d",&tmp) | ((tmp!=1) && (tmp!=2)))
        {
            fflush(stdin);
            er=1;
            goto delete;
        }
        fflush(stdin);

        if(tmp==1)
        {
            tusr->play_time=0;
            file=fopen(tusr->name, "wb");
            fwrite(tusr, sizeof(struct usr),1,file);
            fclose(file);
            system("cls");
            hangman(8);
            printf("Successfully clear all game records!\n\n");
            printf("Press Enter to return to menu...");
            getchar();
            fflush(stdin);
            goto logmenu;
        }


        if (tmp==2)
            goto logmenu;
    }

 	if (tmp==4)
		return 0;
    return 0;
}


int reg(struct usr *tusr)
{
    char tmp;
    int i,er,up_check,num_check,low_check;
    FILE *file;
    system("cls");
    hangman(8);
    printf("(Letters and numbers only, not case sensitive, maximum length 16)\n");
    printf("Please enter username: ");

    reg:
    i=0;
    er=0;
    
	while(1) /* username checker */
	{
	    tmp=getchar();
	    if (tmp==10)
	    {
	        if (!er && i && i!=17)
	        {   
	            tusr->name[i]='\0';
	            if (fexists(tusr->name))
	            {
	                system("cls");
	                hangman(8);
	                printf("(Letters and numbers only, not case sensitive, maximum length 16)\n");
	                printf("Already exists! Retry: ");  /* for the corresponding error */
	                goto reg;  
	                return 0;              
	            }
	            file=fopen(tusr->name, "wb");
	            break;
	        }
	        else
	        {
	            system("cls");
	            hangman(8);
	            printf("(Letters and numbers only, not case sensitive, maximum length 16)\n");
	            printf("Wrong username format! Retry: ");  /* for the corresponding error */
	            goto reg;
	            return 0;
	        }
	    }   
	    if (!er && (i!=17))
	    {
	        if ((tmp>47 && tmp<58)|(tmp>64) && (tmp<91)|(tmp>96) && (tmp<123))
	        {
	            tusr->name[i]=tmp;
	            i++;
	        }
	    else er=1;
	    }
	}
    

	system("cls");
	hangman(8);
    printf("(Must contain uppercase letters, lowercase letters and numbers, the maximum length is 16)\n");
	printf("Please enter your password: ");

	password: /*password*/
	up_check=0;
	low_check=0;
	num_check=0;
	i=0;
	er=0;

    while(1)
    {
    	tmp=getchar();
    	if (tmp==10)
        {
            if (!er && i && i!=17 && up_check && low_check && num_check)
            {   
                tusr->pw[i]='\0';
                break;
            }
            else
            {
            	system("cls");
	            hangman(8);
            	printf("(Must contain uppercase letters, lowercase letters and numbers, the maximum length is 16)\n");
                printf("Wrong password format! Retry: ");  /* for the corresponding error */
                goto password;
                return 0;
            }
        } 
        if (!er && (i!=17))
        {
            if ((tmp>47 && tmp<58)|(tmp>64) && (tmp<91)|(tmp>96) && (tmp<123))
            {
                tusr->pw[i]=tmp;
                i++;
                if (tmp>64 && tmp<91)
                	up_check=1;
                else if (tmp>47 && tmp<58)
                	num_check=1;
                else
                	low_check=1;
            }
        else er=1;
        }
    }
    
    /* re-Enter */
    i=0;
	er=0;

	system("cls");
	hangman(8);
	printf("Please re-enter the password: ");

    while(1)
    {
    	tmp=getchar();
    	if (!er)
    	{
    		if (tmp!=tusr->pw[i] && tmp!=10)
    			er=1;
    		i++;
    	}
    	if (tmp==10 && !er && tusr->pw[i-1]=='\0')
    	{
    		tusr->play_time=0;
    		printf("\n");
    		printf("Register successfully, press Enter to login automatically!");
    		getchar();
    		fflush(stdin);
    		fwrite(tusr, sizeof(struct usr), 1, file);
			fclose(file);
    		login(tusr);
    		return 0;
    	}
    	if (tmp==10)
    	{
    		system("cls");
    		hangman(8);
			printf("(Must contain uppercase letters, lowercase letters and numbers, the maximum length is 16)\n");
			printf("Does not match! Please retry setting password: ");
            fflush(stdin);
    		goto password;
    	}
    }


    return 0;
}




int main()
{   
    struct usr iusr;
    int tmp,er,i,nousr,pwer;
    char buf;
    FILE *file;
    pwer=0;
    er=0;
    nousr=0;
    
    srand((unsigned)time(NULL));   /* re-seed the random number for only one time */

menu:
    iusr.name[0]='\0';
	system("cls");
    hangman(8);
    if (nousr)   /* for the corresponding error */
    	printf("No such user! Back to the menu...\n\n");
    if (er)
    	printf("Invalid input! Please Retry...\n\n");
    if (pwer)
    	printf("Wrong password! Please Retry...\n\n");
    pwer=0;
    er=0;
    nousr=0;
    printf("Choose from the following options:\n");
    printf("\n");
    printf("        1.Login\n");
    printf("        2.Register\n");
    printf("        3.Quit\n");
    printf("\n");
    printf("Input your choice and press Enter: ");
    if (!scanf("%d",&tmp) | ((tmp!=1) && (tmp!=2) && (tmp!=3)))
    {
    	fflush(stdin);
    	er=1;
    	goto menu;
    }
    fflush(stdin);

 	if (tmp==1)   /* entering the login process, part of the login() function */
 	{
 		i=0;
 		system("cls");
 		hangman(8);
 		printf("Please enter your username: ");
 		while(1)
 		{
 			buf=getchar();
 			if (buf==10)
 				break;
 			if (i<16)
 			{
 				iusr.name[i]=buf;
 				i++;
 				iusr.name[i]='\0';
 			}
 		}
 		if (i>15)
 		{
 			nousr=1;
 			goto menu;
 		}


 		i=0;
 		if (!fexists(iusr.name))
 		{
 			nousr=1;
 			goto menu;
 		}
 		else
 		{
 			file=fopen(iusr.name, "rb");
 			fread(&iusr, sizeof(struct usr), 1, file);

 			system("cls");
 			hangman(8);
 			printf("Please enter your password: ");

 			while(1)
 			{
 				buf=getchar();
 				if (!pwer)
    			{
    				if (buf!=iusr.pw[i] && buf!=10)
    					pwer=1;
    				i++;
    			}
		    	if (buf==10 && !pwer && iusr.pw[i]=='\0')
		    	{
		    		printf("\n");
		    		printf("Login successfully, press Enter to countinue...");
		    		getchar();
		    		fflush(stdin);
		    		login(&iusr);
		    		fflush(stdin);
		    		goto menu;
		    	}
		    	if (buf==10)
		    	{
		    		pwer=1;
		    		goto menu;
		    	}
		 			
 			}

 		}
 	}

 	if (tmp==2)   /* entering the register function */
 	{
 		reg(&iusr);
 		goto menu;
 	}

 	if (tmp==3) /* quit */
 	{
 		return 0;
 	}
    return 0;
}
