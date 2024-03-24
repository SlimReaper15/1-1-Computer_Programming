#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Group {
  Diary,
  Vegetables,
  Fruits
} Group;

char group_names[3][100] = {
    "diary",
    "vegetable",
    "fruit"
  };

typedef struct InventoryItem {
  char name[100];
  int quantity;
  int price;
  Group group;
} InventoryItem;

int main(int argc, char* argv[]) {

  InventoryItem inventory[100];

/* Problem 2.1: Suppose the first argument of a.out
contains the csv file of inventories, write code 
here, which reads that file and stores the data in 
the `inventory` array declared above.
*/
    FILE *f = fopen(argv[1], "r");
    char ch;
    int l = 1;
    while ((ch = fgetc(f)) != EOF) {
        if (ch == '\n')
            l++;
    }
    rewind(f);
    for (int i = 0; i < l; i++)
        fscanf(f, "%s %d %d", inventory[i].name, &inventory[i].quantity, &inventory[i].price);

/* Problem 2.2: Suppose the second argument of a.out
contains the csv file which has the group name
corresponding to each inventory item, write code here,
which updates the `group` field
in each InventoryItem of the `inventory` array.
*/
    FILE *f = fopen(argv[2], "r");
    char ch;
    int ll = 1;
    while ((ch = fgetc(f)) != EOF) {
        if (ch == '\n')
            l++;
    }
    rewind(f);
    
    for (int i = 0; i < ll; i++) {
        char food[20], group[20];
        fscanf(f, "%s %s", food, group);
        for (int j = 0; j < l; j++) {
            if (strcmp(inventory[j].name, food) == 0)

        }
    }
 
int grouped_value[3];
/* Problem 2.3: Compute the total value of all
items in a group and store it in the correpsonding
entry of the array `grouped_value`. That is
lgrouped_value[0] has the total value of all
Diary items. Similarly Vegetables for 1 and Fruits for 2.
*/

/* Problem 2.4: Write down the grouped inventory values
into a file given by the third argument to a.out, in the format
specificed for `grouped_inventory.csv`.
*/

}