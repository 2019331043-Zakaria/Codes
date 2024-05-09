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
void nrzl(char a[], int s);

int main()
{
k: Sleep(800);
  system("cls");
  char a[10];
  cout << "Enter 10 digit binary: ";
  for (int i = 0; i < 10; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 10; i++) {
    if (a[i] == '1' || a[i] == '0')
    {
    }
    else
    {
      cout << "Invalid Binary";
      goto k;
    }
  }
  char b[4];
  cout << "Enter the Encoding Method: ";
  for (int i = 0; i < 4; i++) {
    cin >> b[i];
  }
  if (b[0] == 'N' || b[0] == 'n') {
    if (b[1] == 'R' || b[1] == 'r') {
      if (b[2] == 'Z' || b[2] == 'z') {
        if (b[3] == 'L' || b[3] == 'l') {
          nrzl(a, 10);
        }
      }
      else {
        cout << "Invalid Method" << endl;
        goto k;
      }


    }
    else {
      cout << "Invalid Method" << endl;
      goto k;
    }

  }
  else {
    cout << "Invalid Method" << endl;
    goto k;
  }
}

void gotoXY(int x, int y)
{
  CursorPosition.X = x;
  CursorPosition.Y = y;
  SetConsoleCursorPosition(console, CursorPosition);
}
void nrzl(char a[], int b) {


  int x = 0, y = 0;
  system("cls");
  x = 3, y = 1;
  cout << "Amplitutde";
  x = 4; y = 1;
  gotoXY(x, y);
  cout << "^";
  y++;
  while (y != 17) {
    gotoXY(x, y);
    cout << "|";
    y++;
  }

  x = 7;
  y = 3;
  x = 0; y = 9;
  gotoXY(x, y);
  cout << "NRZL";
  for (int i = 0; i < b; i++)
  {
    int temp = 0;
    if (a[i] == '0') {
      if (i == 0) {
        x = 7;
        y = 2;
        gotoXY(x, y);
        cout << a[i];
        x = 5;
        y = 7;
        gotoXY(x, y);
        cout << "_____";
      }
      if (a[i - 1] == '1') {

        x += 3;
        temp = y;
        y = 2;
        gotoXY(x, y);
        cout << a[i];
        x -= 3;
        y = temp;


        gotoXY(x, y);
        cout << "|";
        y++;
        gotoXY(x, y);
        cout << "|";
        y++;
        gotoXY(x, y);
        cout << "|";
        y -= 3;
        x++;
        gotoXY(x, y);
        cout << "_____";
      }
      if (a[i - 1] == '0') {
        y = 2;
        x += 2;
        gotoXY(x, y);
        cout << a[i];
        x -= 2;
        y = 7;
        gotoXY(x, y);
        cout << "_____";
      }
    }
    else {
      if (i == 0) {

        x = 7;
        y = 2;
        gotoXY(x, y);
        cout << a[i];



        x = 5;
        y = 10;
        gotoXY(x, y);
        cout << "_____";
      }
      if (a[i - 1] == '0') {

        x += 3;
        temp = y;
        y = 2;
        gotoXY(x, y);
        cout << a[i];
        x -= 3;
        y = temp;

        gotoXY(x, y);
        cout << "|";
        y++;
        gotoXY(x, y);
        cout << "|";
        y++;
        gotoXY(x, y);
        cout << "|";
        x += 1;
        gotoXY(x, y);
        cout << "_____";
      }
      if (a[i - 1] == '1') {

        y = 2;
        x += 2;
        gotoXY(x, y);
        cout << a[i];
        x -= 2;
        y = 10;
        gotoXY(x, y);
        cout << "_____";
      }


    }
    x = x + 5;
    y = 8;

  }
  y++;
  gotoXY(x, y);
  cout << "---------> time" << endl;
  char choice;
  cout << endl << endl << endl << endl << endl << endl << "Enter \"Y\" to try again and \"N\" or any character to quit: ";
  cin >> choice;
  if (choice == 'Y' || choice == 'y') {
    main();
  }
  else
  {
    exit(0);
  }
}
