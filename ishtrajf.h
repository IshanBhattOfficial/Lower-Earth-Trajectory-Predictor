//1 space is 1km
#include<stdio.h>
#include<math.h>
#define PI 3.14
#define G 0.0098        //gravitational acceleration
#define R 6400          //radius of the earth
#define f 0.00001157 //frequency of earths rotation
#define G_ 0.0098

struct logs
{
    double th, v, phi;   //user input
    double mh, md;       //limits for loop (m stands for maximum)
    double reqh;        //required height
    int sucess;
    };

struct logs one;

int trajectory()
{
    FILE *fp; //file pointer to store logs

    double hc, dc;       //calculate in loop (counter vairables)
    double g=G;
    double help;
    fp = fopen("flight_logs.txt", "a");
    char ch;
    system("cls");

    // user input


    printf("Enter initial velocity:(in km/s) \t");
    scanf("%lf", &one.v);
    printf("Enter initial angle:(in degrees) \t");
    scanf("%lf", &one.th);
    one.th=PI*one.th/180;
    printf("Please enter latitude:(in degrees) \n\n This is optional, if you don't want to use this feature, just enter 0(zero): \t ");
    scanf("%lf", &one.phi);
    printf("Please enter required height:(in km) \t");
    scanf("%lf", &one.reqh);

    // getting proper input
    if(one.v>=7 || one.v<=0)
    {
        printf("\n\n\tUsually, initial velocity is less than 7km//s, keep in mind we are neglecting air resistance.");
        printf("\n\n\tContinuing with the same value might result in unpredicted result or the program to misbehave.");
        printf("\n\n Please confirm the value of initial velocity:(in km/s) \t");
        scanf("%lf", &one.v);
    }
    if((one.th)*(180/PI)>=85 || one.th*(180/PI)<=5)
    {
        printf("\n\n\tUsually, initial angle is between 5 and 85 degrees, keep in mind we are neglecting air resistance.");
        printf("\n\n\tContinuing with the same value might result in unpredicted result or the program to misbehave.");

        printf("\n\n Please confirm the value of initial velocity:(in degrees) \t");
        scanf("%lf", &one.th);
    }
    if(one.phi>=85 || one.phi<=5)
    {
        printf("\n\n\tUsually, latitude is between 5 and 85 degrees, keep in mind there are no launching pads on the poles!");
        printf("\n\n\tContinuing with the same value might result in unpredicted result or the program to misbehave.");

        printf("\n\n Please confirm the value of latitude:(in degrees) \t");
        scanf("%lf", &one.phi);
    }


    //calculation of g with phi

    g=g-((2*PI*f)*(2*PI*f)*R*cos(one.phi)*cos(one.phi));


    // calculation of limits

    one.mh=one.v*one.v*sin(one.th)*sin(one.th)/(2*g);
    one.md=one.v*one.v*fabs(sin(2*one.th))/g;

    /*printf("mh: %lf   md: %lf \n", mh, md);*/
    // loops and printing

    system("cls"); // cleaning the screen before trajectory printing

    help=one.md+10;

    if(round(one.reqh)==round(one.mh))
    {
    help=(help/2)-1;
    }

    for(hc=2*one.mh;hc>=0;hc--)
    {

        g=G_*(1-(2*hc/R));

        for(dc=0;dc<=help;dc++)
        {

                if( round(hc) == round ( (dc*tan(one.th)) - (g*dc*dc)/(2*one.v*one.v*cos(one.th)*cos(one.th)) ) )
                {
                printf("*");
                //if(round(one.reqh)==round(hc))


                }
                else if(round(hc) == round ( (dc*tan(one.th)) - (g*dc*dc)/(2*one.v*one.v*cos(one.th)*cos(one.th)) ) + 1 || round(hc) == round ( (dc*tan(one.th)) - (g*dc*dc)/(2*one.v*one.v*cos(one.th)*cos(one.th)) ) -1 )
                printf("#");
            else if(floor(hc)==0 || round(hc)==10 || round(hc)==50 || round(hc)==100 || round(hc)==200  || round(hc)==300 || round(hc)==400 || round(hc)==500 || round(hc)==600 || round(hc)==700 || round(hc)==800 || round(hc)==900 || round(hc)==1000 || round(hc)==1500 || round(hc)==2000 || round(hc)==2500 || round(hc)==3000 || round(hc)==4000  || round(hc)==5000 || round(hc)==7500 || round(hc)==10000)
                printf("-");
            else
               {
                 printf(" ");
                 //return 8;
               }
            }

        switch((int)round(hc))
        {
        case 1:
            printf("ground");
            break;
        case 10:
            printf("%2.0lfkm",round(hc));
            break;
        case 50:
            printf("%2.0lfkm", round(hc));
            break;
        case 100:
            printf("%2.0lfkm", round(hc));
            break;
        case 200:
            printf("%2.0lfkm", round(hc));
            break;
        case 300:
            printf("%2.0lfkm", round(hc));
            break;
        case 400:
            printf("%2.0lfkm", round(hc));
            break;
        case 500:
            printf("%2.0lfkm", round(hc));
            break;
        case 600:
            printf("%2.0lfkm", round(hc));
            break;
        case 700:
            printf("%2.0lfkm", round(hc));
            break;
        case 800:
            printf("%2.0lfkm", round(hc));
            break;
        case 900:
            printf("%2.0lfkm", round(hc));
            break;
        case 1000:
            printf("%2.0lfkm", round(hc));
            break;
        case 1500:
            printf("%2.0lfkm", round(hc));
            break;
        case 2000:
            printf("%2.0lfkm", round(hc));
            break;
        case 2500:
            printf("%2.0lfkm", round(hc));
            break;
        case 3000:
            printf("%2.0lfkm", round(hc));
            break;
        case 4000:
            printf("%2.0lfkm", round(hc));
            break;
        case 5000:
            printf("%2.0lfkm", round(hc));
            break;
        case 7500:
            printf("%2.0lfkm", round(hc));
            break;
        case 10000:
            printf("%2.0lfkm", round(hc));
            break;

        default:
            printf(" ");

        }
        printf("\n");
    }


    if(round(one.reqh)==round(one.mh))
    {
        printf("\n\n\nWe HAVE made it into ORBIT!!!\a");
        one.sucess=1;
    }
    else if(round(one.reqh)>round(one.mh))
    {
        printf("\n\n required height is more than the height attained by the projectile.\n Try increasing the initial velocity or initial angle.");
        one.sucess=0;
    }
    else if(round(one.reqh)<round(one.mh))
    {
        printf("\n\n required height is less than the height attained by the projectile.\n Try reducing the initial velocity or initial angle.");
        one.sucess=0;
    }

    fprintf(fp, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%d\n", one.v,(one.th*180/PI),one.phi,one.mh,one.md,one.reqh,one.sucess);

    fclose(fp);

    printf("\n\n\n *Enter 'M' or 'm' to get back to main menu. ");
    printf("\n *Enter 'A' or 'a' to get cracking!");
    printf("\n *Enter 'E' or 'e' to exit");
    printf("\n *Any other key wil take you to main menu. \n\t\tEnter your choice here: ");
    ch=getch();
    switch(ch)
 {
 case 'a':
 case 'A':
    trajectory();
    break;
 case 'b':
 case 'B':
    read();
    break;
 case 'E':
 case 'e':
    exit(0);
 default:
    menu();

    return 0;
  }

}


void read()
{
    FILE *fp;
    char ch;
    system("cls");
    fp=fopen("flight_logs.txt", "r");

    while(1)
    {
        ch=fgetc(fp);
        if(ch==EOF)
            break;
        printf("%c", ch);
    }
    fclose(fp);

    printf("\n\n\n *Enter 'M' or 'm' to get back to main menu. ");
    printf("\n *Enter 'A' or 'a' to get cracking!");
    printf("\n *Enter 'E' or 'e' to exit");
    printf("\n *Any other key wil take you to main menu. \n\t\tEnter your choice here: ");
    ch=getch();
    switch(ch)
 {
 case 'a':
 case 'A':
    trajectory();
    break;
 case 'b':
 case 'B':
    read();
    break;
 case 'E':
 case 'e':
    exit(0);
 default:
    menu();
 }

}

void menu()
{
 char ch;
 system("cls");
 printf("\n\n\tChoose your option from the menu:");
 printf("\n\tA. Trajectory Prediction");
 printf("\n\tB. View previous Flight logs");
 printf("\n\tE. Exit");
 printf("\n\nEnter your choice here: ");
 ch=getch();
 switch(ch)
 {
 case 'a':
 case 'A':
    trajectory();
    break;
 case 'b':
 case 'B':
    read();
    break;
 case 'E':
 case 'e':
    exit(0);
 default:
    menu();
 }

}

void start()
{
    printf("\a\n\n\t\t\t Welcome to LEO trajectory predictor:\n\n");
    printf("\t\tThis program is built with the aim to predict and construct the trajectories of satellites on the screen.\n\n\t\t\t **Disclaimers**\n\n\t\t");
    printf("1. To use this program, the users must have the initial velocity and initial angle. The user may also enter the latitude of the launch-station optionally.\n\t\t");
    printf("2. The scale of the trajectory is such that one character space is a two-dimensional surface of 1 square-kilomter.\n\t\t");
    printf("3. The resistance due to air is neglected. \n\t\t4. It is mandatory for the users to keep smiling while they use this program! ");
    printf("\n*Press any key to continue.");
    getch();

    menu();
}
