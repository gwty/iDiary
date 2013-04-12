/**
Author:Gowtham Ashok
E-mail: gwty93@gmail.com
Program:iDiary
Platform: Turbo C++ 16-bit Windows
Note:
go to options-compiler-code generation and select large memory model
to run this code
*/



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>   //gotoxy(),kbhit()
#include<fstream.h>
#include<time.h>
#include<ctype.h>

/* Declaring the menu function for use by submenus */
void menu();

/* Initializing times to hop from submenus to menus */
int times=0;

/* Tries before program is locked[Login Screen] */
int tries=3;

/* Adjust delay according to CPU Speed for Stars */
double delay1=13000;

/* Adjust delay according to CPU Speed for Introduction Border*/
long rotate=100000;

/* Converter Submenu Declaration*/
void converter();

/*Delay Function */

void delay(double i)
{
    long j,k;
    for(k=0; k<i; k++)
    {
        j=i+1993;   //Random operation for creating delay
        if(kbhit())
            break;
    }
}
void dec()
{
    gotoxy(0,0);    //defined in conio.h
    for(int i=0; i<40; i++)
    {
        cout<<"* ";
    }
    for(i=1; i<25; i++)
    {
        gotoxy(80,i)  ;
        cout<<"*";
    }
    for(i=80; i>0; i-=2)
    {
        gotoxy(i,24) ;
        cout<<"*";
    }
    for(i=24; i>0; i--)
    {
        gotoxy(0,i);
        cout<<"*";
    }
}

/*Stars around the Text */

void stars(char s[30])
{
    int x,y,c;
    x=35;
    y=3;
    c=strlen(s);
    gotoxy(x,y);
    puts(s);
    gotoxy(x-1,y-1);
    for(int ppp=0; ppp<=c+1; ppp++)
        cout<<"*";
    gotoxy(x+c,y);
    cout<<"*";
    for(ppp=1; ppp<=c+2; ppp++)
    {
        gotoxy(((x+c+1)-ppp),y+1);
        cout<<"*";
    }
    gotoxy(x-1,y);
    cout<<"*";
}

/*Temperature converter */

void tempconv()
{
    dec();
    int unit1,unit2;
    float inp,outp;
    stars("Temperature Converter");
    gotoxy(28,10);
    if(times>0)
    {
        cout<<"Do you want to go to Converter menu (y/n)?";
        char got=getch();
        if(got=='y' || got=='Y')
        {
            clrscr();
            converter();
        }
    }
    times++;
    gotoxy(32,7);
    cout<<" 1 . Celsius \n"<<endl;
    gotoxy(32,9);
    cout<<" 2 . Fahrenheit"<<endl;
    gotoxy(32,11);
    cout<<"Enter FROM unit"<<endl;
    gotoxy(32,12);
    cin>>unit1;
    gotoxy(32,14);
    cout<<"Enter TO unit"<<endl;
    gotoxy(32,15);
    cin>>unit2;
    switch(unit1)
    {
    case 1:
        gotoxy(32,17);
        cout<<"Enter the celsius \n";
        gotoxy(32,18);
        cin>>inp;
        gotoxy(32,20);
        switch(unit2)
        {
        case 1 :
            cout<<inp<<" celsius = "<<inp<<" celsius ";
            getch();
            clrscr();
            tempconv();
            break;
        case 2 :
            gotoxy(32,20);
            cout<<inp<<" celsius = "<<(9*(inp/5)+32)<<" fahrenheit ";
            getch();
            clrscr();
            tempconv();
            break;
        default :
            cout<<"invalid option ";
        }
        break;
    case 2:
        gotoxy(32,20);
        cout<<"Enter the fahrenheit \n";
        gotoxy(32,21);
        cin>>inp;
        switch(unit2)
        {
        case 2 :
            gotoxy(32,20);
            cout<<inp<<" fahrenheit ="<<inp<<" fahrenheit ";
            getch();
            clrscr();
            tempconv();
            break;
        case 1 :
            gotoxy(32,20);
            cout<<inp<<" fahrenheit = "<<(inp-32)*0.55<<" celsius ";
            getch();
            clrscr();
            tempconv();
            break;
        default :
            gotoxy(32,20);
            cout<<"invalid option ";
            getch();
            clrscr();
            tempconv();
        }
        break;
    default :
        cout<<"invalid option "   ;
        getch();
        tempconv();
    }
}

/*Area Converter */

void areaconv()
{
    dec();
    gotoxy(17,6);
    gotoxy(32,5);
    if(times>0)
    {
        gotoxy(28,10);
        cout<<"Do you want to go to Converter menu (y/n)?";
        char got=getch();
        if(got=='y' || got=='Y')
        {
            clrscr();
            converter();
        }
    }
    times++;
    int unit1,unit2;
    float inp,outp;
    gotoxy(37,3);
    stars("Area Converter");
    gotoxy(32,10);
    cout<<" 1 . sqcm (cm^2)"<<endl;
    gotoxy(32,11);
    cout<<" 2 . sqmetre(m^2)"<<endl;
    gotoxy(32,12);
    cout<<" 3 . sqfoot "<<endl;
    gotoxy(32,13);
    cout<<" 4 . sqyard "<<endl;
    gotoxy(32,15);
    cout<<"Convert FROM";
    gotoxy(32,16);
    cin>>unit1;
    gotoxy(32,17);
    cout<<"Convert TO";
    gotoxy(32,18);
    cin>>unit2;
    switch(unit1)
    {
    case 1:
        gotoxy(32,20);
        cout<<"Enter the sqcm \n";
        gotoxy(32,21);
        cin>>inp;
        switch(unit2)
        {
        case 1 :
            gotoxy(32,23);
            cout<<inp<<" sqcm = "<<inp<<" sqcm ";
            getch();
            clrscr();
            areaconv();
            break;
        case 2 :
            gotoxy(32,23);
            cout<<inp<<" sqcm = "<<inp/10000<<" sqm ";
            getch();
            clrscr();
            areaconv();
            break;
        case 3 :
            gotoxy(32,23);
            cout<<inp<<" sqcm = "<<inp*0.00107<<" sqfoot ";
            getch();
            clrscr();
            areaconv();
            break;
        case 4 :
            gotoxy(32,23);
            cout<<inp<<" sqcm = "<<inp*0.000119<<" sqyard ";
            getch();
            clrscr();
            areaconv();
            break;
        default :
            cout<<"invalid option ";
            getch();
            clrscr();
            areaconv();
        }
        break;
    case 2:
        gotoxy(32,20);
        cout<<"Enter the sqm \n";
        gotoxy(32,21);
        cin>>inp;
        switch(unit2)
        {
        case 1 :
            gotoxy(32,23);
            cout<<inp<<" sqm = "<<inp<<" sqm "<<endl;
            getch();
            clrscr();
            areaconv();
            break;
        case 2 :
            gotoxy(32,23);
            cout<<inp<<" sqm = "<<inp/0.0001<<" sqcm "<<endl;
            getch();
            clrscr();
            areaconv();
            break;
        case 3 :
            gotoxy(32,23);
            cout<<inp<<" sqm = "<<inp*0.1763<<" sqfoot "<<endl;
            getch();
            clrscr();
            areaconv();
            break;
        case 4 :
            gotoxy(32,23);
            cout<<inp<<" sqm = "<<inp*0.0011954<<" sqyard "<<endl;
            getch();
            clrscr();
            areaconv();
            break;
        default :
            gotoxy(32,23);
            cout<<"invalid option ";
            getch();
            clrscr();
            areaconv();
        }
        break;
    case 3:
        gotoxy(32,20);
        cout<<"Enter the sqfoot \n";
        gotoxy(32,21);
        cin>>inp;
        switch(unit2)
        {
        case 1 :
            gotoxy(32,23);
            cout<<inp<<" sqfoot = "<<inp<<" sqfoot ";
            getch();
            clrscr();
            areaconv();
            break;
        case 2 :
            gotoxy(32,23);
            cout<<inp<<" sqfoot = "<<inp*0.9290<<" sqm ";
            getch();
            clrscr();
            areaconv();
            break;
        case 3 :
            gotoxy(32,23);
            cout<<inp<<" sqfoot = "<<inp*929.03<<" sqcm ";
            getch();
            clrscr();
            areaconv();
            break;
        case 4 :
            gotoxy(32,23);
            cout<<inp<<" sqfoot = "<<inp*0.111<<" sqyard ";
            getch();
            clrscr();
            areaconv();
            break;
        default :
            gotoxy(32,23);
            cout<<"invalid option ";
            getch();
            clrscr();
            areaconv();
        }
        break;
case4:
        gotoxy(32,20);
        cout<<"Enter the sqyard \n";
        gotoxy(32,21);
        cin>>inp;
        switch(unit2)
        {
        case 1 :
            gotoxy(32,23);
            cout<<inp<<" sqyard = "<<inp<<" sqyard ";
            getch();
            clrscr();
            areaconv();
            break;
        case 2 :
            gotoxy(32,23);
            cout<<inp<<" sqyard = "<<inp*0.8361<<" sqm ";
            getch();
            clrscr();
            areaconv();
            break;
        case 3 :
            gotoxy(32,23);
            cout<<inp<<" sqyard = "<<inp*8631.273<<" sqcm ";
            getch();
            clrscr();
            areaconv();
            break;
        case 4 :
            gotoxy(32,23);
            cout<<inp<<" sqyard = "<<inp*9<<" sqfoot ";
            getch();
            clrscr();
            areaconv();
            break;
        default :
            gotoxy(32,23);
            cout<<"invalid option ";
            getch();
            clrscr();
            areaconv();
        }
        break;
    default :
        gotoxy(32,23);
        cout<<"invalid option ";
    }
    getch();
    clrscr();
    areaconv();
}

/*Weight Converter */

void weightconv()
{
    dec();
    int unit1,unit2;
    gotoxy(17,8);
    gotoxy(32,5);
    if(times>0)
    {
        gotoxy(28,10);
        cout<<"Do you want to go to Converter menu (y/n)?";
        char got=getch();
        if(got=='y' || got=='Y')
        {
            clrscr();
            converter();
        }
    }
    times++;
    float inp,outp;
    stars("Weight Converter");
    gotoxy(32,9);

    cout<<" 1.grams\n"<<endl;
    gotoxy(32,10);
    cout<<" 2.kilograms\n"<<endl;
    gotoxy(32,11);
    cout<<" 3.tonne\n"<<endl;
    gotoxy(32,14);
    cout<<" Convert From"<<endl;
    gotoxy(32,15);
    cin>>unit1;
    gotoxy(32,16);
    cout<<" Convert To "<<endl;
    gotoxy(32,17);
    cin>>unit2;
    gotoxy(32,18);
    switch(unit1)
    {
    case 1:
    {
        gotoxy(32,19);
        cout<<"Enter the grams\n";
        gotoxy(32,20);
        cin>>inp;
        switch(unit2)
        {
        case 1 :
            gotoxy(32,22);
            cout<<inp<<" grams = "<<inp<<" grams ";
            getch();
            clrscr();
            weightconv();
            break;
        case 2 :
            gotoxy(32,22);
            cout<<inp<<" grams = "<<inp*0.001<<" kilograms ";
            getch();
            clrscr();
            weightconv();
            break;
        case 3 :
            gotoxy(32,22);
            cout<<inp<<" grams = "<<inp*.000001<<" tonne ";
            getch();
            clrscr();
            weightconv();
            break;
        default :
            gotoxy(32,22);
            cout<<"invalid option ";
            getch();
            clrscr();
            weightconv();
        }
    }
    break;
    case 2:
    {
        gotoxy(32,19);
        cout<<"Enter the kilograms\n";
        gotoxy(32,20);
        cin>>inp;
        switch(unit2)
        {
        case 1:
            gotoxy(32,22);
            cout<<inp<<" kilograms = "<<inp<<" kilograms "<<endl;
            getch();
            clrscr();
            weightconv();
            break;
        case 2:
            gotoxy(32,22);
            cout<<inp<<" kilograms = "<<inp*1000<<" grams "<<endl;
            getch();
            clrscr();
            weightconv();
            break;
        case 3:
            gotoxy(32,22);
            cout<<inp<<" kilograms = "<<inp*0.000984<<" tonne "<<endl;
            getch();
            clrscr();
            weightconv();
            break;
        default :
            gotoxy(32,22);
            cout<<"invalid option ";
            getch();
            clrscr();
            weightconv();
        }
        break;
    }
    case 3:
        gotoxy(32,19);
        cout<<"Enter the tonne\n";
        gotoxy(32,20);
        cin>>inp;
        switch(unit2)
        {
        case 1:
            gotoxy(32,22);
            cout<<inp<<" tonne = "<<inp<<" tonne "<<endl;
            getch();
            clrscr();
            weightconv();
            break;
        case 2:
            gotoxy(32,22);
            cout<<inp<<" tonne = "<<inp*1000<<" kilogram "<<endl;
            getch();
            clrscr();
            weightconv();
            break;
        case 3:
            gotoxy(32,22);
            cout<<inp<<" tonne = "<<inp*1000000<<" grams "<<endl;
            getch();
            clrscr();
            weightconv();
            break;
        default :
            gotoxy(32,22);
            cout<<"invalid option ";
            getch();
            clrscr();
            weightconv();
        }
        break;
    default :
        gotoxy(32,22);
        cout<<"invalid option ";
        getch();
        clrscr();
        weightconv();
    }
}

