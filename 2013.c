#include <stdio.h>
#include <string.h>

int stack[100];
int top = 0;

void stack_push(int val){
    if(top == 99)
        return;
    stack[++top] = val;
}

void stack_show(){
    for(int i = 0;i <= top;i++)
        printf("%d ", stack[i]);
}

#define dbg(x) printf("\n<%s:%d> " #x " : %d", __func__, __LINE__, x)

void sorted_merge(int arr[], int l, int m, int u, int aux[]){
    int b = l;
    int j = m + 1;
    int k = 0;
    while(l <= m && j <= u){
        if(arr[l] < arr[j]){
            aux[k] = arr[l];
            l++;
        }
        else {
            aux[k] = arr[j];
            j++;
        }
        k++;
    }

    while(l <= m){
        aux[k] = arr[l];
        k++; l++;
    }
    while(j <= u){
        aux[k] = arr[j];
        k++; j++;
    }

    for(int i = 0;i < k;i++){
        arr[b + i] = aux[i];
    }
}

void merge_sort_nonrecursive(){
    int num;
    printf("\nEnter the number of elements : ");
    scanf("%d", &num);
    int arr[num];
    printf("\nEnter %d elements : ", num);
    for(int i = 0;i < num;i++)
        scanf("%d", &arr[i]);

    printf("\nBefore sorting : ");
    for(int i = 0;i < num;i++)
        printf("%d ", arr[i]);

    int stacks[5][num], sp[5] = {0}, aux[num];

    int start = 0, stop = 1, beg = 2, mid = 3, end = 4;

    stacks[start][sp[start]++] = 0;
    stacks[stop][sp[stop]++] = num - 1;

    while(sp[start] > 0){
        int b = stacks[start][--sp[start]];
        int e = stacks[stop][--sp[stop]];
        int m = (b + e)/2;
        
        stacks[beg][sp[beg]++] = b;
        stacks[mid][sp[mid]++] = m;
        stacks[end][sp[end]++] = e;

        if(b < m){
            stacks[start][sp[start]++] = b;
            stacks[stop][sp[stop]++] = m;
        }
        if(m+1 < e){
            stacks[start][sp[start]++] = m + 1;
            stacks[stop][sp[stop]++] = e;
        }
    }

    while(sp[beg] > 0){
        sorted_merge(arr, stacks[beg][--sp[beg]], stacks[mid][--sp[mid]], 
                stacks[end][--sp[end]], aux);
    }
    
    printf("\nAfter sorting : ");
    for(int i = 0;i < num;i++)
        printf("%d ", arr[i]);
    
}

void largest_string(){
    printf("\nEnter number of strings : ");
    int num;
    scanf("%d", &num);
    if(num < 2){
        printf("\n[Error] Atleast two string are required!");
        return;
    }

    char strings[num][100];
    for(int i = 0;i < num;i++){
        printf("\nEnter string %d : ", i + 1);
        fgets(strings[num], 99, stdin);
    }

    int maxlen = 0, maxidx = 0;
    for(int i = 0;i < num;i++){
        if(maxlen < (int)strlen(strings[i])){
            maxlen = strlen(strings[i]);
            maxidx = i;
        }
    }

    printf("\nThe string with maximum length is : %s", strings[maxidx]);
}

int main(){

    return 0;
}
