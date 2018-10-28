/*
===================== Program =====================
Program name: PIG LATIN
Level: Beginner
Setter: Earl Chukwu
Submitted by: Saleh Ibne Omar
Date of submission: 29 October 2018
Method copyright 2018 Saleh Ibne Omar

Problem Sample:

 Translate English to Pig Latin by following these two simple rules:

    1.If the word begins with a consonant, then move the first consonant
      or group of consonants to the end of the word and add "ay." For example, "dusty" becomes "usty-day" and "choice" becomes "oice-chay."
    2.If the word begins with a vowel, then just add "yay," "hay," "way," or
      "ay" to the end of the word, depending on your regional dialect. (I prefer the "yay" style.) For example, "apple" becomes "apple-yay" and "orange" becomes "orange-yay."

*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){

    cout <<"Enter:"<<endl;
    //Array size can be taken dynamically
    char arr[20];
    char temp[20];
    cin >>arr;

    //To be appended (condition of the problem)
    char yay[4] = {'y', 'a', 'y', '\0'};
    char ay[3] = {'a', 'y', '\0'};

    int counter = 0;
    int rplc = 0;
    int tr = 0;
    int length = strlen(arr);

    cout <<endl;
    cout <<"Input is:"<<endl;
    cout <<arr<<endl;

    /* Check if the first letter of the character array is a vowel,
    if true then keep the string unchanged and concatenate 'yay' at the end of the string
    */
    if(arr[0] =='A' || arr[0] =='E' || arr[0] =='I' || arr[0] =='O' || arr[0] =='U' || arr[0] =='Y'
       || arr[0] =='a' || arr[0] =='e' || arr[0] =='i' || arr[0] =='o' || arr[0] =='u' || arr[0] =='y'){

        //Concatenate function (built in)
        strcat(arr, yay);

        cout <<endl;
        cout <<"Output is:"<<endl;
        cout <<arr<<endl;
    }

    else{
    /* If false then check for the first vowel from a given word
    */
        for(int x=0; x<length; x++){
            //As soon as a vowel found break the loop
            if(arr[x] =='A' || arr[x] =='E' || arr[x] =='I' || arr[x] =='O' || arr[x] =='U' || arr[x] =='Y'
            || arr[x] =='a' || arr[x] =='e' || arr[x] =='i' || arr[x] =='o' || arr[x] =='u' || arr[x] =='y'){
                break;
            }

            //Count the number of of time this vowel checking loop executed
            counter++;
            rplc = counter;

            //Store the values in a temporary array before the loop breaks
            for(int t=0; t<counter; t++){
                temp[t] = arr[t];
            }

        }

        //Replace the empty spaces in the array with the left out values after the break
        for(int r=0; r<length; r++){
            arr[r] = arr[rplc];
            rplc++;
        }

        //Get the new string length
        int newLen = strlen(arr);

        //Store the values which was taken by the temp array and put them from newLen as index number
        //This loop will run from newLen as index number to the old length of the array
        for(int n=newLen; n<length; n++){
            //Enter the temp values from newLen as index number
            arr[n] = temp[tr];
            tr++;
        }

      //Concatenate function (built in)
      strcat(arr, ay);

      cout <<endl;
      cout <<"Output is:"<<endl;
      cout <<arr<<endl;
    }


 return 0;
}