/*Length Converter*/

void lengthconv()
{
    dec();
    gotoxy(17,8);
    gotoxy(32,5);
    if(times>0)
    {
        gotoxy(28,10);
        cout<<"Do you want to go to Converter menu (y/n)?";
        char got=getch();
        if(got=='y' || got=='Y')
        {
            clrscr();
            converter();
        }
    }
    times++;
    int unit1,unit2 ;
    float inp,outp;
    stars("Length Converter");
    gotoxy(32,9);

    cout<<"1. metre\n\n";
    gotoxy(32,10);
    cout<<"2. inch \n\n";
    gotoxy(32,11);
    cout<<"3. foot \n\n";
    gotoxy(32,12);
    cout<<"4. mile \n\n"<<endl;
    gotoxy(32,16);
    cout<<"Enter FROM unit ";
    gotoxy(32,17);
    cin>>unit1;
    gotoxy(32,18);
    cout<<"Enter TO unit ";
    gotoxy(32,19);
    cin>>unit2;
    switch(unit1)
    {
    case 1 :
    {
        gotoxy(32,20);
        cout<<"Enter the metres \n";
        gotoxy(32,21);
        cin>>inp;
        switch(unit2)
        {
        case 1 :
            gotoxy(32,23);
            cout<<inp<<" metres = "<<inp<<" metres ";
            getch();
            clrscr();
            lengthconv();
            break;
        case 2 :
            gotoxy(32,23);
            cout<<inp<<" metres = "<<inp*39.73<<" inches\n";
            getch();
            clrscr();
            lengthconv();
            break;
        case 3 :
            gotoxy(32,23);
            cout<<inp<<" metres = "<<inp*3.3108<<" foot\n";
            getch();
            clrscr();
            lengthconv();
            break;
        case 4 :
            gotoxy(32,23);
            cout<<inp<<" metres = "<<inp*0.006214<<" miles\n";
            getch();
            clrscr();
            lengthconv();
            break;
        default :
            gotoxy(32,23);
            cout<<"invalid option ";
            getch();
            clrscr();
            lengthconv();
        }
        break;
    }
    case 2 :
    {
        gotoxy(32,20);
        cout<<"Enter the inches \n";
        gotoxy(32,21);
        cin>>inp;
        switch(unit2)
        {
        case 1 :
            gotoxy(32,23);
            cout<<inp<<" inches = "<<inp*0.0251<<" metres ";
            getch();
            clrscr();
            lengthconv();
            break;
        case 2 :
            gotoxy(32,23);
            cout<<inp<<" inches = "<<inp<<" inches ";
            getch();
            clrscr();
            lengthconv();
            break;
        case 3 :
            gotoxy(32,23);
            cout<<inp<<" inches = "<<inp/12.0<<" foot ";
            getch();
            clrscr();
            lengthconv();
            break;
        case 4 :
            gotoxy(32,23);
            cout<<inp<<" inches = "<<inp*0.006214*.0251<<" miles";
            getch();
            clrscr();
            lengthconv();
        default :
            gotoxy(32,23);
            cout<<"invalid option ";
            getch();
            clrscr();
            lengthconv();
        }
        break;
    }
    case 3 :
    {
        gotoxy(32,20);
        cout<<"Enter the feet \n";
        gotoxy(32,21);
        cin>>inp ;
        switch(unit2)
        {
        case 1 :
            gotoxy(32,23);
            cout<<inp<<" foot ="<<inp*0.3020<<" metres \n";
            getch();
            clrscr();
            lengthconv();
            break;
        case 2 :
            gotoxy(32,23);
            cout<<inp<<" foot ="<<inp*12<<" inches"<<endl;
            getch();
            clrscr();
            lengthconv();
            break;
        case 3 :
            gotoxy(32,23);
            cout<<inp<<" foot ="<<inp<<" foot"<<endl;
            getch();
            clrscr();
            lengthconv();
            break;
        case 4 :
            gotoxy(32,23);
            cout<<inp<<" foot ="<<inp* 0.000189393<<" miles"<<endl;
            getch();
            clrscr();
            lengthconv();
            break;
        default :
            gotoxy(32,23);
            cout<<"invalid option ";
            getch();
            clrscr();
            lengthconv();
        }
        break;
    }
    case 4 :
    {
        gotoxy(32,20);
        cout<<"Enter the miles \n";
        gotoxy(32,21);
        cin>>inp ;
        switch(unit2)
        {
        case 1 :
            gotoxy(32,23);
            cout<<inp<<" miles ="<<inp*1609.344 <<" metres \n";
            getch();
            clrscr();
            lengthconv();
            break;
        case 2 :
            gotoxy(32,23);
            cout<<inp<<" miles ="<<(inp*63360) <<" inches"<<endl;
            getch();
            clrscr();
            lengthconv();
            break;
        case 3 :
            gotoxy(32,23);
            cout<<inp<<" miles ="<<inp*5280 <<" feet"<<endl;
            getch();
            clrscr();
            lengthconv();
            break;
        case 4 :
            gotoxy(32,23);
            cout<<inp<<" miles ="<<inp<<" miles"<<endl;
            getch();
            clrscr();
            lengthconv();
            break;
        default :
            gotoxy(32,23);
            cout<<"invalid option ";
            getch();
            clrscr();
            lengthconv();
        }
        break;
    }
    default :
        gotoxy(32,23);
        cout<<"invalid option ";
        getch();
        clrscr();
        lengthconv();
    }
}

/*Volume Converter */

void volumeconv()
{
    dec();
    gotoxy(32,5);
    if(times>0)
    {
        gotoxy(28,10);
        cout<<"Do you want to go to Converter menu (y/n)?";
        char got=getch();
        if(got=='y' || got=='Y')
        {
            clrscr();
            converter();
        }
    }
    times++;
    int unit1,unit2 ;
    float inp,outp;
    stars("Volume Converter");
    gotoxy(32,9);
    cout<<"1. cubic metre(m)\n\n";
    gotoxy(32,10);
    cout<<"2. gallon(US) \n\n";
    gotoxy(32,11);
    cout<<"3. litre \n\n";
    gotoxy(32,14);
    cout<<"Convert FROM \n";
    gotoxy(32,15);
    cin>>unit1;
    gotoxy(32,16);
    cout<<"Convert TO\n";
    gotoxy(32,17);
    cin>>unit2;
    switch(unit1)
    {
    case 1 :
    {
        gotoxy(32,18);
        cout<<"Enter the cubic metre \n";
        gotoxy(32,19);
        cin>>inp ;
        switch(unit2)
        {
        case 1 :
            gotoxy(32,20);
            cout<<inp<<" cubic metre = "<<inp<<" cubic metre \n";
            getch();
            clrscr();
            volumeconv();
            break;
        case 2 :
            gotoxy(32,20);
            cout<<inp<<" cubic metre= "<<inp*264.17<<" gallon(US) "<<endl;
            getch();
            clrscr();
            volumeconv();
            break;
        case 3 :
            gotoxy(32,20);
            cout<<inp<<" cubic metre = "<<inp*1000 <<" litre"<<endl;
            getch();
            clrscr();
            volumeconv();
            break;
        default :
            gotoxy(32,20);
            cout<<"invalid option "   ;
            getch();
            clrscr();
            volumeconv();
        }
        break;
    }
    case 2 :
    {
        gotoxy(32,18);
        cout<<"Enter the gallons(US) \n";
        gotoxy(32,19);
        cin>>inp ;
        switch(unit2)
        {
        case 1 :
            gotoxy(32,20);
            cout<<inp<<" gallon(US) ="<<inp*0.003785411 <<" cubic metre \n";
            getch();
            clrscr();
            volumeconv();
            break;
        case 2 :
            gotoxy(32,20);
            cout<<inp<<" gallon(US) ="<<inp<<" gallon(US) "<<endl;
            getch();
            clrscr();
            volumeconv();
            break;
        case 3 :
            gotoxy(32,20);
            cout<<inp<<" gallon(US) ="<<inp*3.7854<<" litre"<<endl;
            getch();
            clrscr();
            volumeconv();
            break;
        default :
            gotoxy(32,20);
            cout<<"invalid option "   ;
            getch();
            clrscr();
            volumeconv();
        }
        break;
    }
    case 3 :
    {
        gotoxy(32,18);
        cout<<"Enter the litres \n";
        gotoxy(32,19);
        cin>>inp ;
        switch(unit2)
        {
        case 1 :
            gotoxy(32,20);
            cout<<inp<<" litres ="<<inp*0.001<<" cubic metre \n";
            getch();
            clrscr();
            volumeconv();
            break;
        case 2 :
            gotoxy(32,20);
            cout<<inp<<" litres ="<<inp*0.264172<<" gallon(US) "<<endl;
            getch();
            clrscr();
            volumeconv();
            break;
        case 3 :
            gotoxy(32,20);
            cout<<inp<<" litres ="<<inp<<" litre"<<endl;
            getch();
            clrscr();
            volumeconv();
            break;
        default :
            gotoxy(32,20);
            cout<<"invalid option "  ;
            getch();
            clrscr();
            volumeconv();
        }
        break;
    }
    default :
        gotoxy(32,20);
        cout<<"invalid option " ;
        getch();
        clrscr();
        volumeconv();
    }
}

/*Currency Converter */

void currencyconv()
{
    dec();
    gotoxy(32,5);
    if(times>0)
    {
        gotoxy(28,10);
        cout<<"Do you want to go to Converter menu (y/n)?";
        char got=getch();
        if(got=='y' || got=='Y')
        {
            clrscr();
            converter();
        }
    }
    times++;
    int unit1,unit2 ;
    float inp,outp;
    stars("Currency Converter");
    gotoxy(32,9);
    cout<<"1. Bahraini Dinar\n\n";
    gotoxy(32,10);
    cout<<"2. Indian Rupee \n\n";
    gotoxy(32,11);
    cout<<"3. Euro \n\n";
    gotoxy(32,12);
    cout<<"4. US Dollars \n\n"<<endl;
    gotoxy(32,15);
    cout<<"Convert FROM";
    gotoxy(32,16);
    cin>>unit1;
    gotoxy(32,17);
    cout<<"Convert TO";
    gotoxy(32,18);
    cin>>unit2;
    switch(unit1)
    {
    case 1 :
    {
        gotoxy(32,19);
        cout<<"Enter the Bahraini Dinars \n";
        gotoxy(32,20);
        cin>>inp;
        switch(unit2)
        {
        case 1 :
            cout<<inp<<" Bahraini Dinars = "<<inp<<" Bahraini Dinars ";
            getch();
            clrscr();
            currencyconv();
            break;
        case 2 :
            cout<<inp<<" Bahraini Dinars = "<<inp*117.687<<" Indian Rupee \n";
            getch();
            clrscr();
            currencyconv();
            break;
        case 3 :
            cout<<inp<<" Bahraini Dinars = "<<inp*1.898<<" Euro\n";
            getch();
            clrscr();
            currencyconv();
            break;
        case 4 :
            cout<<inp<<" Bahraini Dinars = "<<inp*2.652<<" US Dollars\n";
            getch();
            clrscr();
            currencyconv();
            break;
        default :
            cout<<"invalid option "   ;
            getch();
            clrscr();
            currencyconv();
        }
        break;
    }
    case 2 :
    {
        gotoxy(32,19);
        cout<<"Enter the Indian Rupees \n";
        gotoxy(32,20);
        cin>>inp;
        switch(unit2)
        {
        case 1 :
            cout<<inp<<" Indian Rupee  = "<<inp*0.0085<<" Bahraini Dinars  ";
            getch();
            clrscr();
            currencyconv();
            break;
        case 2 :
            cout<<inp<<" Indian Rupee  = "<<inp<<" Indian Rupee ";
            getch();
            clrscr();
            currencyconv();
            break;
        case 3 :
            cout<<inp<<" Indian Rupee  = "<<inp*0.01614<<" Euro ";
            getch();
            clrscr();
            currencyconv();
            break;
        case 4 :
            cout<<inp<<" Indian Rupee  = "<<inp*0.0225<<" US Dollars";
            getch();
            clrscr();
            currencyconv();
        default :
            cout<<"invalid option "   ;
            getch();
            clrscr();
            currencyconv();
        }
        break;
    }
    case 3 :
    {
        gotoxy(32,19);
        cout<<"Enter the Euros \n";
        gotoxy(32,20);
        cin>>inp ;
        switch(unit2)
        {
        case 1 :
            cout<<inp<<" Euro  ="<<inp*0.526<<" Bahraini Dinars \n";
            getch();
            clrscr();
            currencyconv();
            break;
        case 2 :
            cout<<inp<<" Euro ="<<inp*61.95<<" Indian Rupee "<<endl;
            getch();
            clrscr();
            currencyconv();
            break;
        case 3 :
            cout<<inp<<" Euro ="<<inp<<" Euro"<<endl;
            getch();
            clrscr();
            currencyconv();
            break;
        case 4 :
            cout<<inp<<" Euro ="<<inp* 1.39<<" US Dollars "<<endl;
            getch();
            clrscr();
            currencyconv();
            break;
        default :
            cout<<"invalid option "   ;
            getch();
            clrscr();
            currencyconv();
        }
        break;
    }
    case 4 :
    {
        gotoxy(32,19);
        cout<<"Enter the US Dollars \n";
        gotoxy(32,20);
        cin>>inp ;
        switch(unit2)
        {
        case 1 :
            cout<<inp<<" US Dollars ="<<inp*0.377 <<" Bahraini Dinars \n";
            getch();
            clrscr();
            currencyconv();
            break;
        case 2 :
            cout<<inp<<" US Dollars ="<<inp*44.350 <<" Indian Rupee "<<endl;
            getch();
            clrscr();
            currencyconv();
            break;
        case 3 :
            cout<<inp<<" US Dollars ="<<inp*0.715 <<" Euro "<<endl;
            getch();
            clrscr();
            currencyconv();
            break;
        case 4 :
            cout<<inp<<" US Dollars ="<<inp<<" US Dollars "<<endl;
            getch();
            clrscr();
            currencyconv();
            break;
        default :
            cout<<"invalid option "   ;
            getch();
            clrscr();
            currencyconv();
        }
        break;
        default :
            cout<<"invalid option "   ;
            getch();
            clrscr();
            currencyconv();
        }
    }
}

