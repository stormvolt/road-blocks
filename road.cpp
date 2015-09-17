#include <iostream>
using namespace std;

void printGame (int a[20][47], int *x, int *y)
{
   a[*x][*y]=2;
   for ( int i = 0; i < 20; i++ )
      {
      for ( int j = 0; j < 47; j++ )
      {
        if(a[i][j]==0)
        {
            cout << " ";
        }
        else if(a[i][j]==1)
        {
            cout << "█";
        }
        else if(a[i][j]==2)
        {
            cout << "o";
        }
        else if(a[i][j]==3)
        {
            cout << "X";
        }
      }
      cout << "\n";
      }
      
 a[*x][*y]=0;
   
}


void printGAMEOVER()
{
    cout<< "GAMEOVER";
}

void printNEXT()
{
    cout<< "'##::: ##:'########:'##::::'##:'########::::'##:::::::'########:'##::::'##:'########:'##:::::::"<<"\n";
    cout<< " ###:: ##: ##.....::. ##::'##::... ##..::::: ##::::::: ##.....:: ##:::: ##: ##.....:: ##:::::::"<<"\n";
    cout<< " ####: ##: ##::::::::. ##'##:::::: ##::::::: ##::::::: ##::::::: ##:::: ##: ##::::::: ##:::::::"<<"\n";
    cout<< " ## ## ##: ######:::::. ###::::::: ##::::::: ##::::::: ######::: ##:::: ##: ######::: ##:::::::"<<"\n";
    cout<< " ##. ####: ##...:::::: ## ##:::::: ##::::::: ##::::::: ##...::::. ##:: ##:: ##...:::: ##:::::::"<<"\n";
    cout<< " ##:. ###: ##:::::::: ##:. ##::::: ##::::::: ##::::::: ##::::::::. ## ##::: ##::::::: ##:::::::"<<"\n";
    cout<< " ##::. ##: ########: ##:::. ##:::: ##::::::: ########: ########:::. ###:::: ########: ########:"<<"\n";
    cout<< "..::::..::........::..:::::..:::::..::::::::........::........:::::...:::::........::........::"<<"\n";
}


void mov (int direc, int a[20][47], int *x, int *y)
{
    if(direc==5)
    {
        bool stop=false;
        while(stop==false)
        {
            if(*x-1>=0)
            {
                if(a[*x-1][*y]==0)
                {
                    *x=*x-1;
                    printGame(a,x,y);
                }
                else
                {
                    stop=true;
                }
            }
        }    
    }
    else if(direc==2)
    {
        bool stop=false;
        while(stop==false)
        {
            if(*x+1<21)
            {
                if(a[*x+1][*y]==0)
                {
                    *x=*x-1;
                    printGame(a,x,y);
                }
                else
                {
                    stop=true;
                }
            }
        }    
    }
    else if(direc==1)
    {
        bool stop=false;
        while(stop==false)
        {
            if(*y-1>=0)
            {
                if(a[*x][*y-1]==0)
                {
                    *y=*y-1;
                    printGame(a,x,y);
                }
                else
                {
                    stop=true;
                }
            }
        }    
    }
    else if(direc==3)
    {
        bool stop=false;
        while(stop==false)
        {
            if(*y+1<21)
            {
                if(a[*x][*y+1]==0)
                {
                    *y=*y+1;
                    printGame(a,x,y);
                }
                else
                {
                    stop=true;
                }
            }
        }    
    }

}


int comprobar (int direc, int a[20][47], int *x, int *y, bool *end)
{
    int n=2;
    if(direc==5)
    {
       if(*x-1<0)
       {
           *end=true;
           printGAMEOVER();
           n=0;
       }
       else if(a[*x-1][*y]==3)
       {
          *end=true;
          printNEXT();
          n=1;
       }
       else
       {
           *end=false;           
       }
    }
    else if(direc==2)
    {
       if(*x+1>=21)
       {
           *end=true;
           printGAMEOVER();
           n=0;
       }
       else if(a[*x+1][*y]==3)
       {
          *end=true;
          printNEXT();
          n=1;
       }
       else
       {
           *end=false;           
       }
    }
    else if(direc==1)
    {
       if(*y-1<0)
       {
           *end=true;
           printGAMEOVER();
           n=0;
       }
       else if(a[*x][*y-1]==3)
       {
          *end=true;
          printNEXT();
          n=1;
       }
       else
       {
           *end=false;           
       }
    }
    else if(direc==3)
    {
       if(*y+1>=21)
       {
           *end=true;
           printGAMEOVER();
           n=0;
       }
       else if(a[*x][*y+1]==3)
       {
          *end=true;
          printNEXT();
          n=1;
       }
       else
       {
           *end=false;           
       }
    }
    return n;
}



int level1[20][47] ={{0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,0,0,0},

{0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0},
{0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,1,0,0},

{0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,0,0},

{0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0},
{0,0,1,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0},

{0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,1,0,0,0,0},
{0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0},

{0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,1,0,0,1,0},
{0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,0,0,0,0},
{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},

{0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,0,1,0,0,0,1,0},
{0,0,0,0,1,0,1,0,1,0,1,0,0,1,1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0},

{0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0},
{1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0},

{0,3,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

int x1=0;
int y1=45;


void game(int *c, bool *end)
{
    int n=0;
    int *pn=&n;
    int *px1=&x1;
    int *py1=&y1;
    int direc=0;
    if(*c==1)
    {
        printGame(level1,px1,py1);
        while(end==false)
        {
            cin>> direc;
            mov(direc,level1,px1,py1);
            n=comprobar(direc,level1,px1,py1,end);
        }        
        if(n==1)
        {
            *c=*c+1;
        }
        else if(n==0)
        {
            *c=1;
        }
    }   
}



int main()
{
    int c=1;
    int *pc=&c;
    bool end=false;
    bool *pend=&end;
    game(pc, pend);
    return 1;
}
