#include "header.h"

char opt;
char a[20];
void del_stud(struct st **ptr)
{
	printf("=====================================\n");
        printf("|      Enter choice to delete       |\n");
        printf("===========================================\n");
        printf("|R/r: Enter roll no. to delete |\n");
        printf("|D/d: Enter name to delete |\n");
        printf("===========================================\n");
        printf("enter the option(R/r)(D/d)       \n");
        scanf(" %c", &op); // Read option
        printf("enter the name to delete\n"); // NOTE: This prompt seems incorrect if op is R/r
        scanf(" %s", a); // Read name (or roll, depending on how you use 'a')

    // Handle Delete by Name (D/d)
    if((op == 'D') || (op == 'd'))
    {
        struct st *temp = *ptr;
        int found = 0;

        printf("Matching records:\n");
        printf("-------------------------------------------\n");

        while(temp)
        {
            // Check if the current node's name matches the target name 'a'
            if(strcmp(temp->name, a) == 0)
            {
                found = 1;
                // Print the details of the matching record
                printf("|%d\t%s\t%.2f\n", temp->roll, temp->name, temp->marks);
            }
            temp = temp->next;
        }

        if(!found)
        {
            printf("No students found with name %s\n", a);
            return;
        }
    }
    
    // Handle Delete by Roll Number (R/r) - This block is incomplete in the image
    if((op == 'R') || (op == 'r'))
    {
        struct st *temp;
        int n; // To store the roll number to delete

        printf("enter the roll no to delete\n");
        scanf(" %d", &n); // Read roll number
        temp = *ptr; // Assuming you start searching from the head

        // The image shows an IF condition here that uses 'temp' but the logic is missing
        // The visible code immediately prints the record and asks for confirmation
        
        printf("|%d\t%s\t%.2f\n", temp->roll, temp->name, temp->marks);
        printf("If you want to delete this student detail(y/n)\n");
        
        scanf(" %c", &op); // Reusing 'op' for the confirmation character
        
        if((op == 'Y') || (op == 'y'))
        {
            // The free calls suggest memory management for the deleted node
            free(temp->name); 
            free(temp->marks); // WARNING: This assumes marks is a pointer, but it's a float in the assumed struct
            // Missing logic: find the node with roll 'n' and unlink it from the list
            // e.g., using a prev pointer to bypass the 'temp' node
        }
    }
}
