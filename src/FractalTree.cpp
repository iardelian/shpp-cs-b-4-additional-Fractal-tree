#include <iostream>
#include "gwindow.h"

using namespace std;

/*
 * @param pt - start point of drawing
 * @param branchSize - length of the initial tree branch
 * @param alpha - branch angle
 * @param order - recursion depth
 */
GPoint drawTree(GWindow & gw, GPoint pt, double branchSize, double alpha, int order){
    double reduction = 1.5; // reduction ratio of tree branches
    double angle = 30; // branches deviation angle
    GPoint centerPoint = gw.drawPolarLine (pt, branchSize, alpha); // base of the tree
    if(order == 0){
        return gw.drawPolarLine (pt, branchSize, alpha);
    }else{
        drawTree (gw, centerPoint, branchSize/reduction, alpha - angle, order - 1);
        drawTree (gw, centerPoint, branchSize/reduction, alpha + angle, order - 1);
        return drawTree (gw, pt, branchSize, alpha, order - 1 );
    }
}

int main() {

    double branchSize;
    double order;
    cout << "Please enter the length of the initial tree branch: ";
    cin >> branchSize;
    cout << "Please, enter fractal order: ";
    cin >> order;
    int x = branchSize * 3.1;
    GWindow gw (x, x);

    // coordinates of the initial tree branch
    double px = gw.getWidth() / 2;
    double py = gw.getHeight();

    GPoint pt(px,py);
    pt = drawTree (gw, pt, branchSize, +90, order); // "+90" - angle of the initial tree branch
    return 0;
}
