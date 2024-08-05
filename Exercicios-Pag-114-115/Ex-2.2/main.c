#include <stdio.h>
#include <math.h>

void calc_esfera(float , float *, float *);

int main() {

    float r; // Raio da esfera
    float area; // Area da superficie da esfera
    float volume; // Volume da esfera

    printf("Informe o raio da esfera: ");
    scanf("%f", &r);

    calc_esfera(r, &area, &volume);

    printf("Area da superficie da esfera de raio %.2f: %.2f\n", r, area);
    printf("Volume da esfera de raio %.2f: %.2f\n", r, volume);

    return 0;

}

void calc_esfera(float r, float *area, float *volume) {

    *area = 4*pow(r, 2);
    *volume = (4*pow(r, 3))/3;

}