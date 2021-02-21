#include <stdio.h>
#include <stdint.h>
uint16_t person_nummer;
int length_person_nummer;
int sum_even_digits;
int even_place_value;
int odd_place_value;
int main(void)
{
    printf("Enter your personal identification number(Personnummer): ");
    scanf("%ld", &person_nummer);
    length_person_nummer = len(person_nummer);
    if (validate_personnummer(person_nummer) == 1)
    {
        printf("The enetered number is a valid personnummer \n");
    }
    else
    {
        printf("The enetered number is invalid personnummer \n");
    }

    return 0;
}
int validate_personnummer()
{
    for (int count = 0; count < (length_person_nummer - 2); count++)
    {
        for (int count = 1; count < (length_person_nummer - 1); count++)
        {
            even_place_value = person_nummer[count] * 1;
            int temp_value = even_place_value while (temp_value >= 10)
            {
                int remainder = temp_value % 10;
                int sum = sum + remainder;
                temp_value /= 10;
            }

            if (even_place_value >= 10)
            {
                even_place_value = even_place_value[0] + even_place_value[1];
            }
            sum_even_digits = sum_even_digits + even_place_value;
            count = count + 2;
        }
        odd_place_value = person_nummer[count] * 2;
        if (even_place_value >= 10)
        {
            even_place_value = even_place_value[0] + even_place_value[1];
        }
        sum_even_digits = sum_even_digits + even_place_value;
        count = count + 2;
    }
}
