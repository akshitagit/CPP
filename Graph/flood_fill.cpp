//Problem statement
// An image is represented by a 2-D array of integers,
// each integer representing the pixel value of the image (from 0 to 65535).
// Given a coordinate (sr, sc) representing the starting pixel 
// (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.
// To perform a "flood fill", consider the starting pixel,
// plus any pixels connected 4-directionally to the starting pixel of the same
//  color as the starting pixel, plus any pixels connected 4-directionally to those
//  pixels (also with the same color as the starting pixel), and so on. Replace the
//  color of all of the aforementioned pixels with the newColor.
// At the end, return the modified image.

#include<bits/stdc++.h>
using namespace std;

 vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(image[sr][sc] == newColor)
            return image;
        
        queue<int> qx;
        queue<int> qy;
        
        int rw = image.size();
        int clm = image[0].size();
        
        qx.push(sr);
        qy.push(sc);
        
        int curr = image[sr][sc];
        image[sr][sc] = newColor;
        
        while( !qx.empty() ) {
            
            int x = qx.front();
            int y = qy.front();
            
            qx.pop();
            qy.pop();
            
            int arrx[] = {-1, 0, 1, 0};
            int arry[] = {0, 1, 0, -1};
            
            for(int i=0; i<4; i++) {
                
                int tempx = x + arrx[i];
                int tempy = y + arry[i];
                
                if(tempx <0 || tempy < 0) continue;
                if(tempx >=rw || tempy >= clm) continue;
                
                if(image[tempx][tempy] == curr){
                    qx.push(tempx);
                    qy.push(tempy);
                    image[tempx][tempy] = newColor;
                }
            }
        }
        
        return image;
    }

