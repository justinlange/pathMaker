//
//  PathMaker.cpp
//  ofPathMaker
//
//  Created by Justin Lange on 10/6/13.
//
//


#include "PathMaker.h"

PathMaker::PathMaker(int iTilesPerAxis)
: mTilesPerAxis(iTilesPerAxis), mSolutionCount(0), mTotalCallCount(0), mTempCallCount(0), dist(1), squareSize(10), bigDist(1), lineReps(20)
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
    
    mTempCallCount++;
    mTotalCallCount++;

    
    int d = _d;
    
    
    
    
    //d = (rand() % 4) + 1;
   
    //cout << "random has been called and d is: " << d << "total count: " << mTotalCallCount << endl;
    

    
    
    
    //take x and y
    
    //finally, if global counter is max, return true;
    
    
    
    int successCheck = 0;
    
    for(int i = 0; i < mTilesPerAxis; i++) {
        for(int j = 0; j < mTilesPerAxis; j++) {
            if (mBoard[i][j] == true) {
                successCheck++;
            }
            if (successCheck >= (mTilesPerAxis*mTilesPerAxis)){
                cout << "we have found all solutions" << endl;
                return true;
            }
        }
    }

    
    // if position is outside of grid, return false
    if(x >= mTilesPerAxis - dist || x <= dist || y >= mTilesPerAxis - dist|| y <= dist) {
        return false;
    }

    
    
//    int offset = rand() % 4;
//    int index = 0;
      int newX, newY;
//    index++;

    
    while (1) {
    

        //int current = ((offset + index) % 4) + 1;
        
        
        switch (d)
        {
            case SOUTH:
                newX = x; newY = y+1;
                break;
            case NORTH:
                newX = x; newY = y-1;
                break;
            case EAST:
                newX = x+1; newY = y;
                break;
            case WEST:
                newX = x-1; newY = y;
                break;

        }
        
        
        bool success = solveWithBackTracking(newX, newY , d);
        if (success) return true;
        
        
        if (!success) d = newDir(d);
        
        
        mBoard[newX][newY] = true;
        mTempCallCount = 0;
        solveWithBackTracking(newX, newY, d);
        
        //cout << "draw to text" << endl;
        
        drawToText();
        return false;
        
    }
    



}

void PathMaker::drawToText(){
    
    cout << "Current grid: " << endl;
    
    for(int i = 0; i < mTilesPerAxis; i++) {
		for(int j = 0; j < mTilesPerAxis; j++) {
            cout << mBoard[i][j];
		}
        cout << endl;
	}
    
    
    
}


int PathMaker::newDir(int td)
{
    int nd = (rand() % 4) + 1;
    
    if(nd != td) {
      return nd;
    }else{
        return ((td + 1) % 4) + 1;
    }
}


vector<ofPoint> PathMaker::savePath()
{
    vector<ofPoint> myPath;
    
    for(int i = 0; i< mTilesPerAxis; i++){
        for(int j = 0; j < mTilesPerAxis; j++){
            //cout << "i: " << i << " j: " << j << endl;
            if( mBoard[i][j] == true){
                myPath.push_back(ofVec2f(i*10, j*10));
                
            }
            
        }
    }
    return myPath;
    
}


/*
 switch ( d )
 {
 case SOUTH:
 if (!mBoard[x+dist][y+dist] && !mBoard[x+dist][y] && !mBoard[x-dist][y+dist]) mBoard[x][y] = true;
 sCt++;
 //cout << "south call count: " << sCt << endl;
 if(sCt > lineReps){
 sCt = 0;
 d = newDir(d);
 }else{
 y++;
 }
 solveWithBackTracking(x, y, d );
 break;
 case EAST:
 if (!mBoard[x][y+dist] && !mBoard[x-dist][y] && !mBoard[x-dist][y-dist]) mBoard[x][y] = true;
 eCt++;
 if(eCt > lineReps){
 sCt = 0;
 d = newDir(d);
 }else{
 x++;
 }
 //cout << "east call count: " << eCt << endl;
 solveWithBackTracking(x, y, d);
 break;
 
 case WEST:
 if (!mBoard[x][y+dist] && !mBoard[x+dist][y] && !mBoard[x][y-dist]) mBoard[x][y] = true;
 wCt++;
 if(wCt > lineReps){
 sCt = 0;
 d = newDir(d);
 }else{
 x--;
 }
 //cout << "west call count: " << wCt << endl;
 solveWithBackTracking(x, y, d);
 break;
 
 case NORTH:
 if (!mBoard[x][y+dist] && !mBoard[x-dist][y] && !mBoard[x+dist][y]) mBoard[x][y] = true;
 nCt++;
 if(nCt > lineReps){
 sCt = 0;
 d = newDir(d);
 }else{
 y--;
 }
 //cout << "west call count: " << wCt << endl;
 solveWithBackTracking(x, y, d);
 break;
 }
*/