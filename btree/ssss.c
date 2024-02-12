#include <stdio.h>

const char* hello(const char* who){
    static char buffer[100];
    snprintf(buffer, sizeof(buffer), "Hello %s", who);
    return buffer;
}
int main(){
    char* b = "ht";
    char* s = hello(b);
    printf("%s",s);
    return 0;
}