/**
 * @file evenodd_placeadd.c
 * @author Bharathi Vijayagopal (bharathivijayagopal@gmail.com)
 * @brief This Program gets the input of "Personal identity number (Personnummer) from user and checks whether it is valid or not
 *        This also validates whether the entered number is valid as per the specific format.If not, it tell the user that entered 
 *        number is in a wrong format.
 *        This works according to Luhn algorithm which checks whether  the last digit of the entered number matches with control digit
 *        calculated by checksum operations of digits in even and odd places .
 * @version 0.1
 * @date 2021-02-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#define FORMAT "YYMMDD-nnnC"
int main(void)
{
    char id_number[256];
    char format[100] = FORMAT;
    char string[sizeof(FORMAT) + 1] = {0};
    int place_value = 0, even = 0, odd = 0, check_digit;
    unsigned long long int updated_person_number, person_number;
    // Get input "Personnummer" from user  in specific format

    printf("Enter Personnummer in the format of %s: ", FORMAT);
    fgets(string, sizeof(FORMAT) + 1, stdin);
    string[strlen(string) - 1] = '\0';
    // validate the entered number is in correct format or not before performing luhn computation :
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
    if (is_correct == true)
    // validation of personnummer happens only if given format is correct else it exits and says enter the number in correct format:
    {

        int input_string, modified_num_string = 0;

        // removes the special character '-' from entered personnummer and stores it in string
        for (input_string = 0; string[input_string]; input_string++)
        {
            if (string[input_string] >= '0' && string[input_string] <= '9')
            {

                string[modified_num_string] = string[input_string];
                modified_num_string++;
            }
        }
        string[modified_num_string] = '\0';

        // printf("string after modification %s\n", string);
        //converts the string to unsigned long long integer to perform Luhn algorithm checksum of digits

        unsigned long long int person_number = strtoll(string, NULL, 0);
        check_digit = person_number % 10;
        updated_person_number = (person_number) / 10;
        sprintf(id_number, "%llu", updated_person_number);

        /* if placevalue is odd, multiply  the digit in placevalue by 2  or if place value is even, multiply the 
            digit in place value by 1. Then add all the values of odd and even respectively. */
        while (id_number[place_value] != '\0')
        {
            if (place_value % 2 == 0)
            {
                int odd_value = ((id_number[place_value] - '0') * 2);

                /* if multiplied value is greater than 9, then sum of digits has to be added and kept as the value. For example
                if digit is 8 , then( 8*2=10, then 10 becomes 1+0=1)*/

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
        // check the checksum computation works properly with even and odd values to verify the working of algorithm

        // printf("sum of odd places=  %d\n", odd);
        //printf(" sum of even places=  %d\n", even);
        int final_value = even + odd;

        // validating the personnnummer
        int control_digit = (10 - (final_value % 10)) % 10; //calculate the control digit which is checked with the entered number's check digit.
                                                            // printf("check digit is %d\n", control_digit);

        if (control_digit == check_digit)
        {
            printf("The entered Personnummer is valid");
        }
        else
        {
            printf("The entered Personnummer is invalid");
        }
    }
    else
    {
        printf("Please enter the personnummer in the specified format (YYMMDD-cccN)");
    }
    return 0;
}
