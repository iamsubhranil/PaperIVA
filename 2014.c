#include <stdio.h>

int f(int n){
    static int i = 1;
    if(n >= 5)
        return n;
    n = n + i;
    i++;
    return f(n);
}

void f_1(){ 
    printf("\nf(1) : %d", f(1));
}

void number_to_word(){
    int i;
    printf("\nEnter the number : ");
    scanf("%d", &i);
    printf("\nString : ");

    const char *unit[] = {"one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"};
    const char *eleven[] = {"eleven", "twelve", "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen",
        "nineteen"};
    const char *decimal[] = {"ten", "twenty", "thirty", "forty",
        "fifty", "sixty", "seventy", "eighty", "ninety"};
    const char *positional[] = {"hundred", "thousand", "thousand", "lakh", "lakh"};

    if(i < 0){
        printf("minus ");
        i = -i;
    }
    while(i > 0){
        int j = i, printcrore = 0;
        if(j >= 10000000){
            j = j/10000000;
            i -= (j * 10000000);
            printcrore = 1;
        }

        while(j > 0){
            if(j < 10){
                printf("%s ", unit[j - 1]);
                break;
            }
            int pos = 1, pcount = 0;
            while(pos <= j){
                pos *= 10;
                pcount++;
            }
            int divisor = 0;
            if(pcount == 3)
                divisor = 10;
            else if(pcount < 3 || pcount % 2)
                divisor = 100;
            else
                divisor = 10;

            int two_dig = j / (pos / divisor);
            j -= (two_dig * (pos / divisor));
            int d0 = two_dig % 10;
            int d1 = two_dig / 10;
            if(d1 > 0){
                if(d1 == 1 && d0 > 0){
                    printf("%s ", eleven[two_dig - 11]);
                }
                else
                    printf("%s ", decimal[d1 - 1]);
            }
            if(d1 != 1 && d0 > 0){
                printf("%s ", unit[d0 - 1]);
            }
            if(pcount > 2){
                printf("%s ", positional[pcount - 3]);
            }

        }
        if(printcrore)
            printf("crore ");
        else
            break;
    }
}

#define PRINT(int) printf("int = %d\n", int)
#define PRINT1(x, y, z) printf("x = %d\ty = %d\tz = %d\n", x, y, z)
void print_test(){
    printf("\nOutput : \n");
    
    int x = 1, y = 1, z = 1;
    x += y += z;
    PRINT(x < y ? y : x);
    x = y = z = 1;
    ++x || (++y && ++z);
    PRINT1(x, y, z);
    x = y = z = -1;
    (++x && ++y) || ++z;
    PRINT1(x, y, z);
}

void gcd(){
    printf("\nEnter two numbers : ");
    int x, y, m, n;
    scanf("%d %d", &x, &y);
    m = x; n = y;
    while(m != n){
        if(m > n)
            m = m - n;
        else
            n = n - m;
    }
    printf("Result : %d", n);
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

void div_by_11(){
    int n;
    printf("\nEnter the number : ");
    scanf("%d", &n);

    int pos = 1, bak = n;
    int oddsum = 0, evensum = 0;
    if(n < 0)
        n = -n;
    while(n != 0){
        int dig = n % 10;
        if(pos % 2)
            oddsum += dig;
        else
            evensum += dig;
        pos++;
        n /= 10;
    }
    if(oddsum == evensum){
        printf("\n%d is divisible by 11!", bak);
    }
    else
        printf("\n%d is not divisible by 11!", bak);
}

int main(){
    printf("\n1. Find f(1)");
    printf("\n2. Number to word");
    printf("\n3. Find output of PRINT");
    printf("\n4. GCD");
    printf("\n5. No of 1's in binary");
    printf("\n6. Divisibility by 11 : ");
    char ch;
    scanf(" %c", &ch);
    switch(ch){
        case '1':
            {
                f_1();
            }
            break;
        case '2':
            {
                number_to_word();
            }
            break;
        case '3':
            {
                print_test();
            }
            break;
        case '4':
            {
                gcd();
            }
            break;
        case '5':
            {
                num_1();
            }
            break;
        case '6':
            {
                div_by_11();
            }
            break;
        default:
            printf("\n[Error] Wrong choice!");
            break;
    }
    printf("\n");
    return 0;
}
