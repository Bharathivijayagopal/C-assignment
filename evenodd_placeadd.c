#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define FORMAT "YYMMDD-nnnC"
int main(void)
{
    char id_number[256];
    char format[100] = FORMAT;
    char string[sizeof(FORMAT) + 1] = {0};
    int place_value = 0, even = 0, odd = 0, check_digit;
    unsigned long long int personal_number, person_number;
    printf("Enter Personnummer in the format of %s: ", FORMAT); // Get ibnput -Personnummer in specific format
    fgets(string, sizeof(FORMAT) + 1, stdin);
    // validate the entered number is in correct format or not before performing luhn computation :string[strlen(string) - 1] = '\0'; // fgets captures the newline also and we don't want to have it in the string
    int i = 0;
    bool is_correct = true;

    while (i < sizeof(FORMAT) - 1)
    {
        if (isalpha(format[i]))
        {
            if (!isdigit(string[i]))
            {
                is_correct = false;
                break;
            }
        }
        else
        {
            if (format[i] != string[i])
            {
                is_correct = false;
                break;
            }
        }
        i++;
    }

    printf("The format of the entered date and time is%s correct!\n", is_correct ? "" : " not");
    int input_string, modified_num_string = 0;
    for (input_string = 0; string[input_string]; input_string++)
    {
        if (string[input_string] >= '0' && string[input_string] <= '9')
        {

            string[modified_num_string] = string[input_string];
            modified_num_string++;
        }
    }
    string[modified_num_string] = '\0';
    printf("string after modification %s\n", string);
    unsigned long long int ret = strtoll(string, NULL, 0);
    check_digit = ret % 10;
    person_number = (ret) / 10;
    sprintf(id_number, "%llu", person_number);
    while (id_number[place_value] != '\0')
    {
        if (place_value % 2 == 0)
        {
            int odd_value = ((id_number[place_value] - '0') * 2);
            if (odd_value >= 10)
            {
                int upd_digit = odd_value % 10;
                int odd_number = odd_value / 10;
                int new_value = upd_digit + odd_number;
                odd = odd + new_value;
            }
            else
                odd = odd + odd_value;
        }

        else
        {
            int even_value = ((id_number[place_value] - '0') * 1);
            if (even_value >= 10)
            {
                int upd_digit = even_value % 10;
                int even_number = even_value / 10;
                int new_value = upd_digit + even_number;
                even = even + new_value;
            }
            else
                even = even + even_value;
        }
        place_value++;
    }
    printf("sum of odd places=  %d\n", odd);
    printf(" sum of even places=  %d\n", even);
    int final_value = even + odd;
    int control_digit = (10 - (final_value % 10)) % 10; //calculate the control digit which is checked with the entered number's check digit.

    if (control_digit == check_digit)
    {
        printf("The entered Personnummer is valid");
    }
    else
    {
        printf("The entered Personnummer is invalid");
    }
    return 0;
}
