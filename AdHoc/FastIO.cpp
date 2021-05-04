inline int getint(){
    char ch = getchar(); int x = 0;
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0'; ch = getchar();
    }
    return x;
}
