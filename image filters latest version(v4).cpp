# include <iostream>
# include <cctype>
# include <string>
# include<cctype>
# include <cstring>
# include <algorithm>
# include <vector>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <regex>
#include "Image_Class.h"
using namespace std;
void black_white(Image& primary);
void invert_image(Image& primary);
void rotate_image(Image& primary);
void grayscale_image(Image& primary);
void filter_choices(string filter_choice, Image& primary);
string valid_choice(string filter_choice);
string image_name_validate(string name);
void filters_menu(Image & primary);
string choice_load_save(string choice);
int main() {

    // welcome user and ask him to load the image via name and extension
    cout<<"Welcome to our image filters application"<<endl<<endl;
    cout<<"Load your image"<<endl;
    cout<<"Enter your image name: "<<endl;
    string image_name;
    cin>>image_name;
    Image primary;
    
    // make sure that the image is in the directory
    while(true){
        try{
            primary.loadNewImage(image_name);
            cout<<"Loaded successfully"<<endl;
            cout<<endl;
            break;

        }
        catch(const invalid_argument& e) {
            cout<<"Enter a correct image name"<<endl;
            cin>>image_name;
        }
    }
    filters_menu(primary);




}

void invert_image(Image& primary) {
    for (int i = 0; i < primary.width; i++) {
        for (int j = 0; j < primary.height; j++) {
            for (int k = 0; k < primary.channels; k++) {
                primary(i, j, k) = 255 - primary(i, j, k);
            }
        }
    }
    // see if user wants to keep filtering or save the image
    cout<<"Press 1 if you want to save the image: "<<endl;
    cout<<"Press 2 if you want to continue filtering image: "<<endl;
    string choice;
    cin>>choice;
    choice=choice_load_save(choice);

    // save image
    if(choice=="1"){
        cout << "Enter your new image name with correct extension: "<<endl;
        string Image_name;
        cin >> Image_name;
        Image_name=image_name_validate(Image_name);
        primary.saveImage(Image_name);
        cout<<"Saved Successfully"<<endl<<endl;

        // see if user wants to continue using application
        cout<<"Press 1 if you want to load a new image"<<endl;
        cout<<"Press 2 if you want to exit"<<endl;
        string choice_2;
        cin>>choice_2;
        choice_2=choice_load_save(choice_2);
        if(choice_2=="1")main();
        else if(choice_2=="2"){
            cout<<"Thanks for using our image filter application"<<endl;
            exit(0);
        }
    }

        // keep filtering
    else{
        filters_menu(primary);
    }
}


void rotate_image( Image& primary) {
    Image rotated_image(primary.height, primary.width);
    for (int i = 0; i < primary.width; i++) {
        for (int j = 0; j < primary.height; j++) {
            rotated_image(j, primary.width - 1 - i, 0) = primary(i, j, 0);
            rotated_image(j, primary.width - 1 - i, 1) = primary(i, j, 1);
            rotated_image(j, primary.width - 1 - i, 2) = primary(i, j, 2);
        }
    }
    // see if user wants to keep filtering or save the image
    cout<<"Press 1 if you want to save the image: "<<endl;
    cout<<"Press 2 if you want to continue filtering image: "<<endl;
    string choice;
    cin>>choice;
    choice=choice_load_save(choice);
    
    // save image
    if(choice=="1"){
        cout<<"Enter your new image name with correct extension: "<<endl;
        string Image_name;
        cin>>Image_name;
        Image_name=image_name_validate(Image_name);
        rotated_image.saveImage(Image_name);
        
        // see if user wants to load a new image or exit
        cout<<"Saved Successfully"<<endl<<endl;
        cout<<"Press 1 if you want to load a new image"<<endl;
        cout<<"Press 2 if you want to exit"<<endl;
        string choice_2;
        cin>>choice_2;
        choice_2=choice_load_save(choice_2);
        if(choice_2=="1")main();
        else if(choice_2=="2"){
            cout<<"Thanks for using our image filter application"<<endl;
            exit(0);
        }
    }
    // keep filtering
    else{
        filters_menu(rotated_image);
    }


}

void grayscale_image(Image& primary){
    // loop on each pixel, calculate average of RGB and make each pixel equal that average
    for(int i=0; i<primary.width; i++){
        for(int j=0; j<primary.height; j++){
            int avg=0;
            avg+=primary(i,j,0);
            avg+=primary(i,j,1);
            avg+=primary(i,j,2);
            avg=avg/3;
            primary(i,j,0)=avg;
            primary(i,j,1)=avg;
            primary(i,j,2)=avg;
        }
    }

    // see if user wants to keep filtering or save the image
    cout<<"Press 1 if you want to save the image: "<<endl;
    cout<<"Press 2 if you want to continue filtering image: "<<endl;
    string choice;
    cin>>choice;
    choice=choice_load_save(choice);

    // save image
    if(choice=="1"){
        cout<<"Enter your new image name with correct extension: "<<endl;
        string Image_name;
        cin>>Image_name;
        Image_name=image_name_validate(Image_name);
        primary.saveImage(Image_name);
        cout<<"Saved Successfully"<<endl<<endl;

        // see if user wants to continue using application
        cout<<"Press 1 if you want to load a new image"<<endl;
        cout<<"Press 2 if you want to exit"<<endl;
        string choice_2;
        cin>>choice_2;
        choice_2=choice_load_save(choice_2);
        if(choice_2=="1")main();
        else if(choice_2=="2"){
            cout<<"Thanks for using our image filter application"<<endl;
            exit(0);
        }
    }

    // keep filtering
    else{
        filters_menu(primary);
    }


}

