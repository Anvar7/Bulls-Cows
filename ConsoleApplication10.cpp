
#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<string>
#include<ctime>

using namespace std;

void main();

//--------------------------------


int save = 0;




class random_number//----------------------==========RANDOM_NUMBER==============-----------------------------
{
private:
	int com_num[4];
	friend void hint(int x[], int size, int number);
public:

	//===

	void game1()
	{
		int array[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
		srand(time(0));
		int temp;

		temp = rand() % 9;
		com_num[0] = array[temp];

		array[temp] = array[9];

		int j = 9;

		for (int i = 1; i < 4; i++)
		{
			temp = rand() % j;
			com_num[i] = array[temp];
			array[temp] = array[j - 1];
			j--;
		}
	}





	//===

};


void hint(int x[], int size, int number)
{
	random_number n;
	n.game1();
	cout << "->";
	for (int i = 0; i < number; i++)
		cout << n.com_num[i];
	for (int j = 0; j < 4 - number; j++)
		cout << "x";
	cout << endl;

	for (int i = 0; i < 4; i++)
		x[i] = n.com_num[i];
}



//----------------------------------------------







class game : public random_number//------------------================GAME================-----------------------
{
private:

	int hours = 0, minutes = 0, seconds = 0;//for time
	int bull = 0, cow = 0;//for game
	int user_num_arr[4];//for creating array from number
	int user_num;//users inputed number
	int com_num[4];
	int i = 0;
	int entered = 0, user_score[10];
	string user_name;
	int score2[20];
	string name2[20];
	friend istream &operator>>(istream &input, game &n);


public:

	//==============

	void game1()
	{
		int number;
		char command;
		cout << "Do you need hint?Y/N" << endl;
		command = _getch();
		if (command == 'y' || command == 'Y')
		{
			do{
				cout << "How many digits should be shown?(less than 4)" << endl;

				cin >> number;
			} while (number > 4);
			hint(com_num, 4, number);
		}
		else
			hint(com_num, 4, 0);



		cout << "Press any key to begin" << endl;
		_getch();
		clock_t t1, t2;
		t1 = clock();
		system("cls");

		do
		{
			input();

			bull = 0;
			cow = 0;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (com_num[i] == user_num_arr[j])
					{
						if (i == j)
							bull++;
						else
							cow++;
					}

				}
			}

			cout << endl;
			cout << setw(72) << "B U L L S -> " << bull << "     C O W S -> " << cow << endl;
			cout << setw(75) << "T I M E -> " << (int)clock() / 1000 - (int)t1 / 1000 << " Seconds" << endl << endl;

		} while (bull != 4);
		i++;
		cout << setw(94) << "- =  C O N G R A T U L A T I O N S  = -" << endl;
		t2 = clock();
		int sec((int)t2 / 1000 - (int)t1 / 1000);

