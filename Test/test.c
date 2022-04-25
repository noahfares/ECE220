

struct engine
{
    int horse_power;
    int engine_CC;
};
struct car
{
    char name[50];
    int year;
    struct engine motor;
};
struct car cars[3] = {"Honda Civic Type R", 2021, {306, 2000},

"Toyota Supra", 2020, 255, 2000,
"Ferrari Roma", 2022, {612, 8900}};
struct car *my_car, *your_car, *our_car;
my_car = cars;
your_car = {my_car[2];
our_car = cars + 1;
printf("FIRST: my car: %s; and our car: %s\n",my_car->name, our_car->name);
your_car = my_car;
my_car = our_car + 1;
printf("SECOND: my car: %s; and your car: %s\n",
       my_car->name, your_car->name);
