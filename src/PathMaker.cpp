//
//  PathMaker.cpp
//  ofPathMaker
//
//  Created by Justin Lange on 10/6/13.
//
//


#include "PathMaker.h"

PathMaker::PathMaker(int iTilesPerAxis)
: mTilesPerAxis(iTilesPerAxis), mSolutionCount(0), mTotalCallCount(0), mTempCallCount(0), margin(2), squareSize(10), mTilesFilled(0), lineReps(5), mMult(10)
{
	mBoard = new bool*[mTilesPerAxis];
	for(int i = 0; i < mTilesPerAxis; i++) {
		mBoard[i] = new bool[mTilesPerAxis];
		for(int j = 0; j < mTilesPerAxis; j++) {
			mBoard[i][j] = false;
		}
	}

    vector<ofPoint> myVector;
}


PathMaker::~PathMaker()
{
    delete [] mBoard; //why don't I have to specify both axis?
    
}

void PathMaker::callSolver(){
    solveWithBackTracking(3, 3, SOUTH);
    
}


bool PathMaker::solveWithBackTracking(int x, int y, int d)
{
    
    bool success = true;
    
    mTempCallCount++;
    mTotalCallCount++;

    drawToText();

    
    if(mTilesFilled >= (mTilesPerAxis-margin)*(mTilesPerAxis-margin)){
        return true;
    }
    

    if(x >= mTilesPerAxis - margin || x <= margin || y >= mTilesPerAxis - margin|| y <= margin) {
        return false;
    }
    
        

        if(!mBoard[x-1][y]){
            mBoard[x][y] = true;
            mTilesFilled++;
            solveWithBackTracking(x-1, y , d);
        }
        else if(!mBoard[x+1][y]){
            mBoard[x][y] = true;
            mTilesFilled++;
            solveWithBackTracking(x+1, y , d);
        }
        else if(!mBoard[x][y-1]){
            mBoard[x][y] = true;
            mTilesFilled++;
            solveWithBackTracking(x, y-1 , d);
        }
        else if(!mBoard[x][y+1]){
            mBoard[x][y] = true;
            mTilesFilled++;
            solveWithBackTracking(x, y+1 , d);
        }else{
            if(mBoard[x][y] == true){
                mBoard[x][y] = false;
                mTilesFilled--;
            }
            
            
            return false;
        }
        
        
        
        mLine.addVertex(x*mMult, y*mMult);
    
        //check neighbors, if none avail ;
        // else if avail
        //else if
        //else current tile == false;
        
        
        
        
        //solveWithBackTracking(newX, newY , d);
        
//        if (!success){
//            mBoard[newX][newY] = false;
//            d = newDir(d);
//        }
    
    

    //return true;

}


void PathMaker::drawToText(){
    
    cout << "Current grid: " << endl;
    
    for(int i = 0; i < mTilesPerAxis; i++) {
		for(int j = 0; j < mTilesPerAxis; j++) {
            cout << mBoard[i][j];
		}
        cout << endl;
	}
    
    cout << "total calls: " << mTotalCallCount << " tiles filled: " << mTilesFilled << endl;

    
    
    
}


int PathMaker::newDir(int td)
{
     int nd = (rand() % 4) + 1;
    
    switch( td ){
        case NORTH:
            while(nd == td || nd == SOUTH) {
                nd = (rand()  % 4 ) + 1;
                return nd;
            }
        case SOUTH:
            while(nd == td || nd == NORTH) {
                nd = (rand()  % 4 ) + 1;
                return nd;
            }
        case EAST:
            while(nd == td || nd == WEST) {
                nd = (rand()  % 4 ) + 1;
                return nd;
            }
        case WEST:
            while(nd == td || nd == EAST) {
                nd = (rand()  % 4 ) + 1;
                return nd;
            }
        }
}


ofPolyline PathMaker::returnPolyline(){
    return mLine;
    
}


vector<ofPoint> PathMaker::makeVector(int x, int y){
    myVector.push_back(ofPoint(x,y));
    
    
}





vector<ofPoint> PathMaker::savePathAsPoints()
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