		seconds = sec;
		score_calcul(sec);
		data_saving();
		cout << endl;
		cout << " - =  P R E S S   A N Y   K E Y   T O   G O   B A C K   T O   M E N U  = -" << endl;
		_getch();
		system("cls");
		main();

	}

	//====
	void score_calcul(int sec)
	{
		do
		{
			if (sec >= 60)
			{
				sec = sec - 60;
				++minutes;
			}
		} while (sec >= 60);

		do
		{
			if (minutes >= 60)
			{
				minutes = minutes - 60;
				++hours;
			}
		} while (minutes >= 60);

		cout << "Time is: " << hours << ":" << minutes << ":" << sec << endl;
		cout << "Number of enterings: " << entered << endl;

		if (entered <= seconds / 2)
			user_score[i] = 100 - seconds + entered;
		else
			user_score[i] = 100 - seconds - entered / 2;

		if (user_score[i] > 96)
			user_score[i] = 100;
		if (user_score[i] <= 10)
			user_score[i] = 10;
		cout << "Score is: " << user_score[i] << endl;

	}



	//====
	void input()
	{
		int x;

		do
		{
			cout << setw(95) << "- =  E N T E R   T H E   N U M B E R  = -" << endl;
			cout << setw(70) << "--> ";
			cin >> user_num;
			if (convert_array())
				break;
		} while (true);
	}

	//====

	bool convert_array()
	{
		int x = user_num;
		int temp;


		if (user_num < 1000 || user_num>9999)
		{
			cout << endl;
			cout << setw(85) << "- =  I N V A L I D  = -" << endl << endl;

			return false;
		}
		for (int i = 0, k = 3; i < 4, k >= 0; k--, i++)
		{
			temp = x / pow(10, k);
			user_num_arr[i] = temp;
			x = x - temp*pow(10, k);

		}


		for (int i = 1; i < 4; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (user_num_arr[i] == user_num_arr[j])
				{
					cout << endl;
					cout << setw(85) << "- =  I N V A L I D  = -" << endl << endl;;
					return false;
				}
			}

		}

		entered++;
		return true;
	}

	//====
	void data_sorting(int array[], string name[], int size)
	{
		int flag = 1;
		string temp1;
		int temp;
		array[size];
		name[size];
		for (int j = 0; j <= size; j++)
		{
			for (int k = j + 1; k <= size; k++)
			{
				if (array[k] > array[j])
				{
					temp = array[j];
					array[j] = array[k];
					array[k] = temp;

					temp1 = name[j];
					name[j] = name[k];
					name[k] = temp1;
				}

			}
		}


	}

	void data_saving()
	{

		int score1[10];
		string name1[10];
		ifstream ifs;
		ifs.open("Score.txt");
		for (int k = 0; k < 10; k++)
			ifs >> name1[k] >> score1[k];
		ifs.clear();

		for (int j = 0; j <= 10 + i; j++)
		{
			if (j <= 9)
			{
				score2[j] = score1[j];
				name2[j] = name1[j];
			}
			else
			{
				name2[j] = user_name;
				score2[j] = user_score[j - 10];
			}
		}
		ifs.close();


		data_sorting(score2, name2, 10 + i);

		ofstream ofs;
		ofs.open("Score.txt");
		for (int k = 0; k <= 10 + i; k++)
			ofs << name2[k] << "\t\t" << score2[k] << endl;
		ofs.close();


	}


	void show()
	{
		ifstream ifs("Score.txt");
		for (int j = 0; j < 10 + i; j++)
			ifs >> name2[j] >> score2[j];
		for (int j = 0; j < 10 + i; j++)
		{
			cout << endl;
			cout << setw(68) << name2[j] << "    \t" << score2[j] << endl;
		}
		cout << endl;


	}


	//================

};


istream &operator>>(istream &input, game &n)
{
	input >> n.user_name;
	return input;
}






//--------------------------------





class menu :public game//------------=======================MENU========================---------------------
{
private:

	int choose = 0;
	char command;
	bool exit1 = 0;


public:



	//======

	void choose1()
	{
		m_newgame();

		do
		{
			exit1 = 0;

			command = _getch();

			if (command == 'S' || command == 's')
			{

				choose++;
				if (choose > 3)
					choose = 0;
			}
			else
			if (command == 'W' || command == 'w')
			{
				choose--;
				if (choose < 0)
					choose = 3;
			}


			switch (choose)
			{
			case 0:
				if (command == 'E' || command == 'e'){
					exit1++;
				}
				else
				{
					system("cls");
					m_newgame();
				}
				break;
			case 1:
				if (command == 'E' || command == 'e'){
					system("cls");
					score();
				}
				else{
					system("cls");
					m_score();
				}
				break;

			case 2:
				if (command == 'E' || command == 'e'){
					system("cls");
					about();
				}
				else{
					system("cls");
					m_about();
				}
				break;

			case 3:
				if (command == 'E' || command == 'e'){
					system("cls");
					cout << "Bye" << endl;
					exit(1);
				}
				else{
					system("cls");
					m_exit();
				}
				break;

			}
			if (exit1 == 1)
				break;
		} while (true);
	}

