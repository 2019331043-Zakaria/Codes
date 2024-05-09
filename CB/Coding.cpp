/*Write all the necessary functions and codes for plotting NRZI and Pseodoternary line codings.
Use the following code of NRZL as the template. Add documentation where necessary.
In the given code, the input data stream is fixed as 10 bits. Change it in a way so that the user can provide the length of the data stream
*/
#include <iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

//Coordinates Handler
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoXY(int x, int y);
void nrzl(char a[],int s);
void nrzi(char a[], int s);
void pseudoternary(char a[], int s);
int main()
{
k:
    Sleep(800);
    system("cls");
    int n;
    cout << "Length of the string : ";
    cin >> n;
    char a[n];
    cout<<"enter binary string : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i=0; i<n; i++)
    {
        if(a[i]=='1'||a[i]=='0')
        {
        }
        else
        {
            cout<<"Invalid Binary";
            goto k;
        }
    }
    char b[4];
    cout<<"Enter the Encoding Method: ";
    cin >> b[0];
    if(b[0] == 'p' || b[0] == 'P')
    {
        for (int i = 1; i < 3; i++)
        {
            cin >> b[i];
        }
    }
    else if(b[0] == 'n' || b[0] == 'N')
    {
        for (int i = 1; i < 4; i++)
        {
            cin >> b[i];
        }
    }
    else
    {
        cout << "INVALID METHOD";
        goto k;
    }

    cout << b[0] << b[1]<< b[2] << b[3] << endl;

    if(b[0]=='N'||b[0]=='n')
    {
        if(b[1]=='R'||b[1]=='r')
        {
            if(b[2]=='Z'||b[2]=='z')
            {
                if(b[3]=='L'||b[3]=='l')
                {
                    nrzl(a,n);
                }
                else if(b[3]=='I'||b[3]=='i')
                {
                    nrzi(a,n);
                }

            }
            else
            {
                cout<<"Invalid Methodo"<<endl;
                goto k;
            }


        }
        else
        {
            cout<<"Invalid Methodu"<<endl;
            goto k;
        }

    }
    else
    {
        if(b[0]=='P'||b[0]=='p')
        {
            if(b[1]=='S'||b[1]=='s')
            {
                if(b[2]=='e'||b[2]=='e')
                {
                    pseudoternary(a,n);
                }
            }
        }


        else
        {
            cout<<"Invalid Method"<<endl;
            goto k;
        }

    }
}

void gotoXY(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}
void pseudoternary(char a[],int b)
{


    int x = 0, y = 0;
    system("cls");
    x = 3, y = 1;
    cout << "Amplitutde";
    x = 4;
    y = 1;
    gotoXY(x,y);
    cout<<"^";
    y++;
    while (y != 17)
    {
        gotoXY(x, y);
        cout << "|";
        y++;
    }

    x=7;
    y=3;
    x=0;
    y=9;
    gotoXY(x,y);
    cout<<"Pseudoternary";
    int prev_x, prev_y;
    int cnt = 0, locx = 7, locy = 1;
    for (int i = 0; i < b; i++)
    {
        gotoXY(locx, locy);
        cout << a[i];
        locx += 5;
        int temp=0;
        if (i == 0)
        {
            if (a[i] == '1' )
            {
                x=7;
                y=2;
                gotoXY(x,y);
                //cout<<a[i];
                x = 5;
                y = 7;


                gotoXY(x, y);
                cout << "_____";
            }
            else{

                x=7;
                y=2;
                gotoXY(x,y);
                cout<<a[i];
                x = 5;
                y = 3;
                cnt++;
                gotoXY(x, y);
                cout << "_____";


            }
        }
        else{
                if(a[i] == '1' ){
                x=7;
                y=2;
                gotoXY(x,y);
                //cout<<a[i];
                x = 5+ 5*i;
                y = 7;


                gotoXY(x, y);
                cout << "_____";

                }
                else{
                x=7;
                y=2;
                gotoXY(x,y);
                //cout<<a[i];
                //x = 5;
                if(cnt%2 == 1){
                    y = 10;
                }
                else{
                    y = 3;
                }
                x = 5+ 5*i;

                cnt++;
                gotoXY(x, y);
                cout << "_____";

                }

        }
        x=x+5;
        y=8;

    }
    y++;
    gotoXY(x, y);
    cout << "---------> time" << endl;
    char choice;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<"Enter \"Y\" to try again and \"N\" or any character to quit: ";
    cin>>choice;
    if(choice=='Y'||choice=='y')
    {
        main();
    }
    else
    {
        exit(0);
    }
}

