#include<stdio.h>
#include<stdint.h>

int main(void)
{
    uint32_t attendance = 0;
    int option;
    int studentNum;
    while (1)
    {
        printf("1. Set attendance\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance info\n");
        printf("4. Absence info\n");
        printf("5. Change attendance\n");
        printf("6. Exit\n");
        scanf("%d", &option);
        if (option == 1)
        {
            printf("Enter student number: ");
                scanf("%d", &studentNum);
            if(studentNum > 32){
                printf("There are only 32 students in the class\n");
            }
            else{
                attendance |= 1<<studentNum;
            }
            
        }
        else if (option == 2)
        {
            printf("Enter student number: ");
            scanf("%d", &studentNum);
            if(studentNum > 32){
                printf("There are only 32 students in the class\n");
            }
            else{
                attendance &= ~(1<<studentNum);
            }
        }
        else if (option == 3)
        {
            printf("Attending are: ");
            for(int bit = 15; bit >= 0; bit--){
                //printf("%d", (attendance&(1<<bit))>>bit);
                int temp = !!(attendance&(1<<bit));
                if(temp == 1){
                    printf("Number %d, ", bit);
                }  
            }
            printf("\n");
        }
        else if (option == 4)
        {
            printf("Abscent are: ");
            for(int bit = 15; bit >= 0; bit--){
                //printf("%d", (attendance&(1<<bit))>>bit);
                int temp = !!(attendance&(1<<bit));
                if(temp == 0){
                    printf("Number %d, ", bit);
                }  
            }
            printf("\n");
        }
        else if(option == 5){
            printf("Enter student number: ");
            scanf("%d", &studentNum);
            if(studentNum > 32){
                printf("There are only 32 students in the class\n");
            }
            else{
                attendance ^= 1<<studentNum;
            }
        }

        else if(option == 6){
            break;
        }
    
    }
    return 0;
}