	//======
	void about()
	{
		cout << setw(85) << "-->  A B O U T  <--" << endl << endl;
		cout << "\n   This project is called <Bulls and Cows>. It is electronic format of eponymous game. The main aim of user ";
		cout << "is to find a number that computer made. \nThe terms of game are next:" << endl;
		cout << "1) Computer made four - digit number.And there is no same digit. Respectively user should enter the\nnumber according to these rule." << endl;
		cout << "2) Computer checks each entered number. And game will stop if only if the user will find out the number." << endl;
		cout << "3) Bulls and Cows are data that computer outputs for user. Cow perpesents the number of the same digits" << endl;
		cout << "between the entered number and computers number, but digits that are not having same position.\nBulls represents the number of the same digits between entered number and computer number,\ndigits that are having the same position" << endl;
		cout << "Example:\nIf the computer's number is 4201 and entered number is 1234" << endl;
		cout << "4201\n1234   as you see there is one bull and two cows. The value of the second digit is the same as well as position.\nAlso same numbers 4 and 2 but the positions are different." << endl;
		cout << "4) Computer is also calculating the time. And your score depends on time" << endl;

		cout << endl;
		cout << " - =  P R E S S   A N Y   K E Y   T O   G O   B A C K   T O   M E N U  = -" << endl;
		_getch();
		main();
	}
	//=======

	void score()
	{
		int score[10];
		string name[10];
		cout << setw(85) << "- =  S C O R E S  = -" << endl;
		cout << endl;
		cout << setw(76) << "Name:\t\tScore:" << endl;

		show();
	}

	//=========================================================================================================

	void output_menu()
	{
		cout << setw(104) << "####     ####  ########  ####     ###  ####     ####" << endl;
		cout << setw(104) << "#####   #####  ########  #####    ###  ####     ####" << endl;
		cout << setw(104) << "### ##### ###  ###       ######   ###  ####     ####" << endl;
		cout << setw(104) << "###  ###  ###  ########  ### ###  ###  ####     ####" << endl;
		cout << setw(103) << "###   #   ###  ###       ###  ### ###   ####   ####" << endl;
		cout << setw(102) << "###       ###  ########  ###   ######    #########" << endl;
		cout << setw(100) << "###       ###  ########  ###    #####      #####" << endl;
	}

	//============

