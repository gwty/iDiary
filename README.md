iDiary
======

Personal Digital Organizer

Contains 
  Notes,
  Memo,
  Contacts,
  Stock Market Simulator Game,
  Password Protection

This is a depreceated C++ Application, which was done for my school project.
We had to use Turbo C++, and so here it is, truely non-portable code, due to extensive use of conio.h.

If you somehow have a Turbo C++ Compiler, change the memory model to Large, or it won't compile.
It is because the default Code Size limit is 64KB!

I wished to port it to ANSI C++, but it is too much for me! Rewriting all of this using ncurses will surely take a lot of time, and is not worth the effort. 
It stays here, for the sake of nostalgia.
It reminds me of the limitation of the rand() function in Turbo C++,the Stock Market Game becomes very predictable when I use that.



My instructions [written long ago]:

iDiary is a digital diary, that can be used for various purposes, such as the time, calculator, and so on. It is easy to use and an efficient program.
We hope you enjoy it.
To run the program go to options-compiler-code generation- select  Large Model

Only the standard header files have been used.
conio.h was used more extensively.
__CONIO.H__
-gotoxy(x coordinate,y coordinate) helps us position the text
-kbhit() is used to find out whether a button has been pressed.
-clreol() is like clrscr() but it moves to the next page only when the user hits a key.
__FSTREAM.H__
-contains iostream.h
__STRING.H__
-strcmpi(dest,source) is used to compare both uppercase and lowercase values(which are absent in strcmp)
__TIME.H__
localtime is used to get the system time, which is stored in a structure time_t

All the decorations in this program have used a delay function.
After each delay function, kbhit() is used to check whether a button has been hit.
If it has been hit, then the control changes to getch(), which takes the value and does its user-given function.
If not, it proceeds to the next decoration

ASCII Art has been used in some parts of the program which has been obtained from specially-designed programs.

The size of the window is 80,25.
ie, gotoxy(0,25) points to last line
    gotoxy(80,0) points to last column in the first line.

For Login, the default user is user
 And the default password is pass