/*Converter Title */

void converter()
{
startconvertermenu:
    dec();
    stars("Converter");
    int opt;
    gotoxy(32,7);
    cout<<"1. Length Converter ";
    gotoxy(32,9);
    cout<<"2. Area Converter"   ;
    gotoxy(32,11);
    cout<<"3. Volume Converter ";
    gotoxy(32,13);
    cout<<"4. Temperature Converter";
    gotoxy(32,15);
    cout<<"5. Currency Converter ";
    gotoxy(32,17);
    cout<<"6. Weight Converter ";
    gotoxy(32,19);
    cout<<"7. Main Menu ";
    times=0;
    opt=getch();
    clrscr();
    switch(opt)
    {
    case '1' :
        lengthconv();
        break;
    case '2' :
        areaconv();
        break;
    case '3' :
        volumeconv();
        break;
    case '4' :
        tempconv();
        break;
    case '5' :
        currencyconv();
        break;
    case '6' :
        weightconv();
        break;
    case '7' :
        menu();
    default :
    {
        cout<<"invalid option "   ;
        goto startconvertermenu;
    }
    }
}

/*Calendar */

int IsLeapYear(int Year)
{
    if (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0))
        return 1;
    return 0;
}
int DaysPassedFromYear(int firstYear, int month,int year)
{
    int days;
    int daysPassed[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273,
                         304, 334
                       };
//per month per year
    const int dayOffset = 5;
    //The first day of our start year may not be a Sunday ( in 1800 it was Wednesday)
    const int firstLeapYear = 1804;
    //help to reduce how many leap years we have to check
    int count;
    //calculates basic number of days passed
    days = (year - firstYear) * 365;
    days += dayOffset;
    days += daysPassed[month-1];
    //add on the extra leapdays for past years
    for (count = firstLeapYear; count < year ; count +=4)
    {
        if (IsLeapYear(count) )
        {
            days++;
        }
    }
    //add leapday for this year if requested  month is greater than  Feb
    if( month > 2 && IsLeapYear(year) )
    {
        days++;
    }
    return days;
}
int GetNumberOfDaysInMonth(int Month,int Year)
{
    int NumberOfDaysInMonth;
    cout<<"\n";
    switch (Month)
    {
    case 1:
        gotoxy(35,7);
        cout<<"January "<<Year<<endl;
        NumberOfDaysInMonth = 31;
        break;
    case 2:
        gotoxy(35,7);
        cout<<"February "<<Year<<endl;
        if(IsLeapYear(Year))
            NumberOfDaysInMonth = 29;
        else
            NumberOfDaysInMonth = 28;
        break;
    case 3:
        gotoxy(35,7);
        cout<<"March "<<Year<<endl;
        NumberOfDaysInMonth = 31;
        break;
    case 4:
        gotoxy(35,7);
        cout<<"April "<<Year<<endl;
        NumberOfDaysInMonth = 30;
        break;
    case 5:
        gotoxy(35,7);
        cout<<"May "<<Year<<endl;
        NumberOfDaysInMonth = 31;
        break;
    case 6:
        gotoxy(35,7);
        cout<<"June "<<Year<<endl;
        NumberOfDaysInMonth = 30;
        break;
    case 7:
        gotoxy(35,7);
        cout<<"July "<<Year<<endl;
        NumberOfDaysInMonth = 31;
        break;
    case 8:
        gotoxy(35,7);
        cout<<"August "<<Year<<endl;
        NumberOfDaysInMonth = 31;
        break;
    case 9:
        gotoxy(35,7);
        cout<<"September "<<Year<<endl;
        NumberOfDaysInMonth = 30;
        break;
    case 10:
        gotoxy(35,7);
        cout<<"October "<<Year<<endl;
        NumberOfDaysInMonth = 31;
        break;
    case 11:
        gotoxy(35,7);
        cout<<"November "<<Year<<endl;
        NumberOfDaysInMonth = 30;
        break;
    case 12:
        gotoxy(35,7);
        cout<<"December "<<Year<<endl;
        NumberOfDaysInMonth = 31;
        break;
    }
    gotoxy(24,8);
    cout<<"__________________________________________";
    gotoxy(24,9);
    cout<<"Sun   Mon   Tue   Wed   Thu   Fri   Sat";
    return NumberOfDaysInMonth;
}
void calendar()
{
startcalendar:
    char opt;
    clrscr();
    dec();
    stars("Calendar");
    gotoxy(29,8);
    cout<<"1.Enter 1 for full year calendar"<<endl;
    gotoxy(29,9);
    cout<<"2.Enter 2 for one month calendar"<<endl;
    gotoxy(29,10);
    cout<<"3.Enter e to exit"<<endl;
    dec();
    gotoxy(33,12);
    cin>>opt;
    if(opt=='1')
    {
        dec();
        int year;
        gotoxy(33,13);
        cout<<"Enter the year"<<endl;
        gotoxy(33,14);
        cin>>year;
        clrscr();
        int month;
        for(month=1; month<=12; month++)
        {
            dec();
            const int firstYear = 1800; //This is our start point
            int NumDaysInMonth=GetNumberOfDaysInMonth(month,year);
            int firstDayOfMonth = DaysPassedFromYear(firstYear,month,year) %7;
            //0-Sunday 1-Monday
            firstDayOfMonth++;//ofsetting so that 1-Sunday,2-monday etc
            int i=1;
            gotoxy(22,10);
            for(i=1; i<firstDayOfMonth; i++)
            {
                cout<<"      ";
                if(i%7 == 0)
                {
                    gotoxy(22,10+(i/7));
                }
            }
            for(i=firstDayOfMonth; i<NumDaysInMonth+firstDayOfMonth; i++)
            {
                if((i-firstDayOfMonth) < 9)
                {
                    cout<<"   "<<(i-firstDayOfMonth+1)<<"  ";
                }
                else
                {
                    cout<<"   "<<(i-firstDayOfMonth+1)<<" ";
                }
                if(i%7 == 0)
                    gotoxy(22,10+(i/7));
            }
            clreol();
            getch();
            clrscr();
        }
        goto startcalendar;
    }
    else if(opt=='2')
    {
        dec();
        int year;
        gotoxy(33,13);
        cout<<"Enter the year";
        gotoxy(33,14);
        cin>>year;
        int month=0;
        gotoxy(33,15);
        cout<<"Enter the month";
        gotoxy(33,16);
        cin>>month;
        const int firstYear = 1800;
        //This is our start point
        int NumDaysInMonth=GetNumberOfDaysInMonth(month,year);
        int firstDayOfMonth = DaysPassedFromYear(firstYear,month,year)%7;
        //0-Sunday 1-Monday
        firstDayOfMonth++;//ofsetting so that 1-Sunday,2-monday etc
        int i=1;
        gotoxy(22,10);
        for(i=1; i<firstDayOfMonth; i++)
        {
            cout<<"      ";
            if(i%7 == 0)
            {
                gotoxy(22,10+(i/7));
            }
        }
        for(i=firstDayOfMonth; i<NumDaysInMonth+firstDayOfMonth; i++)
        {
            if((i-firstDayOfMonth) < 9)
            {
                cout<<"   "<<(i-firstDayOfMonth+1)<<"  ";
            }
            else
            {
                cout<<"   "<<(i-firstDayOfMonth+1)<<" ";
            }
            if(i%7 == 0)
                gotoxy(22,10+(i/7));
        }
        clreol();
        getch();
        clrscr();
        goto startcalendar;
    }
    else if(opt=='E' || opt=='e')
    {
        clrscr();
        menu();
    }
    else
    {
        gotoxy(33,13);
        cout<<"Invalid Option. Try Again"<<endl;
        gotoxy(33,14);
        getch();
        clrscr();
        goto startcalendar;
    }
}

/*Reminder */

