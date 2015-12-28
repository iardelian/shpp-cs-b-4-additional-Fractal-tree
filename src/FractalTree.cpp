#include <iostream>
#include "gwindow.h"

using namespace std;

const double WIN_SIZE_COEFF = 3.1;
const double REDUCTION_RATIO = 1.5; // reduction ratio of tree branches
/*
 * @param point - start point of drawing
 * @param branchSize - length of the initial tree branch
 * @param branchAngle - branch angle
 * @param order - recursion depth
 */
GPoint drawTree(GWindow & gw, GPoint point, double branchSize, double branchAngle, int order){
    double deviationAngle = 30; // branches deviation angle
    GPoint centerPoint = gw.drawPolarLine (point, branchSize, branchAngle); // base of the tree
    if (order == 0) {
        return gw.drawPolarLine (point, branchSize, branchAngle);
    } else {
        drawTree(gw, centerPoint, branchSize/REDUCTION_RATIO, branchAngle-deviationAngle, order-1);
        drawTree(gw, centerPoint, branchSize/REDUCTION_RATIO, branchAngle+deviationAngle, order-1);
        return drawTree (gw, point, branchSize, branchAngle, order - 1 );
    }
}

int main() {
    
    double branchSize;
    double order;
    cout << "Please enter the length of the initial tree branch: ";
    cin >> branchSize;
    cout << "Please, enter fractal order: ";
    cin >> order;
    int x = branchSize * WIN_SIZE_COEFF;
    GWindow gw (x, x);
    
    // coordinates of the initial tree branch
    double startPointX = gw.getWidth() / 2;
    double startPointY = gw.getHeight();
    
    GPoint point(startPointX, startPointY);
    // @param +90 - angle of the initial tree branch
    point = drawTree (gw, point, branchSize, +90, order);
    return 0;
}
