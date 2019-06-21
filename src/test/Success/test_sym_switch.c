int putchar(char c);

int main(){
    int x = 3;
    putchar('H');
    putchar('e');
    putchar('l');
    putchar('l');
    putchar('o');
    putchar(' ');
    putchar('w');
    putchar('o');
    putchar('r');
    putchar('l');
    putchar('d');

    switch (x){
        case 3:
            int y = 2;
            x = y;
            break;
        case 2:
            break;
    }
}