class reminder
{
    int op;
    char str1[20],str2[20];
public:
    struct date
    {
        int d1,m1,y1;
        void input();
        void output();
    } date1,date2;
    char r,a;
    reminder()
    {
        op=0;
        strcpy(str1, "");
        strcpy(str2, "");
        date1.d1=0;
        date1.m1=0;
        date1.y1=0;
        date2.d1=0;
        date2.m1=0;
        date2.y1=0;
        r='n';
        a='y';
    }
    int d,m,y;
    void input();
    void output();
};
void reminder::input()
{
    clrscr();
    dec();
    int optionl;
    fstream file1;
    while(1==1)
    {
        file1.open("remind.dat",ios::app|ios::out|ios::binary|ios::in);
//add start point
        dec();
//reminder *
        stars("Reminder");
        gotoxy(33,8);
        cout<<"1.Meeting";
        gotoxy(33,10);
        cout<<"2.Call";
        gotoxy(33,12);
        cout<<"3.Birthday";
        gotoxy(33,14);
        cout<<"4.Memo";
        gotoxy(33,16);
        cout<<"5.Return to main menu";
        gotoxy(33,18);
        cout<<"Enter your option\t";
        gotoxy(33,19);
        cin>>optionl;
        clrscr();
        switch(optionl)
        {
        case 1:
            op=1;
            clrscr();
            dec();
            gotoxy(10,5);
            cout<<"Enter the subject : ";
            gets(str1);
            gotoxy(10,6);
            cout<<"Enter the location :";
            gets(str2);
            gotoxy(10,7);
            cout<<"Enter the start date DD-MM-YY:";
            gotoxy(10,8);
            cin>>date1.d1;
            gotoxy(10,9);
            cin>>date1.m1;
            gotoxy(10,10);
            cin>>date1.y1;
            gotoxy(10,11);
            cout<<"Enter the end date DD-MM-YY";
            gotoxy(10,12);
            cin>>date2.d1;
            gotoxy(10,13);
            cin>>date2.m1;
            gotoxy(10,14);
            cin>>date2.y1;
            gotoxy(10,15);
            gotoxy(10,16);
            cout<<"Repeat??? never(n) Daily(d) Monthly(m) Yearly(y)";
            gotoxy(10,17);
            r=getch();
            gotoxy(10,18);
            cout<<" alarm???(y/n) : ";
            gotoxy(10,19);
            a=getch();
            reminder::input();
            break;
        case 2:
            op=2;
            clrscr();
            dec();
            gotoxy(10,5);
            cout<<"Enter the Name : ";
            gets(str1);
            gotoxy(10,6);
            cout<<"Enter the Phone number : ";
            gets(str2);
            gotoxy(10,7);
            cout<<"Enter the date DD-MM-YY : ";
            gotoxy(10,8);
            cin>>date1.d1;
            gotoxy(10,9);
            cin>>date1.m1;
            gotoxy(10,10);
            cin>>date1.y1;
            gotoxy(10,11);
            cout<<"Repeat??? never(n) Daily(d) Monthly(m) Yearly(y) : ";
            gotoxy(10,12);
            r=getch();
            gotoxy(10,13);
            cout<<"alarm???(y/n) : ";
            gotoxy(10,14);
            a=getch();
            reminder::input();
            break;
        case 3:
            op=3;
            clrscr();
            dec();
            gotoxy(10,5);
            cout<<"Enter the name : ";
            gets(str1);
            gotoxy(10,6);
            cout<<"Enter the date of birth : ";
            gotoxy(10,7);
            cin>>date1.d1;
            gotoxy(10,8);
            cin>>date1.m1;
            gotoxy(10,9);
            cin>>date1.y1;
            r='y';
            gotoxy(10,10);
            cout<<"alarm(y/n)??? : ";
            gotoxy(10,11);
            a=getch();
            reminder::input();
            break;
        case 4:
            op=4;
            clrscr();

            dec();
            gotoxy(10,5);
            cout<<"Enter the subject : ";
            gets(str1);
            gotoxy(10,6);
            cout<<"Enter the start date DD-MM-YY : ";
            gotoxy(10,7);
            cin>>date1.d1;
            gotoxy(10,8);
            cin>>date1.m1;
            gotoxy(10,9);

            cin>>date1.y1;
            gotoxy(10,10);
            cout<<"Enter the end date DD-MM-YY : ";
            gotoxy(10,11);
            cin>>date2.d1;
            gotoxy(10,12);
            cin>>date2.m1;
            gotoxy(10,13);
            cin>>date2.y1;
            gotoxy(10,14);
            cout<<"Repeat??? never(n) Daily(d) Monthly(m) Yearly(y) : ";
            gotoxy(10,15);
            r=getch();
            gotoxy(10,16);
            cout<<"alarm(y/n)??? :";
            gotoxy(10,17);
            a=getch();
            reminder::input();
            break;
        case 5:
            file1.close();
            menu();
            break;
        default:
            reminder::input();
        }
        file1.write((char*)this,sizeof(reminder));
        file1.close();
        break;
    }
    return;
};
void reminder::output()
{
    clrscr();
    dec();
//reminder *
    stars("reminder");
    int op;
    gotoxy(33,8);
    cout<<"1.Meeting";
    gotoxy(33,10);
    cout<<"2.Call";
    gotoxy(33,12);
    cout<<"3.Birthday";
    gotoxy(33,14);
    cout<<"4.Memo";
    gotoxy(33,16);
    cout<<"5.Return to main menu";
    gotoxy(33,18);
    cout<<"Enter your option\t";
    gotoxy(33,19);
    cin>>op;
    clrscr();
    switch(op)
    {
    case 1 :
        clrscr();
        dec();
        gotoxy(10,5);
        cout<<"Reminder Type : Meeting ";
        gotoxy(10,6);
        cout<<"Subject : ";
        cout<<str1;
        gotoxy(10,7);
        cout<<"Location : ";
        cout<<str2;
        gotoxy(10,8);
        cout<<"Start date DD-MM-YY : ";
        cout<<date1.d1<<"-"<<date1.m1<<"-"<<date1.y1;
        gotoxy(10,10);
        cout<<"End date DD-MM-YY : ";
        cout<<date2.d1<<"-"<<date2.m1<<"-"<<date2.y1;
        gotoxy(10,12);
        cout<<"Repeat";
        cout<<r;
        if (a=='y')
            cout<<"\a";
        getch();
        reminder::output();
        break;
    case 2 :
        clrscr();
        dec();
        gotoxy(10,5);
        cout<<"Reminder Type : Call ";
        gotoxy(10,6);
        cout<<"Name : ";
        cout<<str1;
        gotoxy(10,7);
        cout<<"Phone Number : ";
        cout<<str2;
        gotoxy(10,8);
        cout<<"Date DD-MM-YY : ";
        cout<<date1.d1<<"-"<<date1.m1<<"-"<<date1.y1;
        gotoxy(10,9);
        cout<<"Repeat : ";
        cout<<r;
        if (a=='y')
            cout<<'\a';
        getch();
        reminder::output();
        break;
    case 3:
        clrscr();
        dec();
        gotoxy(10,5);
        cout<<"Reminder Type : Birthday ";
        gotoxy(10,6);
        cout<<"Name : ";
        cout<<str1;
        gotoxy(10,7);
        cout<<"DOB DD-MM-YY : ";
        cout<<date1.d1<<"-"<<date1.m1<<"-"<<date1.y1;
        if (a=='y')
            cout<<'\a';
        getch();
        reminder::output();
        break;
    case 4:
        clrscr();
        dec();
        gotoxy(10,5);
        cout<<"Reminder Type : Memo ";
        gotoxy(10,6);
        cout<<"Subject : ";
        cout<<str1;
        gotoxy(10,7);
        cout<<"Start date DD-MM-YY : ";
        cout<<date1.d1<<"-"<<date1.m1<<"-"<<date1.y1;
        gotoxy(10,8);
        cout<<"End date DD-MM-YY : ";
        cout<<date2.d1<<"-"<<date2.m1<<"-"<<date2.y1;
        gotoxy(10,9);
        cout<<"Repeat : ";
        cout<<r;
        if (a=='y')
            cout<<'\a';
        getch();
        reminder::output();
        break;
    case 5:
        menu();
    default:
        reminder::output();
        break;
    }
}
void output_notes(int d, int m, int y)
{
    fstream file2;
    reminder A;
    file2.open("remind.dat",ios::app|ios::out|ios::binary|ios::in);
    double datec,datep,datel;
    datec=y*10000+m*100+d;
    while(!file2.eof())
    {
        file2.read((char*)&A,sizeof(reminder));
        datep=A.date1.y1*10000+A.date1.m1*100+A.date1.d1;
        datel=A.date2.y1*10000+A.date2.m1*100+A.date2.d1;
        if(A.r=='d')
        {
            if(datel==0)
                A.output();
            else if(datec>=datep&&datec<=datel)
                A.output();
        }

        else if(A.r=='m')
        {
            if(datel==0)
            {
                if(d==A.date1.d1)
                    A.output();
            }
            else if(datec>=datep&&datec<=datel)
                if(d==A.date1.d1)
                    A.output();
        }
        else if(A.r=='y')
        {
            if(datel==0)
            {
                if(d==A.date1.d1 && m==A.date1.m1)
                    A.output();
            }
            else if(datec>=datep&&datec<=datel)
            {
                if(d==A.date1.d1 && m==A.date1.m1)
                    A.output();
            }
        }
        else if(A.r=='n')
        {
            if(d==A.date1.d1 && m==A.date1.m1 && y==A.date1.y1)
                A.output();
        }
    }
    file2.close();
}
void remind_all()
{
    fstream file3;
    reminder A;
    file3.open("remind.dat",ios::app|ios::out|ios::binary|ios::in);
    while(!file3.eof())
    {
        file3.read((char*)&A,sizeof(reminder));
        A.output();
        cout<<endl;
        getch();
    }
    file3.close();
}
/*Fit-o-meter */
int minspent()
{
    int min;
    gotoxy(30,20);
    cout<<"Enter minutes spent"<<endl;
    gotoxy(30,21);
    cin>>min;
    return min;
}
void exercisecalc()
{
starting:
    clrscr();
    dec();
    stars("Fit-o-meter");
    float cal=0,min=0;
    char opt;
    gotoxy(30,6);
    cout<<"Enter exercise performed"<<endl<<endl;
    gotoxy(30,8);
    cout<<"1.Basketball"<<endl;
    gotoxy(30,9);
    cout<<"2.Cycling"<<endl;
    gotoxy(30,10);
    cout<<"3.Dancing(moderate)"<<endl;
    gotoxy(30,11);
    cout<<"4.Football"<<endl;
    gotoxy(30,12);
    cout<<"5.Rope Skipping"<<endl;
    gotoxy(30,13);
    cout<<"6.Walking up stairs"<<endl;
    gotoxy(30,14);
    cout<<"7.Aerobics"<<endl;
    gotoxy(30,15);
    cout<<"8.Swimming (back stroke)"<<endl;
    gotoxy(30,16);
    cout<<"9.Swimming (breast stroke)"<<endl;
    gotoxy(30,17);
    cout<<"q.Tennis (singles)"<<endl;
    gotoxy(30,18);
    cout<<"w.Volleyball"<<endl;
    gotoxy(30,20);
    cin>>opt;
    switch(opt)
    {
    case '1':
        min=minspent();
        cal+=min*7.4;
        gotoxy(30,21);
        cout<<"Do you want to add more to the list?(y/n)";
        if(getch()=='y')
            goto starting;
        break;
    case '2':
        min=minspent();
        cal+=min*4.2;
        gotoxy(30,21);
        cout<<"Do you want to add more to the list?(y/n)";
        if(getch()=='y')
            goto starting;
        break;
    case '3':
        min=minspent();
        cal+=min*9.0;
        gotoxy(30,21);
        cout<<"Do you want to add more to the list?, if yes, type c"<<endl;
        if(getch()=='c')
            goto starting;
        break;
    case '4':
        min=minspent();
        cal+=min*8.4;
        gotoxy(30,21);
        cout<<"Do you want to add more to the list?(y/n)";
        if(getch()=='y')
            goto starting;
        break;
    case '5':
        min=minspent();
        cal+=min*10.1;
        gotoxy(30,21);
        cout<<"Do you want to add more to the list?(y/n)";

        if(getch()=='y')
            goto starting;
        break;
    case '6':
        min=minspent();
        cal+=min*10.4;
        gotoxy(30,21);
        cout<<"Do you want to add more to the list?(y/n)";
        if(getch()=='y')
            goto starting;
        break;
    case '7':
        min=minspent();
        cal+=min*6.0;
        gotoxy(30,21);
        cout<<"Do you want to add more to the list?(y/n)";
        if(getch()=='y')
            goto starting;
        break;
    case '8':
        min=minspent();
        cal+=min*12.4;
        gotoxy(30,21);
        cout<<"Do you want to add more to the list?(y/n)";
        if(getch()=='y')
            goto starting;
        break;
    case '9':
        min=minspent();
        cal+=min*11.4;
        gotoxy(30,21);
        cout<<"Do you want to add more to the list?(y/n)";
        if(getch()=='y')
            goto starting;
        break;
    case 'q':
        min=minspent();
        cal+=min*7.3;
        gotoxy(30,21);
        cout<<"Do you want to add more to the list?(y/n)";
        if(getch()=='y')
            goto starting;
        break;
    case 'w':
        min=minspent();
        cal+=min*3.4;
        gotoxy(30,21);
        cout<<"Do you want to add more to the list?(y/n)";
        if(getch()=='y')
            goto starting;
        break;
    case 'e':
        min=minspent();
        cal+=min*5.5;
        gotoxy(30,21);
        cout<<"Do you want to add more to the list?(y/n)";
        if(getch()=='y')
            goto starting;
        break;
    case 'r':
        min=minspent();
        cal+=min*5.1;
        gotoxy(30,21);
        cout<<"Do you want to add more to the list?(y/n)"<<endl;
        if(getch()=='y')
            goto starting;

        break;
    case 't':
        min=minspent();
        cal+=min*12.4;
        gotoxy(30,21);
        cout<<"Do you want to add more to the list?(y/n)";
        if(getch()=='y')
            goto starting;
        break;
    case 'v':
        menu();
    }
    clrscr();
    dec();
    gotoxy(30,12);
    cout<<"Calories expended:";
    cout<<cal;
    gotoxy(30,14);
    cout<<"Joules expended:";
    cout<<cal*4.186;
    getch();
    clrscr();
    menu();
}
/*Calculator */
void calcdesign()
{
calc:
    stars("Calculator");
    gotoxy(30,8);
    cout<<" _____________________  "<<endl;
    gotoxy(30,9);
    cout<<"|  _________________  | "<<endl;
    gotoxy(30,10);
    cout<<"| |                 | | "<<endl;
    gotoxy(30,11);
    cout<<"| |_________________| | "<<endl;
    gotoxy(30,12);
    cout<<"|  ___ ___ ___   ___  | "<<endl;
    gotoxy(30,13);
    cout<<"| | 7 | 8 | 9 | | + | | "<<endl;
    gotoxy(30,14);
    cout<<"| |___|___|___| |___| | "<<endl;
    gotoxy(30,15);
    cout<<"| | 4 | 5 | 6 | | - | | "<<endl;
    gotoxy(30,16);
    cout<<"| |___|___|___| |___| | "<<endl;
    gotoxy(30,17);
    cout<<"| | 1 | 2 | 3 | | x | | "<<endl;
    gotoxy(30,18);
    cout<<"| |___|___|___| |___| | "<<endl;
    gotoxy(30,19);
    cout<<"| | . | 0 | = | | / | | "<<endl;
    gotoxy(30,20);
    cout<<"| |___|___|___| |___| | "<<endl;
    gotoxy(30,21);
    cout<<"|_____________________| "<<endl;
    gotoxy(60,23);
    cout<<"Press e to exit";
}
void calc()
{
    double x;
    char o,get;
    double f,s,r;
    dec();
start:
    gotoxy(34,10);
    r=0;
    get=0;
    clrscr();
    dec();
    calcdesign();
    gotoxy(34,10);
    cin>>f;
    if(f==97)
    {
        clrscr();
        menu();
    }
    clrscr();
    dec();
    calcdesign();
cont:
    gotoxy(34,10);
    if(f==97)
    {
        clrscr();
        menu();
    }
    if(f==0)
    {
        f=r;
    }
    if(get==0)
    {
        gotoxy(48,10);
        o=getch();
        if(o=='e')
        {
            menu();
        }
        cout<<o;
        gotoxy(34,10);
    }
    gotoxy(34,10);
    cin>>s;
    if(s==97)
        menu();
    switch(o)
    {
    case '+':
        clrscr();
        calcdesign();
        dec();
        gotoxy(34,10);
        r=f+s;
        cout<<r;
        gotoxy(34,10);
        f=0;
        break;
    case '-':
        clrscr();
        calcdesign();
        dec();
        gotoxy(34,10);
        r=f-s;
        cout<<r;
        gotoxy(34,10);
        f=0;
        break;
    case '*':
        clrscr();
        calcdesign();
        dec();
        gotoxy(34,10);
        r=f*s;
        cout<<r;
        gotoxy(34,10);
        f=0;
        break;
    case '/':
        clrscr();
        calcdesign();
        dec();
        gotoxy(34,10);
        r=f/s;
        cout<<r;
        f=0;
        gotoxy(34,10);
        break;
    case 'a':
        menu();
    default:
        clrscr();
        dec();
        gotoxy(34,10);
        cout<<"Invalid operation!";
        getch();
        goto start;
    }
    gotoxy(48,10);
    get=getche();
    o=get;
    gotoxy(34,10);
    if(get!='a')
    {
        gotoxy(34,10);
        goto cont;
    }
    else
    {
        clrscr();
        menu();
    }
}
void calculator()
{
    calc();
}
/*
A simple game
s1,s2,s3.... are simplified names of stocks
opt 1=> buy & opt 2=>sell
*/

