#include <stdio.h>

float celsius_to_farenheit(float celsius){
    return (9.0 / 5.0) * celsius + 32.0;
}

float farenheit_to_celsius(float farenheit){
    return (5.0 / 9.0) * (farenheit - 32);
}

float celsius_to_kelvin(float celsius){
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin){
    return kelvin - 273.15;
}

void categorize_temperature(float celsius){
    // print advisory message based on given temp in celsius

    if(celsius <= 0){
        printf("Temperature Category: Freezing \nWeather advisory: Make sure to wear cold-weather gear or stay inside. \n");
    }else if(celsius <= 10){
        printf("Temperature Category: Cold \nWeather advisory: Wear a jacket. \n");
    }else if(celsius <= 25){
        printf("Temperature Category: Comfortable\nWeather advisory: It's a great day to be outside! \n");
    }else if(celsius <= 35){
        printf("Temperature Category: Hot\nWeather advisory: Wear a hat or sunscreen. \n");
    }else{
        printf("Temperature Category: Extreme Heat\nWeather advisory: Wear a hat and suncreen, and bring plenty of water, or stay indoors. \n");
    }
}

int main(){
    
    // get user input
    printf("Enter the temperature: ");
    float input_temp;
    int is_input_valid_num = scanf(" %f", &input_temp);
    
    // re-prompt the user until they enter a valid input temp
    while (!is_input_valid_num){
        getchar(); // clear out a \n from the input stream, left behind for some reason
        printf("Enter a valid, numeric value. \n");
        printf("Enter the temperature: ");
        is_input_valid_num = scanf(" %f", &input_temp);
    }

    // get input unit
    int input_curr_unit;
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    is_input_valid_num = scanf(" %d", &input_curr_unit);

    // input check the input unit
    while (!is_input_valid_num || input_curr_unit < 1 || input_curr_unit > 3){
        getchar(); // clear out a \n from the input stream, left behind for some reason
        printf("Enter a valid integer. \n");
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        is_input_valid_num = scanf(" %d", &input_curr_unit);
    }

    // get output unit
    int output_unit;
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    is_input_valid_num = scanf(" %d", &output_unit);

    // input check the output unit
    while (!is_input_valid_num || output_unit < 1 || output_unit > 3 || input_curr_unit == output_unit){
        getchar(); // clear out a \n from the input stream, left behind for some reason
        if(input_curr_unit == output_unit){
            printf("Output unit cannot be the same as the input unit. \n");
        }else{
            printf("Enter a valid integer. \n");
        }
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        is_input_valid_num = scanf(" %d", &output_unit);
    }

    // convert input to celsius, unless it already is
    float temperature_celsius = input_temp;
    if(input_curr_unit == 2){
        temperature_celsius = farenheit_to_celsius(input_temp);
    }else if (input_curr_unit == 3){
        temperature_celsius = kelvin_to_celsius(input_temp);
    }

    // edge case, output cannot fall below absolute zero
    if(temperature_celsius < -273.15){
        printf("Input temperature is less than absolute zero. Run the program again with correct values. \n");
        return 0;
    }

    // get output in needed units
    float converted_temp = temperature_celsius;
    if(output_unit == 2){
        converted_temp = celsius_to_farenheit(temperature_celsius);
    }else if(output_unit == 3){
        converted_temp = celsius_to_kelvin(temperature_celsius);
    }

    // print outputs
    printf("Converted temperature: %f", converted_temp);
    // print unit
    switch(output_unit){
        case(1):
            printf("C");
            break;
        case(2):
            printf("F");
            break;
        case(3):
            printf("K");
            break;
    }
    printf("\n"); // finish printing converted temperature line
    categorize_temperature(temperature_celsius);

    return 0;
}