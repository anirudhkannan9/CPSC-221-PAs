
#include "stats.h"

// initialize the private vectors so that, for each color channel, 
// (x,y) is the cumulative sum of the the color values from (0,0)
// to (x,y). 
// Note that the hue (h) value of each pixel is represented by
// its cartesian coordinates: X = cos(h) and Y = sin(h). 
// This is done to simplify distance and average computation.
stats::stats(PNG & im) {
    //how hue is translated into cartesian coordinates
    //  e.g. h = 0° => 0*(π/180) = 0rad. float hueX = std::cos(0) => hueX = 1, h = 50° => 50*(π/180) => 0.872665rad. float hueX = cos(0.872665) = 0.642788
    // i.e. hueX = cos(PI*pix->h/180) hueY = sin(PI*pix->h/180)

    unsigned int width = im.width(); 
    unsigned int height = im.height();
    //resize the vectors
        sumHueX.resize(width); 
        sumHueY.resize(width);
        //# doubles in sumHueX/Y @ idx z = height
        for (unsigned int i = 0; i < sumHueX.size(); i++) {
            sumHueX.at(i).resize(height); 
            sumHueY.at(i).resize(height);
        }
        
    //loop thru all pixls in im
    for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) { //for each pixel
            HSLAPixel* currPix = im.getPixel(x, y);

            //get hue,
            double currHue = currPix->h; 

            //If h ≥ 360, wrap around so subtract 360. As a guard - not an assumption
            if (currHue >= 360) {
                currHue = currHue - 360;
            } 

            //convert into hueX & hueY
            double hueX = cos(PI*currHue/180);
            double hueY = sin(PI*currHue/180);       
            
            //is it the very first pixel in the rectangle (entire img)?
            if (x == 0 && y == 0) { //it's the very first pixl (top L): (0, 0)
                sumHueX.at(0).at(0) = hueX;
                sumHueY.at(0).at(0) = hueY;
            } else if (y == 0) { //top row, only count from the left
                sumHueX.at(x).at(y) = hueX + sumHueX.at(x-1).at(y);
                sumHueY.at(x).at(y) = hueY + sumHueY.at(x-1).at(y);
            } else if (x == 0) { //leftmost column, only count from above
                sumHueX.at(x).at(y) = hueX + sumHueX.at(x).at(y-1);
                sumHueY.at(x).at(y) = hueY + sumHueY.at(x).at(y-1);



            }
        }
    }
}

long stats::rectArea(pair<int,int> ul, pair<int,int> lr)
{
    return 0;
}

HSLAPixel stats::getAvg(pair<int,int> ul, pair<int,int> lr)
{
    return HSLAPixel();
}

double stats::entropy(pair<int,int> ul, pair<int,int> lr){

    vector<int> distn;

    /* using private member hist, assemble the distribution over the
    *  given rectangle defined by points ul, and lr into variable distn.
    *  You will use distn to compute the entropy over the rectangle.
    *  if any bin in the distn has frequency 0, then do not add that 
    *  term to the entropy total. see .h file for more details.
    */

    /* my code includes the following lines:
        if (distn[i] > 0 ) 
            entropy += ((double) distn[i]/(double) area) 
                                    * log2((double) distn[i]/(double) area);
    */
    
   // return  -1 * entropy; //calc the entropy, and then return the -ve of it
   return -1.0;
}
