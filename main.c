//
//  Enigma Cypher Machine
/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
//  Created by Nicola di Gruttola Giardino.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "logo.h"
#define MSG 80
#define NROTORS 3
#define ALPHA 26
/*the input is the international alphabet
 those are the rotors used to encode,
 in this case 3 rotors*/
char alphabet[ALPHA]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
char rotor1[ALPHA]=  {"EKMFLGDQVZNTOWYHXUSPAIBRCJ"};
char rotor2[ALPHA]=  {"AJDKSIRUXBLHWTMCQGZNPYFVOE"};
char rotor3[ALPHA]=  {"BDFHJLCPRTXVZNYEIWGAKMUSQO"};
/*reflector of the machine*/
char reflector[ALPHA]=
                     {"YRUHQSLDPXNGOKMIEBFZCWVJAT"};
//the notch for the rotors
char notch[NROTORS]={"QEV"};
char plugboard[8]={""};
int start[3]={1,1,1};
char text[MSG], encoded[MSG];

char enigma(char c){
    int i,x;
    char t,u,v;
    //scrambling the letters
    if (isalpha(c)) {
        //scramble in plugboard
        for (i=0; i<8; i+=2) {
            if(c==plugboard[i])
                c=plugboard[i+1];
            else if(c==plugboard[i+1])
                c=plugboard[i];
        }
    //passing through the rotors
        for (x=0; c!=alphabet[x]; x++) {}
        c=rotor3[x];
        for (x=0; c!=alphabet[x]; x++) {}
        c=rotor2[x];
        for (x=0; c!=alphabet[x]; x++) {}
        c=rotor1[x];
        for (x=0; c!=alphabet[x]; x++) {}
        c=reflector[x];
        //reverse shift
        for (x=0; c!=rotor1[x]; x++) {}
        c=alphabet[x];
        for (x=0; c!=rotor2[x]; x++) {}
        c=alphabet[x];
        for (x=0; c!=rotor3[x]; x++) {}
        c=alphabet[x];
        //scramble in plugboard
        for (i=0; i<8; i+=2) {
            if(c==plugboard[i])
                c=plugboard[i+1];
            else if(c==plugboard[i+1])
                c=plugboard[i];
                }
        }
    //setting up the three rotors
    if (start[2]==27) {
        start[2]=1;
    }
    if (start[1]==27) {
        v=rotor3[25];
        for(i=(ALPHA-1); i >0; i--){
            rotor3[i]=rotor3[i-1];
        }
        rotor3[i]=v;
        start[2]++;
        start[1]=1;
    }
    if (start[0]==27) {
        u=rotor2[25];
        for(i=(ALPHA-1); i >0; i--){
            rotor2[i]=rotor2[i-1];
        }
        rotor2[i]=u;
        start[1]++;
        start[0]=1;
    }
    t=rotor1[25];
    for (i =(ALPHA-1); i >0; i--)
    {
        rotor1[i] = rotor1[i-1];
    }
    rotor1[i]=t;
    start[0]++;
    //checking notch for 1st rotor
    if (rotor1[0]==notch[0]) {
        u=rotor2[25];
        for(i=(ALPHA-1); i >0; i--){
            rotor2[i]=rotor2[i-1];
        }
        rotor2[i]=t;
        start[1]++;
    }
    //checking the same for the 2nd
    if (rotor2[0]==notch[1]) {
        u=rotor3[25];
        for(i=(ALPHA-1); i >0; i--){
            rotor3[i]=rotor3[i-1];
        }
        rotor3[i]=t;
        start[2]++;
    }
    return c;
}

/*take a string and produce the encoded text recalling the previous functions*/
void character(){
    int i=0;
    int c;
    printf("type your text to encode (max 80 chars):\n");
    while((c=getchar()) !=EOF)
    {
        if (c == '\n') {
            if ( i) {
                break;//trailing newline
            }
            else {
                continue;//leading newline
            }
        }
        text[i] = toupper(c);
        i++;
        if (i>=MSG)
            break;
    }
    text[i] = '\0';
    for (i=0; i<strlen(text); i++)
        encoded[i] = enigma(text[i]);
    encoded[i] = '\0';
    printf("your text: %s\n",text);
    printf("encoded text:%s\n", encoded);
}

void startpos(){
    int x,i=0,c;
    char t,u,v,s[3];
    //initial set up of the rotors
    //choosing the startposition
    printf("starting letters (in sequence): ");
    while((c=getchar()) !=EOF)
    {
        if (c == '\n') {
            if ( i) {
                break;//trailing newline
            }
            else {
                continue;//leading newline
            }
        }
        s[i] = toupper(c);
        i++;
        if (i>=3) {
            break;
        }
    }
    s[i]='\0';
    
    for (x=0; s[0]!=alphabet[x]; x++) {}
    start[0]=x+1;
    
    for (x=0; s[1]!=alphabet[x]; x++) {}
    start[1]=x+1;
    
    for (x=0; s[2]!=alphabet[x]; x++) {}
    start[2]=x+1;
    
    //initial stepfwd
    //first rotor
    if (start[0]>1) {
        i=0;
        for(i=0;i<(start[0]-1);i++) {
            t=rotor1[25];
            for (x =(ALPHA-1); x >0; x--)
            {
                rotor1[x] = rotor1[x-1];
            }
            rotor1[x]=t;
        }
    }
    
    //second rotor
    if (start[1]>1) {
        for (i=0; i<(start[1]-1); i++) {
            u=rotor2[25];
            for(x=(ALPHA-1); x >0; x--){
                rotor2[x]=rotor2[x-1];
            }
            rotor2[x]=u;
        }
    }
    
    //third rotor
    if (start[2]>1) {
        for (i=0; i<(start[2]-1); i++) {
            v=rotor3[25];
            for(x=(ALPHA-1); x >0; x--){
                rotor3[x]=rotor3[x-1];
            }
            rotor3[x]=v;
        }
    }
}

void setplug(){
    int j=0;
    int c;
    printf("Give me your plugboard, put the letters in pairs. remember not to use twice the same letter.\n");
    printf("Example: if you want C to be swapped with D and Q with T type 'CDQT'.\n");
    printf("You can give me a max of 8 letters and a min of 2:");
    while((c=getchar())!=EOF){
        if (c == '\n') {
            if (j) {
                break;//trailing newline
            }
            else {
                continue;//leading newline
            }
        }
        plugboard[j]=toupper(c);
            j++;
        if (j>=8) {
            break;
        }
    }
    plugboard[j]='\0';
}

void InitEnigma(){
    int i;
    do{
        printf(" Press 1 for user settings or 0 for default settings: ");
        scanf("%d",&i);
    }while(i!=0 && i!=1);
    if(i==1){
        setplug();
        startpos();
        printf("start position: %c %c %c, plugboard:'%s'\n",alphabet[start[0]-1],alphabet[start[1]-1], alphabet[start[2]-1], plugboard);
    }
    if(i==0)
        printf("start position: %c %c %c, plugboard:'%s'\n",alphabet[start[0]-1],alphabet[start[1]-1], alphabet[start[2]-1], plugboard);
}

void main(int argc, char *argv[]) {
    printf("%s\n",EnigmaLogo);
    InitEnigma();
    character();
}
