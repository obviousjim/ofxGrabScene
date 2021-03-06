//
//  Cursor.h
//  ofxGrabScene
//
#pragma once

#include "ofMain.h"

namespace GrabScene {
	//----------
	class Cursor {
	public:
		Cursor();
		ofVec2f screen;
		ofVec3f world;
		bool worldValid;
		bool button[3];
		bool captured;
		
		virtual void draw() const;
	};
	
	//----------
	class MovingCursor : public Cursor {
	public:		
		MovingCursor();
		
		void start(int button);
		void end(int button);
		
		void draw() const;
		
		float startTime; ///< time of birth
		ofVec2f startScreen;
		ofVec3f startWorld;
		Cursor lastFrame;
		int lastUpdate;
		bool dragged;
		
		ofVec3f worldViewFrameDifference;
		
		float getAge() const;
		ofVec2f getScreenFrameDifference() const;
		ofVec3f getWorldFrameDifference() const;
		ofVec2f getScreenVelocity() const;
		ofVec3f getWorldVelocity() const;
		float getActionAmplitude() const;
	};
}