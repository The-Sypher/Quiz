#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctime>
#include <Windows.h>
#include <fstream>
#include <sstream>
using namespace std;
int score = 0, t = 0;
//the questions
class OPTION
{
public:
  string option;
  bool is_correct;
};
class QUESTION
{
public:
  string question;
  OPTION op[4];
};
class CATEGORY
{
public:
  QUESTION question[20];
  QUESTION set[10];
};
class CONTROL
{
public:
  CATEGORY cat[6];
  CONTROL()
  {
    ifstream fin[10];
    string line;
    string field;
    int i=0,j;
    fin[0].open("Business Questions.txt");
    while(fin[0])
    {
      getline(fin[0],line);
      cat[0].question[i].question = line;
      i++;
    }
    fin[0].close();
    fin[1].open("Geography Questions.txt");
    i=0;
    while(fin[1])
    {
      getline(fin[1],line);
      cat[1].question[i].question = line;
      i++;
    }
    fin[1].close();
    fin[2].open("History Questions.txt");
    i=0;
    while(fin[2])
    {
      getline(fin[2],line);
      cat[2].question[i].question = line;
      i++;
    }
    fin[2].close();
    fin[3].open("Sports Questions.txt");
    i=0;
    while(fin[3])
    {
      getline(fin[3],line);
      cat[3].question[i].question = line;
      i++;
    }
    fin[3].close();
    fin[4].open("Current Affairs Questions.txt");
    i=0;
    while(fin[4])
    {
      getline(fin[4],line);
      cat[4].question[i].question = line;
      i++;
    }
    fin[4].close();
    fin[5].open("Business Answers.txt");
    i=0;
    string op;
    while(fin[5])
    {
      getline(fin[5],line);
      stringstream ss(line);
      j=0;
      while(getline(ss,op,','))
      {
        cat[0].question[i].op[j].option = op;
        cat[0].question[i].op[j].is_correct = false;
        if(op.at(op.length()-1) == '/')
        {
          cat[0].question[i].op[j].is_correct = true;
          cat[0].question[i].op[j].option = cat[0].question[i].op[j].option.substr(0,(cat[0].question[i].op[j].option.length()-1));
        }
        j++;
      }
      i++;
    }
    fin[5].close();
    fin[6].open("Geography Answers.txt");
    i = 0;
    while (fin[6])
    {
      getline(fin[6], line);
      stringstream ss(line);
      j = 0;
      while (getline(ss, op, ','))
      {
        cat[1].question[i].op[j].option = op;
        cat[1].question[i].op[j].is_correct = false;
        if (op.at(op.length() - 1) == '/')
        {
          cat[1].question[i].op[j].is_correct = true;
          cat[1].question[i].op[j].option = cat[1].question[i].op[j].option.substr(0, (cat[1].question[i].op[j].option.length() - 1));
        }
        j++;
      }
      i++;
    }
    fin[6].close();
    fin[7].open("History Answers.txt");
    i = 0;
    while (fin[7])
    {
      getline(fin[7], line);
      stringstream ss(line);
      j = 0;
      while (getline(ss, op, ','))
      {
        cat[2].question[i].op[j].option = op;
        cat[2].question[i].op[j].is_correct = false;
        if (op.at(op.length() - 1) == '/')
        {
          cat[2].question[i].op[j].is_correct = true;
          cat[2].question[i].op[j].option = cat[2].question[i].op[j].option.substr(0, (cat[2].question[i].op[j].option.length() - 1));
        }
        j++;
      }
      i++;
    }
    fin[7].close();
    fin[8].open("Sports Answers.txt");
    i = 0;
    while (fin[8])
    {
      getline(fin[8], line);
      stringstream ss(line);
      j = 0;
      while (getline(ss, op, ','))
      {
        cat[3].question[i].op[j].option = op;
        cat[3].question[i].op[j].is_correct = false;
        if (op.at(op.length() - 1) == '/')
        {
          cat[3].question[i].op[j].is_correct = true;
          cat[3].question[i].op[j].option = cat[3].question[i].op[j].option.substr(0, (cat[3].question[i].op[j].option.length() - 1));
        }
        j++;
      }
      i++;
    }
    fin[8].close();
    fin[9].open("Current Affairs Answers.txt");
    i = 0;
    while (fin[9])
    {
      getline(fin[9], line);
      stringstream ss(line);
      j = 0;
      while (getline(ss, op, ','))
      {
        cat[4].question[i].op[j].option = op;
        cat[4].question[i].op[j].is_correct = false;
        if (op.at(op.length() - 1) == '/')
        {
          cat[4].question[i].op[j].is_correct = true;
          cat[4].question[i].op[j].option = cat[4].question[i].op[j].option.substr(0, (cat[4].question[i].op[j].option.length() - 1));
        }
        j++;
      }
      i++;
    }
    fin[9].close();
    i=0;
  }
  int category,number;
  void create_questions(int c, int d = -1, int e = -1, int f = -1, int g = -1, int h = -1)
  {
    category = c;
    int i = 0, j;
    int numOfSets = 0;
    srand(time(0));
    if (category == 5)
    {
      if (d > -1)
      {
        numOfSets++;
      }
      if (e > -1)
      {
        numOfSets++;
      }
      if (f > -1)
      {
        numOfSets++;
      }
      if (g > -1)
      {
        numOfSets++;
      }
      if (h > -1)
      {
        numOfSets++;
      }
      numOfSets = 10 * numOfSets;
      int ran_index = 0;
      int arr1[10];
      int i = 0, j;
      if (d > -1)
      {
        int ran1;
        i = 0;
        while (i < (10 / (numOfSets / 10)))
        {
          j = 0;
          ran1 = (rand() % 20);
          bool b = true;
          for (j = 0; j <= i; j++)
          {
            if (arr1[j] == ran1)
            {
              b = false;
            }
          }
          if (b)
          {
            arr1[i] = ran1;
            cat[category].set[ran_index] = cat[d].question[ran1];
            ran_index++;
            i++;
          }
        }
      }
      if (e > -1)
      {
        int ran2;
        i = 0;
        while (i < (10 / (numOfSets / 10)))
        {
          j = 0;
          ran2 = (rand() % 20);
          bool b = true;
          for (j = 0; j <= i; j++)
          {
            if (arr1[j] == ran2)
            {
              b = false;
            }
          }
          if (b)
          {
            arr1[i] = ran2;
            cat[category].set[ran_index] = cat[e].question[ran2];
            ran_index++;
            i++;
          }
        }
      }
      if (f > -1)
      {
        int ran3;
        i = 0;
        while (i < (10 / (numOfSets / 10)))
        {
          j = 0;
          ran3 = (rand() % 20);
          bool b = true;
          for (j = 0; j <= i; j++)
          {
            if (arr1[j] == ran3)
            {
              b = false;
            }
          }
          if (b)
          {
            arr1[i] = ran3;
            cat[category].set[ran_index] = cat[f].question[ran3];
            ran_index++;
            i++;
          }
        }
      }
      if (g > -1)
      {
        int ran4;
        i = 0;
        while (i < (10 / (numOfSets / 10)))
        {
          j = 0;
          ran4 = (rand() % 20);
          bool b = true;
          for (j = 0; j <= i; j++)
          {
            if (arr1[j] == ran4)
            {
              b = false;
            }
          }
          if (b)
          {
            arr1[i] = ran4;
            cat[category].set[ran_index] = cat[g].question[ran4];
            ran_index++;
            i++;
          }
        }
      }
      if (h > -1)
      {
        int ran5;
        i = 0;
        while (i < (10 / (numOfSets / 10)))
        {
          j = 0;
          ran5 = (rand() % 20);
          bool b = true;
          for (j = 0; j <= i; j++)
          {
            if (arr1[j] == ran5)
            {
              b = false;
            }
          }
          if (b)
          {
            arr1[i] = ran5;
            cat[category].set[ran_index] = cat[h].question[ran5];
            ran_index++;
            i++;
          }
        }
      }
      while(ran_index < 10)
      {
        if(ran_index == 8)
        {
          int ran6;
          j = 0;
          ran6 = (rand() % 20);
          bool b = true;
          for (j = 0; j <= i; j++)
          {
            if (arr1[j] == ran6)
            {
              b = false;
            }
          }
          if (b)
          {
            arr1[i] = ran6;
            cat[category].set[ran_index] = cat[d].question[ran6];
            ran_index++;
          }
        }
        if (ran_index == 9)
        {
          int ran6;
          j = 0;
          ran6 = (rand() % 20);
          bool b = true;
          for (j = 0; j <= i; j++)
          {
            if (arr1[j] == ran6)
            {
              b = false;
            }
          }
          if (b)
          {
            arr1[i] = ran6;
            cat[category].set[ran_index] = cat[e].question[ran6];
            ran_index++;
          }
        }
      }
    }
    else
    {
      int arr7[10];
      int ran7;
      i = 0;
      while (i < 10)
      {
        j = 0;
        ran7 = (rand() % 20);
        bool b = true;
        for (j = 0; j <= i; j++)
        {
          if (arr7[j] == ran7)
          {
            b = false;
          }
        }
        if (b)
        {
          arr7[i] = ran7;
          cat[category].set[i] = cat[category].question[ran7];
          i++;
        }
      }
    }
  }
  void ask_question(int i)
  {
    cout << "Q" << (i+1) << ") " << cat[category].set[i].question << endl;
    int n;
    cout << "Options: \n";
    for (n = 0; n < 4; n++)
    {
      cout << char(n+65) << ". " << cat[category].set[i].op[n].option << "\n";
    }
    cout << "\n";
  }
  int check_if_correct(char a, int num)
  {
    int option;
    if (a == 'A' || a == 'a')
    {
      option = 0;
    }
    else if (a == 'B' || a == 'b')
    {
      option = 1;
    }
    else if (a == 'C' || a == 'c')
    {
      option = 2;
    }
    else if (a == 'D' || a == 'd')
    {
      option = 3;
    }
    else
    {
      return -1;
    }

    if (cat[category].set[num].op[option].is_correct)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
};
//main
CONTROL con;
void show_correct(int i)
{
  cout << "Right Answer:\n";
  if(con.cat[con.category].set[i].op[0].is_correct)
  {
    cout << "A. " << con.cat[con.category].set[i].op[0].option << endl << endl;
  }
  else if(con.cat[con.category].set[i].op[1].is_correct)
  {
    cout << "B. " << con.cat[con.category].set[i].op[1].option << endl << endl;
  }
  else if(con.cat[con.category].set[i].op[2].is_correct)
  {
    cout << "C. " << con.cat[con.category].set[i].op[2].option << endl << endl;
  }
  else
  {
    cout << "D. " << con.cat[con.category].set[i].op[3].option << endl << endl;
  }
}
void call(int a)
{

  int i = 0,b;
  char ch;
  con.create_questions(a);
  while (i < 10)
  {
    con.ask_question(i);
    do
    {
      cout << "Enter your answer:";
      cin >> ch;
      b = con.check_if_correct(ch, i);
      if (b == -1)
        cout << "Please enter a valid option" << endl;
    } while (b == -1);
    if (b == 0)
    {
      cout << "\nWrong Answer\n\n\n";
      show_correct(i);
    }
    else if(b == 1)
    {
      cout << "\nRight Answer\n\n\n";
      score++;
    }
    if(i!=9)
    {
      cout<<"Next question in 3";
      for(int k=2;k>0;k--)
      {
        cout<<"\b"<<k;
        Sleep(1000);
      }
    }
    else
    {
      cout<<"Redirecting in 3";
      for(int k=2;k>0;k--)
      {
        cout<<"\b"<<k;
        Sleep(1000);
      }
    }
    system("CLS");
    i++;
  }
}
void call(int a, int b, int c, int d, int e)
{

  int i = 0, x;
  char ch;
  con.create_questions(5, a, b, c, d, e);
  while (i < 10)
  {
    con.ask_question(i);
    do
    {
      cout << "Enter your answer:";
      cin >> ch;
      x = con.check_if_correct(ch, i);
      if (x == -1)
      {
        cout << "Please enter a valid option:" << endl;
      }
    }while(x == -1);

    if (x == 0)
    {
      cout << "\nWrong Answer\n\n\n";
      show_correct(i);
    }
    else
    {
      cout << "\nRight Answer\n\n\n";
      score++;
    }
    if(i!=9)
    {
      cout<<"Next question in 3";
      for(int k=2;k>0;k--)
      {
        cout<<"\b"<<k;
        Sleep(1000);
      }
    }
    else
    {
      cout<<"Returning to Main Menu in 3";
      for(int k=2;k>0;k--)
      {
        cout<<"\b"<<k;
        Sleep(1000);
      }
    }
    system("CLS");
    i++;
  }
}
void showcat(int i)
{
  cout << "-------------------------------------------" << endl;
  cout << "                CATEGORIES:" << endl;
  cout << "-------------------------------------------" << endl<< endl;
  cout << "1.Business\n2.Geography\n3.History\n4Sports\n5.Media and Current Affairs\n";
  if(i==1)
    cout<<"6.Start quiz\n";
  cout<<"----(To back to Main Menu enter 0)\nEnter your choice:";
}
void case1()
{
  int c;
  do
  {
    showcat(0);
    cin >> c;
    switch (c)
    {
    case 1:
      system("CLS");
      call(0);
      t += 10;
      break;
    case 2:
      system("CLS");
      call(1);
      t += 10;
      break;
    case 3:
      system("CLS");
      call(2);
      t += 10;
      break;
    case 4:
    system("CLS");
      call(3);
      t += 10;
      break;
    case 5:
      system("CLS");
      call(4);
      t += 10;
      break;
    case 0:
      break;
    default:
      cout << "\nWrong choice, Try again" << endl;
    }
    if(c==0)
      cout<<"\nAre you sure?\n";
    cout << "Enter (1) to choose another category or enter (0) to go to main menu: ";
    cin >> c;
    system("CLS");
  } while (c != 0);
}
void case2()
{
  int c, ct = -1, flag = 0;
  int ca[] = {-1, -1, -1, -1, -1};
  showcat(1);
  do
  {
    cin >> c;
    switch (c)
    {
      case 1:
        ca[0] = 0;
        ct++;
      break;

      case 2:
        ca[1] = 1;
        ct++;
      break;

      case 3:
        ca[2] = 2;
        ct++;
      break;

      case 4:
        ca[3] = 3;
        ct++;
      break;

      case 5:
        ca[4] = 4;
        ct++;
      break;

      case 6:
        if (ct != -1)
          flag = 1;
        else
          cout << "\nError: You have to choose atleast one topic\n";
      break;

      case 0:
        flag = -1;
        break;
      default:
        cout << "Wrong choice";
      break;
    }
  } while (flag !=-1);

  if (flag == 1)
  {
     call(ca[0], ca[1], ca[2], ca[3], ca[4]);
    t += 10;
  }
}
void case3()
{
  cout << "\n\n";
  call(0, 1, 2, 3, 4);
  t += 10;
}
void case4()
{
  cout << "Your total score: " << score << "/" << t << endl;
  cout << "(It means you answered " << score << " questions correctly out of " << t << " questions)" << endl;
  Sleep(3000);
}
void case5()
{
  score = t = 0;
  int k=0;
  char a[]={'\\','|','/','-'};
  cout << "Your scores have been reset" << endl;
  for(int i=1;i<=20;i++)
  {
    cout<<"\b"<<a[k];
    Sleep(100);
    k++;
    if(k==4)
      k=0;
  }
}
int main()
{
  int c;
  do
  {
    cout << "-------------------------------------------" << endl;
    cout << "                  MENU:" << endl;
    cout << "-------------------------------------------" << endl<< endl;
    cout << "1.Questions in a category\n2.Questions from multiple specific categories\n3.Random questions\n4.Show score\n5.Reset scores\n6.Exit\nEnter your choice:";
    cin >> c;
    switch (c)
    {
      case 1:
        system("CLS");
        case1();
        system("CLS");
        break;
      case 2:
        system("CLS");
        case2();
        system("CLS");
        break;
      case 3:
        system("CLS");
        case3();
        system("CLS");
        break;
      case 4:
        system("CLS");
        case4();
        system("CLS");
        break;
      case 5:
        system("CLS");
        case5();
        system("CLS");
        break;
      case 6:
        cout << "Have a good day";
        break;
      default:
        cout << "Wrong choice";
    }
  } while (c != 6);
  return 0;
}