// function that calls filter function according to user's choice
void filter_choices(string filter_choice, Image& primary){
    if (filter_choice == "1") {
        grayscale_image(primary);
    }
    else if (filter_choice == "2") {
        black_white(primary);
    }
    else if (filter_choice == "3") {
        invert_image(primary);
    }
    else if (filter_choice == "6") {
        rotate_image(primary);
    }
    else if(filter_choice=="7"){
        cout<<"Thanks for using our image filters application"<<endl;
        exit(0);
    }
}

// function that validates filter_choice
string valid_choice(string filter_choice){
    while(true){
        if(filter_choice=="1")break;
        else if(filter_choice=="2")break;
        else if(filter_choice=="3")break;
        else if(filter_choice=="6")break;
        else if(filter_choice=="7"){
            cout<<"Thanks for using our image filter application"<<endl;
            exit(0);
        }
        else{
            cout<<"Please enter a valid choice"<<endl;
            cin>>filter_choice;
        }
    }
    return filter_choice;
}

// function that validates if entered image name has a correct extension
string image_name_validate(string name){
    while(true){
        if(name[name.length()-1]=='p' && name[name.length()-2]=='m' && name[name.length()-3]=='b'){
            return name;
        }
        else if(name[name.length()-1]=='g' && name[name.length()-2]=='p' && name[name.length()-3]=='j'){
            return name;
        }
        else if(name[name.length()-1]=='g' && name[name.length()-2]=='n' && name[name.length()-3]=='p'){
            return name;
        }
        else if(name[name.length()-1]=='g' && name[name.length()-2]=='e' && name[name.length()-3]=='p' && name[name.length()-4]=='j'){
            return name;
        }
        else{
            cout<<"Please enter a correct name with a correct extension: "<<endl;
            cin>>name;
            image_name_validate(name);
        }
    }

}


void filters_menu(Image & primary){
    // print out filter options for user
    cout<<"1. Grayscale"<<endl;
    cout << "2. Black and White filter" << endl;
    cout<<"3. Invert image"<<endl;
    cout<<"6. Rotate image"<<endl;
    cout<<"7. Exit"<<endl<<endl;
    cout<<"Please enter your filter choice: "<<endl;
    string filter_choice;
    cin>>filter_choice;

    // validate filter choice and do the filter according to the choice of the user
    filter_choice=valid_choice(filter_choice);
    filter_choices(filter_choice,primary);
}

// function that validates load or save choice
string choice_load_save(string choice){
    while(true){
        if(choice=="1")return choice;
        else if(choice=="2")return choice;
        else if(choice=="7"){
            cout<<"Thanks for using our image filter application"<<endl;
            exit(0);
        }
        else{
            cout<<"Please enter a correct choice: "<<endl;
            cin>>choice;
        }
    }
}

void black_white(Image& primary){
    // if the pixel channel color was under 127 make it 0 else make it 255
    int avg = 0;
    for(int i=0; i<primary.width; i++){
        for(int j=0; j<primary.height; j++){
            for (int k = 0 ; k < primary.channels ; k++){
                avg =+ primary(i,j,k);
            }
            avg = avg%256;
            if(avg > 128){
                primary(i,j,0) = 255;
                primary(i,j,1) = 255;
                primary(i,j,2) = 255;

            }else{
                primary(i,j,0) = 0;
                primary(i,j,1) = 0;
                primary(i,j,2) = 0;

            }
        }
    }

    // see if user wants to keep filtering or save the image
    cout<<"Press 1 if you want to save the image: "<<endl;
    cout<<"Press 2 if you want to continue filtering image: "<<endl;
    string choice;
    cin>>choice;
    choice=choice_load_save(choice);

    // save image
    if(choice == "1" ){
        cout << "Enter your new image name with correct extension:" << endl;
        string Image_name;
        cin >> Image_name;
        Image_name = image_name_validate(Image_name);
        primary.saveImage(Image_name);
        cout << "Saved Successfully" << endl << endl;

        // see if user wants to continue using application
        cout<<"Press 1 if you want to load a new image"<<endl;
        cout<<"Press 2 if you want to exit"<<endl;
        string choice_2;
        cin >> choice_2;
        choice_2 = choice_load_save(choice_2);
        if(choice_2 == "1") {
            main();
        }
        else if(choice_2 == "2"){
            cout << "Thanks for using our Photo Editor application" << endl;
            exit(0);
        }
    }

        // keep filtering
    else{
        filters_menu(primary);
    }


}