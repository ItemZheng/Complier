int puts();
int printf();

int a = 1;

int fact(int n){
    int res = 1;
    if(n > 1){
        res = n * fact(n - 1);
    }
    return res;
}

int main(){
    int xxxx = a;

    puts("Hello World");

    int input = 1;

    printf("Test Access to Global\n");
    printf("a = %d\n", a);

    printf("Test local variable: \n");
    int a = 3;
    printf("a = %d\n", a);

    printf("Test array access: \n");
    int arr[3] = {3, 4, 5};
    printf("arr[0]: %d\n", arr[0]);
    printf("arr[1]: %d\n", arr[1]);
    printf("arr[2]: %d\n", arr[2]);

    printf("DO-WHILE and WHILE and FOR loop to 10:\n");
    printf("Do While: ");
    int time = 0;
    do{
        printf("%d ", time);
        time = time + 1;
    } while (time < 10);
    printf("\n");

    printf("While: ");
    time = 0;
    while(time < 10){
        printf("%d ", time);
        time = time + 1;
    }
    printf("\n");

    printf("For: ");
    for(int i = 0; i < 10; i = i + 1){
        printf("%d ", i);
    }
    printf("\n");

    printf("Test switch: according input to print: \n");
    switch (input){
        case 1:
            printf("One\n");
        case 2:
            printf("Two\n");
            break;
        case 3:
            printf("Three\n");
            break;
        default:
            printf("Number not belong to 1 2 3\n");
            break;
    }

    printf("Test if: ");
    if(input > 3 ){
        printf("Input > 3\n");
    } else if(input > 0){
        printf("Input > 0 and Input <= 3\n");
    } else {
        printf("Input <= 0\n");
    }

    printf("Test function(Recursion): 5!\n");
    printf("5! = %d\n", fact(5));

    printf("Constant Fold\n");
    int c = 1 + 5 * 6 / 2;
    printf("See Code\n");
}