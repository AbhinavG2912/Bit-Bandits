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

// Function to display the menu (by Namitha)
void displayMenu() {
    printf("\n===== Computer Parts Inventory Management System =====\n");
    printf("1. Add a computer part\n");
    printf("2. Display inventory\n");
    printf("3. Search for a computer part\n");
    printf("4. Update quantity of a part\n");
    printf("5. Remove quantity of a part\n");
    printf("6. Exit\n");
}
// Function to add a computer part to the inventory(by Namitha)
void addPart() {
    struct ComputerPart part;
    FILE *file = fopen("inventory.txt", "a");

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    printf("Enter part name: ");
    scanf(" %[^\n]", part.name);
    
    printf("Enter quantity: ");
    scanf("%d", &part.quantity);
    printf("Enter price: ");
    scanf("%f", &part.price);

    fprintf(file, "%s|%d|%.2f\n", part.name, part.quantity, part.price);

    fclose(file);

    printf("Computer part added successfully!\n");
}
