/**
 * Cashion Penha
 * Lab 8
 * Operational Amplifier Circuits
 * 23/10/2017
 */

/**< preprocessor directives / header files*/
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <math.h>

using namespace std; /** Includes commonly used tools, such as cout, cin, To prevent typing "std" */

/**< Separate function to calculate the output voltage of both non inverting and inverting amplifier*/
/**< The output voltage can be calculated using a single function in this case. This is because the output
     voltage of the inverting and the non-inverting amplifier is calculated in the similar manner.
     This will also allow us to limit the output voltage to the supply voltage if the gain becomes to large.*/

void calcOutput(double aV, double vIn, double vCC, double vEE,double *vOut)
{
    *vOut = aV * vIn;
    if (*vOut>vCC)/**< Checking if the output voltage is greater then supply voltage */
        *vOut=vCC;/**< if it is then its limited to the supply voltage*/
    if (*vOut<vEE)
        *vOut=vEE;
    cout.precision(4);
}

/**< Separate function to calculate the gain of the inverting amplifier*/
void invert(double vcc, double vee, double vin, double rin, double rf, double *Av, double *vout)
{
    *Av = -(rf/rin);
    calcOutput(*Av,vin,vcc,vee,vout);
}

/**< Separate function to calculate the gain of the non-inverting amplifier*/
void noninvert(double nvcc, double nvee, double nvin, double r1, double r2, double *nAv, double *nvout)
{
    *nAv = 1+(r2/r1);
    calcOutput(*nAv,nvin,nvcc,nvee,nvout);
}

/**< Separate function to display the menu when called in the main function*/
void menu(void)
{
	/**< clear screen - not good programming practice! - system specific */
	system("cls");

	cout <<"Cashion Penha - C00218875";

	/**< print menu */
	cout << "\n_______________________________________________" <<
            "\nExercise 8 - Operational Amplifier Circuits" <<
			"\n\nChoose from one of the following:" <<
			"\na - Vout and Av of inverting Amplifier" <<
			"\nb - Vout and Av of non inverting Amplifier"
			"\nq - quit" <<
			"\n_______________________________________________" <<endl;

	return;
}


/**< main function */
int main(void)
{
	/**< variable declarations */
	char input;

	/**< continue running program until q is pressed */
	do
	{
		/**< display menu and get user input */
		menu();
		fflush(stdin);
		cin >> input;
		fflush(stdin);

		/**< switch case statement to implement user's decision */
		switch (input)
		{
		    /**< in case when a is entered by user, get values from user, and call the invert function*/
			case 'a':   cout << "_______________________________________________";
                        cout << "\nVout and Av of Inverting Amplifier\n" << endl;
                        double vcc,vee,vin,rin,rf,Av,vOut;

                        cout <<"Please enter value for Vcc: ";
                        cin >> vcc;

                        cout <<"Please enter value for Vee: ";
                        cin >> vee;

                        cout <<"Please enter value for Vin: ";
                        cin >> vin;

                        do
                        {
                          cout <<"Please enter value for Rin: ";
                          cin >> rin;
                        }
                        while(rin<=0);

                        do
                        {
                          cout <<"Please enter value for Rf: ";
                          cin >> rf;
                        }
                        while(rf<=0);

                        invert(vcc, vee, vin, rin, rf, &Av,&vOut);

                        cout << "\nThe Voltage gain (Av) is: " << Av;
                        cout << "\nThe output voltage (Vout) is: " << vOut<< " volts";

                        fflush(stdin);
						getchar();
						break;

			/**< in case when b is entered by user, get values from user, and call the non-invert function*/
            case 'b':   cout << "_______________________________________________";
                        cout << "\nVout and Av of Non-inverting Amplifier\n" << endl;
                        double nvcc, nvee, nvin, r1, r2, nAv;

                        cout <<"Please enter value for Vcc: ";
                        cin >> nvcc;

                        cout <<"Please enter value for Vee: ";
                        cin >> nvee;

                        cout <<"Please enter value for Vin: ";
                        cin >> nvin;

                        do
                        {
                          cout <<"Please enter value for R1: ";
                          cin >> r1;
                        }
                        while(r1<=0);

                        do
                        {
                          cout <<"Please enter value for R2: ";
                          cin >> r2;
                        }
                        while(r2<=0);

                        noninvert(nvcc, nvee, nvin, r1, r2, &nAv,&vOut);

                        cout << "\nThe Voltage gain (Av) is: " << nAv;
                        cout << "\nThe output voltage (Vout) is: " << vOut<< " volts";

                        fflush(stdin);
						getchar();
						break;

            /**< When q is entered by user, provide salutation and end the program*/
			case 'q':   cout << "_______________________________________________";
                        cout << "\nThanks for using the program, Goodbye...\n" << endl;
                        cout << "Press any key to close window"<< endl;
                        fflush(stdin);
                        break;
            /**< When unknown value is entered by user, display the error and display menu again after a key is pressed */
			default:	cout << "\nInvalid input, try again...\n" << endl;
						/**< wait for key to be pressed */
						cout << "Press any key to continue..." << endl;
						fflush(stdin);
						getchar();
						break;
		}
	}
	while (input != 'q');/**< Keep looping until q is not entered by the user, the menu will simply be displayed unless terminated */

	return 0;
}
