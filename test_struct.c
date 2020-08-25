#include <stdio.h>

//構造体：2つの文字列で1つのデータ型を表す(これが嫌な場合、typedef を利用すればよい)
//typedef struct {.....} STUDENT; にように書けばよい。こうすると、以降では STUDENT (変数名) だけで済む
struct STUDENT {
    int id;         //  学籍番号
    char name[256]; //　名前(文字列の長さは256でなくても良いが、2のべき乗が好まれる)
    int kokugo;     //  国語の点数
    int sansu;      //  算数の点数
    int rika;       //  理科の点数
    int shakai;     //  社会の点数
    int eigo;       //  英語の点数
};

//sum1, sum2 関数のいずれも、アドレス値（ポインター）を引数として受け取る（引数に配列をもつので）
//実験的に2種類の方法で、構造体のメンバー変数の和を求めているが、結果は同じ
//sum1, sum2 関数の return 分はそれぞれ3通りで記しているので、コメントアウトして等価性を確認するとよい

//実際は sum1 関数のように引数を2つとる方法は非効率
int sum1(struct STUDENT p[], int i) {   // p[] と *p は等価
    return p[i].kokugo + p[i].sansu + p[i].rika + p[i].shakai + p[i].eigo;
    //return (*(p+i)).kokugo + (*(p+i)).sansu + (*(p+i)).rika + (*(p+i)).shakai + (*(p+i)).eigo;    // p[i] と *(p+i) は等価
    //return (p+i)->kokugo + (p+i)->sansu + (p+i)->rika + (p+i)->shakai + (p+i)->eigo;              // (p+i) と &p[i] は等価
}

//構造体を要素に持つ配列から、各要素のアドレスを1つずつ参照して引数とする
int sum2(struct STUDENT* p) {
    return p->kokugo + p->sansu + p->rika + p->shakai + p->eigo;
    //return p[0].kokugo + p[0].sansu + p[0].rika + p[0].shakai + p[0].eigo;
    //return (*p).kokugo + (*p).sansu + (*p).rika + (*p).shakai + (*p).eigo;    // p[0] と *p は等価
}

int main(){
    struct STUDENT data[5] = {
        { 1001, "石関", 82, 43, 53, 84, 45 },
        { 1002, "八木", 92, 83, 88, 79, 99 },
        { 1003, "三木", 43, 32, 53, 45, 66 },
        { 1004, "ボビー", 72, 73, 71, 68, 59 },
        { 1005, "山本", 99, 72, 82, 91, 94 }
    };

    int isum[5];    //各生徒の総合得点

    //sum1 関数の利用
    /*for(int i = 0; i < 5; i++){
        isum[i] = sum1(data, i);   // data は配列名である( data は &data[0] と等価)
    }*/

    //sum2 関数の利用
    for(int i = 0; i < 5; i++){
        isum[i] = sum2(&data[i]);
    }

    //  データの内訳を表示
    printf("番号\t名前\t国語\t数学\t理科\t社会\t英語\t合計\n");
    for(int i = 0; i < 5; i++){
        printf("%d\t%s\t %d\t %d\t %d\t %d\t %d\t %d\n", data[i].id, data[i].name, data[i].kokugo, data[i].sansu, data[i].rika, data[i].shakai, data[i].eigo, isum[i]);
    }

    return 0;
}
