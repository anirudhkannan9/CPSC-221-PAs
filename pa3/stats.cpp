
#include "stats.h"

// initialize the private vectors so that, for each color channel, 
// (x,y) is the cumulative sum of the the color values from (0,0)
// to (x,y). 
// Note that the hue (h) value of each pixel is represented by
// its cartesian coordinates: X = cos(h) and Y = sin(h). 
// This is done to simplify distance and average computation.
stats::stats(PNG & im) {
//background:
    //first figure out how hue is translated into cartesian coordinates
    //  e.g. h = 0° => 0*(π/180) = 0rad. float hueX = std::cos(0) => hueX = 1
    //       h = 50° => 50*(π/180) => 0.872665rad. float hueX = cos(0.872665) = 0.642788
    //       h = 180° => 180*(π/180) = πrad. float hueX = cos(π) = -1 
    //       h = 243° => 243*(π/180) => 4.24115 rad. float hueX = cos(4.24115) = -.4453991
    //       h = 360° => 360*(π/180) => 2π rad. float hueX = cos(2π) = 1
    // i.e. hueX = cos(PI*pix->h/180) hueY = sin(PI*pix->h/180)

    //then figure out base cases. tests written for 1x1 & 2x2

//TODO: implementation:
    //implement for just e.g. hue first and make sure that's working

    unsigned int width = im.width();
    unsigned int height = im.height();
    //resize the vectors
        //# vectors in sumHueX/Y = width
        sumHueX.resize(width);
        sumHueY.resize(width);
        //# doubles in sumHueX/Y @ idx z = height
        for (unsigned int i = 0; i < sumHueX.size(); i++) {
            sumHueX.at(i).resize(height);
        }
        for (unsigned int j = 0; j < sumHueY.size(); j++) {
            sumHueY.at(j).resize(height);
        }
        
    //loop through all pixls in the img
    for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) { //for each pixel
            HSLAPixel* currPix = im.getPixel(x, y);
            //get its hue,
            double currHue = currPix->h; 
            //If h ≥ 360, wrap around so subtract 360. As a guard - not an assumption
            if (currHue >= 360) {
                currHue = currHue - 360;
            } 
            //convert into hueX & hueY
            double hueX = cos(PI*currHue/180);
            double hueY = sin(PI*currHue/180);       
            
            //is it the very first pixel in the rectangle (entire img)?
            if (x == y && x == 0) { //Y: just add the values themselves to the right position. 
                sumHueX.at(0).at(0) = hueX;
                sumHueY.at(0).at(0) = hueY;
                cout << "added ";
                cout << hueX;
                cout << " to sumHueX at (";
                cout << x;
                cout << ", ";
                cout << y;
                cout << ")";
                cout << " (top L) ";
                cout << endl;

            } else { //N: add curr values + prev cumSum => add the currentCumSum to the right position
                double prevCumSumX;
                double prevCumSumY;
                //find prevCumSum
                    //find position of previous pixel
                    if (x == 0) { //have to go up a row
                        unsigned int prevPixX = width-1;
                        unsigned int prevPixY = y-1;
                        prevCumSumX = sumHueX.at(prevPixX).at(prevPixY);
                        prevCumSumY = sumHueY.at(prevPixX).at(prevPixY);
                    } else {
                        prevCumSumX = sumHueX.at(x-1).at(y);
                        prevCumSumY = sumHueY.at(x-1).at(y);
                    }
                double currCumSumX = prevCumSumX + hueX;
                double currCumSumY = prevCumSumY + hueY;
                sumHueX.at(x).at(y) = currCumSumX;
                sumHueY.at(x).at(y) = currCumSumY;
            
                cout << "added currCumSumX = prevCumSumX + hueX = ";
                cout << prevCumSumX;
                cout << " + ";
                cout << hueX;
                cout << " = ";
                cout << currCumSumX;
                cout << " ";
                cout << " to sumHueX at (";
                cout << x;
                cout << ", ";
                cout << y;
                cout << ")";
                cout << endl;
            }
        }
    }
    cout << endl;
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
