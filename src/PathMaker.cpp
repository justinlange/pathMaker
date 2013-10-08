//
//  PathMaker.cpp
//  ofPathMaker
//
//  Created by Justin Lange on 10/6/13.
//
//


#include "PathMaker.h"

PathMaker::PathMaker(int iTilesPerAxis)
: mTilesPerAxis(iTilesPerAxis), mSolutionCount(0), mTotalCallCount(0), mTempCallCount(0), dist(0), squareSize(10), mTilesFilled(0), lineReps(5), mMult(10)
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


    if(x >= mTilesPerAxis - dist || x <= dist || y >= mTilesPerAxis - dist|| y <= dist) {
        return false;
    }
    
    
    int newX, newY;

    
    while (1) {
        
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
        
        
        
        if(mTempCallCount > lineReps) d = newDir(d);
        
        //cout << "total calls: " << mTotalCallCount << endl;
        
        if(mTotalCallCount >= mTilesPerAxis * mTilesPerAxis) return true;
        
        //if(checkForAllSolutions()) return true;
        
        bool success = solveWithBackTracking(newX, newY , d);
        
        //----< add a point to a line

        drawToText();

        if (success){
            mBoard[newX][newY] = true;
            mLine.addVertex(newX*mMult, newY*mMult);
            mTilesFilled++;
        }
        
        if (!success) d = newDir(d);
        
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
    
    while(nd == td) {
        nd = (rand()  % 4 ) + 1;
    }
    return nd;
}


ofPolyline PathMaker::returnPolyline(){
    return mLine;
    
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


bool PathMaker::checkForAllSolutions(){
    
     int successCheck = 0;
     
     for(int i = 0; i < mTilesPerAxis-1; i++) {
         for(int j = 0; j < mTilesPerAxis-1; j++) {
            if (mBoard[i][j] == true) {
                successCheck++;
            }
             if (successCheck >= ((mTilesPerAxis*mTilesPerAxis) - 15)){
                 cout << "we have found all solutions" << endl;
                 return true;
             }
             
         }
     }
    
    return false;
}
