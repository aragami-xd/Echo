#pragma once

#include <Core.h>

class ECHO_DLL Scoring
{
protected:
	int combo;
	int maxCombo;
	int score;
public:
	Scoring();

	virtual void AddScore(int sscore) = 0;

	inline int GetMaxCombo() { return maxCombo; }
	inline int GetCombo() { return combo; }
	inline int GetScore() { return score; }
};