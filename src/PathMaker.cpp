//
//  PathMaker.cpp
//  ofPathMaker
//
//  Created by Justin Lange on 10/6/13.
//
//


#include "PathMaker.h"

PathMaker::PathMaker(int iTilesPerAxis)
: mTilesPerAxis(iTilesPerAxis), mSolutionCount(0), mTotalCallCount(0), mTempCallCount(0), dist(1), squareSize(10), bigDist(4)
{
	mBoard = new bool*[mTilesPerAxis];
	for(int i = 0; i < mTilesPerAxis; i++) {
		mBoard[i] = new bool[mTilesPerAxis];
		for(int j = 0; j < mTilesPerAxis; j++) {
			mBoard[i][j] = false;
		}
	}
}


PathMaker::~PathMaker()
{
    delete [] mBoard; //why don't I have to specify both axis?
    
}


bool PathMaker::solveWithBackTracking(int x, int y, int _d)
{
   // if(mBoard[x][y]) return false;

    //check area
    
    mTotalCallCount++;
    
    if(mTotalCallCount > mTilesPerAxis * mTilesPerAxis) return false;
    
    int d = _d;
    
    cout << "x: " << x << " y: " << y << endl;
    
    
    if(x >= mTilesPerAxis-bigDist){
        x-=bigDist;
        d = NORTH;
    }
   
    if( x <= bigDist) {
       x +=bigDist;
       d = SOUTH;
    }
    
    
    if ( y >= mTilesPerAxis-bigDist) {
        y -=bigDist;
        d = WEST;
    }
    
    if ( y <= bigDist) {
        y +=bigDist;
        d = EAST;
    }
    
    switch ( d )
    {
        case SOUTH:
            if (!mBoard[x+dist][y+dist] && !mBoard[x+dist][y] && !mBoard[x-dist][y+dist]) mBoard[x][y] = true;
            y++;
            sCt++;
            cout << "south call count: " << sCt << endl;
            solveWithBackTracking(x, y, d );
        case EAST:
            if (!mBoard[x][y+dist] && !mBoard[x-dist][y] && !mBoard[x-dist][y-dist]) mBoard[x][y] = true;
                x++;
                eCt++;
                cout << "east call count: " << eCt << endl;
                solveWithBackTracking(x, y, d);

        case WEST:
            if (!mBoard[x][y+dist] && !mBoard[x+dist][y] && !mBoard[x][y-dist]) mBoard[x][y] = true;
                wCt++;
                x--;
                cout << "west call count: " << wCt << endl;
                solveWithBackTracking(x, y, d);

        case NORTH:
            if (!mBoard[x][y+dist] && !mBoard[x-dist][y] && !mBoard[x+dist][y]) mBoard[x][y] = true;
                y--;
                cout << "west call count: " << wCt << endl;
                solveWithBackTracking(x, y, d);

        }
    
    d = rand() % 4;
    
    return false;
    
}

vector<ofPoint> PathMaker::savePath()
{
    vector<ofPoint> myPath;
    
    for(int i = 0; i< mTilesPerAxis; i++){
        for(int j = 0; j < mTilesPerAxis; j++){
            //cout << "i: " << i << " j: " << j << endl;
            if( mBoard[i][j] == true){
                myPath.push_back(ofVec2f(i, j));
                
            }
            
        }
    }
    return myPath;
    
}