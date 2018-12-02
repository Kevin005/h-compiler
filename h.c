#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
 
////////////////////
struct variable{
	signed int i;
	signed int Len;
	signed int j;
	signed int r;
	char*String;
	char Char[10];
	char*str;
	bool boolean[10];
}Nect;
void Token(char character,int i){
	switch(character){
		case '+':
			Nect.Char[i]++;
		break;
		case '-':
			Nect.Char[i]--;
		break;
		case 'P':
			putchar(Nect.Char[i]);
		break;
		case 'I':
			Nect.Char[i] = getchar();
		break;
		default:
			return;
		break;
	}
	return;
}
char*NullChar(char*Cha,int j){
	int i = 0;
	for(i = 0;i < j;i++){
		Cha[i] = 0;
	}
	return Cha;
}
 
char Ichar(char ch){
	switch(ch){
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '-':
		break;
		default:
			return '0';
		break;
	}
	return ch;
}
int Int(int b){
	switch((char)b){
		case '1':
			b = 1;
		break;
		case '2':
			b = 2;
		break;
		case '3':
			b = 3;
		break;
		case '4':
			b = 4;
		break;
		case '5':
			b = 5;
		break;
		case '6':
			b = 6;
		break;
		case '7':
			b = 7;
		break;
		case '8':
			b = 8;
		break;
		case '9':
			b = 9;
		break;
		default:
			b = 0;
		break;
	}
	return b;
}
 
int user(char token[99999]){
	struct variable*Next = (struct variable*)malloc(sizeof(struct variable));
	Next -> String = (char*)malloc(sizeof(char));
	Next -> str =  (char*)malloc(sizeof(char));
	Next -> String = (char*)token;
	signed int j = 0;
	Next -> Len = strlen(Next -> String);
	for(Next -> i = 0;(Next -> i) <= (Next -> Len);Next -> i++){
		switch(Next -> String[Next -> i]){
			case 'I':
				Next -> r = Int(Next -> String[Next -> i+1]);
			break;
			case 'R':
				if((Next -> String[Next -> i+2]) == '='){
					Nect.Char[Int(Next -> String[Next -> i+1])] = (Next -> String[Next -> i+3]);
					Next -> i += 4;
				}
			break;
			case '+':
				if((Next -> String[Next -> i+1]) == '['){
					Next -> i+= 3;
					Nect.boolean[0] = true;
					Next -> r = Int(Next -> String[Next -> i-1]);
				}
			break;
			case '-':
				if((Next -> String[Next -> i+1]) == '['){
					Next -> i += 3;
					Nect.boolean[1] = true;
					Next -> r = Int(Next -> String[Next -> i-1]);
				}
			break;
			case ']':
				if(Nect.boolean[0] == true){
					Nect.Char[Next -> r] += atol(Next -> str);
					Nect.boolean[0] = false;
				}else if(Nect.boolean[1] == true){
					Nect.Char[Next -> r] -= atol(Next -> str);
					Nect.boolean[1] = false;
				}
				j = 0;
				NullChar(Next -> str , 10);
				/*
				Next -> str[0] = 0;
				Next -> str[1] = 0;
				Next -> str[2] = 0;
				Next -> str[3] = 0;
				Next -> str[4] = 0;
				*/
			break;
			case 'P':
				Next -> r = Int(Next -> String[Next -> i+1]);
			break;
			case 'n':
				Nect.Char[Int(Next -> String[Next -> i+1])] = 0;
			break;
			case 'N':
				for(j = 0;j < 10;j++){
					Nect.Char[j] = 0;
				}
			break;
			
		}
	
		if(Nect.boolean[1] == true || Nect.boolean[0] == true){
			//Nect.Char[Next -> r] -= Int(Next -> String[Next -> i]);
			Next -> str[j++] = Ichar(Next -> String[Next -> i]);
		}else{
			Token(Next -> String[Next -> i],
			Next -> r);
		}
	}
	free(Nect.String);
	free(Nect.str);
	free(Next);
	return 0;
}
 
int main(int argc, char** argv) {
	FILE*fp = NULL;
	int i = 0;
	char*str = (char*)malloc(sizeof(char)*1024);
	if(!(fp = fopen("AAIF.f","r"))){
		printf("%s:%d",__FILE__,__LINE__-1);
		free(str);
		exit(0);
	}
	for(i = 0;!(feof(fp));i++)
		fscanf(fp,"%c",&str[i]);
	user(str);
	fclose(fp);
	free(str);
	return 0;
}

