#include <stdio.h>
#include <string.h>

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

struct complexnum {
    int x;
    int y;
};

typedef struct complexnum complex;

void complex_show(complex a){
    printf("%d + %di", a.x, a.y);
}

void complex_sum(){
    int ax, ay, bx, by;
    printf("\nEnter the x and y of the first number : ");
    scanf("%d%d", &ax, &ay);
    printf("\nEnter the x and y of the second number : ");
    scanf("%d%d", &bx, &by);
    complex a, b;
    a.x = ax; a.y = ay;
    b.x = bx; b.y = by;
    complex c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;

    printf("\nSum : ");
    complex_show(c);
}

void complex_mult(){
    int ax, ay, bx, by;
    printf("\nEnter the x and y of the first number : ");
    scanf("%d%d", &ax, &ay);
    printf("\nEnter the x and y of the second number : ");
    scanf("%d%d", &bx, &by);
    complex a, b;
    a.x = ax; a.y = ay;
    b.x = bx; b.y = by;
    complex c;
    c.x = a.x * b.x;
    c.y = (a.x * b.y) + (a.y * b.x);
    c.x = -1 * (a.y * b.y);
    printf("\nMultiplication result : ");
    complex_show(c);
}

void complex_run(){
    char ch;
    int run = 1;
    while(run){
        printf("\n1. Sum");
        printf("\n2. Multiply");
        printf("\n3. Exit : ");
        scanf(" %c", &ch);
        switch(ch){
            case '1':
                {
                    complex_sum();
                }
                break;
            case '2':
                {
                    complex_mult();
                }
                break;
            case '3':
                run = 0;
                break;
            default:
                printf("\n[Error] Wrong choice!");
                break;
        }
    }
}

void good_morning1(int argc, char *argv[]){
    printf("\nOutput : ");
    while(--argc)
        printf("%s%c", *++argv, argc > 0 ? ' ' : '\n');
}

void good_morning2(){
    printf("\nOutput : ");
    int argc = 3;
    char *arg[] = {strdup("echo"), strdup("good"), strdup("morning")};
    char **argv = &arg[0];
    while(--argc)
        printf("%s%c", *(++argv), argc > 0 ? ' ' : '\n');
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

int main(int argc, char *argv[]){
    printf("\n1. Reverse string using recursion");
    printf("\n2. Complex");
    printf("\n3. good_morning1");
    printf("\n4. good_morning2");
    printf("\n5. No of 1's in binary representation : ");
    char ch;
    scanf(" %c", &ch);
    switch(ch){
        case '1':
            {
                reverse_string();
            }
            break;
        case '2':
            {
                complex_run();
                break;
            }
        case '3':
            {
                good_morning1(argc, argv);
            }
            break;
        case '4':
            {
                good_morning2();
            }
            break;
        case '5':
            {
                num_1();
            }
            break;
        default:
            printf("\n[Error] Wrong choice!");
            break;
    }
    printf("\n");
    return 0;
}
