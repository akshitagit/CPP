#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>

#define PRINCIPAL 199
#define TOTAL 240

const char fich[12] = "fichash.txt"; //Filename

FILE *fh = NULL;

using namespace std;

typedef struct{
    char code[7];
    char author[41];
    char title [41];
}Book;

#define DISPLACE(n) ((n)*sizeof(Book))

void create(); //write records with the "*" field to indicate that they are free
void buy();
void sell();
void query();
void collisions(Book bk);
int indexSynonyms(const char c[]);
int Hash(char c[]);
long transformKey(const char c[]);
void print(Book bk);

int main(){
    char option;
    fh = fopen(fich,"rb");
    if(fh == NULL){
        puts("the file will be created");
        create();
    }
    else
        fh=NULL;
    do{
        puts("1.- Buy");
        puts("2.- Sell");
        puts("3.- Query");
        puts("4.- Exit");
        do{
            puts("Choose an option");
            cin >> option;
        }while(option < '1' || option > '4');
        switch(option){
            case '1':
                buy();
            break;
            case '2':
                sell();
            break;
            case '3':
                query();
            break;
        }
    }while(option != '4');
    if(fh != NULL)
        fclose(fh);
    return 0;
}

void create(){
    Book bk;
    int i;
    fh = fopen(fich,"wb+");
    strcpy(bk.code,"*");
    for(i =1; i<= TOTAL; i++)
        fwrite(&bk, sizeof(bk), 1, fh);
    fclose(fh);
    fh = NULL;
    cout << endl;
}

void buy(){
    Book bk, bkar;
    long position;
    if(fh == NULL)
        fh = fopen(fich,"rb+");
    cout << "Code: ";
    cin >> bk.code;
    cout << "Author: ";
    cin >> bk.author;
    cout << "Title: ";
    cin >> bk.title;
    position = Hash(bk.code);
    position = DISPLACE(position);

    fseek(fh, position, SEEK_SET);
    fread(&bkar, sizeof(Book), 1, fh);

    if(strcmp(bkar.code, "*") == 0){
        fseek(fh, -sizeof(Book), SEEK_CUR);
        fwrite(&bk, sizeof(Book), 1 , fh);
        cout << "record recorded at address: " << position << endl;
    } else if(strcmp(bk.code, bkar.code) == 0){
        puts("repeated code, check data");
        return;
    }else
        collisions(bk);
    fflush(fh);
    cout << endl;
}

void sell(){
    Book bk;
    char code[7], r;
    long position;

    if(fh == NULL)
        fh = fopen(fich,"rb+");

    cout << "code: ";
    cin >> code;
    position = Hash(code);
    position = DISPLACE(position);

    fseek(fh, position, SEEK_SET);
    fread(&bk, sizeof(Book), 1, fh);

    if(strcmp(bk.code, code) != 0)
        position = indexSynonyms(code);
    if(position != -1){
        print(bk);
        cout << "The data is correct? (Y/N): ";
        cin >> r;
        if(toupper(r) == 'Y'){
            strcpy(bk.code, "*");
            fseek(fh, -sizeof(Book), SEEK_CUR);
            fwrite(&bk,sizeof(Book), 1, fh);
        }
    }else
        puts("There are no records with that code");
    fflush(fh);
    cout << endl;
}

void query(){
    Book bk;
    char code[7];
    long position;

    if(fh == NULL)
        fh = fopen(fich, "rb+");

    cout << "Code: ";
    cin >> code;
    position = Hash(code);
    position = DISPLACE(position);

    fseek(fh, position, SEEK_SET);
    fread(&bk, sizeof(Book), 1, fh);

    if(strcmp(bk.code, code) == 0)
        print(bk);
    else{
        int position;
        position = indexSynonyms(code);
        if(position != -1){
            fseek(fh, -sizeof(Book), SEEK_CUR);
            fread(&bk, sizeof(Book), 1, fh);
            print(bk);
        }else
            puts("There are no records with that code");
    }
}

void collisions(Book bk){
    Book book;
    int position = DISPLACE(PRINCIPAL);
    int j = PRINCIPAL;
    bool fnd;

    fseek(fh, position, SEEK_SET);
    fnd = 0;

    while((j < TOTAL) && !fnd){
        fread(&book.code, sizeof(Book), 1, fh);
        j++;
        if(strcmp(book.code,"*") == 0){
            fnd = 1;
            fseek(fh, -sizeof(Book), SEEK_CUR);
            fwrite(&bk, sizeof(Book), 1, fh);
            puts("data saved in the synonymous area");
        }
    }
    if(!fnd)
        puts("full synonym area");
    fflush(fh);
    cout << endl;
}

int indexSynonyms(const char c[]){
    Book bk;
    int position = DISPLACE(PRINCIPAL);
    int j = PRINCIPAL;
    bool fnd;

    fseek(fh, position, SEEK_SET);
    fnd = 0;

    while((j < TOTAL) && !fnd){
        fread(&bk, sizeof(Book), 1, fh);
        j++;
        if(strcmp(bk.code, c) == 0)
            fnd = 1;
    }
    if(!fnd)
        j = -1;
    return j;
}

int Hash(char c[]){
    int i, sum = 0;
    for(i = 0; i < strlen(c); i++)
        c[i] = toupper(c[i]);
    return transformKey(c) % PRINCIPAL;
}

long transformKey(const char* key){
    int j;
    long d;

    d = 0;
    for(j = 0; j< strlen(key); j++)
        d = d * 27 + key[j];
    if(d < 0)
        d = -d;
    return d;
}

void print(Book bk){
    system("clear");
    cout << "Code: " << bk.code << '\n';
    cout << "Author: " << bk.author << '\n';
    cout << "Title: " << bk.title << endl;
}
