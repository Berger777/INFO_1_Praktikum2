#include <stdio.h>
#include <string.h>

//Funktionsdeklaration
int caeserVerschluesseleBitte(int value, int verschiebungsindex);
void caeserEntschluesselung();
void caeserEntschluesselungWithParam(char in[1024]);


//Funktionen
void gebeAlleZahlenAus(int n){
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0){
            printf("%d\n",i);
        }
    }
}

void gebePrimzahlenAus(int n){
    int isPrime;
    for (int i = 1; i <= n; i+=2) {   //Alle Vielfachen von Zwei überspringen
        //printf("Zahl wird gecheckt: %d\n", i);w
        isPrime = 1;
        for (int j = 3; j*j <= i; ++j) {
            if(i % j == 0){
                isPrime = 0;
            }
        }
        if (isPrime == 1){
            printf("%d ist eine Primzahl!\n",i);
        }
    }
}

void caeserVerschluesselung(){
    char input[1024];
    int verschiebungsindex = -27;
    char output[1024] = {};
    int charValue = 0;
    int newValue;

    printf("Geben Sie den zu verschluesselenden Text ein!:\n");
    fgets(input,1024,stdin);

    for (int i = 0; i < strlen(input)-1; ++i) {
        charValue = (int) input[i];
        newValue = caeserVerschluesseleBitte(charValue, verschiebungsindex);
        //printf("%c\n",newValue);
        output[i] = newValue;
    }
    printf("%s",output);
}

int caeserVerschluesseleBitte(int charvalue, int verschiebungsindex) {
    int newCharVal;

    if(charvalue >= 65 && charvalue <=90){  //Großbuchstabe
        newCharVal = charvalue+verschiebungsindex;

        if (newCharVal < 65) {
            int tmp = -(newCharVal - 65) % 26; //wir sind tmp unter a
            newCharVal = 91 - tmp;
        } else if (newCharVal > 90) {
            int tmp = (newCharVal - 90) % 26; //wir sind tmp ueber z
            newCharVal = 64 + tmp;
        }

    }else if(charvalue >= 97 && charvalue <= 122) {  //Kleinbuchstabe
        newCharVal = charvalue + verschiebungsindex;

        if (newCharVal < 97) {
            int tmp = -(newCharVal - 97) % 26; //wir sind tmp unter a
            newCharVal = 123 - tmp;
        } else if (newCharVal > 122) {
            int tmp = (newCharVal - 122) % 26; //wir sind tmp ueber z
            newCharVal = 96 + tmp;
        }
    }else if(charvalue == '\n'){
        printf(" ");
    }else{
        newCharVal = charvalue;
    }
    return newCharVal;
}


void caeserEntschluesselungWithParam(char in[1024]) {
    int verschiebungsindex = 0;
    for (int i = 1; i < 26; ++i) {
        verschiebungsindex = i;
        printf("Index %d: ",verschiebungsindex);
        for (int j = 0; j < strlen(in); ++j) {
            printf("%c",caeserVerschluesseleBitte(in[j],verschiebungsindex));
        }
        printf("\n");
    }

}

void caeserEntschluesselung() {
    char input[1024];
    int verschiebungsindex = 0;
    printf("Geben Sie den zu entschluesselenden Text ein!:\n");
    fgets(input, 1024, stdin);
    for (int i = 1; i < 26; ++i) {
        verschiebungsindex = i;
        printf("Verschiebungsindex: %d: ", verschiebungsindex);
        for (int j = 0; j < strlen(input) - 1; ++j) {
            printf("%c", caeserVerschluesseleBitte(input[j], verschiebungsindex));
        }
        printf("\n");
    }
}

int main() {
    printf("Praktikum 2!\n\n");
    int ZAHLEN_BIS = 1000000;
    char test[1024] = "Ebowifzebk Dirbzhtrkpze! Pfb exybk afb Sbopzeirbppbirkd\n"
                      "dbhkxzhq rka ybhljjbk yxia bfk Gly-Xkdbylq slj xjbofhxkfpzebk\n"
                      "Dbebfjafbkpq.";
    //gebeAlleZahlenAus(ZAHLEN_BIS);
    //gebePrimzahlenAus(ZAHLEN_BIS);
    //caeserVerschluesselung("test",3);
    //caeserEntschluesselung();
    caeserEntschluesselungWithParam(test);
    return 0;
}


