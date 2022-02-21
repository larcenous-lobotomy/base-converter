#include <stdio.h>

//simple conversion by multiplying each binary bit
// with corresponding power of 2 base 10 (using Horner's method)
void BinaryToDecimal(int n, char * arr){
        int R = 0;
    for(int k = 0; k < n; k++){
        R *= 2;
        R += (arr[k] - '0');
    }
    printf("%d", R);//print
}

//8 = 2^3, so dividing a binary string into set of threes(each 'block'
//is an octal digit)
//eg: 010101
//-> 0*(2^5) + 1*(2^4) + 0*(2^3) + 1*(2^2) + 0*(2^1) + 1*(2^0)
//-> 010*(8^1) + 101*(8^0)
void BinaryToOctal(int n, char * arr){
    int k = 0, f = 0, m = 0;
    char R[1000]; //stores result
    //if string length is not divisible by 3, we must account for the extra bits by storing them appropriately
    if(n % 3 != 0){
        while((n - k) % 3 != 0){
            f *= 2;
            f += (arr[k++] - '0'); 
        }
        R[m++] = (f + '0');
    }
    //for the 'even' part
    for(int i = k; i + 2 < n; i += 3){
        f = 0;
        for(int j = i; j < i + 3; j++){
            f *= 2;
            f += (arr[j] - '0');
        }
        R[m++] = (f + '0');
    }
    printf("%s", R);//print

}

//16 = 2^4 , so dividing a binary string into set of fours(each 'block'
// is a hex digit - NOTE - all such hex 'digits' greater than
// 9 must be denoted by letters 'A' to 'F')
//eg:0010101
//-> 1*(2^4) + 0*(2^3) + 1*(2^2) + 0*(2^1) + 1*(2^0)
//-> 0001*(16^1) + 0101*(16^0)
void BinaryToHex(int n, char * arr){
    int k = 0, f = 0, m = 0, M;
    //M stores length of hex string 
    if (n % 4 == 0) M = (n / 4);
    else M = (n / 4) + 1;
    char R[M];//stores result 	
    //if string length is not divisible by 4, we must account for the extra bits by storing them appropriately
    if(n % 4 != 0){
        while((n - k) % 4 != 0){
            f *= 2;
            f += (arr[k++] - '0'); 
        }
        if(f <= 9) R[m++] = (f + '0'); //if 0 <= f <= 9, enter 9
        else R[m++] = (f - 10 + 'A'); //else enter corresponding alphabet from A to F
    }
    //for the 'even' part
    for(int i = k; i + 3 < n; i += 4){
        f = 0; 
        for(int j = i; j < i + 4; j++){
            f *= 2;
            f += (arr[j] - '0');
        }
        if(f <= 9) R[m++] = (f + '0');//if 0 <= f <= 9, enter 9
        else R[m++] = (f - 10 + 'A');//else enter corresponding alphabet from A to F
    }
    for(int i = 0; i < M; i++) printf("%c", R[i]);//print
}

//DRIVER
int main(){

    int n;
    scanf("%d", &n);
    char arr[n];
    scanf("%s",arr);

    BinaryToDecimal(n, arr);printf(",");
    BinaryToOctal(n, arr);printf(",");
    BinaryToHex(n, arr);printf("\n");
    return 0;
}