/*Display*/
void dec1()
{
    gotoxy(0,0);
    for(int i=0; i<40; i++)
    {
        cout<<"* ";
    }
    for(i=1; i<25; i++)
    {
        gotoxy(80,i)  ;
        cout<<"*";
    }
    for(i=80; i>0; i-=2)
    {
        gotoxy(i,24) ;
        cout<<"*";
    }
    for(i=24; i>0; i--)
    {
        gotoxy(0,i);
        cout<<"*";
    }
}


void s1(int,int);
void s2(int,int);
void s3(int,int);
void s4(int,int);
void s5(int,int);
void s6(int,int);
void s7(int,int);
void s8(int,int);
void s9(int,int);
void s10(int,int);
void cash(double ca)
{
    gotoxy(60,22);
    cout<<"Cash:"<<ca;
}
struct cashcount
{
    long ca;
    long s1amt;
    long s2amt;
    long s3amt;
    long s4amt;
    long s5amt;
    long s6amt;
    long s7amt;
    long s8amt;
    long s9amt;
    long s10amt;
} cas;
void operation(int opt,long no,long price)
{
    if(opt==1)
        cas.ca=cas.ca-(no*price);
    else if(opt==2)
        cas.ca=cas.ca+(no*price);
end:
}


void s1operation()
{
    long no;
    char ch=getch();
    if(ch=='b' || ch=='B')
    {
        if(cas.ca<-100000)
        {
            gotoxy(3,14);
            cout<<"You cannot buy anymore. Please sell stocks"<<endl;
            getch();
            goto end;
        }
        gotoxy(3,14);
        cout<<"Number of stocks you want to buy"<<endl;
        cin>>no;
        s1(1,no);
        cas.s1amt+=no;
end:
        clrscr();
        cash(cas.ca);
    }
    else if(ch=='s' || ch=='S')
    {
        if(cas.s1amt>0)
        {
            gotoxy(3,14);
            cout<<"Number of stocks you want to sell"<<endl;
            cin>>no;
            if(no>cas.s1amt)
            {
                gotoxy(3,14);
                cout<<"You do not have that much stock to sell"<<endl;
                getch();
                no=0;
            }
            s1(2,no);
            clrscr();
            cash(cas.ca);
            cas.s1amt=cas.s1amt-no;
        }
        else
        {
            gotoxy(3,14);
            cout<<"Not enough stock to sell"<<endl;
            getch();
            clrscr();
            cash(cas.ca);
        }
    }
    else
    {
        gotoxy(3,14);
        cout<<"Invalid option";
        getch();
        clrscr();
        cash(cas.ca);
    }
}
long s1price()
{
    randomize();
    long price=3000,pricer;
    for(int k=0; k<random(200); k++)
        for(int j=0; j<random(300); j++)
            for(int i=0; i<random(100); i++)
                pricer=random(4000);
    price=price+pricer;
    return(price);
}
void s1(int opt,int no)                      //Infosys stock
{
    long price=s1price();
    operation(opt,no,price);
    cash(cas.ca);
}


void s2operation()
{
    long no=0;
    char ch=getch();
    if(ch=='b' || ch=='B')
    {
        if(cas.ca<-100000)
        {
            gotoxy(3,14);
            cout<<"You cannot buy anymore. Please sell stocks"<<endl;
            getch();
            goto end;
        }
        gotoxy(3,14);
        cout<<"Number of stocks you want to buy"<<endl;
        cin>>no;
        s2(1,no);
end:
        clrscr();
        cash(cas.ca);
        cas.s1amt+=no;
    }
    else if(ch=='s' || ch=='S')
    {
        if(cas.s2amt>0)
        {
            gotoxy(3,14);
            cout<<"Number of stocks you want to sell"<<endl;
            cin>>no;
            if(no>cas.s2amt)
            {
                gotoxy(3,14);
                cout<<"You do not have that much stock to sell"<<endl;
                getch();
                no=0;
            }
            s2(2,no);
            clrscr();
            cash(cas.ca);
            cas.s1amt=cas.s1amt-no;
        }
        else
        {
            gotoxy(3,14);
            cout<<"Not enough stock to sell"<<endl;
            getch();
            clrscr();
            cash(cas.ca);
        }
    }
    else
    {
        gotoxy(3,14);
        cout<<"Invalid option";
        getch();
        clrscr();
        cash(cas.ca);
    }
}
long s2price()
{
    randomize();
    long price=8000,pricer;
    for(int k=0; k<random(200); k++)
        for(int j=0; j<random(300); j++)
            for(int i=0; i<random(100); i++)
                pricer=random(5000);
    price=price+pricer;
    return(price);
}
void s2(int opt,int no)                      //Wipro stock
{
    long price=s2price();
    operation(opt,no,price);
    cash(cas.ca);
}


void s3operation()
{
    long no=0;
    char ch=getch();
    if(ch=='b' || ch=='B')
    {
        if(cas.ca<-100000)
        {
            gotoxy(3,14);
            cout<<"You cannot buy anymore. Please sell stocks"<<endl;
            getch();
            goto end;
        }
        gotoxy(3,14);
        cout<<"Number of stocks you want to buy"<<endl;
        cin>>no;
        s3(1,no);
end:
        clrscr();
        cash(cas.ca);
        cas.s3amt+=no;
    }
    else if(ch=='s' || ch=='S')
    {
        if(cas.s3amt>0)
        {
            gotoxy(3,14);
            cout<<"Number of stocks you want to sell"<<endl;
            cin>>no;
            if(no>cas.s3amt)
            {
                gotoxy(3,14);
                cout<<"You do not have that much stock to sell"<<endl;
                getch();
                no=0;
            }
            s3(2,no);
            clrscr();
            cash(cas.ca);
            cas.s1amt=cas.s1amt-no;
        }
        else
        {
            gotoxy(3,14);
            cout<<"Not enough stock to sell"<<endl;
            getch();
            clrscr();
            cash(cas.ca);
        }
    }
    else
    {
        gotoxy(3,14);
        cout<<"Invalid option";
        getch();
        clrscr();
        cash(cas.ca);
    }
}
long s3price()
{
    randomize();
    long price=10000,pricer;
    for(int k=0; k<random(200); k++)
        for(int j=0; j<random(300); j++)
            for(int i=0; i<random(100); i++)
                pricer=random(2000);
    price=price+pricer;
    return(price);
}
void s3(int opt,int no)                      //Asian Paints stock
{
    long price=s1price();
    operation(opt,no,price);
    cash(cas.ca);
}


void s4operation()
{
    long no=0;
    char ch=getch();
    if(ch=='b' || ch=='B')
    {
        if(cas.ca<-100000)
        {
            gotoxy(3,14);
            cout<<"You cannot buy anymore. Please sell stocks"<<endl;
            getch();
            goto end;
        }
        gotoxy(3,14);
        cout<<"Number of stocks you want to buy"<<endl;
        cin>>no;
        s4(1,no);
end:
        clrscr();
        cash(cas.ca);
        cas.s4amt+=no;
    }
    else if(ch=='s' || ch=='S')
    {
        if(cas.s4amt>0)
        {
            gotoxy(3,14);
            cout<<"Number of stocks you want to sell"<<endl;
            cin>>no;
            if(no>cas.s4amt)
            {
                gotoxy(3,14);
                cout<<"You do not have that much stock to sell"<<endl;
                getch();
                no=0;
            }
            s4(2,no);
            clrscr();
            cash(cas.ca);
            cas.s4amt=cas.s4amt-no;
        }
        else
        {
            gotoxy(3,14);
            cout<<"Not enough stock to sell"<<endl;
            getch();
            clrscr();
            cash(cas.ca);
        }
    }
    else
    {
        cout<<"Invalid option";
        getch();
        clrscr();
        cash(cas.ca);
    }
}
long s4price()
{
    randomize();
    long price=10000,pricer;
    for(int k=0; k<random(200); k++)
        for(int j=0; j<random(300); j++)
            for(int i=0; i<random(100); i++)
                pricer=random(4000);
    price=price+pricer;
    return(price);
}
void s4(int opt,int no)                      //TCS stock
{
    long price=s4price();
    operation(opt,no,price);
    cash(cas.ca);
}


void s5operation()
{
    long no=0;
    char ch=getch();
    if(ch=='b' || ch=='B')
    {
        if(cas.ca<-100000)
        {
            gotoxy(3,14);
            cout<<"You cannot buy anymore. Please sell stocks"<<endl;
            getch();
            goto end;
        }
        gotoxy(3,14);
        cout<<"Number of stocks you want to buy"<<endl;
        cin>>no;
        s5(1,no);
end:
        clrscr();
        cash(cas.ca);
        cas.s5amt+=no;
    }
    else if(ch=='s' || ch=='S')
    {
        if(cas.s5amt>0)
        {
            gotoxy(3,14);
            cout<<"Number of stocks you want to sell"<<endl;
            cin>>no;
            if(no>cas.s5amt)
            {
                gotoxy(3,14);
                cout<<"You do not have that much stock to sell"<<endl;
                getch();
                no=0;
            }
            s5(2,no);
            clrscr();
            cash(cas.ca);
            cas.s5amt=cas.s5amt-no;
        }
        else
        {
            gotoxy(3,14);
            cout<<"Not enough stock to sell"<<endl;
            getch();
            clrscr();
            cash(cas.ca);
        }
    }
    else
    {
        gotoxy(3,14);
        cout<<"Invalid option";
        getch();
        clrscr();
        cash(cas.ca);
    }
}
long s5price()
{
    randomize();
    long price=20000,pricer;
    for(int k=0; k<random(200); k++)
        for(int j=0; j<random(300); j++)
            for(int i=0; i<random(100); i++)
                pricer=random(5000);
    price=price+pricer;
    return(price);
}
void s5(int opt,int no)                      //TISCO stock
{
    long price=s5price();
    operation(opt,no,price);
    cash(cas.ca);
}


void s6operation()
{
    long no=0;
    char ch=getch();
    if(ch=='b' || ch=='B')
    {
        if(cas.ca<-100000)
        {
            gotoxy(3,14);
            cout<<"You cannot buy anymore. Please sell stocks"<<endl;
            getch();
            goto end;
        }
        gotoxy(3,14);
        cout<<"Number of stocks you want to buy"<<endl;
        cin>>no;
        s6(1,no);
end:
        clrscr();
        cash(cas.ca);
        cas.s6amt+=no;
    }
    else if(ch=='s' || ch=='S')
    {
        if(cas.s6amt>0)
        {
            gotoxy(3,14);
            cout<<"Number of stocks you want to sell"<<endl;
            cin>>no;
            if(no>cas.s6amt)
            {
                gotoxy(3,14);
                cout<<"You do not have that much stock to sell"<<endl;
                getch();
                no=0;
            }
            s6(2,no);
            clrscr();
            cash(cas.ca);
            cas.s6amt=cas.s6amt-no;
        }
        else
        {
            gotoxy(3,14);
            cout<<"Not enough stock to sell"<<endl;
            getch();
            clrscr();
            cash(cas.ca);
        }
    }
    else
    {
        gotoxy(3,14);
        cout<<"Invalid option";
        getch();
        clrscr();
        cash(cas.ca);
    }
}
long s6price()
{
    randomize();
    long price=10000,pricer;
    for(int k=0; k<random(200); k++)
        for(int j=0; j<random(300); j++)
            for(int i=0; i<random(100); i++)
                pricer=random(3000);
    price=price+pricer;
    return(price);
}
void s6(int opt,int no)                      //SAIL stock
{
    long price=s6price();
    operation(opt,no,price);
    cash(cas.ca);
}


