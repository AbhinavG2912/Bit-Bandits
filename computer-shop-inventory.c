//Computer parts shop inventory manager
//Assignment: 3
//By: Bit Bandits
/*
Members:
Abhinav. G
Nakul. R
Namitha. N
Reva. S
Adithya Vinayak
Dashami Perumal
*/

#include <stdio.h>
#include <string.h>
void displayMenu();
void addPart();
void displayInventory();
void searchPart();
void updatePart();
void removePart();

// Function to display the menu
void displayMenu() {
    printf("\n===== Computer Parts Inventory Management System =====\n");
    printf("1. Add a computer part\n");
    printf("2. Display inventory\n");
    printf("3. Search for a computer part\n");
    printf("4. Update quantity of a part\n");
    printf("5. Remove quantity of a part\n");
    printf("6. Exit\n");
}
