#pragma once

class ObjectRenderer
{
protected:

public:
	// draw using buffer vertices coordinates
	virtual void DrawBuf(int time) = 0;

	// draw using fragment shader
	virtual void DrawFrag(int time) = 0;
};