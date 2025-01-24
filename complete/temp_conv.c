#include <stdio.h>
#define MAX_TEMP 300
#define TEMP_INC 20

double c_to_f(double c_val, double f_val){
    if (c_val < -273.15) 
        return (f_val - 32.0) * 5.0 / 9.0;
    else 
        return c_val * 9.0 / 5.0 + 32.0;
}
int main(){
    double temp_val = 0;
    for (temp_val = -40.0; temp_val < MAX_TEMP; temp_val += TEMP_INC){
        printf("C: %7.2f, F: %7.2f\n", temp_val, c_to_f(temp_val, 0.0));
    }
    for (temp_val = -40.0; temp_val < MAX_TEMP; temp_val += TEMP_INC){
        printf(
            "F: %7.2f, C: %7.2f\n", 
            temp_val, c_to_f(-274.0, temp_val)
        );
    }
    return 0;
}

