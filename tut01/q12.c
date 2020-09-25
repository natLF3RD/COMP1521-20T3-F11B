// Define a struct that might store information about a pet.

// The information should include the pet's name, type of animal, age and weight.

// Create a variable of this type and assign information to it to represent an axolotl named "Fluffy" of age 7 that weighs 300grams.

#define MAX_NAME_LENGTH 20
#define MAX_TYPE_LENGTH 20


struct pet {
    char name[MAX_NAME_LENGTH];
    char type[MAX_TYPE_LENGTH];
    int age;
    float weight;  // in kilograms
    // int = 5
    // float = 5.1
};

int main (void) {

    struct pet pet1;
    // Fyi, you can do pet1.name = "Fluffy"; in this case.
    // In the tut I ran out of time, but you would want to use strcpy 
    //  when you want to copy a string already stored in a variable.
    strcpy(pet1.name, "Fluffy");
    strcpy(pet1.type, "axolotl");
    pet1.age = 7;
    pet1.weight = 0.3;


    return 0;
}
