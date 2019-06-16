int a;
int b = a;
int c = 1;

int add(){
    a = 5;
    return a + b;
}

void main(){
    int d = add();

    // loop
    int i = 0, sum = 0;
    for(int i = 0; i <= 9; i++){
        sum = sum + i;
    }

    while(i <= 19){
        sum = sum + i;
        i++;
        break;
    }

    // switch
    switch(i){
        case 19:
            int sum = 0;
            sum = sum + 19;
        case 9:
            sum = sum + 9;
        default:
            break;
    }

    // if
    if( i == 19)
        sum = sum + 19;
    else
    if(i == 9)
        sum = sum + 9;
    else if(i == 10)
        sum = sum + 10;
    else
        sum = sum + 1;

    // 带括号
    if( i == 19){
        int i = 1;
        sum = sum + 1;
    } else if(i == 1){
        int i = 2;
        sum = sum + i;
    } else {
        sum = sum + 1;
    }

    // array
    int a[100];
    a[0] = 1;
    a[1] = 2;

}
