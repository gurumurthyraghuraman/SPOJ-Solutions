#include <iostream>
#include <cmath>
using namespace std;



int main() {
    int rows,cols,k;
    int mousex,mousey,cat1x,cat1y,cat2x,cat2y;
    cin>>rows>>cols;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>mousex>>mousey>>cat1x>>cat1y>>cat2x>>cat2y;
        if((mousex==cat1x && mousey==cat1y) || (mousex==cat2x && mousey==cat2y))
            cout<<"NO"<<endl;
        else if((abs(cat1x-cat2x)==abs(cat1y-cat2y)) && (abs(mousex-cat1x)==abs(mousey-cat1y)) && mousex<=max(cat1x,cat2x) && mousex>=min(cat1x,cat2x) && mousey>=min(cat1y,cat2y) && mousey<=max(cat1y,cat2y))
            cout<<"NO"<<endl;
        /*else if((cat1x<=mousex && cat2x<=mousex) || (cat1x>=mousex && cat2x>=mousex) || (cat1y<=mousey && cat2y<=mousey) || (cat1y>=mousey && cat2y>=mousey))
            cout<<"YES"<<endl;
        else if(mousex==1 || mousex==rows || mousey==1 || mousey==cols)
            cout<<"YES"<<endl;*/
        else cout<<"YES"<<endl;

    }

}
