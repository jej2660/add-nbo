#include <stdint.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int convert(uint32_t t){
    return (t & 0xFF000000) >> 24 | (t & 0x00FF0000) >> 8 | (t & 0x0000FF00) << 8 | (t & 0x000000FF) << 24;
}

int main(int argc, char *argv[]){
    FILE *f1, *f2;
    uint32_t s1,s2, result;
    
    if(argc != 3) {cout << "Usage: ./add-nbo <file1> <file2>"; return 0;}
    f1 = fopen(argv[1], "rb");
    f2 = fopen(argv[2],"rb");
    fread(&s1, 4, 1, f1);
    fread(&s2, 4, 1, f2);
    s1 = convert(s1);
    s2 = convert(s2);
    result = s1 + s2;
    
    
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", s1, s1, s2, s2,  result, result);
}