	void output_b_c()
	{
		cout << endl;
		cout << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "\t\t\t\t\t\t\t       " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "\t\t\t" << "       " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "\t\t\t\t\t\t\t\t   " << char(254) << " " << char(254) << " " << char(254) << endl;
		cout << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "\t\t\t\t\t\t\t     " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "\t\t" << "     " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "\t\t\t\t\t\t\t   " << char(254) << " " << char(254) << " " << char(254) << endl;
		cout << " " << char(254) << " " << char(254) << "   \t    " << " " << char(254) << " " << char(254) << "\t\t\t    " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t\t   " << char(254) << " " << char(254) << "\t       " << char(254) << " " << char(254) << "\t\t" << "   " << char(254) << " " << char(254) << "\t       " << char(254) << " " << char(254) << "\t\t\t\t\t\t\t   " << char(254) << " " << char(254) << " " << char(254) << endl;
		cout << " " << char(254) << " " << char(254) << "   \t    " << " " << char(254) << " " << char(254) << "\t\t\t    " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t\t   " << char(254) << " " << char(254) << "\t       " << char(254) << " " << char(254) << "\t\t" << " " << char(254) << " " << char(254) << "\t\t\t\t\t\t\t\t\t   " << char(254) << " " << char(254) << " " << char(254) << endl;
		cout << " " << char(254) << " " << char(254) << "   \t    " << " " << char(254) << " " << char(254) << "\t\t\t    " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t\t     " << char(254) << " " << char(254) << "     " << char(254) << " " << char(254) << "\t\t" << " " << char(254) << " " << char(254) << "\t\t\t\t\t\t\t\t\t   " << char(254) << " " << char(254) << " " << char(254) << endl;
		cout << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "  \t" << char(254) << " " << char(254) << "    \t  " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t\t       " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "\t\t\t" << " " << char(254) << " " << char(254) << "\t\t\t   " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "\t   " << char(254) << " " << char(254) << "\t\t\t   " << char(254) << " " << char(254) << "\t   " << char(254) << " " << char(254) << " " << char(254) << endl;
		cout << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "  \t" << char(254) << " " << char(254) << "    \t  " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t\t         " << char(254) << " " << char(254) << "\t\t\t" << " " << char(254) << " " << char(254) << "\t\t\t " << char(254) << " " << char(254) << "\t   " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t\t\t  " << char(254) << " " << char(254) << "\t   " << char(254) << " " << char(254) << " " << char(254) << endl;
		cout << " " << char(254) << " " << char(254) << "   \t    " << " " << char(254) << " " << char(254) << "  \t" << char(254) << " " << char(254) << "    \t  " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t\t       " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "     " << char(254) << " " << char(254) << "\t\t" << " " << char(254) << " " << char(254) << "\t\t\t " << char(254) << " " << char(254) << "\t   " << char(254) << " " << char(254) << "\t     " << char(254) << " " << char(254) << "\t         " << char(254) << " " << char(254) << "\t   " << char(254) << " " << char(254) << " " << char(254) << endl;
		cout << " " << char(254) << " " << char(254) << "   \t    " << " " << char(254) << " " << char(254) << "  \t" << char(254) << " " << char(254) << "    \t  " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t\t     " << char(254) << " " << char(254) << "     " << char(254) << " " << char(254) << "   " << char(254) << " " << char(254) << "\t\t" << " " << char(254) << " " << char(254) << "\t\t\t " << char(254) << " " << char(254) << "\t   " << char(254) << " " << char(254) << "\t      " << char(254) << " " << char(254) << "\t        " << char(254) << " " << char(254) << "\t   " << char(254) << " " << char(254) << " " << char(254) << endl;
		cout << " " << char(254) << " " << char(254) << "   \t    " << " " << char(254) << " " << char(254) << "  \t" << char(254) << " " << char(254) << "    \t  " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t\t   " << char(254) << " " << char(254) << "         " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "\t\t" << " " << char(254) << " " << char(254) << "\t\t\t " << char(254) << " " << char(254) << "\t   " << char(254) << " " << char(254) << "\t       " << char(254) << " " << char(254) << "\t       " << char(254) << " " << char(254) << endl;
		cout << " " << char(254) << " " << char(254) << "   \t    " << " " << char(254) << " " << char(254) << "  \t" << char(254) << " " << char(254) << "    \t  " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t\t   " << char(254) << " " << char(254) << "         " << char(254) << " " << char(254) << " " << char(254) << "\t\t" << "   " << char(254) << " " << char(254) << "\t       " << char(254) << " " << char(254) << "\t " << char(254) << " " << char(254) << "\t   " << char(254) << " " << char(254) << "\t        " << char(254) << " " << char(254) << "\t" << char(254) << "     " << char(254) << " " << char(254) << "\t   " << char(254) << " " << char(254) << " " << char(254) << endl;
		cout << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "  \t" << char(254) << " " << char(254) << "    \t  " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t\t   " << char(254) << " " << char(254) << "        " << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "\t\t" << "     " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "\t " << char(254) << " " << char(254) << "\t   " << char(254) << " " << char(254) << "\t         " << char(254) << " " << char(254) << "  " << char(254) << " " << char(254) << " " << char(254) << "  " << char(254) << " " << char(254) << "\t   " << char(254) << " " << char(254) << " " << char(254) << endl;
		cout << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "  \t" << "  " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t    " << char(254) << " " << char(254) << "\t\t     " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "     " << char(254) << " " << char(254) << "\t" << "       " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "\t\t   " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << " " << char(254) << "\t          " << char(254) << " " << char(254) << " " << char(254) << "   " << char(254) << " " << char(254) << " " << char(254) << "\t\t   " << char(254) << " " << char(254) << " " << char(254) << endl;
		cout << endl << endl;
	}

