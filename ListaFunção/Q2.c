#include <stdio.h>

int subtrai(int a, int b, int c) {
    return a - b - c;
}

int main() {
    int x, y, z, resultado;
    
    scanf("%d %d %d", &x, &y, &z);
    resultado = subtrai(x, y, z);
    printf("%d\n", resultado);
    
    return 0;
}
