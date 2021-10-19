#include "block.h" //FIxME: why squiggly? // VS doesn't know ugrad setup - ignore
#include <cmath>
#include <iostream>
#include <vector>
#include "cs221util/HSLAPixel.h"
#include <typeinfo>


/* Returns the width, in pixels
 * of the current block
 */
int Block::width() const
{
    // Your code here!
    //row-major organization -> every vector in 'data' is a row -> width is the number of elements in a row/vector

    return data[0].size();
}

/* Returns the height, in pixels 
 * of the current block
 */
int Block::height() const
{
    // Your code here!
    //row-maj org -> every vect in 'data' is a row -> height is # of vectors in 'data'

    return data.size();
}

/* Given an image whose size is large enough, place                 //FIxME: does this mean 'assume all images are large enough'?
 * the current block in the image so that its upper left corner     //ToDO: can't go wrong w a guard -- compare PNG size w member var 'data'. Print smth + exit
 * is at position column, row. Existing pixels in the image
 * will be replaced by those of the block.
 */
void Block::render(PNG &im, int column, int row) const //FIxME: the 'const' refers to the Block, correct? Y
{
    // Your code here!
    //guard to check if img is big enough. 
        //# of pixels in im = im.width() * im.height()
    //# of pixels in Block = data.size() * data[0].size()
    int imageSize = im.width() * im.height();
    int blockSize = data.size() * data[0].size();
    if (imageSize < blockSize) {
        cout << "in Block::render; image not big enough to fit this block into it" << endl;
    } else {
        //column, row are y, x co-ords for the PNG, not the Block
        //PNG.h: pixels in a PNG are represented by an array of pixels/pixel ptrs
        int blockHeight = data.size();
        int blockWidth = data[0].size();
        //loop through the pixels in the PNG, starting @ (row, column)
        //for each pixel, replace its hsla values with the hsla values in the corresponding pixel in the Block
        for (int x = column; x < blockWidth + column; x++) {
            for (int y = row; y < blockHeight + row; y++) {
                HSLAPixel* currentImagePixel = im.getPixel(x, y);
                *currentImagePixel = data[y-row][x-column];
                // data[y-row][x-column].h = currentImagePixel->h;
                // data[y-row][x-column].s = currentImagePixel->s;
                // data[y-row][x-column].l = currentImagePixel->l;
                // data[y-row][x-column].a = currentImagePixel->a;
            }
        }
    }
}

/* create a block of pixels whose color values are the same as the
 * rectangle in the image described by the upper left corner (column, row)
 * whose size is width x height.
 */
void Block::build(PNG &im, int column, int row, int width, int height)
{
    // Your code here!
    //initialize data to be of the right size
    //outer vector represents rows, has 'height' rows
    //inner vectors represent columns, have 'width' columns
    //for loop

    data.resize(height);
    // // cout << "Resized; data is now size (height): " << endl;
    // // cout << data.size() << endl;
    
    for (int m = 0; m < height; m++) {
        data[m].resize(width);
    }

    // //cout << "Resized all vectors within data, they are now size (width): " << endl;
    // // for (int y = 0; y < height; y++) {
    // //    cout << data[y].size() << endl;
    // // }


    //loop through the correct values of 'im'
    //go from im @ (column, row) = arr[row*(im.width())+column]
    //  to im @ (column + width - 1, row + height - 1) = arr[(row+height-1) * (im.width()) + (column+width-1)]
    // int startAtImageIndex = row * im.width() + column;
    // int endAtImageIndex = (row + height - 1) * (im.width()) + (column + width - 1);
    // for (int i = startAtImageIndex; i <= endAtImageIndex; i++) {
    //     //for each pixel in 'im' that we loop thru, find the corresponding pixel in 'data' 
    //     //and assign to it the 'im' pixel's HSLA values

    // }

    //toDO: the above is overengineering it; using PNG's getPixel(x, y) method
    //go row by row, from row until height - 1
        //and column by column, from column until width - 1
        //for each pixel 'p' in im that we loop through, 
            //find the corresponding pixel in Block, and assign p's HSLA values to this pixel's HSLA values
            //data[i-row][j-column];
            //data[y-row][x-column]
    for (int y = row; y <= row + height - 1; y++) {
        for (int x = column; x <= column + width - 1; x++) {
            HSLAPixel* currentImagePixel = im.getPixel(x, y);
            data[y-row][x-column] = *currentImagePixel;
            // data[y-row][x-column].h = currentImagePixel->h;
            // data[y-row][x-column].s = currentImagePixel->s;
            // data[y-row][x-column].l = currentImagePixel->l;
            // data[y-row][x-column].a = currentImagePixel->a;
            
        }
    }    
}

/* Flip the current block across its horizontal midline.
 * This function changes the existing block.
 */
void Block::flipVert()
{
    for (int y = 0; y < (data.size()/2); y++) {
        for (int x = 0; x < data[0].size(); x++) {
            std::swap(data[y][x], data[data.size()-1-y][x]);
        }
    }
}

/* Flip the current block across its vertical midline.
 * This function changes the existing block.
 */
void Block::flipHoriz()
{
    // Your code here!
        for (int y = 0; y < data.size(); y++) {
        for (int x = 0; x < data[0].size()/2; x++) {
            std::swap(data[y][x], data[y][data[0].size()-1-x]);
        }
    }

    // //2 cases:
    // if (numOfColumns % 2 == 0) {
    //     //even # of columns, split in half evenly
    // } else {
    //     //odd # of columns, flip over the midline (midline stays the same)
    // }
} 

/* Rotate the current block 90 degrees clockwise.
 * This function changes the existing block.
 */
void Block::rotateRight()
{
    //ASSUMES SQUARE BLOCKS
    std::swap(data[0][0], data[2][0]); //swap data[0][0] & data[data.size()-1][0]
    std::swap(data[0][2], data[2][0]); //data[0][data.size()-1] & data[data.size()-1][0]
    std::swap(data[2][0], data[2][2]); //data[data.size()-1][0] & data[data.size()-1][data.size()-1]
    std::swap(data[0][1], data[1][0]); //data[0][data.size()-1/2] & data[data.size()-1/2][0]
    std::swap(data[1][2], data[2][1]); //data[data.size()-1/2][data.size()-1] & data[data.size()-1][data.size()-1/2]
    std::swap(data[1][0], data[1][2]); //data[data.size()-1/2][0] & data[data.size()-1/2][data.size()-1]    

}
