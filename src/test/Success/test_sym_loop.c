int main(){
    // for loop
    int i;
    for(int i = 0; i < 5; i++){
        int i = 5;
        int y = i + 1;
    }

    // do while
    int j = 8;
    do{
        int i = 1;
        j--;
    } while (j > 0);

    // while
    int x = 10;
    while(x < 0){
        x--;
        int x = 3;
    }

    // nest
    int l1 = 1;
    for(int l2 = 1; l2 < 10; l2++, l1++){
        int l3 = l1 + l2;
        do{
            l3++;
            while((l1 + l2 + l3)< 20){
                l3 ++;
            }
        }while (l3 < 10);
    }
}