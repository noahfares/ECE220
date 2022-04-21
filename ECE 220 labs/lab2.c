//
// Created by Ahmed Chaari
//

#include<stdio.h>
#include <locale.h>

#define ERR -1

#define FROM_SIZE 3
#define TO_SIZE 4

int main() {
    FILE* fkey;
    FILE* fin;
    FILE* fout;

    setlocale(LC_ALL, "en_US.UTF-8");


    // Change the path to the files

    // fkey_path : file path for the key file  (change it, use your own local path)
    char fkey_path[] = "H:\School\University Year 2 Semester 2\ECE 202 Lecture Code\ECE 220 labs\Key.dat"; //(mac OS or Linux)
    // (Windows) C:\\Users\\YourUserID\\ece220\\lab-02\\Key.dat

    // fin_path : file path for the Raw input file  (change it, use your own local path)
    char fin_path[] = "H:\School\University Year 2 Semester 2\ECE 202 Lecture Code\ECE 220 labs\Raw.dat";
    // (Windows) C:\\Users\\YourUserID\\ece220\\lab-02\\Raw.dat

    // fout_path : file path for the decoded output file  (change it, use your own local path)
    char fout_path[] = "H:\School\University Year 2 Semester 2\ECE 202 Lecture Code\ECE 220 labs\Encoded_result.dat";
    // (Windows) C:\\Users\\YourUserID\\ece220\\lab-02\\Encoded_result.dat





    //buf_in : array of size 3 used as an input buffer for the base 64 conversion
    unsigned char buf_in[FROM_SIZE];
    //buf_out : array of size 4 used as an output buffer for the base 64 conversion
    unsigned char buf_out[TO_SIZE];

    // keys: array to store the index table
    char keys[64];

    int count;
    int total_char;

    fkey=fopen(fkey_path,"r");
    //load Key.dat

    //VS version (We need first  errno_t err; at the top)
    //err = fopen_s(&fkey, fkey_path, "r+b");

    //check if key file cannot be found
    // add code here

    // load key file character by character into keys array
    for(int i=0;i<64;i++) {
        keys[i] = getc(fkey);
    }
    fclose(fkey);


/*
    //open  Raw.dat in reading mode
    fin=fopen(fin_path,"r");

    //check if  raw file cannot be found
    // add code here

    //open  Encoded_result.dat in writing mode
    fout=fopen(fout_path,"w");

    //check if  decoded file cannot be found
    // add code here



    total_char=0;

    // fread here read each time 3 bytes(FROM_SIZE) from the input raw file(fin) and store it in buf_in
    //count= The total number of elements successfully read
    // while loop stops when count is not equal to 3
    
    while	((count=fread(buf_in,1,FROM_SIZE,fin))==FROM_SIZE) {

        // select the last six bits from buf_in[0] using the mask 0xFC=1111 1100 ,
        // then shift the bit two position to the right >>2 to rearrange the six bits and
        // if buf_in[0]=[b_7|b_6|b_5|b_4|b_3|b_2|b_1|b_0]then  buf_out[0]= [0|0|b_7|b_6|b_5|b_4|b_3|b_2]
        buf_out[0]=keys[(buf_in[0]&(0xFC))>>2];


        // select the first two bits from buf_in[0] using the mask 0x03=0000 0011 ,
        // then shift the bit four position to the left <<4 to rearrange the two bits and
        // select the last four bits from buf_in[1] using the mask 0xF0=1111 0000 ,
        // then shift the bit four position to the right >>4 to rearrange the two bits and
        // if buf_in[0]=[b_7|b_6|b_5|b_4|b_3|b_2|b_1|b_0]
        // and buf_in[1]=[c_7|c_6|c_5|c_4|c_3|c_2|c_1|c_0]
        // then  buf_out[0]= [0|0|b_7|b_6|c_7|c_6|c_5|c_4]
        // | (or in binary) is used to concatenate buf_in[0] and buf_in[1] after bits are selected and rearranged
        buf_out[1]=keys[((buf_in[0]&(0x03))<<4)|((buf_in[1]&(0xF0))>>4)];


        // 0x0F=0000 1111  and  0xC0= 1100 0000
        buf_out[2]=keys[((buf_in[1]&(0x0F))<<2)|((buf_in[2]&(0xC0))>>6)];

        // 0x3F 00111111
        buf_out[3]=keys[(buf_in[2]&(0x3F))];

        // fwrite here writes all 4 characters of buf_out into fout
        fwrite(buf_out,TO_SIZE,1,fout);



        // file formatting
        total_char+=TO_SIZE;
        if(total_char%48==0) {
            // add return to line after 6 groups (line should contain 6 groups)
            // add code here
        } else if(total_char%8==0) {
            // add a space for each separated into groups of 8 characters with a space between
            // add code here
        }
    }
    if(count!=0) {


        buf_out[0]=// add code here
        if(count==1) {
            buf_out[1]=;// add code here
            buf_out[2]='=';
        } else if(count==2) {
            buf_out[1]=;// add code here
            buf_out[2]=;// add code here
        }
        buf_out[3]=// add code here
        fwrite(buf_out,TO_SIZE,1,fout);
    }
    fclose(fin);
    fclose(fout);
*/
    return 0;
}