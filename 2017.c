#include <stdio.h>
#include <string.h>

void print_source(const char *execname){
    char filename[strlen(execname) + 3];
    size_t i = 0;
    while(execname[i] != '.' && execname[i] != '\0'){
        filename[i] = execname[i];
        i++;
    }
    filename[i++] = '.';
    filename[i++] = 'c';
    filename[i] = '\0';

    FILE *fp = fopen(filename, "r");
    if(!fp){
        printf("[Error] Unable to open file for reading %s!", filename);
        return;
    }
    printf("\nSource : \n");
    while(!feof(fp))
        fputc(fgetc(fp), stdout);
    printf("\n");
    fclose(fp);
}

void reverse_string_rec(char *str, size_t pointer){
    if(str[pointer] == '\0')
        return;

    reverse_string_rec(str, pointer+1);
    char c = str[pointer];
    size_t i = pointer;
    for(;str[i] != '\0';i++)
        str[i] = str[i+1];
    str[i - 1] = c;
}

void reverse_string(){
    char line[100];
    printf("\nEnter the string : ");
    char c;
    while((c = getchar()) != '\n' && c != EOF);
    fflush(stdin);
    fgets(line, 99, stdin); 
    reverse_string_rec(line, 0);
    printf("\nReversed string : %s", line);
}

void one_to_hundred_rec(int i){
    if(i == 0)
        return;
    one_to_hundred_rec(i - 1);
    printf("%d ", i);
}

void one_to_hundred(){
    printf("\nOutput : \n");
    one_to_hundred_rec(100);
}

int main(int argc, char *argv[]){
    (void)argc;
    printf("\n1. Print source");
    printf("\n2. Reverse string using recursion");
    printf("\n3. One to hundred using recursion : ");
    char ch;
    scanf("%c", &ch);
    switch(ch){
        case '1':
            print_source(argv[0]);
            break;
        case '2':
            {
                reverse_string();
            }
            break;
        case '3':
            one_to_hundred();
            break;
        default:
            printf("\nWrong choice!");
            break;
    }
    printf("\n");
    return 0;
}