void s7operation()
{
    long no=0;
    char ch=getch();
    if(ch=='b' || ch=='B')
    {
        if(cas.ca<-100000)
        {
            gotoxy(3,14);
            cout<<"You cannot buy anymore. Please sell stocks"<<endl;
            getch();
            goto end;
        }
        gotoxy(3,14);
        cout<<"Number of stocks you want to buy"<<endl;
        cin>>no;
        s7(1,no);
end:
        clrscr();
        cash(cas.ca);
        cas.s7amt+=no;
    }
    else if(ch=='s' || ch=='S')
    {
        if(cas.s7amt>0)
        {
            gotoxy(3,14);
            cout<<"Number of stocks you want to sell"<<endl;
            cin>>no;
            if(no>cas.s7amt)
            {
                gotoxy(3,14);
                cout<<"You do not have that much stock to sell"<<endl;
                getch();
                no=0;
            }
            s7(2,no);
            clrscr();
            cash(cas.ca);
            cas.s7amt=cas.s7amt-no;
        }
        else
        {
            gotoxy(3,14);
            cout<<"Not enough stock to sell"<<endl;
            getch();
            clrscr();
            cash(cas.ca);
        }
    }
    else
    {
        gotoxy(3,14);
        cout<<"Invalid option";
        getch();
        clrscr();
        cash(cas.ca);
    }
}
long s7price()
{
    randomize();
    long price=15000,pricer;
    for(int k=0; k<random(200); k++)
        for(int j=0; j<random(300); j++)
            for(int i=0; i<random(100); i++)
                pricer=random(10000);
    price=price+pricer;
    return(price);
}
void s7(int opt,int no)                      //Microsoft stock
{
    long price=s7price();
    operation(opt,no,price);
    cash(cas.ca);
}


void s8operation()
{
    long no=0;
    char ch=getch();
    if(ch=='b' || ch=='B')
    {
        if(cas.ca<-100000)
        {
            gotoxy(3,14);
            cout<<"You cannot buy anymore. Please sell stocks"<<endl;
            getch();
            goto end;
        }
        gotoxy(3,14);
        cout<<"Number of stocks you want to buy"<<endl;
        cin>>no;
        s8(1,no);
end:
        clrscr();
        cash(cas.ca);
        cas.s8amt+=no;
    }
    else if(ch=='s' || ch=='S')
    {
        if(cas.s8amt>0)
        {
            gotoxy(3,14);
            cout<<"Number of stocks you want to sell"<<endl;
            cin>>no;
            if(no>cas.s8amt)
            {
                gotoxy(3,14);
                cout<<"You do not have that much stock to sell"<<endl;
                getch();
                no=0;
            }
            s8(2,no);
            clrscr();
            cash(cas.ca);
            cas.s8amt=cas.s8amt-no;
        }
        else
        {
            gotoxy(3,14);
            cout<<"Not enough stock to sell"<<endl;
            getch();
            clrscr();
            cash(cas.ca);
        }
    }
    else
    {
        gotoxy(3,14);
        cout<<"Invalid option";
        getch();
        clrscr();
        cash(cas.ca);
    }
}
long s8price()
{
    randomize();
    long price=17000,pricer;
    for(int k=0; k<random(200); k++)
        for(int j=0; j<random(300); j++)
            for(int i=0; i<random(100); i++)
                pricer=random(11000);
    price=price+pricer;
    return(price);
}
void s8(int opt,int no)                      //Apple stock
{
    long price=s8price();
    operation(opt,no,price);
    cash(cas.ca);
}


void s9operation()
{
    long no=0;
    char ch=getch();
    if(ch=='b' || ch=='B')
    {
        if(cas.ca<-100000)
        {
            gotoxy(3,14);
            cout<<"You cannot buy anymore. Please sell stocks"<<endl;
            getch();
            goto end;
        }
        gotoxy(3,14);
        cout<<"Number of stocks you want to buy"<<endl;
        cin>>no;
        s9(1,no);
end:
        clrscr();
        cash(cas.ca);
        cas.s9amt+=no;
    }
    else if(ch=='s' || ch=='S')
    {
        if(cas.s9amt>0)
        {
            gotoxy(3,14);
            cout<<"Number of stocks you want to sell"<<endl;
            cin>>no;
            if(no>cas.s9amt)
            {
                gotoxy(3,14);
                cout<<"You do not have that much stock to sell"<<endl;
                getch();
                no=0;
            }
            s9(2,no);
            clrscr();
            cash(cas.ca);
            cas.s9amt=cas.s9amt-no;
        }
        else
        {
            gotoxy(3,14);
            cout<<"Not enough stock to sell"<<endl;
            getch();
            clrscr();
            cash(cas.ca);
        }
    }
    else
    {
        cout<<"Invalid option";
        getch();
        clrscr();
        cash(cas.ca);
    }
}
long s9price()
{
    randomize();
    long price=20000,pricer;
    for(int k=0; k<random(200); k++)
        for(int j=0; j<random(300); j++)
            for(int i=0; i<random(100); i++)
                pricer=random(10000);
    price=price+pricer;
    return(price);
}
void s9(int opt,int no)                      //Google stock
{
    long price=s1price();
    operation(opt,no,price);
    cash(cas.ca);
}


void s10operation()
{
    long no=0;
    char ch=getch();
    if(ch=='b' || ch=='B')
    {
        if(cas.ca<-100000)
        {
            gotoxy(3,14);
            cout<<"You cannot buy anymore. Please sell stocks"<<endl;
            getch();
            goto end;
        }
        gotoxy(3,14);
        cout<<"Number of stocks you want to buy"<<endl;
        gotoxy(3,15);
        cin>>no;
        s10(1,no);
end:
        clrscr();
        cash(cas.ca);
        cas.s10amt+=no;
    }
    else if(ch=='s' || ch=='S')
    {
        if(cas.s10amt>0)
        {
            gotoxy(3,14);
            cout<<"Number of stocks you want to sell"<<endl;
            cin>>no;
            if(no>cas.s10amt)
            {
                gotoxy(3,14);
                cout<<"You do not have that much stock to sell"<<endl;
                getch();
                no=0;
            }
            s10(2,no);
            clrscr();
            cash(cas.ca);
            cas.s10amt=cas.s10amt-no;
        }
        else
        {
            gotoxy(3,14);
            cout<<"Not enough stock to sell"<<endl;
            getch();
            clrscr();
            cash(cas.ca);
        }
    }
    else
    {
        cout<<"Invalid option";
        getch();
        clrscr();
        cash(cas.ca);
    }
}


long s10price()
{
    randomize();
    long price=10000,pricer;
    for(int k=0; k<random(200); k++)
        for(int j=0; j<random(300); j++)
            for(int i=0; i<random(100); i++)
                pricer=random(15000);
    price=price+pricer;
    return(price);
}
void s10(int opt,int no)                      //IBM stock
{
    long price=s10price();
    operation(opt,no,price);
    cash(cas.ca);
}


void sty(char a[])
{
    int l=strlen(a);
    for(int i=0; i<l; i++)
    {
        cout<<a[i];
        delay(delay1);
    }
}
void marketintrotext()
{
    dec();
    stars("Stock Market Simulator");
    cout<<endl;
    gotoxy(10,6);
    sty("Welcome to the Stock Market Simulator");
    cout<<endl;
    gotoxy(10,8);
    sty("-This game illustrates the use of random() function of C++ extensively.");
    gotoxy(10,10);
    sty("-You start with an initial amount of 100000 credits.");
    gotoxy(10,12);
    sty("-If your credit, at any time, goes below -100000, you lose the game.");
    gotoxy(10,14);
    sty("-If you buy more shares than you can afford, you lose the game.");
    gotoxy(10,18);
    sty("-Press any key to proceed");
}
void stockgame()
{
    marketintrotext();
    getch();
    clrscr();
    cas.s1amt=0;
    cas.s2amt=0;
    cas.s3amt=0;
    cas.s4amt=0;
    cas.s5amt=0;
    cas.s6amt=0;
    cas.s7amt=0;
    cas.s8amt=0;
    cas.s9amt=0;
    cas.s10amt=0;
    cas.ca=100000;     //starting cash
    cash(cas.ca);
update:
    cash(cas.ca);
    if(cas.ca<=-100000)
    {
        clrscr();
        dec1();
        gotoxy(40,12);
        cout<<"GAME OVER";
        getch();
        clrscr();
        menu();
    }
    dec1();
    gotoxy(2,23);
    cout<<"Enter the stock option no for transaction"<<endl;
    gotoxy(2,2);
    cout<<" Stock \t Price  Shares"<<endl;
    while(!kbhit())
    {
        randomize();
        gotoxy(60,4);
        cout<<"Press e to exit";
        gotoxy(3,3);
        cout<<"1.INFOSYS \t "<<s1price()<<'\t'<<cas.s1amt<<endl;
        gotoxy(3,4);
        cout<<"2.WIPRO \t "<<s2price()<<'\t'<<cas.s2amt<<endl;
        gotoxy(3,5);
        cout<<"3.ASIPAI \t "<<s3price()<<'\t'<<cas.s3amt<<endl;
        gotoxy(3,6);
        cout<<"4.TCS \t "<<s4price()<<'\t'<<cas.s4amt<<endl;
        gotoxy(3,7);
        cout<<"5.TISCO \t "<<s5price()<<'\t'<<cas.s5amt<<endl;
        gotoxy(3,8);
        cout<<"6.SAIL \t "<<s6price()<<'\t'<<cas.s6amt<<endl;
        gotoxy(3,9);
        cout<<"7.MICSOF \t "<<s7price()<<'\t'<<cas.s7amt<<endl;
        gotoxy(3,10);
        cout<<"8.APPLE \t "<<s8price()<<'\t'<<cas.s8amt<<endl;
        gotoxy(3,11);
        cout<<"9.GOOG \t "<<s9price()<<'\t'<<cas.s9amt<<endl;
        gotoxy(3,12);
        cout<<"0.IBM  \t "<<s10price()<<'\t'<<cas.s10amt<<endl;
        delay(10);
    }
    char option=getch();
    if(option=='1')
    {
        gotoxy(3,13);
        cout<<"B to buy, S to sell Infosys"<<endl;
        s1operation();
    }
    else if(option=='2')
    {
        gotoxy(3,13);
        cout<<"B to buy, S to sell Wipro"<<endl;
        s2operation();
    }
    else if(option=='3')
    {
        gotoxy(3,13);
        cout<<"B to buy, S to sell Asian Paints"<<endl;
        s3operation();
    }
    else if(option=='4')
    {
        gotoxy(3,13);
        cout<<"B to buy, S to sell TCS"<<endl;
        s4operation();
    }
    else if(option=='5')
    {
        gotoxy(3,13);
        cout<<"B to buy, S to sell TISCO"<<endl;
        s5operation();
    }
    else if(option=='6')
    {
        gotoxy(3,13);
        cout<<"B to buy, S to sell SAIL"<<endl;
        s6operation();
    }
    else if(option=='7')
    {
        gotoxy(3,13);
        cout<<"B to buy, S to sell MICROSOFT"<<endl;
        s7operation();
    }
    else if(option=='8')
    {
        gotoxy(3,13);
        cout<<"B to buy, S to sell APPLE"<<endl;
        s8operation();
    }
    else if(option=='9')
    {
        gotoxy(3,13);
        cout<<"B to buy, S to sell GOOGLE"<<endl;
        s9operation();
    }
    else if(option=='0')
    {
        gotoxy(3,13);
        cout<<"B to buy, S to sell IBM"<<endl;
        s10operation();
    }
    else if(option=='e')
    {
        clrscr();
        menu();
    }
    else
    {
        gotoxy(3,15);
        cout<<"Try Again(Invalid key)"<<endl;
        getch();
        clrscr();
    }
    goto update;
}
void games()
{
    stockgame();
}

/*Contact Book */

