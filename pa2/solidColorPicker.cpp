#include "solidColorPicker.h"

/**
 * Constructs a new solidColorPicker.
 *
 * @param fillColor The color for this color picker.
 */
solidColorPicker::solidColorPicker(HSLAPixel fillColor)
{
    solidColor = fillColor; //presume copy by value
}

/**
 * Picks the color for pixel (x, y).
 * 
 * Simply returns the same color (used to construct the picker) all of the
 * time.
 */
HSLAPixel solidColorPicker::operator()(int x, int y)
{
    return solidColor;
}
