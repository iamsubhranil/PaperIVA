#include <stdio.h>
#include <ctype.h>

void largest_num(){
    int a, b, c;
    printf("\nEnter three numbers : ");
    scanf("%d%d%d", &a, &b, &c);
    int res = a > b ? a : b;
    res = res > c ? res : c;
    printf("\nLargest among three : %d", res);
}

void num_1(){
    int input;
    printf("\nEnter the number : ");
    scanf("%d", &input);
    int res = 0, bak = input;
    unsigned long loop = 0;
    while(loop < sizeof(int)*8){
        res += input & 1;
        input >>= 1;
        loop++;
    }
    printf("\nNo of 1's in %d's binary representation is : %d", bak, res);
}

#define SQUARE(x) x*x
void square_test(){
    int a, b;
    printf("\nEnter two numbers : ");
    scanf("%d%d", &a, &b);
    printf("c = %d", SQUARE(a+b));
}

void store_vowels(){
    char file[100];
    printf("\nEnter the filename to read : ");
    scanf("%s", file);

    FILE *fp = fopen(file, "r");
    if(!fp){
        printf("\n[Error] Unable to open file for reading : %s", file);
        return;
    }

    FILE *w = fopen("vowel.txt", "w");
    if(!w){
        printf("\n[Error] Unable to open file for writing : vowel.txt");
        fclose(fp);
        return;
    }

    long bak = 0;
    while(!feof(fp)){
        char c = fgetc(fp);
        if(c == ' '){
            long tmp = ftell(fp);
            fseek(fp, bak, SEEK_SET);
            char ch = fgetc(fp);
            char c = tolower(ch);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                while(ftell(fp) != tmp){
                    fputc(ch, w);
                    ch = fgetc(fp);
                }
                fputc(ch, w);
            }
            fseek(fp, tmp, SEEK_SET);
            bak = tmp;
        }
    }

    fputc(0, w);
    fclose(fp);
    fclose(w);

    printf("\nContents of vowel.txt : ");
    fp = fopen("vowel.txt", "r");
    while(!feof(fp)){
        fputc(fgetc(fp), stdout);
    }
}

int main(){
    printf("\n1. Largest among three");
    printf("\n2. No of 1's in binary");
    printf("\n3. Square macro");
    printf("\n4. Vowel separation : ");
    char ch;
    scanf(" %c", &ch);
    switch(ch){
        case '1':
            {
                largest_num();
            }
            break;
        case '2':
            {
                num_1();
            }
            break;
        case '3':
            {
                square_test();
            }
            break;
        case '4':
            {
                store_vowels();
            }
            break;
        default:
            printf("\nWrong choice!");
            break;
    }
    printf("\n");
    return 0;
}