void contactbook();
class contacts
{
    char name[40];
    double phone;
    char email_id[50];
public:
    void getcontact();
    void showcontact();
    double retphone()
    {
        return phone;
    }
};
void contacts:: getcontact()
{
    clrscr();
    dec();
    gotoxy(33,8);
    cout<<"Enter the name :: ";
    gets (name);
    cout<<endl;
    gotoxy(33,10);
    cout<<"Enter phone number :: ";
    cin>>phone;
    gotoxy(33,12);
    cout<<"Enter the email id of the contact :: ";
    gets(email_id);
    cout<<endl;
}
void contacts::showcontact()
{
    clrscr();
    dec();
    gotoxy(33,8);
    cout<<"Name :: "<<name<<endl;
    gotoxy(33,10);
    cout<<"Telephone number :: "<<phone<<endl;
    gotoxy(33,12);
    cout<<"Email ID :: "<<email_id<<endl;
    getch();
}
void newcont()
{
    contacts c;
    char a;
    ofstream file;
    file.open("newfile.dat",ios::out|ios::binary|ios::app);
    do
    {
        c.getcontact();
        file.write((char*)&c,sizeof(c));
        gotoxy(33,14);
        cout<<"Continue to add more contacts?(y/n) ::  ";
        gotoxy(33,16);
        cin>>a;
    }
    while(a=='y');
    file.close();
    contactbook();
}
void search()
{
    contacts c;
    clrscr();
    dec();
    char a;
    int p=0;
    double phone;
    ifstream file;
    file.open("newfile.dat",ios::in|ios::binary);
    gotoxy(20,10);
    cout<<"Enter the phone number to be searched";
    gotoxy(20,11);
    cin>>phone;
    while(!file.eof())
    {
        file.read((char*)&c, sizeof(c));
        if(c.retphone()== phone)
        {
            c.showcontact();
            p=1;
            clrscr();
            break;
        }
    }
    if(p==0)
    {
        gotoxy(33,18);
        cout<<"The number was not found"<<endl;
    }
    file.close();
}
void displaycont()
{
    dec();
    contacts c;
    ifstream file;
    file.open("newfile.dat",ios::in|ios::binary);
    while(!file.eof())
    {
        file.read((char*)&c,sizeof(c));
        c.showcontact();
    }
    clrscr();
}
void contactbook()
{
screen:
    clrscr();
    dec();
    /*Stars for Contact book */
    stars("Contact Book");
    gotoxy(33,8);
    cout<<"1.Add new contact"<<endl;
    gotoxy(33,10);
    cout<<"2.Display contact"<<endl;
    gotoxy(33,12);
    cout<<"3.Search contact"<<endl;
    gotoxy(33,14);
    cout<<"4.Return to main menu"<<endl;
    int opt;
    gotoxy(33,16);
    cout<<"Enter option";
    gotoxy(33,17);
    cin>>opt;
    switch(opt)
    {
    case 1:
        newcont();
        break;
    case 2:
        displaycont();
        break;
    case 3:
        search();
        break;
    case 4:
        break;
    default:
        gotoxy(33,18);
        cout<<"Wrong Option.";
        getch();
        contactbook();
        break;
    }
    if(opt==4)
        menu();
    else
        goto screen;
}
/*World Clock*/
void clockalarm()
{
    stars("World Clock");
#define ABD (+1)                           //GMT IS -3
#define ATH (-1)
#define IST (+2)
#define HWI (-13)
#define SAN (-11)
#define BGK (+4)
#define BEJ (+5)
#define TOK (+6)
#define SYD (+8)
#define WEL (+10)
#define LON (-3)
#define FRA (-2)
    while(!kbhit())
    {
        time_t rawtime;
        tm * ptm;
        time ( &rawtime );
        ptm = localtime ( &rawtime );


        gotoxy(25,8);
        cout<<"Abu Dhabi (UAE): ";
        gotoxy(50,8);
        if(((ptm->tm_hour+ABD)%24)<10)
            cout<<"0";
        cout<<(ptm->tm_hour+ABD)%24;
        cout<<":";
        if(ptm->tm_min<10)
            cout<<"0";
        cout<<ptm->tm_min;
        cout<<":";
        if(ptm->tm_sec<10)
            cout<<"0";
        cout<<ptm->tm_sec;
        cout<<endl;


        gotoxy(25,9);
        cout<<"Athens (Greece): ";
        gotoxy(50,9);
        if(((ptm->tm_hour+ATH)%24)<10)
            cout<<"0";
        cout<<abs((ptm->tm_hour+ATH)%24);
        cout<<":";
        if(ptm->tm_min<10)
            cout<<"0";
        cout<<ptm->tm_min;
        cout<<":";
        if(ptm->tm_sec<10)
            cout<<"0";
        cout<<ptm->tm_sec;
        cout<<endl;


        gotoxy(25,10);
        cout<<"Hawaii (USA):  ";
        gotoxy(50,10);
        if(((abs(ptm->tm_hour+HWI)%24))<10)
            cout<<"0";
        cout<<abs((ptm->tm_hour+HWI)%24);
        cout<<":";
        if(ptm->tm_min<10)
            cout<<"0";
        cout<<ptm->tm_min;
        cout<<":";
        if(ptm->tm_sec<10)
            cout<<"0";
        cout<<ptm->tm_sec;
        cout<<endl;


        gotoxy(25,11);
        cout<<"San Francisco (USA):  ";
        gotoxy(50,11);
        if(abs(((ptm->tm_hour+SAN)%24))<10)
            cout<<"0";
        cout<<abs((ptm->tm_hour+SAN)%24);
        cout<<":";
        if(ptm->tm_min<10)
            cout<<"0";
        cout<<ptm->tm_min;
        cout<<":";
        if(ptm->tm_sec<10)
            cout<<"0";
        cout<<ptm->tm_sec;
        cout<<endl;


        gotoxy(25,12);
        cout<<"Mumbai (India):  ";
        if(ptm->tm_min<30)
        {
            gotoxy(50,12);
            if(((ptm->tm_hour+IST)%24)<10)
                cout<<"0";
            cout<<(ptm->tm_hour+IST)%24;
            cout<<":";
            if((ptm->tm_min)+30<10)
                cout<<"0";
            cout<<ptm->tm_min+30;
        }
        if(ptm->tm_min>=30)
        {
            gotoxy(50,12);
            if(((ptm->tm_hour+IST)%24+1)<10)
                cout<<"0";
            cout<<((ptm->tm_hour+IST)%24+1);
            cout<<":";
            if(((ptm->tm_min)+30)%30<10)
                cout<<"0";
            cout<<((ptm->tm_min)+30)%30;
        }
        cout<<":";
        if(ptm->tm_sec<10)
            cout<<"0";
        cout<<ptm->tm_sec;
        cout<<endl;


        gotoxy(25,13);
        cout<<"Bangkok (Thailand):  ";
        gotoxy(50,13);
        if(((ptm->tm_hour+BGK)%24)<10)
            cout<<"0";
        cout<<(ptm->tm_hour+BGK)%24;
        cout<<":";
        if(ptm->tm_min<10)
            cout<<"0";
        cout<<ptm->tm_min;
        cout<<":";
        if(ptm->tm_sec<10)
            cout<<"0";
        cout<<ptm->tm_sec;
        cout<<endl;


        gotoxy(25,14);
        cout<<"Beijing (China) ";
        gotoxy(50,14);
        if(((ptm->tm_hour+BEJ)%24)<10)
            cout<<"0";
        cout<<(ptm->tm_hour+BEJ)%24;
        cout<<":";
        if(ptm->tm_min<10)
            cout<<"0";
        cout<<ptm->tm_min;
        cout<<":";
        if(ptm->tm_sec<10)
            cout<<"0";
        cout<<ptm->tm_sec;
        cout<<endl;


        gotoxy(25,15);
        cout<<"Tokyo (Japan):  ";
        gotoxy(50,15);
        if(((ptm->tm_hour+TOK)%24)<10)
            cout<<"0";
        cout<<(ptm->tm_hour+TOK)%24;
        cout<<":";
        if(ptm->tm_min<10)
            cout<<"0";
        cout<<ptm->tm_min;
        cout<<":";
        if(ptm->tm_sec<10)
            cout<<"0";
        cout<<ptm->tm_sec;
        cout<<endl;


        gotoxy(25,16);
        cout<<"Sydney (Australia):  ";
        gotoxy(50,16);
        if(((ptm->tm_hour+SYD)%24)<10)
            cout<<"0";
        cout<<(ptm->tm_hour+SYD)%24;
        cout<<":";
        if(ptm->tm_min<10)
            cout<<"0";
        cout<<ptm->tm_min;
        cout<<":";
        if(ptm->tm_sec<10)
            cout<<"0";
        cout<<ptm->tm_sec;
        cout<<endl;


        gotoxy(25,17);
        cout<<"Wellington(New Zealand)";
        gotoxy(50,17);
        if(((ptm->tm_hour+WEL)%24)<10)
            cout<<"0";
        cout<<(ptm->tm_hour+WEL)%24;
        cout<<":";
        if(ptm->tm_min<10)
            cout<<"0";
        cout<<ptm->tm_min;
        cout<<":";
        if(ptm->tm_sec<10)
            cout<<"0";
        cout<<ptm->tm_sec;
        cout<<endl;


        gotoxy(25,18);
        cout<<"London (U.K.):  ";
        gotoxy(50,18);
        if(((ptm->tm_hour+LON)%24)<10)
            cout<<"0";
        cout<<abs((ptm->tm_hour+LON)%24);
        cout<<":";
        if(ptm->tm_min<10)
            cout<<"0";
        cout<<ptm->tm_min;
        cout<<":";
        if(ptm->tm_sec<10)
            cout<<"0";
        cout<<ptm->tm_sec;
        cout<<endl;


        gotoxy(25,19);
        cout<<"Paris (France):  ";
        gotoxy(50,19);
        if(((ptm->tm_hour+FRA)%24)<10)
            cout<<"0";
        cout<<abs((ptm->tm_hour+FRA)%24);
        cout<<":";
        if(ptm->tm_min<10)
            cout<<"0";
        cout<<ptm->tm_min;
        cout<<":";
        if(ptm->tm_sec<10)
            cout<<"0";
        cout<<ptm->tm_sec;
        cout<<endl;

        dec();
        if(kbhit())
            break;
        delay(10000);
    }
    menu();
}


