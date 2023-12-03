#include <stdio.h>
#include <string.h>

unsigned short int room[50]; // 1p = 0, 2p = 1
unsigned short int number_of_room;
unsigned short int number_of_guest_group;

short add_guest_to_room(int number_of_guest){
    for(static int i = 0; i < number_of_room; i++){
        if(number_of_guest > 0){
            if(number_of_guest > 1){
                room[i] = 2;
                number_of_guest -= 2;
                continue;
            }
            else{
                room[i] = 1;
                number_of_guest -= 1;
                continue;
            }
            
        }else return 0;
    }
    return number_of_guest;
}

void room_pairing(int number_of_guest){
    for(int i = 0; i <number_of_room; i++){
        if(number_of_guest > 0)
            if(room[i] != 2){
                room[i] = 2;
                number_of_guest -=1;
            }

    }
}

int main(){
    FILE *f = fopen("input.inp", "r");
    fscanf(f,"%d %d", &number_of_room, &number_of_guest_group);

    for(short int i = 0; i < number_of_guest_group; i++){
        short int temp;

        fscanf(f,"%hd", &temp);
        temp = add_guest_to_room(temp);
        if(temp != 0) room_pairing(temp);
    }
    fclose(f);
    f = fopen("output.out", "w");
    for(short int i = 0; i <number_of_room; i++){
        fprintf(f,"%d\n", room[i]);
    }
    fclose(f);
    

}