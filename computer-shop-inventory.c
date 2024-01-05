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
// Define the structure for computer parts
struct ComputerPart {
    char name[50];
    int quantity;
    float price;
};

void displayMenu();
void addPart();
void displayInventory();
void searchPart();
void updatePart();
void removePart();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPart();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                searchPart();
                break;
            case 4:
                updatePart();
                break;
            case 5:
                removePart();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to display the menu (by Namitha)
void displayMenu(){
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
    if (file == NULL){
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

// Function to remove a part from the inventory (by abhinav)
void removePart() {
    struct ComputerPart part;
    char searchName[50];
    int found = 0;
    FILE *file = fopen("inventory.txt", "r");
    FILE *tempFile = fopen("temp_inventory.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Error opening file(s) for reading/writing.\n");
        return;
    }

    printf("Enter the name of the part to remove: ");
    scanf(" %[^\n]", searchName);

    while (fscanf(file, "%[^|]|%d|%f\n", part.name, &part.quantity, &part.price) != EOF) {
        if (strcmp(part.name, searchName) == 0) {
            found = 1;
            printf("Part %s removed from inventory.\n", part.name);
        } else {
            fprintf(tempFile, "%s|%d|%.2f\n", part.name, part.quantity, part.price);
        }
    }

    if (!found) {
        printf("Part not found in the inventory.\n");
    }

    fclose(file);
    fclose(tempFile);

    remove("inventory.txt");
    rename("temp_inventory.txt", "inventory.txt");
}
