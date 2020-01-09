#include "OsuScoring.h"

void OsuScoring::AddScore(int sscore)
{
	if (sscore < 0)
		return;
	else if (sscore == 0)
		combo = 0;
	else
	{
		combo++;
		score += combo * sscore;
		if (combo > maxCombo)
			maxCombo = combo;
	}
}
