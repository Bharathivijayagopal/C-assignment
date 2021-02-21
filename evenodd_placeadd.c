#include <stdio.h>

int main(void)
{
    char id_number[20];
    int place_value = 0, even = 0, odd = 0, person_number;
    printf("Enter the personal identification number (person_number) in YYMMDD-NNNC format : ");
    scanf("%d", &person_number);
    sprintf(id_number, "%d", person_number);
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
    int final_value = even + odd;
    int control_digit = (10 - (final_value % 10)) % 10;
    printf("%d\n", control_digit);

    return 0;
}