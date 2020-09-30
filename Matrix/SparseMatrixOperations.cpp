#include <stdio.h>
#define size 200
/*
A sparse matrix is a matrix which contains very few non-zero elements
For eg.
0 0 1 0
0 2 0 0
0 0 0 3

Now, given matrix could be represented as
mrow = Number of rows in the original matrix
mcol = Number of columns in the original matrix
mvalue = Number of non-zero elements in the original matrix
The above matrix could be represented as- 

mrow = 3
mcol = 4
mvalue = 3

row  |col   |value
1    |3     |1 
2    |1     |2
3    |4     |3

Where value[i] denotes the value at the index row[i],col[i] in the original matrix
*/
struct sparse{
    int mrow,mcol,mvalue;
    int row[size];
    int col[size];
    int value[size];
};

struct sparse transpose(struct sparse B){
        struct sparse result;
        result.mvalue = B.mvalue;
        int count[size]={0};
        for(int i = 0; i < B.mcol; i++){
            count[i] = 0;
        }
        for(int i = 0; i < B.mvalue; i++){
            count[B.col[i]]++;
        }
        int index[size]={0};
        index[0] = 0;
        for(int i = 1; i < B.mcol; i++){
            index[i] = index[i-1] + count[i-1];
        }
        for(int i = 0; i < B.mvalue; i++){
            int rpos = index[B.col[i]]++;
            result.row[rpos] = B.col[i];
            result.col[rpos] = B.row[i];
            result.value[rpos] = B.value[i];
        }
        result.mrow=B.mcol;
        result.mcol=B.mrow;
        return result;
    }

struct sparse addMatrix(struct sparse A,struct sparse B){
    struct sparse C;
    C.mvalue=0;
    C.mrow=0;
    C.mcol=0;
    if(A.mrow==B.mrow && A.mcol==B.mcol){
        int i=0,j=0,k=0;
        while(i<A.mvalue && j<B.mvalue){
            if(A.row[i]==B.row[j] && A.col[i]==B.col[j]){
                C.row[k]=A.row[i];
                C.col[k]=A.col[i];
                if(A.value[i]+B.value[j]!=0){
                    C.value[k]=(A.value[i]+B.value[j]);
                    k++;
                }
                i++;j++;
            }
            else if(A.row[i]<B.row[j] || (A.row[i]==B.row[j] && A.col[i]<B.col[j])){
                C.row[k]=A.row[i];
                C.col[k]=A.col[i];
                C.value[k]=A.value[i];
                i++;k++;
            }
            else{
                C.row[k]=B.row[j];
                C.col[k]=B.col[j];
                C.value[k]=B.value[j];
                j++;k++;
            }
        }
        while(i<A.mvalue){
                C.row[k]=A.row[i];
                C.col[k]=A.col[i];
                C.value[k]=A.value[i];
                i++;k++;
        }
        while(j<B.mvalue){
                C.row[k]=B.row[j];
                C.col[k]=B.col[j];
                C.value[k]=B.value[j];
                j++;k++;
        }
        C.mrow=A.mrow;
        C.mcol=A.mcol;
        C.mvalue=k;
        return C;
    } 
    else{
        printf("Cannot add matrices\n");
        return C;
    }

};
struct sparse multiply(struct sparse A,struct sparse B){
    struct sparse C;
    C.mvalue=0;
    C.mrow=0;
    C.mcol=0;
    if(A.mcol!=B.mrow){
        C.mvalue = -1;
        printf("Matrix Mutliplication Not possible!\n");
        return C;
    }
    B=transpose(B);
    int avalue, bvalue;
    for(avalue = 0; avalue < A.mvalue;){
        int r = A.row[avalue];
        for(bvalue = 0; bvalue < B.mvalue;){
            int c = B.row[bvalue];
            int tempa = avalue;
            int tempb = bvalue;
            int sum = 0;
            while(tempa < A.mvalue && A.row[tempa] == r && tempb < B.mvalue && B.row[tempb] == c){
                if(A.col[tempa] < B.col[tempb]){
                    tempa++;
                }
                else if(A.col[tempa] > B.col[tempb]){
                    tempb++;
                }
                else{
                    sum += A.value[tempa++]*B.value[tempb++];
                }
            }
            if(sum != 0){
                C.row[C.mvalue] = r;
                C.col[C.mvalue] = c;
                C.value[C.mvalue] = sum;
                C.mvalue++;
            }
            while(bvalue < B.mvalue && B.row[bvalue] == c){
                bvalue++;
            }
        }
        while(avalue < A.mvalue && A.row[avalue] == r){
            avalue++;
        }
    }
    C.mrow=A.mrow;
    C.mcol=B.mrow;
    return C;

};
void readmatrix(struct sparse*S){
    int x=0,k=0;
    printf("Enter the no. of rows\n");
    scanf("%d",&S->mrow);
    printf("Enter the no. of columns\n");
    scanf("%d",&S->mcol);
    for(int i=0;i<S->mrow;i++){
        for(int j=0;j<S->mcol;j++){
            scanf("%d",&x);
            if(x!=0){
                S->row[k]=i;S->col[k]=j;
                S->value[k]=x;
                k++;
            }
        }
    }
    S->mvalue=k;
}
void printmatrix(struct sparse S){
    int k=0,i=0,j=0;
    printf("The matrix is\n");
    for(i=0;i<S.mrow;i++){
        for(j=0;j<S.mcol;j++){
            if(S.row[k]==i && S.col[k]==j){
                printf("%d ",S.value[k]);k++;}
            else{printf("0 ");}
        }
        printf("\n");
    }
}
int main(){
    struct sparse A,B;
    readmatrix(&A);
    readmatrix(&B);
    printf("Matrix A = \n");
    printmatrix(A);
    printf("Matrix B = \n");
    printmatrix(B);
    struct sparse C;
    C = multiply(A,B);
    if(C.mvalue!=-1){
        printf("Matrix C = \n");
        printmatrix(C);
    }
    return 0;
}