	//=============

	void m_newgame()
	{
		output_menu();

		cout << endl;
		cout << setw(93) << "|                               |" << endl;
		cout << setw(93) << "|     ->  N E W  G A M E  <-    |" << endl;
		cout << setw(93) << "|                               |" << endl;
		cout << setw(93) << "|           S C O R E           |" << endl;
		cout << setw(93) << "|                               |" << endl;
		cout << setw(93) << "|           A B O U T           |" << endl;
		cout << setw(93) << "|                               |" << endl;
		cout << setw(93) << "|            E X I T            |" << endl;
		cout << setw(93) << "|_______________________________|" << endl;
		cout << setw(90) << "w - up; s - down; e - enter" << endl;

	}


	//==========


	void m_score()
	{

		output_menu();

		cout << endl;
		cout << setw(93) << "|                               |" << endl;
		cout << setw(93) << "|         N E W  G A M E        |" << endl;
		cout << setw(93) << "|                               |" << endl;
		cout << setw(93) << "|       ->  S C O R E  <-       |" << endl;
		cout << setw(93) << "|                               |" << endl;
		cout << setw(93) << "|           A B O U T           |" << endl;
		cout << setw(93) << "|                               |" << endl;
		cout << setw(93) << "|            E X I T            |" << endl;
		cout << setw(93) << "|_______________________________|" << endl;
		cout << setw(90) << "w - up; s - down; e - enter" << endl;

	}


	//==========



	void m_about()
	{

		output_menu();

		cout << endl;
		cout << setw(93) << "|                               |" << endl;
		cout << setw(93) << "|         N E W  G A M E        |" << endl;
		cout << setw(93) << "|                               |" << endl;
		cout << setw(93) << "|           S C O R E           |" << endl;
		cout << setw(93) << "|                               |" << endl;
		cout << setw(93) << "|       ->  A B O U T  <-       |" << endl;
		cout << setw(93) << "|                               |" << endl;
		cout << setw(93) << "|            E X I T            |" << endl;
		cout << setw(93) << "|_______________________________|" << endl;
		cout << setw(90) << "w - up; s - down; e - enter" << endl;
	}



	//==========



	void m_exit()
	{
		output_menu();

		cout << endl;
		cout << setw(93) << "|                               |" << endl;
		cout << setw(93) << "|         N E W  G A M E        |" << endl;
		cout << setw(93) << "|                               |" << endl;
		cout << setw(93) << "|           S C O R E           |" << endl;
		cout << setw(93) << "|                               |" << endl;
		cout << setw(93) << "|           A B O U T           |" << endl;
		cout << setw(93) << "|                               |" << endl;
		cout << setw(93) << "|        ->  E X I T  <-        |" << endl;
		cout << setw(93) << "|_______________________________|" << endl;
		cout << setw(90) << "w - up; s - down; e - enter" << endl;
	}
	//==============================================================================
};




//-------------------------------------




void main()
{
	//This part is needed just at the first use. To create file of scores. It is not needed after the first compilation.
	int score[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	string arr[10] = { "NO-NAME", "NO-NAME", "NO-NAME", "NO-NAME", "NO-NAME", "NO-NAME", "NO-NAME", "NO-NAME", "NO-NAME", "NO-NAME" };
	ofstream ofs("Score.txt", ios::app);
	for (int i = 0; i < 10; i++)
		ofs << arr[i] << "\t" << score[i];
	ofs.close();
	//Till this
	int number;
	random_number obj;
	menu obj1;
	game obj2;
	if (save == 0)
	{
		system("color 3");
		obj1.output_b_c();
		cout << setw(101) << "-->  P L E A S E   E N T E R   Y O U R   N A M E  <--" << endl;
		cout << endl;
		cout << setw(70) << "--> ";
		cin >> obj2;
		save++;
	}

	obj.game1();



	system("cls");
	obj1.choose1();
	obj2.game1();

}