void nrzi(char a[],int b)
{


    int x = 0, y = 0;
    system("cls");
    x = 3, y = 1;
    cout << "Amplitutde";
    x = 4;
    y = 1;
    gotoXY(x,y);
    cout<<"^";
    y++;
    while (y != 17)
    {
        gotoXY(x, y);
        cout << "|";
        y++;
    }

    x=7;
    y=3;
    x=0;
    y=9;
    gotoXY(x,y);
    cout<<"NRZI";
    int prev_x, prev_y;
    for (int i = 0; i < b; i++)
    {
        int temp=0;
        if (i == 0)
        {
            if (a[i] == '0' || a[i] == '1')
            {
                x=7;
                y=2;
                gotoXY(x,y);
                cout<<a[i];
                x = 5;
                y = 7;
                prev_x = x;
                prev_y = y;

                gotoXY(x, y);
                cout << "_____";
            }
        }
        else
        {
            if(a[i] == '0' )
            {
                //x=7;
                y=2;
                gotoXY(x,y);
                cout<<a[i];
                //x = prev_x;
                y = prev_y;
                gotoXY(x, y);
                cout << "_____";

            }
            if(a[i] == '1' )
            {
                //x=7;
                y=2;
                gotoXY(x,y);
                cout<<a[i];
                if(prev_y == 7)
                {

                    gotoXY(x, 8);
                    cout << "|";
                    gotoXY(x, 9);
                    cout << "|";
                    gotoXY(x, 10);
                    cout<<"|";
                    y = 10;

                }
                else if (prev_y == 10)
                {
                    gotoXY(x, 8);
                    cout << "|";
                    gotoXY(x, 9);
                    cout << "|";
                    gotoXY(x, 10);
                    cout<<"|";
                    y = 7;
                }
                prev_y = y;



                //prev_x = x;

                gotoXY(x+1, y);
                cout << "_____";

            }
        }
        x=x+5;
        y=8;

    }
    y++;
    gotoXY(x, y);
    cout << "---------> time" << endl;
    char choice;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<"Enter \"Y\" to try again and \"N\" or any character to quit: ";
    cin>>choice;
    if(choice=='Y'||choice=='y')
    {
        main();
    }
    else
    {
        exit(0);
    }
}

void nrzl(char a[],int b)
{


    int x = 0, y = 0;
    system("cls");
    x = 3, y = 1;
    cout << "Amplitutde";
    x = 4;
    y = 1;
    gotoXY(x,y);
    cout<<"^";
    y++;
    while (y != 17)
    {
        gotoXY(x, y);
        cout << "|";
        y++;
    }

    x=7;
    y=3;
    x=0;
    y=9;
    gotoXY(x,y);
    cout<<"NRZL";
    for (int i = 0; i < b; i++)
    {
        int temp=0;
        if (a[i] == '0')
        {
            if (i == 0)
            {
                x=7;
                y=2;
                gotoXY(x,y);
                cout<<a[i];
                x = 5;
                y = 7;
                gotoXY(x, y);
                cout << "_____";
            }
            if(a[i-1]=='1')
            {

                x+=3;
                temp=y;
                y=2;
                gotoXY(x,y);
                cout<<a[i];
                x-=3;
                y=temp;


                gotoXY(x, y);
                cout << "|";
                y++;
                gotoXY(x, y);
                cout << "|";
                y++;
                gotoXY(x, y);
                cout<<"|";
                y -= 3;
                x++;
                gotoXY(x, y);
                cout << "_____";
            }
            if(a[i-1]=='0')
            {
                y=2;
                x+=2;
                gotoXY(x,y);
                cout<<a[i];
                x-=2;
                y=7;
                gotoXY(x,y);
                cout<<"_____";
            }
        }
        else
        {
            if (i == 0)
            {

                x=7;
                y=2;
                gotoXY(x,y);
                cout<<a[i];



                x = 5;
                y = 10;
                gotoXY(x, y);
                cout << "_____";
            }
            if(a[i-1]=='0')
            {

                x+=3;
                temp=y;
                y=2;
                gotoXY(x,y);
                cout<<a[i];
                x-=3;
                y=temp;

                gotoXY(x, y);
                cout << "|";
                y++;
                gotoXY(x, y);
                cout << "|";
                y++;
                gotoXY(x, y);
                cout << "|";
                x+=1;
                gotoXY(x, y);
                cout << "_____";
            }
            if(a[i-1]=='1')
            {

                y=2;
                x+=2;
                gotoXY(x,y);
                cout<<a[i];
                x-=2;
                y=10;
                gotoXY(x,y);
                cout<<"_____";
            }


        }
        x=x+5;
        y=8;

    }
    y++;
    gotoXY(x, y);
    cout << "---------> time" << endl;
    char choice;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<"Enter \"Y\" to try again and \"N\" or any character to quit: ";
    cin>>choice;
    if(choice=='Y'||choice=='y')
    {
        main();
    }
    else
    {
        exit(0);
    }
}
