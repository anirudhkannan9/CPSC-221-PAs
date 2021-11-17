#include "gridColorPicker.h"

gridColorPicker::gridColorPicker(HSLAPixel gridColor, int gridSpacing) 
//FIXME: param name 'gridColor' here; 'fillColor' in .h file, matters? 
{
    color = gridColor;
    spacing = gridSpacing;
}

HSLAPixel gridColorPicker::operator()(int x, int y)
{
    HSLAPixel white = HSLAPixel(0.0, 0.0, 1.0, 1.0);
    bool isNorthBorder = (y == 0);
    bool isWestBorder = (x == 0);
    bool xMultipleOfSpacing = (x%spacing == 0);
    bool yMultipleOfSpacing = (y%spacing == 0);
    if (isNorthBorder || isWestBorder || xMultipleOfSpacing || yMultipleOfSpacing) {
        return color;
    } else {
        return white;
    }
}