/*Introduction*/
void intro()
{
    gotoxy(0,8);
    cout<<"        **   *********     **                                            "<<endl;
    cout<<"              **    **                                                   "<<endl;
    cout<<"        **    **    **     **      ********     **  **      **    **"<<endl;
    cout<<"        **    **    **     **            **     ******      **    **"<<endl;
    cout<<"        **    **    **     **      ********     **            ****  "<<endl;
    cout<<"        **    **    **     **     **     **     **            ****  "<<endl;
    cout<<"        **    **   **      **     **     **     **             **    "<<endl;
    cout<<"       ***   *******      ***      *********    **             **    "<<endl;
    cout<<"                                                             **      "<<endl;
    cout<<"                                                             **      "<<endl;
    gotoxy(18,24);
    char ch=169;
    cout<<ch;
    cout<<"2010-2011 Vinyl Inc, All rights reserved";
    delay(1800000);
    clrscr();
}
void rotating(int i,int dectype)
{
    if(dectype==1)
    {
        gotoxy(i,0);
        cout<<"|||||";
        delay(rotate);
        cout<<"     ";
        delay(rotate);
        gotoxy(i,0);
        cout<<"/////";
        delay(rotate);
        gotoxy(i,0);
        cout<<"     ";
        delay(rotate);
        gotoxy(i,0);
        cout<<"|||||";
        delay(rotate);
        gotoxy(i,0);
        cout<<"     ";
        delay(rotate);
        gotoxy(i,0);
        cout<<"-----";
        delay(rotate);
        gotoxy(i,0);
        cout<<"     ";
        delay(rotate);
        gotoxy(i,0);
        cout<<"\\\\\\\\\\";
        delay(rotate);
        gotoxy(i,0);
        cout<<"     ";
    }
    else if(dectype==2)
    {
        gotoxy(75,i);
        cout<<"|||||";
        delay(rotate);
        gotoxy(75,i);
        cout<<"     ";
        delay(rotate);
        gotoxy(75,i);
        cout<<"/////";
        delay(rotate);
        gotoxy(75,i);
        cout<<"     ";
        delay(rotate);
        gotoxy(75,i);
        cout<<"-----";
        delay(rotate);
        gotoxy(75,i);
        cout<<"     ";
        delay(rotate);
        gotoxy(75,i);
        cout<<"\\\\\\\\\\";
        delay(rotate);
        gotoxy(75,i);
        cout<<"     ";
    }
    else if(dectype==3)
    {
        gotoxy(i,24);
        cout<<"|||||";
        delay(rotate);
        gotoxy(i,24);
        cout<<"     ";
        delay(rotate);
        gotoxy(i,24);
        cout<<"/////";
        delay(rotate);
        gotoxy(i,24);
        cout<<"     ";
        delay(rotate);
        gotoxy(i,24);
        cout<<"-----";
        delay(rotate);
        gotoxy(i,24);
        cout<<"     ";
        delay(rotate);
        gotoxy(i,24);
        cout<<"\\\\\\\\\\";
        delay(rotate);
        gotoxy(i,24);
        cout<<"     ";
    }
    else if(dectype==4)
    {
        gotoxy(0,i);
        cout<<"|||||";
        delay(rotate);
        gotoxy(0,i);
        cout<<"     ";
        delay(rotate);
        gotoxy(0,i);
        cout<<"/";
        delay(rotate);
        gotoxy(0,i);
        cout<<"     ";
        delay(rotate);
        gotoxy(0,i);
        cout<<"-----";
        delay(rotate);
        gotoxy(0,i);
        cout<<"     ";
        delay(rotate);
        gotoxy(0,i);
        cout<<"\\\\\\\\\\";
        delay(rotate);
        gotoxy(0,i);
        cout<<"     ";
    }
}
void decorations()
{
    while(!kbhit())
    {
        //from old
        for(int i=1; i<80; i+=2)
        {
            gotoxy(i,0);
            cout<<"* ";
            if(kbhit())
                break;
            delay(delay1);
            stars("Main Menu");
        }
        for(i=78; i>1; i-=2)
        {
            gotoxy(i,2);
            cout<<" *";
            if(kbhit())
                break;
            delay(delay1);
            stars("Main Menu");
        }
        for(i=1; i<25; i++)
        {
            gotoxy(80,i)  ;
            cout<<"*";
            if(kbhit())
                break;
            delay(delay1);
            stars("Main Menu");
        }
        for(i=23; i>1; i--)
        {
            gotoxy(78,i)  ;
            cout<<"*";
            if(kbhit())
                break;
            delay(delay1);
            stars("Main Menu");
        }
        for(i=80; i>0; i-=2)
        {
            gotoxy(i,24) ;
            cout<<"*";
            if(kbhit())
                break;
            delay(delay1);
            stars("Main Menu");
        }
        for(i=79; i>1; i-=2)
        {
            gotoxy(i,23) ;
            cout<<"*";
            if(kbhit())
                break;
            delay(delay1);
            stars("Main Menu");
        }
        for(i=24; i>0; i--)
        {
            gotoxy(0,i);
            cout<<"*";
            if(kbhit())
                break;
            delay(delay1);
            stars("Main Menu");
        }
        for(i=1; i<24; i++)
        {
            gotoxy(3,i);
            cout<<"*";
            if(kbhit())
                break;
            delay(delay1);
            stars("Main Menu");
        }
        //erasing the first ones
        for(i=1; i<80; i+=2)
        {
            gotoxy(i,0);
            cout<<"  ";
            if(kbhit())
                break;
            delay(delay1);
            stars("Main Menu");
        }
        for(i=80; i>1; i-=2)
        {
            gotoxy(i,2);
            cout<<"  ";
            if(kbhit())
                break;
            delay(delay1);
            stars("Main Menu");
        }
        for(i=1; i<25; i++)
        {
            gotoxy(80,i)  ;
            cout<<" ";
            if(kbhit())
                break;
            delay(delay1);
            stars("Main Menu");
        }
        for(i=23; i>1; i--)
        {
            gotoxy(78,i)  ;
            cout<<" ";
            if(kbhit())
                break;
            delay(delay1);
            stars("Main Menu");
        }
        for(i=80; i>0; i-=2)
        {
            gotoxy(i,24) ;
            cout<<" ";
            if(kbhit())
                break;
            delay(delay1);
            stars("Main Menu");
        }
        for(i=79; i>1; i-=2)
        {
            gotoxy(i,23) ;
            cout<<" ";
            if(kbhit())
                break;
            delay(delay1);
            stars("Main Menu");
        }
        for(i=24; i>0; i--)
        {
            gotoxy(0,i);
            cout<<" ";
            if(kbhit())
                break;
            delay(delay1);
            stars("Main Menu");
        }
        for(i=1; i<24; i++)
        {
            gotoxy(3,i);
            cout<<" ";
            if(kbhit())
                break;
            delay(delay1);
            stars("Main Menu");
        }


        gotoxy(0,0);
        for(i=0; i<75; i++)
        {
            rotating(i,1);
        }
        for(i=1; i<24; i++)
        {
            rotating(i,2);
        }
        for(i=75; i>0; i-=2)
        {
            rotating(i,3);
        }
        for(i=24; i>0; i--)
        {
            rotating(i,4);
        }
    }
}
void option(int opt)
{
    switch(opt)
    {
    case '1' :
    {
        reminder r;
        dec();
        char ch;
        gotoxy(32,12);
        cout<<"Input or Output(I/O) :";
        ch=getchar();
        if(ch=='i'|| ch=='I')
            r.input();
        else
            r.output();
        break;
    }
    case '2' :
    {
        contactbook();
        break;
    }
    case '3' :
    {
        exercisecalc();
        break;
    }
    case '4' :
    {
        clockalarm();
        break;
    }
    case '5' :
    {
        calendar();
        break;
    }
    case '6' :
    {
        calculator();
        break;
    }
    case '7' :
    {
        converter();
        break;
    }
    case '8' :
    {
        games();
        break;
    }
    default:
    {
        cout<<"Invalid option";
        menu();
    }
    }
}

/*Pretty Menu */
void menu()
{
    clrscr();
    int opt;
    stars("Main Menu");
    gotoxy(33,5) ;
    cout<<"1. Reminders \n"<<endl ;
    gotoxy(33,7) ;
    cout<<"2. Contacts Book \n"<<endl;
    gotoxy(33,9);
    cout<<"3. Fit-o-meter \n"<<endl;
    gotoxy(33,11);
    cout<<"4. World Clock \n"<<endl;
    gotoxy(33,13);
    cout<<"5. Calendar \n"<<endl;
    gotoxy(33,15);
    cout<<"6. Calculator \n"<<endl;
    gotoxy(33,17);
    cout<<"7. Converter \n"<<endl;
    gotoxy(33,19);
    cout<<"8. Games \n"<<endl;
    gotoxy(33,21)  ;
    cout<<"Your choice ";
    decorations();
    opt=getch();
    clrscr();
    if(opt=='1')
    {
        gotoxy(34,10);
        cout<<"        # #   ";
        gotoxy(34,11);
        cout<<"    # # # #   ";
        gotoxy(34,12);
        cout<<"        # #   ";
        gotoxy(34,13);
        cout<<"        # #   ";
        gotoxy(34,14);
        cout<<"        # #   ";
        gotoxy(34,15);
        cout<<"        # #   ";
        gotoxy(34,16);
        cout<<"        # #   ";
        gotoxy(34,17);
        cout<<"        # #   ";
        gotoxy(34,18);
        cout<<"   # # # # # # ";
    }
    else if(opt=='2')
    {
        gotoxy(34,10);
        cout<<"    # # # # #  ";
        gotoxy(34,11);
        cout<<"  # #       # #";
        gotoxy(34,12);
        cout<<"            # #";
        gotoxy(34,13);
        cout<<"            # #";
        gotoxy(34,14);
        cout<<"          # #  ";
        gotoxy(34,15);
        cout<<"        # #    ";
        gotoxy(34,16);
        cout<<"	 # #       ";
        gotoxy(34,17);
        cout<<"    # #        ";
        gotoxy(34,18);
        cout<<"  # # # # # # #";
    }
    else if(opt=='3')
    {
        gotoxy(34,10);
        cout<<"    # # # # #   ";
        gotoxy(34,11);
        cout<<"  # #       # # ";
        gotoxy(34,12);
        cout<<"            # # ";
        gotoxy(34,13);
        cout<<"            # # ";
        gotoxy(34,14);
        cout<<"      # # # #   ";
        gotoxy(34,15);
        cout<<"            # # ";
        gotoxy(34,16);
        cout<<"            # # ";
        gotoxy(34,17);
        cout<<"  # #       # # ";
        gotoxy(34,18);
        cout<<"   # # # # #    ";
    }
    else if(opt=='4')
    {
        gotoxy(34,10);
        cout<<"               # #      ";
        gotoxy(34,11);
        cout<<"	      # # #      ";
        gotoxy(34,12);
        cout<<"  	    #   # #      ";
        gotoxy(34,13);
        cout<<"         #     # #      ";
        gotoxy(34,14);
        cout<<"       #       # #     ";
        gotoxy(34,15);
        cout<<"       # # # # # # # # ";
        gotoxy(34,16);
        cout<<"	        # #      ";
        gotoxy(34,17);
        cout<<"	        # #      ";
        gotoxy(34,18);
        cout<<"	        # #      ";
    }
    if(opt=='5')
    {
        gotoxy(34,10);
        cout<<"	 # # # # # #   ";
        gotoxy(34,11);
        cout<<"	 # #           ";
        gotoxy(34,12);
        cout<<"	 # #           ";
        gotoxy(34,13);
        cout<<"	 # # # # # #     ";
        gotoxy(34,14);
        cout<<"	         # #   ";
        gotoxy(34,15);
        cout<<"                # #   ";
        gotoxy(34,16);
        cout<<"                # #  ";
        gotoxy(34,17);
        cout<<"                # #  ";
        gotoxy(34,18);
        cout<<"	 # # # # # #     ";
    }
    if(opt=='6')
    {
        gotoxy(34,10);
        cout<<"     # # # #   ";
        gotoxy(34,11);
        cout<<"   # #          ";
        gotoxy(34,12);
        cout<<"  # #           ";
        gotoxy(34,13);
        cout<<"  # # # # # #   ";
        gotoxy(34,14);
        cout<<"  # #       # # ";
        gotoxy(34,15);
        cout<<"  # #       # # ";
        gotoxy(34,16);
        cout<<"  # #       # # ";
        gotoxy(34,17);
        cout<<"  # #       # # ";
        gotoxy(34,18);
        cout<<"    # # # # #    ";
    }
    if(opt=='7')
    {
        gotoxy(34,10);
        cout<<"       # # # # # # #";
        gotoxy(34,11);
        cout<<"	         # # ";
        gotoxy(34,12);
        cout<<"	        # # ";
        gotoxy(34,13);
        cout<<"	       # #   ";
        gotoxy(34,14);
        cout<<"	     # #   ";
        gotoxy(34,15);
        cout<<"          # #     ";
        gotoxy(34,16);
        cout<<"	  # #     ";
        gotoxy(34,17);
        cout<<"	# #       ";
        gotoxy(34,18);
        cout<<"     # #       ";
    }
    if(opt=='8')
    {
        gotoxy(34,10);
        cout<<"    # # # # #   ";
        gotoxy(34,11);
        cout<<"  # #       # # ";
        gotoxy(34,12);
        cout<<"  # #       # # ";
        gotoxy(34,13);
        cout<<"  # #       # # ";
        gotoxy(34,14);
        cout<<"    # # # # #    ";
        gotoxy(34,15);
        cout<<"  # #       # # ";
        gotoxy(34,16);
        cout<<"  # #       # # ";
        gotoxy(34,17);
        cout<<"  # #       # # ";
        gotoxy(34,18);
        cout<<"    # # # # #    ";
    }
    if(opt=='9')
    {
        gotoxy(34,10);
        cout<<"    # # # # #   ";
        gotoxy(34,11);
        cout<<"  # #       # #";
        gotoxy(34,12);
        cout<<"  # #       # #";
        gotoxy(34,13);
        cout<<"  # #       # #";
        gotoxy(34,14);
        cout<<"  # #       # #";
        gotoxy(34,15);
        cout<<"    # # # # # # ";
        gotoxy(34,16);
        cout<<"	     # # ";
        gotoxy(34,17);
        cout<<"	    # #   ";
        gotoxy(34,18);
        cout<<"     # # # #     ";
    }
    delay(1000000);
    clrscr();
    option(opt);
}

/*Basic Login Screen */

int login_page()
{
    stars("Login Page");
    dec();
    int checker,i=0;
    char check=0,username[100]="user",password[100]="pass",tempuser[100],temppass[100];

    gotoxy(30,40);
    cout<<"*You have "<<tries<<"/3 tries left*";
    gotoxy(15,10);
    cout<<"Username:";
    gotoxy(15,11);
    cout<<"Password:";

    gotoxy(24,10);
    gets(tempuser);

    gotoxy(24,11);
    while(check!=13)
    {
        check=getch();
        if(check==13)
            break;
        if(check!=8)
        {
            cout<<"*";
            temppass[i]=check;
            i++;
        }
        else
        {
            int r=i;
            r--;
            if(i>=0)
            {
                i--;
                gotoxy(24+i,11) ;
                temppass[i]=0;
                temppass[i+1]=0;
                cout<<" ";
                gotoxy(24+i,11) ;
            }
        }
    }
    gotoxy(30,40)    ;
    if(strcmp(username,tempuser)==0 && strcmp(password,temppass)==0)
    {
        cout<<"You have been logged in... ";
        checker=1;
    }
    else
    {
        cout<<"*You have Failed to login...*";
        checker=0;
    }
    return checker;
}


void login()
{
    int checker;

next:
    checker=login_page();

    clrscr();

    if(checker==1)
        menu();
    else if(checker==0)
    {
        tries=tries-1;
        if(tries>0)
            goto next;
        else
        {
            gotoxy(30,10);
            cout<<"You can not login...bye! ";
        }
    }

}

void project()
{
    intro();
    menu();
}

void main()
{
    project();
}
